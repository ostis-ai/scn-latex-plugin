#include "tex_one_to_environment_command.h"

using namespace helper;

std::string TexOneToEnvironmentCommand::Complete(
        TexCommandParams const &params)
{
    std::stringstream result;
    const std::string &commandName = GetCommandName(params);
    result << texSlash << "begin" << openBr << commandName << closeBr << newline << beginToDo << newline
           << ParseByDelim(params) << endToDo << newline << texSlash << "end" << openBr << commandName << closeBr
           << newline;
    return result.str();
}
