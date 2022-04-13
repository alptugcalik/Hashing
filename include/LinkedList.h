#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


//Linked list class
template <class T>
class LinkedList{
private:
    Node <T> *head;
public:
    LinkedList(); // constructor
    Node <T> * getHead() const; // get head
    void InsertNode(Node<T> *newNode); // method to insert a node from the head
    Node<T>* deleteHead(void); // method to delete the HEAD
    int getNumberOfColls() const; // method to get the collusion amount
    ~LinkedList(); // destructor
};


#endif // LINKEDLIST_H

//constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr; // the list is empty
}

//destructor
template <class T>
LinkedList<T>::~LinkedList(){
    delete head;
}

//InsertNode
template <class T>
void LinkedList<T>::InsertNode(Node<T>* newNode){
    //Operations to insert the node to the head of the list
    if(head == nullptr) head = newNode; // check if the linked list is empty
    else{
    newNode->setNext(head);
    head = newNode;
    }
}

//Delete Head
template <class T>
Node<T>* LinkedList<T>:: deleteHead(void){
    //Operations to delete the node at the head of the list
    Node<T> *temp = head;
    head = head->getNext();
    return temp;
}

// get head
template <class T>
Node <T> * LinkedList<T>::getHead() const{
    return head;
}

