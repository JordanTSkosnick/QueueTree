/**
 * @file Node.cpp
 * @author Jordan Skosnick
 * @brief cpp file for a node
 */
#include "Node.h"
#include <cstddef>

/**
 * default constructor
 */
template<class ItemType>
Node<ItemType>::Node()
{
} // end default constructor

/**
 * constructor
 * @param anItem - value of an item
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
} // end constructor

/**
 * constructor
 * @param anItem - a value of an item
 * @param nextNodePtr - a pointer to the next node
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType>> nextNodePtr)
               : item(anItem), next(nextNodePtr)
{
} // end constructor

/**
 * sets an item to item
 * @param anItem - a value of an item
 */
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

/**
 * sets the next node
 * @param nextNodePtr - the pointer to the next node
 */
template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

/**
 * gets an item value
 * @return an item value
 */
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

/**
 * gets the next item
 * @return the next item
 */
template<class ItemType>
auto Node<ItemType>::getNext() const
{
   return next;
} // end getNext
