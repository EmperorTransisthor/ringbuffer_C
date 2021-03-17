/*
 * @file ring_buffer.c
 * @author Michal Bogon
 * @date 17'th Mar 2021
 * @brief File containing ring buffer functions.
 * @ver 1.0
 */

/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include <string.h>
#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);
	
	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
	    ringBuffer->head    = 0;
	    ringBuffer->tail    = 0;
        ringBuffer->isFull  = false;
        ringBuffer->buffer  = dataBuffer;
        ringBuffer->capacity = dataBufferSize;
	    return true;
	}
	
	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		ClearBuffer(ringBuffer);
		ringBuffer->head    = 0;
		ringBuffer->tail    = 0;
		ringBuffer->isFull  = false;
		return true;
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);	
	if ((ringBuffer->head == ringBuffer->tail) && !ringBuffer->isFull)
	    return true;

    return false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
	    if (ringBuffer->isFull)
	        return ringBuffer->capacity;
	    else if (ringBuffer->head >= ringBuffer->tail)
		    return (ringBuffer->head - ringBuffer->tail);
		else
		    return (ringBuffer->capacity - ringBuffer->tail + ringBuffer->head);
	}
	return 0;
	
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->capacity;
	}
	return 0;	
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
	    if (RingBuffer_GetLen(ringBuffer) < ringBuffer->capacity)
	    {
	        //char* actualBuffer = ringBuffer->buffer + ringBuffer->head;
	        *(ringBuffer->buffer + ringBuffer->head) = c;                                       // buffer[head] = c
		    ringBuffer->head++;
		    ringBuffer->head %= ringBuffer->capacity;
		    if (ringBuffer->head == ringBuffer->tail)
		        ringBuffer->isFull = true;
		    return true;
	    }
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);
	
    if ((ringBuffer) && (c)) {
        if (!RingBuffer_IsEmpty(ringBuffer))
        {
    		*c = *(ringBuffer->buffer + ringBuffer->tail);              // c = buffer[tail]
    		ringBuffer->tail++;
    		ringBuffer->tail %= ringBuffer->capacity;
    		if (ringBuffer->isFull)
    		    ringBuffer->isFull = false;
    		return true;
        }
	}
	return false;
}

void ClearBuffer(RingBuffer* ringBuffer)
{
    for (int i = 0; i < ringBuffer->capacity; i++)
        *(ringBuffer->buffer + i) = "\0";
    ringBuffer->isFull = false;
}
