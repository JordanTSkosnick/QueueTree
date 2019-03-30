/**
 * @file ValueTraversableQueue.cpp
 * @author Jordan Skosnick
 * @brief cpp file implementation of a Value Traversable Queue
 */

#include "ValueTraversableQueue.h"
#include <cassert>
#include <memory>

/**
 * Default constructor
 */
template<class ItemType>
ValueTraversableQueue<ItemType>::ValueTraversableQueue()
{     }  // end default constructor

/**
 * Destructor
 */
template<class ItemType>
ValueTraversableQueue<ItemType>::~ValueTraversableQueue()
{
  //smart pointers will clean-up
    backPtr = nullptr;
    frontPtr = nullptr;
}  // end des

/**
 * Checks if the queue/tree ADT is empty 
 * @return bool - if it is empty: returns 1 if it is not empty: returns 0 
 */
template<class ItemType>
bool ValueTraversableQueue<ItemType>::isEmpty() const
{
    return backPtr == nullptr;
}  // end isEmpty
 
/**
 * Creates and places a node into a tree
 * @param subTreePtr - the root pointer of the tree
 * @param newNodePtr - Pointer to the new node placed.
 * @return the new root pointer
 */
template<class ItemType>
auto ValueTraversableQueue<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else
    {
        if (subTreePtr->getItem() > newNodePtr->getItem())
        {
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
        }
        else 
        {
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
        }
        return subTreePtr;
    }  // end if
}  // end placeNode 

/**
 * helper function to add a node to a tree
 * @param newBinaryNodePtr - A pointer to the new tree node
 * @return true when the item was placed
 */
template<class ItemType>
bool ValueTraversableQueue<ItemType>::add(std::shared_ptr<BinaryNode<ItemType>> newBinaryNodePtr)
{
    treePtr = placeNode(treePtr, newBinaryNodePtr);
   
    return true;
}  // end add

/**
 * Adds items to a queue and tree
 * @param newEntry - an item to be added to the ADT
 * @return true when successful
 */
template<class ItemType>
bool ValueTraversableQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    
    //auto newBinaryNodePtr = std::make_shared<BinaryNode<ItemType>>();
    auto newNodePtr = std::make_shared<Node<BinaryNode<ItemType>>>(newEntry);
    //BinaryNode<ItemType> bn = newNodePtr->getItem();
    //BinaryNode<ItemType> newBinaryNodePtr = newBinaryNodePtr.getItem();
    auto newBinaryNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
    add(newBinaryNodePtr);
    BinaryNode<ItemType> bn = newBinaryNodePtr->getItem();
    newNodePtr->setItem(bn);
    // Insert the new node
    if (isEmpty())
    {
        frontPtr = newNodePtr;        // Insertion into empty queue
    }
    else
    {
        backPtr->setNext(newNodePtr); // Insertion into nonempty queue
    }
    
    backPtr = newNodePtr;            // New node is at back

    return true;
}  // end enqueue                          

/**
 * Removes the node on the left
 * @param nodePtr - a pointer to the node in which to delete the left most node
 * @param inorderSuccessor - a new value of the node
 * @return a pointer to node above which was deleted
 */
template<class ItemType> 
auto ValueTraversableQueue<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr,
                                                                     ItemType& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == nullptr)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }  // end if      
}  // end removeLeftmostNode

/**
 * Selects the node which is to be deleted.
 * @param nodePtr - pointer to the node in which should be deleted
 * @return the node to delete
 */
template<class ItemType>
auto ValueTraversableQueue<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
   if (nodePtr->isLeaf())
   {
      nodePtr.reset();
      return nodePtr; // delete and return nullptr
   }
   else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
   {
      return nodePtr->getRightChildPtr();
   }
   else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
   {
      return nodePtr->getLeftChildPtr();
   }
   else                                             // Has two children
   {
      // Traditional way to remove a value in a node with two children
      ItemType newNodeValue;
      nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
      nodePtr->setItem(newNodeValue);
      return nodePtr;
   }  // end if
}  // end removeNode

/**
 * Removes a node from the tree where the value is equal to the value you wish to delete
 * @param subTreePtr - the root tree pointer
 * @param target - the item value you wish to delete from the tree
 * @param success - boolean that is true onces the target is deleted from the tree
 * @return the root tree pointer
 */
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> ValueTraversableQueue<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& success)
{
   if (subTreePtr == nullptr)           
   {
      // Not found here
      success = false;
      return subTreePtr;
   }
   if (subTreePtr->getItem() == target)
   {
      // Item is in the root of some subtree
      subTreePtr = removeNode(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      if (subTreePtr->getItem() > target)
      {
         // Search the left subtree
         subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
      }
      else
      {
         // Search the right subtree
         subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
      }
      return subTreePtr;
   }  // end if
}  // end removeValue

/**
 * Helper function to remove a node from a tree
 * @param target - the value you wish to delete from the tree
 * @return bool - true if it was delete, false otherwise
 */
template<class ItemType>
bool ValueTraversableQueue<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   // call may change isSuccessful
   treePtr = removeValue(treePtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

/**
 * Deletes the queue/tree adt one value at a time
 * @return true when it was a success
 */
template<class ItemType>
bool ValueTraversableQueue<ItemType>::dequeue()
{
    bool result = false;
    if (!isEmpty())
    {
        if (frontPtr == backPtr)
        {  // Special case: one node in queue
            remove(frontPtr->getItem().getItem());
            backPtr = nullptr;
            frontPtr = nullptr;
        }
        else
        {
            
            remove(frontPtr->getItem().getItem());
            frontPtr = frontPtr->getNext();
        }

        result = true;
    }  // end if

    return result;
}  // end dequeue

/**
 * Retrieves the front item of the queue
 * @return the item at the front of the queue
 */
template<class ItemType>
ItemType ValueTraversableQueue<ItemType>::peekFront() const
{
    if(isEmpty())
    {
        throw std::logic_error("peekFront() called with empty tree.");
    }
    // Queue is not empty; return front
    return frontPtr->getItem().getItem();
}  // end peekFront
// End of implementation file.

/**
 * Traverses through the tree in order
 * @param visit - a client defined function 
 * @param treePtr -  the root pointer of the tree
 */
template<class ItemType>
void ValueTraversableQueue<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end inorder

/**
 * Calls inorder to traverse through the tree in order
 * @param visit - a client defined function
 */
template<class ItemType>
void ValueTraversableQueue<ItemType>::traverse(void visit(ItemType&)) const
{
    inorder(visit, treePtr);
}
