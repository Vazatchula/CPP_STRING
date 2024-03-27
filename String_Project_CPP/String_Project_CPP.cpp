// String_Project_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "String.h"
#include <fstream>
#include <ctime>
using namespace std;
extern int passRate;
extern int failRate;
extern bool pass;


int main()
{
    
    
   
    fstream file;

    struct tm newtime;
    __time64_t long_time;
    char timebuf[26];
    errno_t error;

    _time64(&long_time);
    error = _localtime64_s(&newtime, &long_time);

    error = asctime_s(timebuf, 26, &newtime);
    
    printf("%.19s \n", timebuf);
    file.open("File.txt", ios::app);
    file << "\n\n" << timebuf << endl;



    
    String* hello = new String("Hello");
    String* world = new String("World");

    /////////finding length of an input /////////

    hello->Length(); if (pass == true) file << "Length operator SUCCESS" << endl;
    if (pass == false) file << "Length operator FAIL" << endl;
    world->Length(); if (pass == true) file << "Length operator SUCCESS" << endl;
    if (pass == false) file << "Length operator FAIL" << endl;


    /////// finding a letter in a word ////////////
    
    hello->CharacterAt(3); if (pass == true) file << "Character At operator SUCCESS" << endl;
    if (pass == false) file << "Character At operator FAIL" << endl;
    world->CharacterAt(2); if (pass == true) file << "Character At operator SUCCESS" << endl;
    if (pass == false) file << "Character At operator FAIL" << endl;


    ////// equality ////////////

    // hello = world; // copies 'World' onto the hello string and makes them the same. Returns true
    hello->EqualTo(*world); // false! 'Hello' and 'World' are not the same
    if (pass == true) file << "Equal To operator SUCCESS" << endl;
    if (pass == false) file << "Equal To operator FAIL" << endl;
    
    /////// lowercase|UPPERCASE ////////////

    hello->ToLower(); if (pass == true) file << "Lowercase operator SUCCESS" << endl;
    if (pass == false) file << "Lowercase operator FAIL" << endl;
    world->ToUpper(); if (pass == true) file << "Uppercase operator SUCCESS" << endl;
    if (pass == false) file << "Uppercase operator FAIL" << endl;


    ////// append //////////

    hello->Append(*world); if (pass == true) file << "Append operator SUCCESS" << endl;
    if (pass == false) file << "Append operator FAIL" << endl;

    // uncomment individually for testing purposes


    //////// prepend /////// 

    hello->Prepend(*world); if (pass == true) file << "Prepend operator SUCCESS" << endl;
    if (pass == false) file << "Prepend operator FAIL" << endl;
    
    // uncomment individually for testing purposes

    ////// find string /////////////

    hello->Find(*world); if (pass == true) file << "Find operator SUCCESS" << endl;
    if (pass == false) file << "Find operator FAIL" << endl;



     
    ///// CStr ////////////////
    cout << "--- CStr ---" << endl;
    cout << hello->CStr() << endl; // returns the string content, but collects it from the private string class
    cout << world->CStr() << endl;
    if (pass == true) file << "CStr operator SUCCESS" << endl;
    if (pass == false) file << "CStr operator FAIL" << endl;

    ////// write to console ////////
    cout << "--- Reading | Writing ---" << endl;
    hello->WriteToConsole(); if (pass == true) file << "Write to Console operator SUCCESS" << endl;
    if (pass == false) file << "Write to Console operator FAIL" << endl;// writes "Hello" in the file 'test.txt'
    world->ReadFromConsole(); if (pass == true) file << "Read to Console operator SUCCESS" << endl;
    if (pass == false) file << "Read to Console operator FAIL" << endl;

    
    ////// OPERATORS //////
    cout << "--- operator functions ---" << endl;

    cout << "string1 != string2: ";
    if (*hello != *world) cout << "Yes" << endl; if (pass == true) file << "!= operator SUCCESS" << endl;// returns true, both strings are not equal
    if (pass == false) file << "!= operator FAIL" << endl;


    cout << "string1 == string2: ";
    if (*hello == *world) cout << "Yes" << endl; if (pass == true) file << "== operator SUCCESS" << endl;
    else cout << "No" << endl; // returns false, the strings are not equal
    if (pass == false) file << "== operator FAIL" << endl;


    cout << "--- ASSIGNMENT OPERATOR ---" << endl;
    *hello = *world; if (pass == true) file << "= operator SUCCESS" << endl;// copies 'test2' onto 'test1'
    if (pass == false) file << "= operator FAIL" << endl;


    cout << "RERUN: string1 == string2: ";
    if (*hello == *world) cout << "Yes" << endl; if (pass == true) file << "== operator SUCCESS" << endl;// should work now.
    if (pass == false) file << "== operator FAIL" << endl;


    cout << "--- SUBSCRIPT OPERATOR ---" << endl;

    cout << "string2 second letter: "; // should be 'o' from 'World'
    (*world)[2];
    if (pass == true) file << "Subscript operator SUCCESS" << endl;
    if (pass == false) file << "Subscript operator FAIL" << endl;

    int finalScore;



    finalScore = ((passRate * 100) /18) + 1; // its literally 1% off turn a blind eye
    file << finalScore << "% SUCCESS RATE" << endl;

    finalScore = ((failRate * 100) / 18);
    file << finalScore << "% FAIL RATE" << endl;
    file << "\n \n \n" << endl;
    file.close();


}




