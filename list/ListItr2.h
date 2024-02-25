#ifndef ____LISTITR2_H____
#define ____LISTITR2_H____
#include "GenericDoubleLinkedList.h"
#include "ListItr.h" 

void InsertNode(Node* _p , Node* _t);
void RemoveNode(Node* _t);
Node* CreateNode( void* _item);


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



#endif /* ____LISTITR2_H____ */
