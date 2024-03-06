// String_Project_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "String.h"
using namespace std;


int main()
{
   
    
    String* hello = new String("Hello");
    String* world = new String("World");

    /////////finding length of an input /////////

    hello->Length();
    world->Length();    


    /////// finding a letter in a word ////////////
    
    hello->CharacterAt(3);
    world->CharacterAt(2);


    ////// equality ////////////

    // hello = world; // copies 'World' onto the hello string and makes them the same. Returns true
    hello->EqualTo(*world); // false! 'Hello' and 'World' are not the same

    
    /////// lowercase|UPPERCASE ////////////

    //hello->ToLower(input);
    //world->ToUpper(input);


    ////// append //////////

    /*hello->Append(*world);*/

    // uncomment individually for testing purposes


    //////// prepend /////// 

    /*hello->Prepend(*world);*/
    
    // uncomment individually for testing purposes
     
    ///// CStr ////////////////
    cout << "--- CStr ---" << endl;
    cout << hello->CStr() << endl; // returns the string content, but collects it from the private string class
    cout << world->CStr() << endl;


    ////// write to console ////////
    cout << "--- Reading | Writing ---" << endl;
    hello->WriteToConsole(); // writes "Hello" in the file 'test.txt'
    world->ReadFromConsole();

    
    ////// OPERATORS //////
    cout << "--- operator functions ---" << endl;

    cout << "string1 != string2: ";
    if (*hello != *world) cout << "Yes" << endl; // returns true, both strings are not equal

    cout << "string1 == string2: ";
    if (*hello == *world) cout << "Yes" << endl;
    else cout << "No" << endl; // returns false, the strings are not equal

    cout << "--- ASSIGNMENT OPERATOR ---" << endl;
    *hello = *world; // copies 'test2' onto 'test1'

    cout << "RERUN: string1 == string2: ";
    if (*hello == *world) cout << "Yes" << endl; // should work now.

    cout << "--- SUBSCRIPT OPERATOR ---" << endl;

    cout << "string2 second letter: "; // should be 'o' from 'World'
    (*world)[2];
   
    



}




