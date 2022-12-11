#include"vmtype/TLArray.h"
#include"config.h"
#include"vmtype/TLError.h"
#define TL_ARRAY_INDEX_CHK(array,index)(array->capacity>index&&index>=0)
#define TL_ARRAY_ASSERT(ptr) TL_ASSERT(ptr,TL_ERROR_NULL_PTR);TL_ASSERT(ptr->data,TL_ERROR_NULL_PTR);
TL_Array_t* TL_ArrayAlloc(TL_ArrayUnitSize usize)
{
    TL_RESOUCE_NEW(TL_Array_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->used=0;
    re->capacity=re->unit_size=usize;
    re->data=TL_MEM_ALLOC(usize*sizeof(char*));
    TL_ASSERT_WITH_EXPR(re->data,TL_MEM_FREE(re->data),TL_ERROR_MEMORY_EXHAUST);  
    return re;
}

void* TL_ArraySet(TL_Array_t* array,void *value,uint32_t index)
{
    TL_ARRAY_ASSERT(array);
    TL_ASSERT(TL_ARRAY_INDEX_CHK(array,index),TL_ERROR_NULL_PTR);
    array->data[index]=value;
    return value;

}

void* TL_ArrayPush(TL_Array_t* array,void*value)
{
    TL_ARRAY_ASSERT(array);
    if(array->capacity>array->used)
    {
        array->data[array->used]=value;
        array->used++;
    }else
    {
        void* nubf=TL_MEM_REALLOC(array->data,sizeof(TL_Ptr)*(array->capacity+array->unit_size));
        if(!nubf)TL_ASSERT(0,TL_ERROR_MEMORY_EXHAUST);
        //TL_MEM_FREE(array->data);
        array->data=nubf;
        array->capacity+=array->unit_size;
        array->data[array->used]=value;
        array->used++;
    }
    return value;
}

void* TL_ArrayGet(TL_Array_t* array,uint32_t index)
{
    TL_ARRAY_ASSERT(array);
    TL_ASSERT(TL_ARRAY_INDEX_CHK(array,index),TL_ERROR_NULL_PTR);
    return array->data[index];
}

uint32_t TL_ArrayFree(TL_Array_t*array)
{
    TL_ARRAY_ASSERT(array);
    TL_MEM_FREE(array->data);
    TL_MEM_FREE(array);

}