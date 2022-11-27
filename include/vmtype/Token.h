#pragma once
#include<stdint.h>
#define MAX_WORD_LEN 20
typedef char TL_TokenType;
typedef struct TL_Token
{
    TL_TokenType type;
    union
    {
        char strs[MAX_WORD_LEN];
        int val:MAX_WORD_LEN;
    };
};
