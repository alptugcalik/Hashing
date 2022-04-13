#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;


// a global function to take input as string and convert it to long long int
long long int takeStringtoLong(){
    long long int number;
    string sizeS;
    bool control = true;
while(true){
    cin>>sizeS;
    // check each char's ascii number
    for(unsigned int i=0; i<sizeS.length();i++){
        if(sizeS[i]<48 || sizeS[i]>57){
            cout<<"Invalid input!"<<endl;
            control = false;
            return -1;
        }
        control = true;
    }
    if(control == true) break;
    }
    number = stoll(sizeS);
    // check if the ID is valid
    if(number<10000000000 || number>99999999999){
        cout<<"Invalid TC number!"<<endl;
        return -1;
    }
    return number;
}

int main()
{
    char input;
    HashTable hashTable;
    long long int number;

    cout<<"Welcome to TC ID HashTable Generator"<<endl;

    while(true){
    cout<<endl;
    cout<<"Choose the operation from the menu:"<<endl;
    cout<<"0. Terminate The Program"<<endl;
    cout<<"1. Initialize Hash Table"<<endl;
    cout<<"2. Load T.C. ID Numbers from file"<<endl;
    cout<<"3. Add new T.C. ID Number"<<endl;
    cout<<"4. Delete a T.C. ID Number"<<endl;
    cout<<"5. Search for a T.C. ID Number"<<endl;
    cout<<"6. Print out Hash Table"<<endl;
    cin>>input;
    cout<<endl;
    // input is taken as char and ascii number of the char is checked to find the integer value
    if(input<48 || input > 54){
        cout<<"Invalid operation! Please enter an integer in the range 0-7!"<<endl;
        continue;
    }
    if(input == 48){
        break;  // terminate the loop
    }
    else if(input == 49){
        hashTable.initHashTable(); // init hash table
    }
    else if(input == 50){
        hashTable.loadHashTable(); // load a hash table from the file
    }
    else if(input == 51){
        cout<<"Enter a 11 digit TC number."<<endl;
        // first check the validity of the input
        number = takeStringtoLong();
        if(number == -1)
            continue;
        hashTable.addNewNumber(number); // add a new ıd to the table
    }
    else if(input == 52){
        cout<<"Enter a 11 digit TC number."<<endl;
        // first check the validity of the input
        number = takeStringtoLong();
        if(number == -1)
            continue;
        hashTable.deleteID(number); // delete a specified id
    }
    else if(input == 53){
        cout<<"Enter a 11 digit TC ID."<<endl;
        // first check the validity of the input
        number = takeStringtoLong();
        if(number == -1)
            continue;
        hashTable.searchID(number); // search an id
    }
    else if(input == 54){
        hashTable.printTable(); // print the table
    }


    }
    return 0;
}
