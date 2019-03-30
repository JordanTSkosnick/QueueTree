/**
 * @file test_driver.cpp
 * @author Jordan Skosnick
 * @brief Test the value traversable queue
 */

#include <iostream>
#include "ValueTraversableQueue.h"

/**
 * Displays an integer for each node
 * @param anItem - an integer to output
 */
void display(int& anItem)
{
   std::cout << "Displaying item in tree - " << anItem << std::endl;
}  // end display

/**
 * Displays a double for each node
 * @param anItem - a double to output
 */
void displayDouble(double& anItem)
{
   std::cout << "Displaying item in tree - " << anItem << std::endl;
}  // end display

/**
 * Displays a string for each node
 * @param anItem - a string to output
 */
void displayString(std::string& anItem)
{
   std::cout << "Displaying item in tree - " << anItem << std::endl;
}  // end display

/**
 * Main for the test driver
 */
int main()
{
    ///////////////////////////////////////////
    // STRINGS
    ///////////////////////////////////////////
    std::cout<<"\nVTQ QUEUE/TREE WITH STRINGS" << std::endl;
    //create the queueTree ADT
    ValueTraversableQueue<std::string> vtq0;
    std::cout << "Empty?(should be 1)" << vtq0.isEmpty() << std::endl;
    std::cout << "Adding names...." << std::endl;
    vtq0.enqueue("Bob");
    vtq0.enqueue("Casey");
    vtq0.enqueue("Christina");
    vtq0.enqueue("Susan");
    vtq0.enqueue("Thomas");
    std::cout << "Empty?(should be 0)" << vtq0.isEmpty() << std::endl;
    std::cout << "Checking traverse:" << std::endl;
    vtq0.traverse(displayString);
    std::cout << "Peaking front then deleting names...." << std::endl;
    while(!vtq0.isEmpty()) 
    {
        std::string y = vtq0.peekFront();
        std::cout << y << std::endl;
        vtq0.dequeue();
    }
    std::cout << "Empty?(should be 1)" << vtq0.isEmpty() << std::endl;
    std::cout<< "check the traverse with an empty tree(there should be nothing): " << std::endl;
    vtq0.traverse(displayString);
    
    ///////////////////////////////////////////
    // DOUBLES
    ///////////////////////////////////////////
    std::cout<<"\nVTQ QUEUE/TREE WITH DOUBLES" << std::endl;
    //create the queueTree ADT
    ValueTraversableQueue<double> vtq1;
    std::cout << "Empty?(should be 1)" << vtq1.isEmpty() << std::endl;
    std::cout << "Adding names...." << std::endl;
    vtq1.enqueue(5.55);
    vtq1.enqueue(6.66);
    vtq1.enqueue(7.77);
    vtq1.enqueue(8.88);
    vtq1.enqueue(9.99);
    std::cout << "Empty?(should be 0)" << vtq1.isEmpty() << std::endl;
    std::cout << "Checking traverse:" << std::endl;
    vtq1.traverse(displayDouble);
    std::cout << "Peaking front then dequeueing numbers...." << std::endl;
    while(!vtq1.isEmpty()) 
    {
        double z = vtq1.peekFront();
        std::cout << z << std::endl;
        vtq1.dequeue();
    }
    std::cout << "Empty?(should be 1)" << vtq1.isEmpty() << std::endl;
    std::cout<< "check the traverse with an empty tree(there should be nothing): " << std::endl;
    vtq1.traverse(displayDouble);
    
    
    ///////////////////////////////////////////
    // INTEGERS
    ///////////////////////////////////////////
    std::cout<<"\nVTQ QUEUE/TREE WITH INTEGERS" << std::endl;
    ValueTraversableQueue<int> vtq;
    //check if its empty, should be 1
    std::cout << "Empty?(should be 1)" << vtq.isEmpty() << std::endl;
    std::cout << "Adding names...." << std::endl;
    for (int i = 0; i<10; i++) 
    {
        vtq.enqueue(i);
    }
    //check if its empty, should be 0
    std::cout << "Empty?(should be 0)" << vtq.isEmpty() << std::endl;

    //Check the traverse function to make sure it works, should display 0-9 in order.
    std::cout << "Checking traverse:" << std::endl;
    vtq.traverse(display);
    
    std::cout << "Peaking front then dequeueing numbers...." << std::endl;
    while(!vtq.isEmpty()) 
    {
        int x = vtq.peekFront();
        std::cout << x << std::endl;
        vtq.dequeue();
    }
    //check traverse with empty tree.    
    std::cout<< "check the traverse with an empty tree(there should be nothing): " << std::endl;
    vtq.traverse(display);

    //Check peekfront with an empty queue/tree. Should say it was called with an empty tree.
    std::cout<< "Checking Peekfront with empty queue/tree " << std::endl;
    try 
    {
        vtq.peekFront();
    }
    catch(std::logic_error e) 
    {
        std::cout << e.what() << std::endl;
    }


  return 0;
}

