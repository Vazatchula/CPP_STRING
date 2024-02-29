// String_Project_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "String.h"
using namespace std;

int main()
{
    char input[12];
    char input2[12];


   //char name[12];

    String* str_01 = new String();
    //cin >> name;




    /////////finding length of an input /////////

    /*str_01->Length(name); */



    

    /////// finding a letter in a word ////////////
    /*int val = 3;
    
    cin >> input;

    cin >> val;

    str_01->CharacterAt(input, val);*/




    ////// equality ////////////

    //cin >> input;
    //cin >> input2;
    

    //str_01->EqualTo(input);




    /////// lowercase|UPPERCASE ////////////

    //cin >> input;

    //str_01->ToLower(input);
    //str_01->ToUpper(input);




    ////// append //////////

    String* test = new String("one");
    String* test2 = new String("TWO");

    //test->Append(*test2); // comment out for prepend

    //////// prepend /////// -- using the above code --

    // test->Prepend(*test2);




    //////// equal to /////////////

    // test->EqualTo(*test2);
     



    ///// CStr ////////////////
    cout << test->CStr();




    ////// 





}


