#include "GenericHeap.h"
#include <stdlib.h>
#include <stddef.h>  
#define LEFT_INDEX(i) (2 * (i) + 1)
#define RIGHT_INDEX(i) (2 * (i) + 2)
#define HAS_RIGHT_SON(heap, i) ((2 * (i) + 2) < heap->m_heapSize)
#define IS_LEAF(heap, i) ((2 * (i) + 1) >= heap->m_heapSize)
#define TRUE 1
#define FALSE 0
struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
    LessThanComparator m_cFunc;
};
static size_t FindNewHead(Heap* _heap, size_t _index);
static void SwapFatherSon(Heap* _heap, size_t _indexfather, void* _father, size_t _indexSon, void* _son);
static void heapifyRec(Heap* _heap, size_t _index);
static void BobbleUpRec(Heap* _heap, size_t _index);

Heap* HeapBuild(Vector* _vector, LessThanComparator _pfLess)
{
    Heap* newHeap = NULL;
	size_t i, iSmallestFather; /*index to the smallest father*/
	if (NULL == _vector || NULL == _pfLess)
	{
		return NULL;
	}
	if ((newHeap = (Heap*)malloc(sizeof(Heap)) ) == NULL)
    {
        return NULL;
    }

	newHeap -> m_vec = _vector;
	newHeap -> m_heapSize =  VectorSize(_vector);
    newHeap -> m_cFunc = _pfLess;

    if (newHeap -> m_heapSize > 1)
    {
        iSmallestFather = (newHeap -> m_heapSize -1)/2; /* we can reach to the smallest father by the smallest son (that locat in the last index)*/
        for (i = iSmallestFather; i> 0; i-- ) /*macRo to FAThER*/
        {
    	    heapifyRec( newHeap , iSmallestFather);
        }
        heapifyRec( newHeap , 0); /*to cover the 0 becuase it i--*/
    }   
    return newHeap;
}
/****************************************************************************/
Vector* HeapDestroy(Heap** _heap)
{
	Vector* vector;
    if (NULL == _heap ||NULL == *_heap) 
	{
	    return NULL;
	}
	 vector = (*_heap) -> m_vec;
     free(*_heap);
      *_heap = NULL;
     return vector;
}
/****************************************************************************/
HeapResultCode HeapInsert(Heap* _heap, void* _element)
{
    size_t index;
    size_t sizeOfVec;
	if (NULL ==_heap || NULL == _element) 
	{
		return HEAP_NOT_INITIALIZED;
	}

    if (VECTOR_SUCCESS != VectorAppend(_heap -> m_vec, _element)) /*add errors of vector append*/
    {
        return HEAP_ALLOCATION_FAILED;
    }

	BobbleUpRec(_heap, _heap -> m_heapSize);
	(_heap -> m_heapSize)++;
	return HEAP_SUCCESS; 
}
/****************************************************************************/
const void* HeapPeek(const Heap* _heap)
{
    void *topElement;
    if (NULL ==_heap || _heap -> m_heapSize == 0) 
	{
		return NULL;
	}
    VectorGet(_heap->m_vec, 0 , &topElement);
    return topElement; /*the test need to include const variable to catch it*/
}
/****************************************************************************/
void* HeapExtract(Heap* _heap)
{
	void *topElement, *putTheRemove;
	if (NULL ==_heap || _heap -> m_heapSize == 0) 
	{
	    return NULL;
	}	
	VectorGet(_heap-> m_vec, 0, &topElement);
    VectorRemove(_heap-> m_vec, &putTheRemove);
	(_heap -> m_heapSize)--;
	if (_heap -> m_heapSize > 0)
	{
		VectorSet(_heap-> m_vec, 0, putTheRemove);
		heapifyRec(_heap, 0);
	}
	return topElement; /*add a test of one element and Extract*/
}
/****************************************************************************/
size_t HeapSize(const Heap* _heap)
{
	if(NULL == _heap)
	{
		return 0;
	}
	
	return(_heap->m_heapSize);
}
/****************************************************************************/
size_t HeapForEach(const Heap* _heap, ActionFunction _act, void* _context)
{ 
    size_t size, i;
    void* item;
    Vector* vector; 
    if (NULL == _heap || NULL == _act) /*there can be no _context*/
    {
        return  0;
    }
    size = _heap -> m_heapSize;
    vector = _heap -> m_vec;
    for(i = 0; i < size; ++i)
    {
        VectorGet(vector, i, &item);
        if(_act(item, _context) == 0)
        {
            break;
        }
        
    }
    return i;
}
/****************************************************************************/
/*****************************Help FUNC**************************************/
/****************************************************************************/
static void heapifyRec(Heap* _heap, size_t _index)
{
	void* fathervalue= 0;
	void* sonValue = 0;
	size_t newHead = 0; 
	if (IS_LEAF(_heap, _index))
	{
		return;
	}
	newHead = FindNewHead(_heap, _index);
	
	if(newHead == _index)
	{
		return;
	}
	VectorGet(_heap-> m_vec, newHead, &sonValue);
	VectorGet(_heap-> m_vec, _index, &fathervalue);
	SwapFatherSon(_heap, _index, fathervalue, newHead, sonValue);
	heapifyRec(_heap, newHead); /**/
}
/****************************************************************************/
static size_t FindNewHead(Heap* _heap, size_t _index)
{
	void*  leftValue; 
    void* rightValue;
    void* fatherValue;
    void* newHeadValue;
	size_t newHeadIndex = _index;
	
	VectorGet(_heap->m_vec, _index, &fatherValue);
	VectorGet(_heap->m_vec, LEFT_INDEX(_index), &leftValue);
	
	if(_heap -> m_cFunc( fatherValue, leftValue) == TRUE) 
    {
        newHeadIndex = LEFT_INDEX(_index);
    }	
	if(HAS_RIGHT_SON(_heap, _index))
	{
		VectorGet(_heap->m_vec, newHeadIndex, &newHeadValue);
        VectorGet(_heap->m_vec, RIGHT_INDEX(_index), &rightValue);
		if(_heap -> m_cFunc(newHeadValue, rightValue) == TRUE)
		{
			newHeadIndex = RIGHT_INDEX(_index);
		}
	}	
	return newHeadIndex;
}
/****************************************************************************/
static void SwapFatherSon(Heap* _heap, size_t _indexfather, void* _father, size_t _indexSon, void* _son)
{
	VectorSet(_heap-> m_vec, _indexSon, _father);
	VectorSet(_heap-> m_vec, _indexfather, _son);
}
/****************************************************************************/
static void BobbleUpRec(Heap* _heap, size_t _index)            
{
	void *father, *son;
	size_t iFather;
	if(_index == 0)
	{
		return;
	}
	
	iFather = (_index -1)/2;
	VectorGet(_heap -> m_vec, iFather, &father);
	VectorGet(_heap -> m_vec, _index, &son);
	
	if(_heap -> m_cFunc(father,son))
	{
		SwapFatherSon(_heap, iFather , father, _index, son);
		BobbleUpRec(_heap,iFather);
	}
}
