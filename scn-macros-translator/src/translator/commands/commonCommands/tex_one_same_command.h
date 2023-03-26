#pragma once

#include "../command.h"

class TexOneSameCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
