#include <stdio.h> /*printf*/
#include <stddef.h> /*size_t*/
#include "listFanctions.h"
#include "ListItr2.h" 
typedef int (*GenFunction)(void* _element, void* _context);
typedef int (*InnerFunction)(int _result, void* _context);

ListItr static InternalForEach(ListItr _begin,ListItr _end, GenFunction _genFunction, void* context, InnerFunction _innerFunction, void* _intercounter);
static int InnerFindFirst(int _result, void* _innerContext);
static int InnerItrCountIf(int _result, void* _innerContext);
static int InnerItrForEach(int _result, void* _innerContext);
/************************************************************************************/
ListItr ListItrFindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
    if (NULL == _begin || NULL == _end || NULL == _predicate)
    {
        return NULL;
    }
   return InternalForEach(_begin,_end, _predicate, _context, InnerFindFirst, NULL);
}
/***************************************************************************/
size_t ListItrCountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
    size_t counter =0;
    if (NULL == _begin || NULL == _end || NULL == _predicate)
    {
        return 0;
    } 
    InternalForEach(_begin, _end, _predicate ,_context, InnerItrCountIf, &counter);
    return counter;
}
/***************************************************************************/
ListItr ListItrForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
    if (NULL == _begin || NULL == _end || NULL == _action)
    {
        return NULL;
    }
    return InternalForEach(_begin, _end, _action ,_context, InnerItrForEach, NULL);
}
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
ListItr static InternalForEach(ListItr _begin,ListItr _end, GenFunction _genFunction, void* context, InnerFunction _innerFunction, void* _intercounter)
{
    int result;
    void* data;
    if (NULL == _begin || NULL == _end)
    {
        return NULL;
    }
    while(_begin != _end)
    {
        data = ListItrGet(_begin);
        result = _genFunction(data, context);
        result = _innerFunction(result,_intercounter);
        if(result == 0) 
        {
            break;
        }
       _begin = ListItrNext(_begin);
    }
    return _begin;

}
/***************************************************************************/
static int InnerFindFirst(int _result, void* _innerContext)
{
    if (_result == 1)
    {
        return 0;
    }
    return 1;
}
/***************************************************************************/
static int InnerItrCountIf(int _result, void* _innerContext)
{
    if (_result == 1)
    {
        ++(*(size_t*) _innerContext);
    }
    return 1;
}
/***************************************************************************/
static int InnerItrForEach(int _result, void* _innerContext)
{
    if (_result == 0)
    {
       return 0;
    }
    return 1;
}
