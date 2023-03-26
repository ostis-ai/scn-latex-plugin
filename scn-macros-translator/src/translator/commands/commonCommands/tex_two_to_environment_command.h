#pragma once

#include "../command.h"

class TexTwoToEnvironmentCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
