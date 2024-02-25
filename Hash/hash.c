#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "hash.h"
#define FULL 3
#define WAS_FULL -1
#define VIRGIN 0
#define SIZE_FACTOR 1.3
#define TRUE 1
#define FALSE 2

struct Hash
{

    void** m_data;
    char* m_state;
    size_t (*m_hashFunction)(void* _data);
    int (*m_equalityFunction)(void* _firstData, void* _secondData);
    size_t m_originalHashSize; /*original size given by the client*/
    size_t m_realSize; /*real hash size */
    size_t m_numOfItems; /*number of occupied places in the table*/
    size_t m_maxOfRehashOperations; /*maximum amount of rehash operations
    which have been done over one insertion*/
    size_t m_counterOfInsertions; /*total amount of insertions into the table*/
    size_t m_allRehashOperations; /*all rehash operations mutual counter*/

};
size_t GetNewSize(Hash *_hash)
{
	return _hash -> m_realSize;
}
size_t GetnRealSize(Hash *_hash)
{
	return _hash -> m_originalHashSize;
}

size_t GetNumOfItems(Hash *_hash)
{
	return _hash -> m_numOfItems;
}
size_t GetInsertionsCount(Hash *_hash)
{
	return _hash -> m_counterOfInsertions;
}
size_t GetMaxOfRehash(Hash *_hash)
{
	return _hash -> m_maxOfRehashOperations;
}
size_t GetAllRehash(Hash *_hash)
{
	return _hash -> m_allRehashOperations;
}
static size_t FindDataIndex(const Hash* _hash, void* _data);
size_t FinfdPrime (size_t _size);
static size_t InsertHere(Hash* _hash, size_t _hashIndex);
/**********************************************************************/
Hash* HashCreate(size_t _size, size_t (*_hashFunction)(void*), int
(*_equalityFunction)(void*, void*))
{
    Hash* newHash=NULL;
    char* statusArr = NULL;
    void** dataArr =NULL;
    size_t newSize;
    if (_size<2)
    {
        return NULL;
    }
    if (NULL == _hashFunction || NULL == _equalityFunction)
    {
        return NULL;
    }
    newSize =FinfdPrime(_size * SIZE_FACTOR);
    if(NULL == (newHash = (Hash*)calloc(1, sizeof(Hash))))
    {
        return NULL;
    }
    if(NULL == (statusArr = (char*)calloc(newSize, sizeof(char))))
    {
        free (newHash);
        return NULL;
    }
    if(NULL == (dataArr = (void**)calloc(newSize, sizeof(void*))))
    {
        free (statusArr);
        free (newHash);
        return NULL;
    }

    newHash->m_data = dataArr;
    newHash->m_state = statusArr;
    newHash-> m_hashFunction = _hashFunction;
    newHash->m_equalityFunction = _equalityFunction;
    newHash->m_originalHashSize = _size;
    newHash->m_realSize = newSize;
    return newHash;
}
 /***********************************************************************/
 void HashDestroy(Hash** _hash, void (*_keyDestroy)(void* _data))
 {
	size_t size, i;
	if (NULL == _hash || NULL == *_hash)
	{
		return;
	}
	if(NULL != _keyDestroy)
	{
		size = (*_hash) -> m_numOfItems;
		for(i = 0; i < size ; ++i)
		{
			if(FULL==(*_hash) -> m_state[i])/***/
            {
                _keyDestroy((*_hash) -> m_data[i]);
            }
            
		}
	}
	free((*_hash) -> m_data);
	free((*_hash) -> m_state);
	free(*_hash);
	*_hash = NULL;
}
 /***********************************************************************/
