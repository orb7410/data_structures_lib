#include <stdio.h>
#include <stdlib.h>
#include "Gtree.h"
#define TREE_IS_EMPTY(tree) (tree -> m_root.m_left == NULL)
#define HAS_NO_LEFT_SON(_node) ((Node*)_node) -> m_left == NULL
#define HAS_RIGHT_SON(_node) (((Node*)_node) -> m_right != NULL)
#define HAS_NO_RIGHT_SON(_node) (((Node*)_node) -> m_right == NULL)
#define IS_ROOT(node)((node) -> m_father == (node))
#define IS_LEEF(node)((node) -> m_left == NULL && (node) -> m_right == NULL)
#define IS_LEFT_CHILD(node)((node) -> m_father -> m_left == (node))
#define HAS_ONE_CHILD(node)(((node) -> m_left == NULL && (node) -> m_right != NULL) ||\
                             ((node) -> m_left != NULL && (node) -> m_right == NULL)) 
#define HAS_ONE_CHILD_LEFT(node)((node) -> m_left != NULL)
typedef struct Node Node;
struct Node
{
	void* m_data;
	Node* m_left;
	Node* m_right;
	Node* m_father;
};

struct BSTree
{
	Node m_root;
    ActionFunction m_func;
};
void* GetNodeLeft(BSTree* _tree)
{
    return _tree ->m_root.m_left;
}
void* GetNodeLeftData(BSTree* _tree)
{
    return _tree ->m_root.m_left->m_data;
}
void* GetNodeRight(BSTree* _tree)
{
    return _tree ->m_root.m_right;
}
void* GetTreeRoot(BSTree* _tree)
{
    return &(_tree ->m_root);
}
void* GetRootFather(BSTree* _tree)
{
    return _tree ->m_root.m_father;
}
void* GetData(BSTreeItr* _node)
{
    return ((Node*) _node)->m_data;
}
static Node* FindData(BSTree* _tree, void* _data);
static void NodeDestroyRec (Node *_root, void (*_destroyer)(void*));
static Node* NodeCreate(void* _data, Node *_father);
static Node* BSTreeItrBeginRec(Node* _node);
static void RemoveLeaf(Node* _node);
static void RemoveSingleChild(Node* _node);
static void SwapData(Node* _node1, Node* _node2);
BSTree* BSTreeCreate(LessComparator _less)
{
    BSTree *pTree;
    if (NULL == _less)
    {
        return NULL;
    }
    if (NULL==(pTree = (BSTree*)malloc(sizeof(BSTree))))
	{
		return NULL;
 	}

 	pTree->m_func = _less;
    pTree -> m_root.m_data = NULL;
    pTree -> m_root.m_left = NULL;
    pTree -> m_root.m_right = NULL;
    pTree -> m_root.m_father= &(pTree ->m_root);             
	
 	
 	return pTree;
}
/*****************************************************************/
void  BSTreeDestroy(BSTree** _tree, void (*_destroyer)(void*))
{
    if (NULL == _tree  || NULL == *_tree) 
    {
		return;
    }
  	
    NodeDestroyRec((*_tree) -> m_root.m_left, _destroyer );
  
	free(*_tree);
    *_tree = NULL;
}
/*****************************************************************/
BSTreeItr BSTreeInsert(BSTree* _tree, void* _item) /*return root case err allocation/duplication*/
{
	Node *newNode = NULL;
	Node *ptrFather = NULL;
	if (NULL == _tree || NULL == _item ) /*ptr null check*/
    {
		return NULL;
    }	
    if (_tree -> m_root.m_left == NULL) /*check if the root is empty so we can just insert to left*/
    {
		if ( NULL == (newNode = NodeCreate( _item, NULL ))) /*placement of the data allready done in the NodeCreat func*/ 
		{
			return (&(_tree ->m_root));
		}
        _tree->m_root.m_left = newNode;
        newNode -> m_father= &(_tree ->m_root); 
		return newNode;
    }	
    
    if (NULL == (ptrFather = FindData( _tree, _item)))/*case findata return NULL means doplication of data*/
    {
    	return (&(_tree ->m_root));	
    }
    else
    {
    	if ((newNode = NodeCreate (_item ,ptrFather)) == NULL)
    	{
    		return (&(_tree ->m_root));
    	}
    	else if( -1 == _tree-> m_func(ptrFather-> m_data , _item))
    	{
    		ptrFather ->m_right = newNode;
    	}
    	else if( 1 == _tree-> m_func(ptrFather-> m_data , _item))
    	{
    		ptrFather ->m_left = newNode;
    	}	
    	return newNode;
    }
}
/**************************************************************/
BSTreeItr BSTreeItrBegin(const BSTree* _tree)
{
    if (NULL == _tree)
    {
        return NULL;
    }
	if(NULL == _tree->m_root.m_left)
	{
		return ((void*)&(_tree ->m_root));
	}	
		
	return (BSTreeItrBeginRec(_tree-> m_root.m_left));
}
/**************************************************************/
BSTreeItr BSTreeItrEnd(const BSTree* _tree)
{
    if (NULL == _tree)
    {
        return NULL;
    }
    return ((void*)&(_tree ->m_root));
}
/**************************************************************/
int BSTreeItrEquals(BSTreeItr _a, BSTreeItr _b)
{
    return (_a == _b);
}
/**************************************************************/
BSTreeItr BSTreeItrNext(BSTreeItr _it)
{
    Node* current, *temp;
    if(NULL == _it)
    {
        return NULL;
    }
    current = (Node*)_it;
    if(HAS_NO_RIGHT_SON(current))
    { 
        temp = current;
        current = current -> m_father;
        while(current -> m_left != temp) /*as long you are the right son*/
        {
            temp = current;
            current = current -> m_father;
            if (current == temp) /*if you are the root*/
            {
                return _it;
            }
        }
    }
        else /*has right son*/
        {
           current = current->m_right;
           while(current -> m_left!= NULL) /*goes to the end*/
           {
                current = current->m_left;
           }
        }
    return current;
}
/**************************************************************/
BSTreeItr BSTreeItrPrev(BSTreeItr _it)
{
    Node* current, *temp;
    if(NULL == _it)
    {
        return NULL;
    }
    current = (Node*)_it;
    if(HAS_NO_LEFT_SON(current)) /*get up til you are a left son*/
    { 
        temp = current;
        current = current -> m_father;
        while(current -> m_right != temp) /*as long you are the left son(you are not equal to your father right son)*/
        {
            temp = current;
            current = current -> m_father;
            if (current == temp) /*if you are the root*/
            {
                return _it;
            }
        }
    }
    else /*has left son*/ /*go left and then right til the end*/    
        {
           current = current-> m_left;
           while(current ->m_right != NULL) /*goes to the end*/
           {
                current = current->m_right;
           }
        }
    return current;
}
/**************************************************************/
void* BSTreeItrRemove(BSTreeItr _it)
{
    Node* current, *next;
    void* data;
    if(NULL == _it|| IS_ROOT((Node*)_it))
    {
        return NULL;
    }
    current = (Node*)_it;
    data = current -> m_data;
    if (IS_LEEF(current))
    {
        RemoveLeaf(current);
    }
    else if (HAS_ONE_CHILD(current))
    {
        RemoveSingleChild(current);
    }
    else /*has two sons*/
    {
        next = (Node*)BSTreeItrNext(_it);
        SwapData(current, next);
        if(HAS_ONE_CHILD(next)) /*if your son has 1 son*/
        {
            RemoveSingleChild(next);
        }
        else /*if your son has 2 son*/
        {
            RemoveLeaf(current); /*if you have 2 chiled you cant be the next*/
        }
    }
    return data;
}
/**************************************************************/
void* BSTreeItrGet(BSTreeItr _it)
{
    if (_it == NULL || ((Node*)_it) -> m_father == (Node*)_it)
    {
        return NULL;
    }
    return (((Node*)_it) -> m_data);
}
/**************************************************************/
/**************************************************************/
/**************************************************************/
static void RemoveSingleChild(Node* _node)
{
    if (HAS_ONE_CHILD_LEFT(_node))
    {
        if (IS_LEFT_CHILD(_node))
        {
            _node -> m_father -> m_left = _node -> m_left;
        }
        else /*if you are a right son*/
        {
            _node -> m_father -> m_right = _node -> m_left;
        }
        _node -> m_left -> m_father = _node -> m_father;
    }
    else {
        if (IS_LEFT_CHILD(_node))
        {
            _node -> m_father -> m_left = _node -> m_right;
        }
        else {
            _node -> m_father -> m_right = _node -> m_right;
        }
        _node -> m_right -> m_father = _node -> m_father;
    }
    free(_node);
    return;
}
static void RemoveLeaf(Node* _node)
{
    if (IS_LEFT_CHILD(_node))
    {
        _node -> m_father -> m_left = NULL;
    }
    else {
        _node -> m_father -> m_right = NULL;
    }
    free(_node);
    return;
}
/**************************************************************/
static void SwapData(Node* _node1, Node* _node2)
{
    void* temp = _node1-> m_data;
    _node1-> m_data = _node2-> m_data;
    _node2-> m_data = temp;

}
/**************************************************************/
static Node* NodeCreate(void* _data, Node *_father)
{
	Node *pNode = (Node*)malloc(sizeof(Node));
	if ( NULL == pNode)
	{
		return NULL;
 	}
	
	 pNode -> m_data = _data;
 	 pNode -> m_left = NULL;
 	 pNode -> m_right = NULL;
 	 pNode -> m_father = _father;
 	
 	return pNode;
}
/*************************************************************/
static Node* BSTreeItrBeginRec(Node* _node)
{
    if (NULL == _node->m_left)
    {
       return _node;
    }
    return BSTreeItrBeginRec (_node-> m_left);
}
/**************************************************************************/
static Node* FindData(BSTree* _tree, void* _data)
{
	Node *runner = _tree-> m_root.m_left;
	Node *father = runner;
	while (runner!= NULL)  
	{
		father = runner; /*we keep the previous root address in the father*/
        if ( 1 == (_tree-> m_func(runner -> m_data, _data)))
        {
            runner = runner -> m_left; /*we promote the loop to the next root*/
        }
        else if ( -1 == (_tree-> m_func(runner -> m_data, _data)))
        {
            runner = runner -> m_right;/*we promote the loop to the next root*/
        }
        else if ( 0 == (_tree-> m_func(runner -> m_data, _data))) /*case of duplication*/
        {
            return NULL;
        }		
	}	
	return father;
}
/****************************************************************/
void NodeDestroyRec (Node *_root, void (*_destroyer)(void*))
{
	if (NULL == _root)
	{
	 return;
	}
	NodeDestroyRec (_root-> m_left, _destroyer);
	NodeDestroyRec (_root-> m_right, _destroyer);
    if (NULL != _destroyer)
	{
        _destroyer(_root->m_data);
	}
    free(_root);
}
