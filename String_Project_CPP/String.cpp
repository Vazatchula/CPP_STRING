#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>


using namespace std;
bool pass;
int passRate = 0;
int failRate = 0;


String::String() {
	cout << "+++ string constructor +++" << endl;
	
	strNew = new char[0];
}

String::~String() {
	cout << "--- string deconstructor ---" << endl;
	delete[] strNew;
}

String::String(const String& other) {
	cout << "+++ string copy +++" << endl;

	size_t size;
	size = strlen(other.strNew);
	strNew = new char[size + 1];
	strcpy(strNew, other.strNew);



}

String::String(const char* str) {
	cout << "+++ string const: " << str << " +++" << endl;
	
	size_t size;
	size = strlen(str);
	strNew = new char[size + 1];
	strcpy(strNew, str);


}

size_t String::Length() const // writes the length of the string's char array
{
	pass = false;
	cout << "\n--- length? operator ---" << endl;
	int length = strlen(strNew);
	cout << "length of " << strNew << " is: " << length << endl;
	passRate++;
	pass = true;
	return length;
}

char& String::CharacterAt(size_t index)
{
	pass = false;
	cout << "\n--- character at? function ---" << endl;
	cout << "letter " << index << " of " << strNew << " is the character: ";
	//cout << strlen(strNew) << endl;

	if (strlen(strNew) <= 0) {
		cout << "NO STRING INPUT";
		failRate++;
	}

	if (strNew[index - 1] < (strlen(strNew)) || ('\0') || (strNew[index - 1] <= -1)) {
 
		cout << "INVALID INPUT";
		failRate++;
	}
	else {
		cout << strNew[index - 1] << endl;
		passRate++;
		pass = true;
	}

	
	return strNew[index];

}

bool String::EqualTo(const String& other) // equality FUNCTION, different to the operator but does the same thing
{
	pass = false;
	cout << "\n--- equal to? function ---" << endl;

	if (strcmp(strNew, other.strNew) == 0) {
		cout << "The strings are equal" << endl;
		passRate++;
		pass = true;
	}
	else {
		cout << "The strings are not equal" << endl;
		failRate++;
	}

	return this;

}

String& String::Append(const String& _str)
{
	pass = false;
	cout << "\n--- append? function ---" << endl;
	//strcpy(strNew, _str.strNew);
	strcat(strNew, " ");
	strcat(strNew, _str.strNew);
	cout << strNew << endl;
	passRate++;
	pass = true;
	return *this;
}

String& String::Prepend(const String& _str)
{
	pass = false;
	cout << "\n--- prepend? function ---" << endl;
	strcat(_str.strNew, " ");
	strcat(_str.strNew, strNew);
	cout << _str.strNew << endl;
	passRate++;
	pass = true;
	return *this;
}

const char* String::CStr() const
{
	pass = false;
	passRate++;
	pass = true;
	return strNew; // collected from private class
}

String& String::ToLower() // makes every char lowercase
{
	pass = false;
	for (size_t i = 0; i < strlen(strNew); i++) {

		strNew[i] = tolower(strNew[i]);
	}
			
	cout << "Lowercase: " << strNew << endl;
	passRate++;
	pass = true;
	
	return *this;
}

String& String::ToUpper() // makes every char UPPERCASE
{
	pass = false;
	for (size_t i = 0; i < strlen(strNew); i++) {

		strNew[i] = toupper(strNew[i]);
	}

	cout << "Uppercase: " << strNew << endl;
	passRate++;
	pass = true;

	return *this;
}

size_t String::Find(const String& _str)
{
	pass = false;
	cout << "--- FIND ---" << endl;

	char* found = strstr(strNew, _str.strNew);

	if (found == nullptr) return -1;
	passRate++;
	pass = true;

	return found - strNew;
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	pass = false;
	cout << "--- FIND (INDEX) ---" << endl;

	if ((_startIndex < 0) || (_startIndex >= strlen(strNew))) return -1;

	char* foundIndexed = strstr(strNew + _startIndex, _str.strNew);

	if (foundIndexed == nullptr) return -1;
	passRate++;
	pass = true;

	return foundIndexed - strNew;
}

String& String::Replace(const String& _find, const String& _replace)
{
	pass = false;
	cout << "--- REPLACE ---" << endl;

	size_t replace = 0;

	while (replace != -1) {
		replace = Find(replace, _find.strNew);

		strNew[replace] = *_replace.strNew;
	}
	passRate++;
	pass = true;
	return *this;
}

String& String::ReadFromConsole()
{
	pass = false;
	cout << "READING FROM FILE: " << "Hello_World.txt:" << endl;
	fstream wordsReader("Hello_World.txt", ios::in);
	string word;	
	
	while (!wordsReader.eof())
	{
		wordsReader >> word;
		cout << word << " ";
	}
	cout << endl;

	wordsReader.close();
	passRate++;
	pass = true;
	return *this;
}

String& String::WriteToConsole()
{
	pass = false;
	cout << "WRITING TO FILE" << endl;
	fstream file;
	file.open("test.txt", ios::out);
	file << strNew << endl;
	file.close();
	passRate++;
	pass = true;
	return *this;
}

bool String::operator==(const String& _other) // operator overload for equality ('==')
{
	pass = false;
	if (strcmp(strNew, _other.strNew) == 0) {
		pass = true;
		passRate++;
		return true;
	}

	else {
		failRate++;
		return false;
	}
}

bool String::operator!=(const String& _other) // operator overload for inequality ('!=')
{
	pass = false;
	if (strcmp(strNew, _other.strNew) != 0) {
		passRate++;
		pass = true;
		return true;
	}

	else {
		failRate++;
		return false;
	}
}

String& String::operator=(const String& _str) // operator overload for assignment ('=')
{
	pass = false;
	strcpy(strNew, _str.strNew);
	passRate++;
	pass = true;
	return *this;
}

char& String::operator[](size_t index)
{
	pass = false;
	if (strlen(strNew) <= 0) cout << "NO STRING INPUT";

	if (strNew[index - 1] < (strlen(strNew)) || ('\0') || (strNew[index - 1] <= -1)) {
		failRate++;
		cout << "INVALID INPUT";
	}
	else {
		passRate++;
		pass = true;
		cout << strNew[index - 1];
	}


	return strNew[index];
}



