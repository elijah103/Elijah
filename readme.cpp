/*
/**********************************************************************
 *  readme.txt template
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions
 **********************************************************************/

/*Name: Elijah Miles


Hours to complete assignment : 4
*/

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

/*
The purpose of the assignment was to make a class called CircularBuffer that could
successfully use the functions enqueue, dequeue, isFull, isEmpty, and peek.
*/



 /**********************************************************************
  *  Discuss one or more key algorithms, data structures, or
  *  OO designs that were central to the assignment.
  **********************************************************************/


/*
The queue data structure was central to this assignment, since the CircularBuffer class
used a queue in order to test it's functions.
*/


  /**********************************************************************
   *  Briefly explain the workings of the features you implemented.
   *  Include code excerpts.
   **********************************************************************/


/*
For isEmpty and isFull, I checked to see if the size of the queue was equal to 0
or equal to the capacity of the queue. For enqueue, I tested for the exception
of the queue being full, then used push and increased the size and the capacity if
it needed it. For dequeue, I tested for the exception of the queue being empty, then
used pop, decreased the size, and returned the front of the queue. For peek, I checked
if the queue was empty, then returned the front.
*/


   /**********************************************************************
    *  Did you complete the whole assignment?
    *  Successfully or not?
    *  Indicate which parts you think are working, and describe
    *    how you know that they're working.
    **********************************************************************/

/*
I think all of the functions are working successfully.
The cpplint.py file wasn't included.
*/



    /**********************************************************************
     *  Does your CircularBuffer implementation pass the unit tests?
     *  Indicate yes or no, and explain how you know that it does or does not.
     **********************************************************************/





     /**********************************************************************
      *  Explain the time and space performance of your RingBuffer
      *	implementation
      **********************************************************************/





      /**********************************************************************
       *  List whatever help (if any) you received from lab TAs,
       *  classmates, or anyone else.
       **********************************************************************/

/*
None
*/

       /**********************************************************************
        *  Describe any serious problems you encountered.
        **********************************************************************/



        /**********************************************************************
         *  List any other comments here.
         **********************************************************************/