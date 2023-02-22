#include "tex_zero_same_command.h"

using namespace helper;

std::string TexZeroSameCommand::Complete(
        TexCommandParams const &params)
{
    std::stringstream result;
    result << texSlash << GetCommandName(params);
    return result.str();
}
