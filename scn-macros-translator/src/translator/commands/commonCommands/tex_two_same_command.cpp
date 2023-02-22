#include "tex_two_same_command.h"

using namespace helper;

std::string TexTwoSameCommand::Complete(
        TexCommandParams const &params)
{
    std::stringstream result;
    result << texSlash << GetCommandName(params) << openBr << GetFirstParameter(params) << closeBr << openBr
           << GetSecondParameter(params) << closeBr << newline;
    return result.str();
}
