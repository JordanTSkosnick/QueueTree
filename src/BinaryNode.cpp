/**
 * @file BinaryNode.cpp
 * @author Jordan Skosnick
 * @brief cpp file for a Binary Node
 */

#include "BinaryNode.h"
#include <cstddef>

/**
 * default constructor
 */
template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
      : item(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end default constructor

/**
 * a constructor
 * @param anItem - an item value
 */
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
      : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end constructor

/**
 * a constructor
 * @param anItem - an item value
 * @param leftPtr - the left pointer of the node
 * @param rightPtr - the right pointer of the node
 */
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                    std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                                    std::shared_ptr<BinaryNode<ItemType>> rightPtr)
      : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{ }  // end constructor

/**
 * sets an item
 * @param anItem - the item to set to item
 */
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
}  // end setItem

/**
 * gets an item
 * @return the item
 */
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const 
{
   return item;
}  // end getItem

/**
 * checks if a node is a leaf
 * @return if the current node is a leaf in a tree
 */
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

/**
 * sets a left child pointer to a node
 * @param leftPtr - the left pointer of a node
 */
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
   leftChildPtr = leftPtr;
}  // end setLeftChildPtr

/**
 * sets a right child pointer to a node
 * @param rightPtr - the right pointer of a node
 */
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
   rightChildPtr = rightPtr;
}  // end setRightChildPtr

/**
 * gets the left child pointer
 * @return the left child pointer
 */
template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
   return leftChildPtr;
}  // end getLeftChildPtr		

/**
 * gets the right child pointer of a node
 * @return the right child pointer of a node
 */
template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
   return rightChildPtr;
}  // end getRightChildPtr		

