#include "SortedLinkedListDict.hpp"
void SortedLinkedListDict::insert(int value)
{

    Node* newNode = new Node(); // create a new node
    newNode -> data = value;  //take data and add it to the new node

    newNode -> next = nullptr; //set head to null



    //check if the list is empty
    if (head == nullptr)
    {
        head = newNode;
    }

    // is a pointer that is looking at head
    Node* tempNode;
    tempNode = head;
    tempNode -> data = value;

    //makes a copy of =tempNode's next node
    Node* nextNode;
    nextNode = tempNode -> next;



    // as we iterate, we are searching for the last linked list's next pointer
    while (tempNode ->next != nullptr)
    {
        // moves onto next node as the for loop iterates
        //nextNode = nextNode -> next;


        //if we are inserting at the beginning of the list
        if ( newNode -> data <= head -> data)
        {
            newNode -> next = head;
            tempNode = newNode;
            head = tempNode;
            nextNode = tempNode -> next;
        }

        //if we are inserting at the middle of the list
        if (newNode -> data < head ->next -> data && newNode -> data > head-> data)
        {
            newNode -> next = tempNode -> next;
            tempNode ->next = newNode;
            head = tempNode;
        }


        // if we are inserting at the end of the list
        if (head ->next == nullptr)
        {

            tempNode -> next = newNode;
            head ->next = tempNode;
            head = tempNode;
        }


        tempNode = tempNode ->next;


    }

};

bool SortedLinkedListDict::lookup(int value) const
{


    //follows the head pointer
    Node* tempNode;
    tempNode = head;
    tempNode -> data = value;


    //if head is empty

    if (head == nullptr)
    {
        return false;
    }
    //we are iterating and comparing to see if the value inside the linked list
    // is actually the number we are looking for
    // if not then we continue
    while (tempNode != nullptr)
    {
        if (tempNode -> data == value)
        {

            return true;
        }

        if (tempNode -> data > value)
        {
            return false;
        }
        tempNode= tempNode -> next;

    }

    return false;


}
void SortedLinkedListDict::remove(int value)
{
    //keeps track of head pointer
    Node* tempNode;

    //create another for loop to look for the value we want to delete
    tempNode = head;

    //makes a copy of current's next node
    Node* nextNode = head ->next;

    //if head is empty
    if (head == nullptr)
        return;

    if (tempNode -> data == value)
    // this checks if the node has the right value
    {

        head = tempNode -> next;
        delete tempNode;
    }

    while(nextNode && nextNode -> data < value)
    {

        tempNode = nextNode;


        nextNode = nextNode -> next;
    }

    if (nextNode && nextNode -> data == value)
    {
        tempNode -> next = nextNode -> next;
        delete nextNode;
    }
}