/**
 * @file Node.h
 * @author Jordan Skosnick
 * @brief header file for a node
 */
#ifndef NODE_
#define NODE_

#include <memory>

/**
 * Class for a Node
 */
template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   std::shared_ptr<Node<ItemType>> next; // Pointer to next node
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
   ItemType getItem() const ;
   auto getNext() const ;

}; // end Node

#include "Node.cpp"
#endif