#pragma once

#include "../command.h"

class TexTwoSameCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
