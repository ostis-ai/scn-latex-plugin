#pragma once

#include "../command.h"

class TexOneToTextCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};
