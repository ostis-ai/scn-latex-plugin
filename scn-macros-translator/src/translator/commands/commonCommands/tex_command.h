#pragma once

#include "../command.h"

class TexCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
