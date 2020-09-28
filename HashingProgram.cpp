//
//  main.cpp
//  NewProject8
//
//  Created by Erik Pantoja on 10/27/19.
//  Copyright © 2019 Erik Pantoja. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

struct record{
    int studentID;
    string name;
};

//General helper Functions
void introductionPart1();
void introductionPart2();
void conclusion();
void createRecords();
int size = 500;
int elementCount, elementCount2;
record arrayRecords[30];

//Part 1 functions
void insert(record);
void search(record);
record a[500];
int m = 73;

//Part 2 functions
void insert2(record);
void search2(record);
record a2[500];
int m2 = 512, temp;
float A7 = 0.6180339887;

int main() {
    // Part 1 begins - Hash Function

    introductionPart1();
    createRecords();
    cout << "Created records for testing complete"<<endl<<endl;
    
    for (int k = 0; k < 30; k++){
        insert(arrayRecords[k]);
    }
    cout << "Inserted records in a hashtable "<<endl<<endl;
    
    
    cout << "Printing out HashTable"<<endl<<endl;
    for(int i = 0; i<500 ;i++){
        if(a[i].studentID != 0)
        cout << i << " ID: " << a[i].studentID << " Name: "  << a[i].name << endl;
    }
    
    cout <<endl<<endl<< "Searching for a element that exists "<<endl;
    record goodSearch;
    goodSearch.studentID = arrayRecords[5].studentID;
    
    search(goodSearch);
    
    cout << endl<<"Searching for a element that does not exist " <<endl;
    record badSearch;
    badSearch.studentID = 999999;
    
    search(badSearch);
    
    // Part 2 begins  - Hash Table
    
    introductionPart2();
    
    for (int k = 0; k < 30; k++){
        insert2(arrayRecords[k]);
    }
    cout << "Completed insert" <<endl;
    
    cout << "Printing out HashTable 2"<<endl<<endl;
      for(int h = 0; h < 500; h++){
          if(a2[h].studentID != 0)
          cout << h << " ID: " << a2[h].studentID << " Name: "  << a2[h].name << endl;
      }
    cout << "Completed printing " <<endl;
    
    cout <<endl<<endl<< "Searching for a element that exists "<<endl;
    record goodSearch2;
    goodSearch2.studentID = arrayRecords[5].studentID;
    
    search2(goodSearch2);
    
    cout << endl<<"Searching for a element that does not exist " <<endl;
    record badSearch2;
    badSearch2.studentID = 999999;
    
    search2(badSearch2);
    
    conclusion();

    return 0;
}



void introductionPart1() {
    
    cout << " Program 8 Part A "<<endl;
    cout << " This program will use a hash function to store data of student IDs using division"<<endl<<endl;
    
}

void introductionPart2(){
    
    cout << "*** Program 8 Part B ****************************************************"<<endl<<endl;
    cout << " This program will use a hash function to store data of student IDs using multiplication"<<endl<<endl;
    
}

void conclusion(){
    cout << " Part A, and Part B completed, Program is completed " <<endl;
    cout << " Implemented for Data Structures 2019 by Erik Pantoja" <<endl;
}

void createRecords(){
    srand (time(NULL));
    string names[30];
    // Adding random names to be stored and added to structs to be placed into hashing as required
    names[0] = "Bill";names[1] = "Jack";names[2] = "Greg";names[3] = "Phil";names[4] = "Steve";names[5] = "Johnny";names[6] = "Sam";names[7] = "Frank";names[8] = "JoJo";names[9] = "Juan";names[10] = "Erik";names[11] = "Jayson";names[12] = "Emma";names[13] = "Sally";names[14] = "Clarissa";names[15] = "Brian";names[16] = "Jane";names[17] = "Courtney";names[18] = "Kelli";names[19] = "Matt";names[20] = "Kaitlyn";names[21] = "Yleana";names[22] = "Drew";names[23] = "Andrew";names[24] = "Xavier";names[25] = "Taylor";names[26] = "Travis";names[27] = "Kori";names[28] = "Austin";names[29] = "Samual";
    
    int randomNum;
    
    for (int i = 0; i<30; i++){
    randomNum = rand() % 1000000 + 100000;
        
        arrayRecords[i].studentID = randomNum;
        arrayRecords[i].name = names[i];
    }
}



void search(record key){
 int pos,flag=0,count=0;
    
if(elementCount == 0)
cout << "The Hashtable is empty"<<endl;
else {
pos = key.studentID % m;

while((a[pos].studentID != key.studentID) && (count != size)){
pos = (pos + 1) % m;
count++;
}
if(a[pos].studentID == key.studentID){
cout <<"The Element was found at location : " << pos <<endl;
flag = 1;
}
if(flag == 0)
    cout << "The Element was not found in the Hashtable"<<endl<<endl;
}
}


void insert(record key){
    // key holds struct to insert
    int pos; // creating pos variable
    if(elementCount == 500){
    cout << "array is full" <<endl;
}
    
else { // array is not full
    pos = key.studentID % m; // int pos holds value of struct modules m so ... ~ 19
    
   /* while(pos > 30){      // Double Hashing - not needed - no fixed size requirement - but works
    pos = (pos + 1) % m;
    }*/
    
    while(a[pos].studentID != 0){ // using linear probing to make sure the element is not already taken
        pos = (pos + 1) % m;}
a[pos].studentID = key.studentID;  // array element pos id now is the value of the input
a[pos].name = key.name;            // also saving the name
        elementCount++;                // adding 1 to the element count
}
}

// Part 2 functions
    void insert2(record key){
         float pos = 0;
         if(elementCount == 500){
            cout << "Array is full" <<endl;
        } else {
        pos = floor(m2 * (key.studentID * A7 - floor(key.studentID * A7)));
        temp = pos;
        while(a2[temp].studentID != 0){
            pos = pos + 1;
            temp = pos;
        }
        a2[temp].studentID = key.studentID;
        a2[temp].name = key.name;
        elementCount2++;
    }
    }




void search2(record key){
int pos,flag = 0,count = 0;
if(elementCount2 == 0)
cout << "The Hashtable is empty"<<endl;

else {
pos = floor(m2 * (key.studentID * A7 - floor(key.studentID * A7)));

while((a2[pos].studentID != key.studentID) && (count != size)){
pos = floor(m2 * (key.studentID * A7 - floor(key.studentID * A7)));
pos = pos + 1;
count++;
}
    
if(a2[pos].studentID == key.studentID){
cout << " The Element was found at location : " << pos <<endl;
flag = 1;
}
if(flag == 0)
    cout << "The Element was not found in the Hashtable"<<endl<<endl;
}
}
