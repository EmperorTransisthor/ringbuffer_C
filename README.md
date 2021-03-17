# Ring buffer

Ring buffer is a mechanism, which is very useful in asynchronous systems. Basically, it is FIFO register, which is storing data until they are read. <br />
There are 3 crucial things you need to know about it: <br />
* ```char* buffer``` is a pointer to the beggining of string, where data is strored <br />
* ```int head``` is a pointer to the place, where next variable will be stored <br />
* ```int tail``` is a pointer to the place, where first variable of the buffer, which has to be read <br />
<br />

**Equasions** <br />
As we now know, that ```char* buffer``` is pointer to the beggining of our ring buffer, head and tail variables are pointing to places in memory, where we want to write / read accordingly, the equasions for operations in ring buffer would look like:
* Read:   buffer + tail
* Write:  buffer + head
<br />

**Example** <br />
*Writing information to the buffer* <br />

``` C
RingBuffer_Write (RingBuffer* ringBuffer, char c)      // Simplified RingBuffer_PutChar function (idea behind it)
{
     *(ringBuffer->buffer + ringBuffer->head) = c;
     
     /*
     head operations
     */
}
```

*Reading information from the buffer*

``` C
RingBuffer_Read (RingBuffer* ringBuffer, char* c)       // Simplified RingBuffer_GetChar function (idea behind it)
{
     *c = *(ringBuffer->buffer + ringBuffer->tail);
     
     /*
     tail operations
     */
}
```

More about the concept: https://www.embedded.com/ring-buffer-basics/

This is homework for Microcontroller Applications subject. Feel free to use it. <br />
