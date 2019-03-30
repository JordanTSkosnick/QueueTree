/**
 * @file ValueTraversableQueue.h
 * @author Jordan Skosnick
 * @brief header file for a value traversable queue
 */
 
#ifndef VALUE_TRAVERSABLE_QUEUE
#define VALUE_TRAVERSABLE_QUEUE

#include <memory>
#include "TraversableQueueInterface.h"
#include "Node.h"
#include "BinaryNode.h"

/**
 * Class for the Value traversable queue
 */
template<class ItemType>
class ValueTraversableQueue : public TraversableQueueInterface<ItemType>
{
private:
    // The queue is implemented as a chain of linked nodes that has
    // two external pointers, a head pointer for front of the queue and
    // a tail pointer for the back of the queue.
    std::shared_ptr<BinaryNode<ItemType>> treePtr;
    std::shared_ptr<Node<BinaryNode<ItemType>>> backPtr;
    std::shared_ptr<Node<BinaryNode<ItemType>>> frontPtr;

    auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode);
    void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& success);
    auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
    auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                            ItemType& inorderSuccessor);
    
    public:
    ValueTraversableQueue();
    ~ValueTraversableQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    void traverse(void visit(ItemType&)) const;
    /** @throw PrecondViolatedExcep if the queue is empty */
    ItemType peekFront() const;
    bool add(std::shared_ptr<BinaryNode<ItemType>> newBinaryNodePtr);
    bool remove(const ItemType& anEntry);
}; // end LinkedQueue

#include "ValueTraversableQueue.cpp"


#endif
