#pragma once

#include "../command.h"

class TexOneToEnvironmentCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
