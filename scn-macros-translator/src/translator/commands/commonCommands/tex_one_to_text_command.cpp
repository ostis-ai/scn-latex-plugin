#include "tex_one_to_text_command.h"

using namespace helper;

std::string TexOneToTextCommand::Complete(
        TexCommandParams const &params)
{
    std::stringstream result;
    std::string commandName = GetCommandName(params);
    std::string scn = "scn";

    std::size_t ind = commandName.find(scn);
    if (ind != std::string::npos)
    {
        commandName.erase(ind, scn.length());
    }
    result << texSlash << "scntext" << openBr << commandName << closeBr << openBr << GetFirstParameter(params)
           << closeBr;
    return result.str();
}