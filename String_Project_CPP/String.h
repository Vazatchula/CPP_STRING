#define _CRT_SECURE_NO_WARNINGS
#pragma once




class String
{
public:
	String();



	String(const char* str);

	String(const String& other); // copy constructor

	~String();






	char name[12];

public:
	size_t Length(char* name) const;
	//char& CharacterAt(size_t index);
	const char& CharacterAt(char* input, size_t index) const;
	//
	bool EqualTo(const String& other);
	//
	String& Append(const String& _str);
	String& Prepend(const String& _str);
	//
	const char* CStr() const;
	//
	String& ToLower(char* input);
	String& ToUpper(char* input);
	//
	//	size_t Find(const String& _str);
	//	size_t Find(size_t _startIndex, const String& _str);
	//
	//	String& Replace(const String& _find, const String& _replace);
	//
	//	String& ReadFromConsole();
	//	String& WriteToConsole();
	//
	//public:
		bool operator==(const String& _other);
		bool operator!=(const String& _other);
	
		String& operator=(const String& _str);
	
	//	char& operator[](size_t _index);
	//	const char& operator[](size_t _index) const;

private:
	//unsigned int m_length;
	char* strNew;



};
