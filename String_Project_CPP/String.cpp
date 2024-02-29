#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <iostream>
#include <ctype.h>
#include <string>


using namespace std;


String::String() {
	cout << "--- string constructor: " << " ---" << endl;
	
	strNew = new char[0];
}

String::~String() {
	cout << "--- string deconstructor ---" << endl;
	delete[] strNew;
}

String::String(const String& other) {
	cout << "--- string copy ---" << endl;

	size_t size;
	size = strlen(other.strNew);
	strNew = new char[size + 1];
	strcpy(strNew, other.strNew);



}

String::String(const char* str) {
	cout << "--- string const: " << str << " ---" << endl;
	
	size_t size;
	size = strlen(str);
	strNew = new char[size + 1];
	strcpy(strNew, str);


}

size_t String::Length(char* name) const {
	cout << "--- length operator ---" << endl;
	int length = strlen(name);
	cout << length;
	return length;
}

//char& String::CharacterAt(size_t index)
//{
//	// TODO: insert return statement here
//}

const char& String::CharacterAt(char* input, size_t index) const
{
	cout << input[index];
	return input[index];
}

bool String::EqualTo(const String& other) {

	if (strcmp(strNew, other.strNew) == 0) {
		cout << "The Input is equal" << endl;
	}
	else cout << "The Input is not equal" << endl;

	return this;

}

String& String::Append(const String& _str)
{
	//strcpy(strNew, _str.strNew);
	strcat(strNew, " ");
	strcat(strNew, _str.strNew);
	cout << strNew << endl;
	return *this;
}

String& String::Prepend(const String& _str)
{
	strcat(_str.strNew, " ");
	strcat(_str.strNew, strNew);
	cout << _str.strNew << endl;
	return *this;
}

const char* String::CStr() const
{
	return strNew;
}

String& String::ToLower(char* input)
{
	for (size_t i = 0; i < strlen(input); i++) {

		input[i] = tolower(input[i]);
	}
			
	cout << "lowercase: " << input << endl;
	
	return *this;

}

String& String::ToUpper(char* input)
{
	for (size_t i = 0; i < strlen(input); i++) {

		input[i] = toupper(input[i]);
	}

	cout << "uppercase: " << input << endl;

	return *this;
}

//size_t String::Find(const String& _str)
//{
//	return size_t();
//}
//
//size_t String::Find(size_t _startIndex, const String& _str)
//{
//	return size_t();
//}
//
//String& String::Replace(const String& _find, const String& _replace)
//{
//	// TODO: insert return statement here
//}
//
//String& String::ReadFromConsole()
//{
//	// TODO: insert return statement here
//}
//
//String& String::WriteToConsole()
//{
//	// TODO: insert return statement here
//}
//
bool String::operator==(const String& _other)
{
	return this;
}

bool String::operator!=(const String& _other)
{
	return this;
}

String& String::operator=(const String& _str)
{
	return *this;
}

//char& String::operator[](size_t _index)
//{
//	// TODO: insert return statement here
//}
//
//const char& String::operator[](size_t _index) const
//{
//	// TODO: insert return statement here
//}
