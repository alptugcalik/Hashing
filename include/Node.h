#ifndef NODE_H
#define NODE_H



// Node class in order to implement linked list
template <class T>
class Node{
private:
    Node <T> *next;
    T data;
public:
    Node(const T& item, Node <T> * newNext = nullptr); //constructor
    void setNext(Node <T> * newNext); // set next node
    Node <T> * getNext() const; // get next node
    void setData(const T& item); // set the data of the node
    T getData() const; // get the data of the node
    ~Node(); // destructor
    void insertAfter(Node <T> * newNext);
    Node <T> * deleteAfter();
};

#endif // NODE_H



//constructor
template <class T>
Node<T>::Node(const T& item,Node <T> * newNext){
    data = item; // assign data
    next = newNext ; // allocate memory for next
}

//destructor
template <class T>
Node<T>::~Node(){
    delete next;
}

template <class T>
void Node<T>::setNext(Node <T> * newNext){
    next = newNext; // change the next node
}

template <class T>
Node <T> * Node<T>::getNext() const{
    return next; // return the next node
}

template <class T>
void Node<T>::setData(const T& item){
    data = item; // set another data
}

template <class T>
T Node<T>::getData() const{
    return data; // get the data
}

template <class T>
void Node<T>::insertAfter(Node <T> * newNext){
    if(newNext == nullptr) return;
    newNext->setNext(next); // insert a node after the current one
    next = newNext; // set next
}

template <class T>
Node <T> * Node<T>::deleteAfter(){
    if(next == nullptr) return nullptr;
    Node <T> * tempPtr = next;
    next = tempPtr->getNext(); // delete the next node and return it
    return tempPtr;
}
