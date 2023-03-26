#pragma once

#include "tex_one_same_command.h"

class TexZeroSameCommand : public TexOneSameCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
