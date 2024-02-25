#include <stdio.h> /*for the print*/
#include <stdlib.h> /*for malloc*/
#include "GenericDoubleLinkedList.h"
struct Node

{
    void* m_data;
    Node* m_next;
    Node* m_prev;
};

struct List
{
    Node m_head;
    Node m_tail;
};
Node* CreateNode( void* _item);
void InsertNode(Node* _p, Node* _t);
static int ListIsEmpty(List* _list);
void RemoveNode(Node* _t);

Node* GetHeadNext(List *_list)
{
	return _list -> m_head.m_next;
}
Node* GetTailPrev(List *_list)
{
	return _list -> m_tail.m_prev;
}
Node* GetHeadPrev(List *_list)
{
	return _list -> m_head.m_prev;
}
Node* GetTailNext(List *_list)
{
	return _list -> m_tail.m_next;
}
/**************************************************************************/
List* ListCreate(void)
{
    List *pList;
	if ((pList = (List*)malloc(sizeof(List))) == NULL)
	{
		return NULL;
 	}
 	pList -> m_head.m_next = &pList -> m_tail;
 	pList -> m_head.m_prev =  &pList -> m_head; 	
 	pList -> m_tail.m_next = &pList ->m_tail;
 	pList -> m_tail.m_prev = &pList -> m_head;

 	return pList;	
}
/**************************************************************************/
void ListDestroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* current;

	if (NULL == _pList || NULL == *_pList) 
    {
        return;
    }
	  
    current = ((*_pList)->m_head).m_next;
    while (current != &(*_pList)-> m_tail)
    {	
        if (NULL != _elementDestroy)
        {
            _elementDestroy (current-> m_data);
        }
        current = current->m_next;
        free(current->m_prev);
    }
    
    free(*_pList);
    *_pList = NULL;
}
/**************************************************************************/
ListResult ListPushHead(List* _list, void* _item)
{
    Node* newNode = NULL;
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
    if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if (NULL == (newNode = CreateNode(_item)))
	{
		return LIST_ALLOCATION_ERROR;
	}
	InsertNode(newNode, _list-> m_head.m_next);/*the func gets the one to insert and the last node, the new go before */
	
	return LIST_SUCCESS;
}
/****************************************************************************/
ListResult ListPushTail(List* _list, void* _item)
{
    Node* newNode = NULL;
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
    if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if (NULL == (newNode = CreateNode(_item)))
	{
		return LIST_ALLOCATION_ERROR;
	}
    InsertNode(newNode, &_list -> m_tail);
	
	return LIST_SUCCESS;
}
/****************************************************************************/
ListResult ListPopHead(List* _list, void** _pItem)
{
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
    if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
    if(TRUE == ListIsEmpty( _list)) 
    {
        return LIST_IS_EMPTY_ERROR;
    }
    * _pItem = _list ->m_head.m_next-> m_data;
    RemoveNode(_list-> m_head.m_next); 

    return LIST_SUCCESS;    
}
/****************************************************************************/
ListResult ListPopTail(List* _list, void** _pItem)
{
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
    if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
    if(TRUE == ListIsEmpty( _list)) 
    {
        return LIST_IS_EMPTY_ERROR;
    }
    * _pItem = _list ->m_tail.m_prev-> m_data; 
    RemoveNode(_list-> m_tail.m_prev); 

    return LIST_SUCCESS;    
}
/****************************************************************************/
size_t ListSize(const List* _list)
{
	size_t counter = 0;
	Node* current;
	if(NULL == _list)
	{
		return 0;
	}
	current = _list->m_head.m_next;

	while (current != &_list->m_tail)
	{
		counter ++;
        current = current->m_next;
	}
	return counter;
}

/****************************************************************************/
/**************************HELP FUNCTIONS***********************************/
/**************************************************************************/
Node* CreateNode( void* _item)
{
    Node* newNode;
    if (NULL == (newNode = (Node*)malloc(sizeof(Node))))
   {
   		return NULL;
   }
 	newNode -> m_data = _item;
    return newNode;
}
/**************************************************************************/
void InsertNode(Node* _p, Node* _t)
{	
	_p-> m_prev = _t-> m_prev;
	_p-> m_next = _t ; /*we put the previous haed on the next of the new head*/
	_t-> m_prev->m_next = _p;
	_t->m_prev = _p;
}
/**************************************************************************/
static int ListIsEmpty(List* _list)
{
	return (_list-> m_head.m_next == & _list-> m_tail) ? TRUE : FALSE;
}
/**************************************************************************/
void RemoveNode(Node* _t)
{
    _t-> m_prev->m_next = _t->m_next;
	_t->m_next->m_prev = _t->m_prev;
	free (_t);
}