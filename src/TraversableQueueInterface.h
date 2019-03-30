/**
 * @file TraversableQueueInterface.h
 * @author Jordan Skosnick
 * @brief Interface for a traversable queue
 */

#ifndef TRAVERSABLE_QUEUE_INTERFACE
#define TRAVERSABLE_QUEUE_INTERFACE

/**
 * Class for the traverasble queue interface
 */
template<class ItemType>
class TraversableQueueInterface
{
public:
   /**
    * Sees whether this queue is empty.
    * @return True if the queue is empty, or false if not.
    */
   virtual bool isEmpty() const = 0;

   /**
    * Adds a new entry to the back of this queue.
    * @post If the operation was successful, newEntry is at the back of the
    * queue.
    * @param newEntry  The object to be added as a new entry.
    * @return True if the addition is successful or false if not.
    */
   virtual bool enqueue(const ItemType& newEntry) = 0;

   /**
    * Removes the front of this queue.
    * @post If the operation was successful, the front of the queue has been
    * removed.
    * @return True if the removal is successful or false if not.
    */
   virtual bool dequeue() = 0;

   /**
    * Returns the front of this queue.
    * @pre The queue is not empty.
    * @post The front of the queue has been returned, and the queue is
    * unchanged.
    * @return The front of the queue.
    */
   virtual ItemType peekFront() const = 0;

   /**
    * Traverses this queue and calls the function visit once for each node.
    * @param visit A client-defined function that performs an operation on or
    * with the data in each visited node.
    */
   virtual void traverse(void visit(ItemType&)) const = 0;

   /** Destroys object and frees memory allocated by object. */
   virtual ~TraversableQueueInterface() { }
};

#endif
