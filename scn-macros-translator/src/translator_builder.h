#pragma once

#include "memory"
#include "translator/macros_translator.h"
#include "translator/commands/command_defines.h"

class TranslatorBuilder
{
public:
    static std::unique_ptr<MacrosTranslator> BuildDefaultTranslator()
    {
        return std::make_unique<MacrosTranslator>();
    }
};
