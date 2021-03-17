# Ring buffer

Ring buffer is a mechanism, which is very useful in asynchronous systems. Basically, it is FIFO register, which is storing data until they are read. <br />
There are 3 crucial things you need to know about it: <br />
* char* buffer is a pointer to the beggining of string, where data is strored <br />
* head is a pointer to the place, where next variable will be stored <br />
* tail is a pointer to the place, where first variable of the buffer, which has to be read <br />
<br />

**Equasions**
* Read:   buffer + tail
* Write:  buffer + head
<br />

**Example** <br />
*Writing information to the buffer* <br />

``` C
RingBuffer_Write(RingBuffer *ringBuffer, char c)      // Simplified RingBuffer_PutChar function
{
  *(ringBuffer->buffer + ringBuffer->head) = c;
}
```

More about the concept: https://www.embedded.com/ring-buffer-basics/

This is homework for Microcontroller Applications subject. Feel free to use it. <br />
