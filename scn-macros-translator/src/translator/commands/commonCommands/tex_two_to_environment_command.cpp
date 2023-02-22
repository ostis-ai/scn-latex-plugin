#include "tex_two_to_environment_command.h"

using namespace helper;

std::string TexTwoToEnvironmentCommand::Complete(
        TexCommandParams const &params)
{
    std::stringstream result;
    const std::string &commandName = GetCommandName(params);
    result << texSlash << "begin" << openBr << commandName << closeBr << openBr << GetFirstParameter(params) << closeBr
           << newline << beginToDo << newline << ParseByDelim(params, SECOND_PARAMETER_POS) << endToDo << newline
           << texSlash << "end" << openBr << commandName << closeBr << newline;
    return result.str();
}
