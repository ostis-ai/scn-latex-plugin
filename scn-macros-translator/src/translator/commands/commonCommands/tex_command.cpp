#include "tex_command.h"
#include <sstream>

using namespace helper;

std::string TexCommand::Complete(TexCommandParams const &params)
{
    std::stringstream result;
    const std::string &commandName = GetCommandName(params);
    result << texSlash << commandName;
    for (const std::string &param: params)
    {
        if (param != commandName)
        {
            result << openBr << param << closeBr;
        }
    }

    return result.str();
}
