#include <boost/program_options.hpp>

#include <iostream>

#include "translator_builder.h"

int main(int argc, const char *argv[]) try
{
    boost::program_options::options_description options_description("Macros-Translator usage");
    options_description.add_options()
            ("help", "Display this message")
            ("sources,s",
             boost::program_options::value<std::string>(), "Path to directory with work directory with tex sources")
            ("target,t", boost::program_options::value<std::string>(), "Path to target directory for scs sources");

    boost::program_options::variables_map vm;
    boost::program_options::store(
            boost::program_options::command_line_parser(argc, argv).options(options_description).run(), vm);
    boost::program_options::notify(vm);

    std::string workDirectory;
    if (vm.count("sources"))
        workDirectory = vm["sources"].as<std::string>();

    std::string targetDirectory;
    if (vm.count("target"))
        targetDirectory = vm["target"].as<std::string>();

    if (vm.count("help"))
    {
        std::cout << options_description;
        return EXIT_SUCCESS;
    }

    auto translator = TranslatorBuilder::BuildDefaultTranslator();

    return translator->Run(workDirectory, targetDirectory) ? EXIT_SUCCESS : EXIT_FAILURE;
}
catch (std::exception const &e)
{
    std::cout << e.what();
}