HashSet_Result HashInsert(Hash* _hash, void* _data)
{
    size_t hashIndex, indexToInsert; 
    size_t size;
    if(NULL == _hash || NULL == _data)
    {
        return SET_UNINITIALIZED;
    }
    size = _hash->m_realSize;
    if(_hash-> m_numOfItems == _hash-> m_originalHashSize)
    {
        return SET_OVERFLOW;
    }
 
    if (size != FindDataIndex( _hash, _data)) /*duplication*/
    {
        return SET_KEY_DUPLICATE;
    }

    hashIndex =( _hash-> m_hashFunction(_data)) % ( size);

   if(0 == _hash ->m_numOfItems || _hash -> m_state[hashIndex] != FULL)  /*if empty we can just insert*/
    {
        _hash -> m_data[hashIndex] = _data;
        _hash -> m_state[hashIndex] = FULL;
        ( _hash -> m_counterOfInsertions) ++;
        ( _hash ->m_numOfItems)++;
        return SET_SUCCESS;
    }
    indexToInsert = InsertHere( _hash, hashIndex);
    _hash -> m_data[indexToInsert] = _data;
    _hash -> m_state[indexToInsert] = FULL;
    ( _hash ->m_numOfItems)++;

    if ( _hash ->m_counterOfInsertions >  _hash ->m_maxOfRehashOperations)
    {
        _hash-> m_maxOfRehashOperations ==  _hash ->m_counterOfInsertions;
    }
    _hash ->m_allRehashOperations += _hash ->m_counterOfInsertions;
    
    return SET_SUCCESS;
  }  
  /***********************************************************************/
  HashSet_Result HashRemove(Hash* _hash, void* _key, void** _data)
  {
    size_t size, indexToRemove; 
    if(NULL == _hash || NULL == _key)
    {
        return SET_UNINITIALIZED;
    }
    if(0 == _hash ->m_numOfItems)
    {
        return SET_UNDERFLOW;
    }
    size = _hash->m_realSize;
    indexToRemove = FindDataIndex( _hash, _key); /*not found*/
    if (size == indexToRemove)
    {
        return SET_KEY_NOT_FOUND;
    }
   *_data =  _hash -> m_data[indexToRemove];
    _hash -> m_data[indexToRemove]= 0;
    _hash -> m_state[indexToRemove] = WAS_FULL;
     (_hash ->m_numOfItems)--;
    return SET_SUCCESS;
  }   
/***********************************************************************/
int HashIsFound(const Hash* _hash, void* _key)
{
    size_t size, indexToFind; 
    if(NULL == _hash || NULL == _key)
    {
        return SET_UNINITIALIZED;
    }
    size = _hash->m_realSize;
    if(0 == _hash ->m_numOfItems)
    {
        return FALSE;
    }
    indexToFind =FindDataIndex( _hash, _key);
    if (size != indexToFind)
    {
        return TRUE;
    }
    return FALSE;

}
/***********************************************************************/
size_t HashNumOfItems(const Hash* _hash)
{
    if(NULL == _hash)
    {
        return 0;
    }
    return (_hash-> m_numOfItems);
}
/***********************************************************************/
size_t HashCapacity(const Hash* _hash)
{
    if(NULL == _hash)
    {
        return 0;
    }
    return (_hash-> m_originalHashSize);
}
/***********************************************************************/
double HashAverageRehashes(const Hash* _hash)
{
    if(NULL == _hash || _hash -> m_counterOfInsertions == 0 )
    {
        return 0;
    }
    return ((_hash ->  m_allRehashOperations) / (_hash -> m_counterOfInsertions));
}
/***********************************************************************/
size_t HashMaxReHash(const Hash* _hash)
{
    if(NULL == _hash)
    {
        return 0;
    }
    return (_hash ->  m_maxOfRehashOperations);
}
/***********************************************************************/
void HashPrint(const Hash* _hash, void (*PrintKey)(void*))
{
    size_t i;
    if(NULL == _hash || NULL == PrintKey ||  _hash -> m_numOfItems == 0 )
    {
        return;
    }
    for (i = 0; i <= _hash->m_originalHashSize; i++)
    {
       if (FULL == _hash->m_state[i])
       {
            PrintKey(_hash->m_data[i]);
       }  
    }
}

/***********************************************************************/
/***********************************************************************/
 static size_t InsertHere(Hash* _hash, size_t _hashIndex)
{
    size_t i = 0;
    size_t index = _hashIndex + 1;
    while(i < _hash -> m_realSize)
    {
        if(FULL != _hash -> m_state[index])
        {
            return index;
        }
        index = (index+1)%(_hash-> m_realSize);
        i ++;
        _hash ->m_counterOfInsertions ++;
    }    
}
/***********************************************************************/
static size_t FindDataIndex(const Hash* _hash, void* _data) /*return size when not found or index when found*/
{
    size_t hashIndex;
    size_t i = 0;
    size_t size = _hash->m_realSize;
    hashIndex = _hash-> m_hashFunction(_data) % size;
    while (i < size)
    {
      /**/  if (i > _hash-> m_maxOfRehashOperations  || _hash-> m_state[hashIndex] == VIRGIN) /*case index get to the max or get to empty virgin*/
        {
            return size;
        }
        if(_hash->m_state[hashIndex] == FULL)
        {
            if (_hash -> m_equalityFunction(_data, _hash->m_data[hashIndex]))
            {
                return hashIndex;
            }
        }

        hashIndex =(hashIndex+1)%(_hash-> m_realSize);
        i ++;
    }
    return size;
}   
/***********************************************************************/
 size_t FinfdPrime (size_t _size)
{
    size_t i;
    size_t temp = _size+1;
    while (1)
    {
         for(i = 2; i< temp; i++)
        {
            if (temp % i == 0)  
            {
                break;
            }
        }
            if (i == temp)
            {
                return temp;
            }
        temp++;
    }
}
   
