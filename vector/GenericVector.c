#include <stdio.h>
#include <string.h>
#include "GenericVector.h"
#include <stdlib.h>
#include <stddef.h>  /*make sure the numbers are positive*/
#define DECLER_FACTOR 2
struct Vector
{
	void** m_items;
	size_t m_originalSize; /* original allocated space for items */
	size_t m_size;/* actual allocated space for items*/
	size_t m_nItems;/* actual number of items */
	size_t m_blockSize;/* the chunk size to be allocated when no space*/
};
static VectorResult ReallocAddVectorAppend (Vector *_vector);
static VectorResult ReallocDeleteVectorAppend (Vector *_vector);
/*******************************************************************************************/
Vector* VectorCreate(size_t _initialCapacity, size_t _blockSize)
{	
    void** pArr = NULL;
    Vector* pVector = NULL;

 	if (_initialCapacity == 0 && _blockSize == 0)
 	 {
 		return NULL;
 	 }
    if ((pVector = (Vector*)malloc(sizeof( Vector)) ) == NULL)
     {
        return NULL;
     }
    
    if ((pArr= (void**)malloc(_initialCapacity*sizeof(void*)))  == NULL)
     {
        free(pVector);
        return NULL;
     }
     
     pVector -> m_items = pArr;
     pVector -> m_originalSize = _initialCapacity;
     pVector -> m_size = _initialCapacity;
     pVector -> m_nItems= 0;
     pVector -> m_blockSize = _blockSize;
     
   return pVector;
}
/*******************************************************************************************/
void VectorDestroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
    size_t i, size;
    if (NULL == _vector || NULL == *_vector) 
    {
        return;
    }
    if (_elementDestroy != NULL)
    {
        size = (*_vector) -> m_nItems;
        for(i = 0; i < size; ++i)
        {
            _elementDestroy ((*_vector)-> m_items[i]);
        }
    }
    free((*_vector)-> m_items);
    free(*_vector);
    *_vector = NULL;
}
/*******************************************************************************************/
VectorResult VectorAppend(Vector* _vector, void* _item)
{
    if (NULL == _vector || NULL == _item)
    {
        return  VECTOR_UNITIALIZED_ERROR;
    }
    if (_vector ->  m_size == _vector -> m_nItems) 	
    {
    if (ReallocAddVectorAppend(_vector) != VECTOR_SUCCESS)
    {
        return VECTOR_ALLOCATION_ERROR;
    }
    }
    _vector-> m_items [  _vector-> m_nItems]= _item;
    (_vector-> m_nItems) ++;


    return VECTOR_SUCCESS;
}
/*******************************************************************************************/
VectorResult VectorRemove(Vector* _vector, void** _pValue)
{
    if (NULL == _vector || NULL == _pValue)
    {
        return  VECTOR_UNITIALIZED_ERROR;
    }
    if (_vector -> m_nItems == 0)
    {
        return VECTOR_UNDERFLOW;
    }
    (_vector-> m_nItems) --;
    *_pValue =  _vector-> m_items [ _vector-> m_nItems];

   ReallocDeleteVectorAppend(_vector);
    return VECTOR_SUCCESS;
}
/*******************************************************************************************/
VectorResult VectorGet(const Vector* _vector, size_t _index, void** _pValue)
{
    if (_vector == NULL || _pValue == NULL)
    {
        return VECTOR_UNITIALIZED_ERROR;
    }
    if (_index >= _vector -> m_nItems)
    {
        return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
    }

    *_pValue =  _vector -> m_items [_index];
    return VECTOR_SUCCESS;
}
/*******************************************************************************************/
VectorResult VectorSet(Vector* _vector, size_t _index, void*  _value)
{
    if (NULL == _vector || NULL == _value)
   {
       return  VECTOR_UNITIALIZED_ERROR;
   }
   
   if (_index >= _vector -> m_nItems)
   {
       return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
   }
   
  _vector -> m_items [_index] = _value;
   return VECTOR_SUCCESS;
}
/*******************************************************************************************/
size_t VectorSize(const Vector* _vector) /*0 is error or size*/
{
    if (NULL == _vector)
    {
        return  0;
    }
    return _vector -> m_nItems;
}
/*******************************************************************************************/
size_t VectorCapacity(const Vector* _vector) /*0 is error or size*/
{
    if (NULL == _vector)
    {
        return  0;
    }
    return _vector -> m_size;
}
/*******************************************************************************************/
size_t VectorForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{ 
    size_t size, i;
    void* item;
    if (NULL == _vector || NULL == _action) /*there can be no _context*/
    {
        return  0;
    }
    size = _vector -> m_nItems;
    for(i = 0; i < size; ++i)
    {
        VectorGet(_vector, i, &item);
        if(_action((_vector)-> m_items[i], i, _context) == 0)
        {
            break;
        }
        
    }
    return i;
}
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
static VectorResult ReallocAddVectorAppend (Vector *_vector)
{
    void **ptemp = NULL;
    if (0 ==_vector->m_blockSize )
    {
        return VECTOR_OVERFLOW;
    }

    ptemp = (void**) realloc(_vector -> m_items, (_vector -> m_blockSize + _vector -> m_size) *sizeof(void*));

    if (NULL == ptemp)
    {
            return VECTOR_REALLOCATION_FAILED;
    }	
    else 
    {
        _vector -> m_items= ptemp;
        _vector -> m_size += _vector -> m_blockSize;
        
    }
    return VECTOR_SUCCESS;
}
/*******************************************************************************************/
static VectorResult ReallocDeleteVectorAppend (Vector *_vector)
{
	void **pTemp=NULL;
	if (0 ==_vector->m_blockSize )
    {
        return;
    }
	if ( (_vector -> m_size > _vector -> m_originalSize) && ((_vector -> m_blockSize)*DECLER_FACTOR) <= (_vector -> m_size - _vector -> m_nItems)) 
	{
		pTemp = (void**) realloc(_vector -> m_items, (_vector -> m_blockSize + _vector -> m_size) *sizeof(void*));
		if( NULL == *pTemp )
		{
			return VECTOR_REALLOCATION_FAILED;
		}
		else
		{
			_vector -> m_items = pTemp; 
			_vector -> m_size -= (_vector -> m_blockSize);
		}
	}
	return VECTOR_SUCCESS;
}
