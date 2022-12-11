#pragma once
#include"vmtype/TLToken.h"

typedef struct
{
    TL_Array_t* token_module_list;
    TL_String_t* current_code_page;
}TL_lexer_t;
