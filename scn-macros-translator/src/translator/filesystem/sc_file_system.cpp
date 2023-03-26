#include "sc_file_system.h"

ScDirectory::ScDirectory(std::string path)
        : m_path(std::move(path))
{
    m_entry = std::filesystem::directory_entry{m_path};
    if (!m_entry.exists())
        std::filesystem::create_directory(m_entry);
}

std::string ScDirectory::GetPath() const
{
    return m_path;
}

ScFile ScDirectory::CopyFile(std::string const &filePath, std::string const &newExtension) const
{
    std::string const &fileName = filePath.substr(filePath.rfind('/') + 1, filePath.size());
    std::string const &fileNameWithoutExtension = fileName.substr(0, fileName.rfind('.'));

    ScStringStream stream;
    (m_path.at(m_path.size() - 1) == '/'
     ? stream << m_path
     : stream << m_path << "/")
            << fileNameWithoutExtension << (newExtension.at(0) == '.' ? newExtension : "." + newExtension);

    return ScFile{stream};
}

ScFile ScDirectory::CopyFile(ScFile const &file, std::string const &newExtension) const
{
    return CopyFile(file.GetPath(), newExtension);
}

ScDirectory ScDirectory::CopyDirectory(std::string nestedDirectoryPath, std::string const &targetDirectoryPath) const
{
    size_t pos = nestedDirectoryPath.find(m_path);
    std::string const &nestedDirectoryName = nestedDirectoryPath.replace(pos, m_path.size(), "");

    ScStringStream stream;
    stream
            << (targetDirectoryPath.at(targetDirectoryPath.size() - 1) == '/'
                ? targetDirectoryPath
                : targetDirectoryPath + "/")
            << nestedDirectoryName;

    return ScDirectory{stream};
}

ScDirectory ScDirectory::CopyDirectory(std::string const &nestedDirectoryPath, ScDirectory const &targetDirectory) const
{
    return CopyDirectory(nestedDirectoryPath, targetDirectory.GetPath());
}

size_t ScDirectory::CountFiles(std::unordered_set<std::string> const &extensions) const
{
    size_t count = 0;
    PathFiles(m_path, count, extensions);

    return count;
}

void ScDirectory::ForEach(
        std::function<void(ScDirectory const &directory)> const &directoryCallback,
        std::function<void(ScFile const &file)> const &fileCallback)
{
    auto const &it = std::filesystem::directory_iterator(m_path);
    for (auto const &item: it)
    {
        if (item.is_directory() && directoryCallback)
        {
            directoryCallback(ScDirectory(item.path()));
        } else if (fileCallback)
        {
            fileCallback(ScFile(item.path()));
        }
    }
}

void ScDirectory::PathFiles(
        std::string const &workDirectory, size_t &count, std::unordered_set<std::string> const &extensions) const
{
    auto const &it = std::filesystem::directory_iterator{workDirectory};
    for (auto &item: it)
    {
        std::string const &path = item.path();

        if (item.is_directory())
        {
            PathFiles(path, count, extensions);
        } else if (ScFile{path}.HasExtension(extensions))
        {
            ++count;
        }
    }
}
