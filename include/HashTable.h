#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "LinkedList.h"

using namespace std;
class HashTable{
private:
    LinkedList<long long int>* hashTable; // list of linked lists
    int sizeN; // size of hash table
    string sizeS; // size of hash table as string
    char method; // hashing method
public:
    HashTable(); // constructor
    int getKey(long long int number); // a function to get the key of an ID considering the hashing method
    void initHashTable(); // initialize hash table
    void loadHashTable(); // load a hast table from a file
    void addNewNumber(long long int number); // add new TC ID
    void deleteID(long long int number); // delete a ID number
    bool searchID(long long int number); // search an ID and return true if exists
    void printTable() const; // print the whole table
};


#endif // HASHTABLE_H
