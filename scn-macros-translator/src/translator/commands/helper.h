#pragma once

#include "iostream"

constexpr int COMMAND_NAME_POS = 0;
constexpr int FIRST_PARAMETER_POS = 1;
constexpr int SECOND_PARAMETER_POS = 2;
const std::string texSlash = "\\";
const std::string delimeter = ";";
const std::string openBr = "{";
const std::string closeBr = "}";
const std::string newline = "\n";
const std::string beginToDo = "%TODO: check by human--->";
const std::string endToDo = "%<---TODO: check by human";

namespace helper {
    static std::string GetCommandName(const std::vector<std::string> &params)
    {
        return params.at(COMMAND_NAME_POS);
    }

    static std::string GetFirstParameter(const std::vector<std::string> &params)
    {
        return params.at(FIRST_PARAMETER_POS);
    }

    static std::string GetSecondParameter(const std::vector<std::string> &params)
    {
        return params.at(SECOND_PARAMETER_POS);
    }

    static std::string GetLastParameter(const std::vector<std::string> &params)
    {
        return params.at(params.size() - 1);
    }

    static std::string ParseByDelim(const std::vector<std::string> &params, int pos = FIRST_PARAMETER_POS,
                                    const std::string &delim = delimeter)
    {
        const std::string &content = params.at(pos);
        for (const auto &param: params)
        {
            std::cout << param << std::endl;
        }
        size_t start;
        size_t end = 0;
        std::stringstream result;
        while ((start = content.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = content.find(delim, start);
            result << texSlash << "scnitem" << openBr << content.substr(start, end - start) << closeBr << newline;
        }
        return result.str();
    }
}