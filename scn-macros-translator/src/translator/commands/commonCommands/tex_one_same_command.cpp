#include "tex_one_same_command.h"

using namespace helper;

std::string TexOneSameCommand::Complete(TexCommandParams const &params)
{
    std::stringstream result;
    result << texSlash << GetCommandName(params) << openBr
           << GetFirstParameter(params) << closeBr << newline;
    return result.str();
}
