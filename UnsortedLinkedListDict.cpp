#include "UnsortedLinkedListDict.hpp"
void UnsortedLinkedListDict::insert(int value)
    {
    //the integer we are given we are just going to throw into the linked list

        Node* newNode = new Node(); // create a new node
        newNode -> data = value;  //take data and add it to the new node

        //check if the list is empty
        if (head == nullptr)
        {
            head = newNode;
        }

        newNode -> next = head;
        head = newNode;


    };
bool UnsortedLinkedListDict::lookup(int value) const
{
    //new node just in case the list is empty
    Node* newNode = new Node(); // create a new node
    newNode -> data = value;


    //follows the head pointer
    Node* current = new Node();
    current = head;
    current -> data = value;

    //we are iterating and comparing to see if the value inside the linked list
    // is actually the number we are looking for
    // if not then we continue
    while (current != nullptr)
    {
        if (current -> data == value)
        {

            return true;
        }
        current = current -> next;
        return false;
    }

}
void UnsortedLinkedListDict::remove(int value)
{
    //keeps track of head pointer
    Node* current = new Node();

    //makes a copy of current's next node
    Node* nextNode = current ->next;

    //create another for loop to look for the value we want to delete
    current = head;

    while(current -> data !=value)
    {
        if (current -> data == value)
        // this checks if the node has the right value
        {

            head = current -> next;
            delete current;
        }

        current = current -> next;
    }

}