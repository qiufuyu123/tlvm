#include"vmtype/TLFuncList.h"
#include"vmtype/TLError.h"
void *TL_FuncListInvoke(TL_FuncList*lst,int idx)
{
    void *f=TL_ArrayGet(lst,idx);
    TL_ASSERT(f,TL_ERROR_ANALYSIS_FLOW_NULL_INVOKE);
    return f;
}