#pragma once
#include<stdint.h>
#include"config.h"
typedef struct 
{
    uint32_t capacity;
    uint32_t used;
    uint8_t unit_size;
    TL_Ptr *data;
}TL_Array_t;
typedef char TL_ArrayUnitSize;

TL_Array_t* TL_ArrayAlloc(TL_ArrayUnitSize usize);

void* TL_ArraySet(TL_Array_t* array,void *value,uint32_t index);

void* TL_ArrayPush(TL_Array_t* array,void*value);

void* TL_ArrayGet(TL_Array_t* array,uint32_t index);

uint32_t TL_ArrayFree(TL_Array_t*array);


