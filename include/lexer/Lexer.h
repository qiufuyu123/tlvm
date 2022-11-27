#pragma once
#include"vmtype/Token.h"

typedef struct TL_LexerStream
{
    char *code;
    uint32_t code_len;
    uint32_t index;

};
