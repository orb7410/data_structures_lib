#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "ListItr2.h" 
#include "ListItr.h" 

/*Node* GetTailNext(List *_list)
{
	return _list -> m_tail.m_next;
}*/

/**************************************************************/
ListItr ListItrBegin(const List* _list)
{
	if (NULL == _list)
	{
		return NULL;
	}
	return((void*) _list -> m_head.m_next);
}
/**************************************************************/
ListItr ListItrEnd(const List* _list)
{
	if (NULL == _list)
	{
		return NULL;
	}
	return ((ListItr*)(&_list -> m_tail));
}
/**************************************************************/
int ListItrEquals(const ListItr _a, const ListItr _b)
{
	if(_a == _b)
	{
		return TRUE;
	}
	return FALSE;
}
/**************************************************************/
ListItr ListItrNext(ListItr _itr)
{
	if (NULL == _itr)
	{
		return NULL;
	}
	return ((Node*)_itr) -> m_next;
}
/**************************************************************/
ListItr ListItrPrev(ListItr _itr)
{
	if (NULL == _itr)
	{
		return NULL;
	}
	/*meaning we in the begine*/
	if(((Node*)_itr)->m_prev -> m_prev == ((Node*)_itr)-> m_prev)
	{
		return _itr;
	}
	return ((Node*)_itr) -> m_prev;
}
/**************************************************************/
void* ListItrGet(ListItr _itr)
{
	if (NULL == _itr || ((Node*)_itr) -> m_next == _itr)
	{
		return NULL;
	}
	return ((Node*)_itr) -> m_data;
}
/**************************************************************/
void* ListItrSet(ListItr _itr, void* _element)
{
	void* item;
	if (NULL == _itr || NULL == _element || ((Node*)_itr) -> m_next == (Node*)_itr)
	{
		return NULL;
	}
	item = ((Node*)_itr) -> m_data;
	((Node*)_itr) -> m_data = _element;
	return item;
}
/**************************************************************/
ListItr ListItrInsertBefore(ListItr _itr, void* _element)
{
	Node* ptrNode = NULL;
	if (NULL == _itr || NULL == _element)
	{
		return NULL;
	}
	ptrNode = CreateNode(_element); /*pointer to new element*/
	if(NULL == ptrNode)
	{
		return NULL;
	}
	InsertNode(ptrNode, _itr);
	return ptrNode;
}
/**************************************************************/
void* ListItrRemove(ListItr _itr)
{
	Node* ptrData = NULL;
	if (NULL == _itr || ((Node*)_itr) -> m_next == _itr)
	{
		return NULL;
	}
	ptrData = ((Node*)_itr) -> m_data;
	RemoveNode((Node*)_itr);
	return ptrData;
}