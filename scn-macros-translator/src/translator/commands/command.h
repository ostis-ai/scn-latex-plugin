#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>

#include "helper.h"

using TexCommandParams = std::vector<std::string>;

class ScSCnTexCommand
{
public:
    virtual std::string Complete(TexCommandParams const &params) = 0;

    virtual ~ScSCnTexCommand() = default;

};
