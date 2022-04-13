#include "HashTable.h"
#include <iostream>
#include <fstream>


using namespace std;

// constructor
HashTable::HashTable(){
    hashTable = nullptr; // assign as null
}


void HashTable::initHashTable(){
    cout<<"Enter the size of the hash table! Only input integers!"<<endl;
    bool control = true;
    while(true){
    cin>>sizeS;
    // check each char's ascii number
    for(unsigned int i=0; i<sizeS.length();i++){
        if(sizeS[i]<48 || sizeS[i]>57){
            cout<<"Invalid input! Try again!"<<endl; // error for undesired char(not int)
            control = false;
            break;
        }
        control = true;
    }
    if(control == true) {
            sizeN = stoi(sizeS); // convert str to int
            // check if the size is zero
            if(sizeN == 0){
                cout<<"Hash table length can not be zero! Try again!"<<endl;
                continue;
            }
            break;
    }
    }


    while(true){
    cout<<"Enter the hashing method!"<<endl;
    cout<<"Enter 'F' for folding."<<endl;
    cout<<"Enter 'M' for middle squaring."<<endl;
    cout<<"Enter 'T' for truncation."<<endl;
    cin>> method;
    if(method != 'M' && method != 'F' && method != 'T'){
        cout<<"Invalid input! Try again!"<<endl;
        continue;
    }
    break;
    }
    hashTable = new LinkedList<long long int>[sizeN];
    if(hashTable == nullptr)
        cout<<"Hash table is not initialized!"<<endl; // check for initialization
    else
        cout<<"Hash table is initialized as empty!"<<endl; // successfully initialized
}

// load hash table
void HashTable::loadHashTable(){
        if(hashTable == nullptr){
            cout<<"Hash table is not initialized!"<<endl;
            return;
        }
        string line;
        ifstream myfile ("hash_table_init.txt");
        if (myfile.is_open())
        {
        int i=0,key;
        long long int newNumber;
        while ( getline (myfile,line) )
        {
        newNumber = stoll(line);
        key = getKey(newNumber);
        hashTable[key].InsertNode(new Node<long long int> (newNumber));
        i++;
        }
        myfile.close();
        cout<<"Load is successful."<<endl;
        }
        else cout << "Unable to open file";
        return;
}

// get the key of the ID
int HashTable::getKey(long long int number){
    int key;
    if(method == 'F'){
        // split the number into parts
        long long int part1,part2,part3,part4,temp;
        part1 = number/100000000;
        temp = part1*100000000;
        temp = number-temp;
        part2 = temp/100000;
        temp = temp - part2*100000;
        part3 = temp/100;
        part4 = temp - part3*100;
        key = (part1+part2+part3+part4) % sizeN;
        return key;
    }
    else if(method == 'M'){
        // get the middle number and take its square
        long long int temp2;
        temp2 = number/10000000;
        temp2 = number-temp2*10000000;
        temp2 = temp2/10000; // the middle number is obtained
        key = (temp2*temp2) % sizeN;
        return key;
    }
    else if(method == 'T'){
        // get the last 2 digits of the number
        long long int temp3;
        temp3 = number/100;
        temp3 = temp3*100;
        key = (number - temp3) % sizeN;
        return key;
    }
    return -1;
}

// add new ID
void HashTable::addNewNumber(long long int number){
    if(hashTable == nullptr){
        cout<<"Hash table is not initialized!"<<endl;
        return;
    }
    // check if the number already exists
    if(searchID(number) == true){
        return; // return from the function
    }
    int key = getKey(number);
    Node<long long int>* newNode = new Node<long long int> (number); // generate a new node

    hashTable[key].InsertNode(newNode); // insert it to head
    cout<< "ID is added successfully."<<endl;
}

// delete ID
void HashTable::deleteID(long long int number){
    if(hashTable == nullptr){
        cout<<"Hash table is not initialized!"<<endl;
        return;
    }
    int key = getKey(number); // get the key
    Node<long long int>* tempNode = hashTable[key].getHead();
    // check if the head is null
    if(tempNode == nullptr){
         cout<<"The ID number does not exist!"<<endl;
        return;
    }
    // check if the number is in the head
    if(tempNode->getData() == number) {
        hashTable[key].deleteHead(); // delete the head
        cout<< "ID is deleted successfully."<<endl;
        return;
    }
    while(true){
            if(tempNode->getNext() != nullptr){
                if(tempNode->getNext()->getData() == number){
                    tempNode->deleteAfter();
                    cout<< "ID is deleted successfully."<<endl; // if id is found, delete it
                    return;
                }
                tempNode = tempNode->getNext(); // continue with the next
            }
            else{
                cout<<"The ID number does not exist!"<<endl; // return if the end of the list is reached
                return;
            }
    }
}

// search ID
bool HashTable::searchID(long long int number){
    if(hashTable == nullptr){
        cout<<"Hash table is not initialized!"<<endl;
        return false;
    }
    int key = getKey(number);
    Node<long long int>* tempNode = hashTable[key].getHead();
    // check if the list is empty
    if(tempNode == nullptr){
         cout<<"The ID number does not exist!"<<endl;
        return false;
    }
    // check if the number is in the head
    if(tempNode->getData() == number) {
        cout<<"The ID exists in the hash table!"<<endl;
        return true;
    }
    while(true){
            if(tempNode->getNext() != nullptr){
                if(tempNode->getNext()->getData() == number){
                   cout<<"The ID exists in the hash table!"<<endl; // if the number is found, return true and print
                    return true;
                }
                tempNode = tempNode->getNext(); // else, continue
            }
            else{
                cout<<"The ID number does not exist!"<<endl; // if reached to the end, return false
                return false;
            }
    }
}

// print table
void HashTable::printTable() const{
    if(hashTable == nullptr){
        cout<<"Hash table is not initialized!"<<endl;
        return;
    }
    cout<<"Printing the table..."<<endl;
    for(int i=0;i<sizeN;i++){
        cout<<i+1<<". ";
        Node<long long int>* tempNode = hashTable[i].getHead();
        // check if head is null
        if(tempNode == nullptr){
            cout<<"E"<<endl; // if the list İS EMPTY
            continue;
        }
        while(true){
            // check if the temp is null
            if(tempNode != nullptr)
                cout<<tempNode->getData(); // if not, get the data
            else
                break;
            // check if the next is null
            if(tempNode->getNext() != nullptr){
                cout<<" - ";
                tempNode = tempNode->getNext(); // if not, continue with the next node
            }
            else{
                break; // break if the end of the list is reached
            }
        }
        cout<<endl;
    }
}
