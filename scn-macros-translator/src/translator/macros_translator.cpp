#include "macros_translator.h"

bool MacrosTranslator::Run(std::string const &workDirectoryPath, std::string const &targetDirectoryPath)
{
    ScDirectory const &workDirectory{workDirectoryPath};
    m_filesCount = workDirectory.CountFiles(m_extensions);
    ScDirectory const &targetDirectory{targetDirectoryPath};

    std::string const &startDirectoryPath = workDirectory.GetPath();
    m_fileNumber = 0;

    std::cout << "Sources directory: " << workDirectory.GetPath() << std::endl;
    std::cout << "Target directory: " << targetDirectory.GetPath() << std::endl;

    std::cout << "Start translate sources:" << std::endl;
    TranslateFiles(startDirectoryPath, workDirectory, targetDirectory);
    std::cout << "Translation finished" << std::endl;

    return true;
}

void MacrosTranslator::TranslateFiles(
        std::string const &nestedDirectoryPath,
        ScDirectory startDirectory,
        ScDirectory const &startTargetDirectory)
{
    ScDirectory targetDirectory = startDirectory.CopyDirectory(nestedDirectoryPath, startTargetDirectory);

    ScDirectory{nestedDirectoryPath}.ForEach(
            [this, &startDirectory, &startTargetDirectory](ScDirectory const &directory) {
                TranslateFiles(directory.GetPath(), startDirectory, startTargetDirectory);
            },
            [this, &targetDirectory](ScFile const &file) {
                bool result = TranslateFile(file.GetPath(), targetDirectory);
                std::cout << "[" << ++m_fileNumber << "/" << m_filesCount << "]: " << file.GetPath()
                          << " - " << (result ? "OK" : "ERROR") << std::endl;
            });
}


bool MacrosTranslator::TranslateFile(
        std::string const &filePath, ScDirectory const &targetDirectory)
{
    ScFile targetFile = targetDirectory.CopyFile(filePath, ".tex");

    std::string texText;
    try
    {
        texText = TranslateText(filePath);
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    targetFile.Write(texText);

    return true;
}

std::string MacrosTranslator::TranslateText(std::string const &filePath)
{
    std::ifstream file(filePath, std::ios_base::in);
    antlr4::ANTLRInputStream input(file);
    SCnTexLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    SCnTexParser parser(&tokens);
    SCnTexParser::ScnTexTextContext *ctx;
    try
    {
        ctx = parser.scnTexText();
    }
    catch (...)
    {
        throw;
    }
    file.close();
    return ctx->resultText;
}
