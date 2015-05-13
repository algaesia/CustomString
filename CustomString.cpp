#include "CustomString.h"
#include <iostream>

//default constructor
CustomString::CustomString()
	//initialise capacity to 256
	: m_Capacity(256),
	//initialise chars pointer to nullptr
	m_Chars(nullptr)
{
	//initialise memory for chars pointer based on capacity
	m_Chars = new char[m_Capacity];

	//insert null terminator
	m_Chars[0] = '\0';
}

//custom constructor taking in char array
CustomString::CustomString(const char* a_CharArray)
	//initialise capacity to zero
	: m_Capacity(0),
	//initialise chars pointer to nullptr
	m_Chars(nullptr)
{
	//variable to track length of incoming char array
	int length = 0;

	//get length of char array passed in
	while (a_CharArray[length] != '\0')
	{
		length++;
	}

	//set own capacity to twice length
	m_Capacity = length * 2 + 1;

	//create new memory to size of capacity
	m_Chars = new char[m_Capacity];

	//assign values across
	for (int i = 0; i < length; ++i)
	{
		m_Chars[i] = a_CharArray[i];
	}

	//assign null terminator at index of length
	m_Chars[length] = '\0';
}

//copy constructor
CustomString::CustomString(const CustomString& a_OtherString)
	//initialise capacity to zero
	: m_Capacity(0),
	//initialise chars pointer to nullptr
	m_Chars(nullptr)
{
	//get length of other string
	int otherLength = a_OtherString.Length();

	//set own capacity to twice that length
	m_Capacity = otherLength * 2 + 1;

	//create new memory to size of capacity
	m_Chars = new char[m_Capacity];

	//assign values across
	for (int i = 0; i < otherLength; ++i)
	{
		m_Chars[i] = a_OtherString.m_Chars[i];
	}

	//assign null terminator at index of length
	m_Chars[otherLength] = '\0';
}

//destructor, simply deletes m_Chars
CustomString::~CustomString()
{
	delete[] m_Chars;
	m_Chars = nullptr;
}

//not including null terminator
int CustomString::Length() const
{
	int counter = 0;
	while (m_Chars[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

const char CustomString::CharacterAt(int a_Index) const
{
	if (a_Index >= 0 && a_Index < Length())
	{
		return m_Chars[a_Index];
	}
	return '\0';
}

const char CustomString::operator[](int a_Index) const
{
	if (a_Index >= 0 && a_Index < Length())
	{
		return m_Chars[a_Index];
	}
	return '\0';
}

void CustomString::operator=(const CustomString& a_OtherString)
{
	//delete old data 
	delete [] m_Chars;

	//get length of new data
	int otherLength = a_OtherString.Length();
	m_Capacity = otherLength * 2;

	//create memory for new data
	m_Chars = new char[m_Capacity];

	//assign new data across
	for (int i = 0; i < otherLength; ++i)
	{
		m_Chars[i] = a_OtherString.m_Chars[i];
	}

	//add null terminator
	m_Chars[otherLength] = '\0';
}

bool CustomString::operator==(const CustomString& a_OtherString)
{
	if (IsEmpty())
		return false;

	int counter = 0;
	while (m_Chars[counter] != '\0')
	{
		if (m_Chars[counter] != a_OtherString.m_Chars[counter])
		{
			return false;
		}
		counter++;
	}
	return true;
}

bool CustomString::EqualTo(const CustomString& a_CustomString)
{
	return *(this) == a_CustomString;
}

bool CustomString::operator!=(const CustomString& a_OtherString)
{
	int counter = 0;
	while (m_Chars[counter] != '\0')
	{
		if (m_Chars[counter] != a_OtherString.m_Chars[counter])
		{
			return true;
		}
		counter++;
	}
	return false;
}

const char* CustomString::c_str() const
{
	return m_Chars;
}

CustomString& CustomString::operator+(const CustomString& a_String)
{
	int thisLength = Length();
	int otherLength = a_String.Length();

	//get total length of this + the other
	int totalLength = thisLength + otherLength;

	//set capacity to be twice total length
	m_Capacity = totalLength * 2 + 1;

	//temp size doesn't need to be same size as capacity
	char* temp = new char[totalLength + 1];

	//assign across values from this
	for (int i = 0; i < thisLength; ++i)
	{
		temp[i] = m_Chars[i];
	}

	//assign values across from other
	//need another counter to track
	//progression through other string
	int otherStringCounter = 0;
	//start from stopping point 
	//last time, go to total length 
	for (int i = thisLength; i < totalLength; ++i)
	{
		temp[i] = a_String.m_Chars[otherStringCounter];
		otherStringCounter++;
	}
	
	//transfer done, can delete m_Chars data
	delete[] m_Chars;

	//set up memory for m_Chars, size of capacity
	m_Chars = new char[m_Capacity];

	//assign across values from temp to m_Chars
	for (int i = 0; i < totalLength; ++i)
	{
		m_Chars[i] = temp[i];
	}

	//assign null terminator
	m_Chars[totalLength] = '\0';

	//get rid off temp
	delete [] temp;

	return *(this);
}

CustomString& CustomString::operator+=(const CustomString& a_OtherString)
{
	CustomString temp = CustomString((*this));
	temp = *(this) + a_OtherString;
	*(this) = temp;
	return *this;
}

CustomString& CustomString::operator+(const char* a_OtherCharArray)
{
	int thisLength = Length();
	int otherLength = 0;

	while (a_OtherCharArray[otherLength] != '\0')
	{
		otherLength++;
	}

	//get total length of this + the other
	int totalLength = thisLength + otherLength;

	//set capacity to be twice total length
	m_Capacity = totalLength * 2 + 1;

	//temp size doesn't need to be same size as capacity
	char* temp = new char[totalLength + 1];

	//assign across values from this
	for (int i = 0; i < thisLength; ++i)
	{
		temp[i] = m_Chars[i];
	}

	//assign values across from other
	//need another counter to track
	//progression through other string
	int otherStringCounter = 0;
	//start from stopping point 
	//last time, go to total length 
	for (int i = thisLength; i < totalLength; ++i)
	{
		temp[i] = a_OtherCharArray[otherStringCounter];
		otherStringCounter++;
	}

	//transfer done, can delete m_Chars data
	delete[] m_Chars;

	//set up memory for m_Chars, size of capacity
	m_Chars = new char[m_Capacity];

	//assign across values from temp to m_Chars
	for (int i = 0; i < totalLength; ++i)
	{
		m_Chars[i] = temp[i];
	}

	//assign null terminator
	m_Chars[totalLength] = '\0';

	//get rid off temp
	delete[] temp;

	return *(this);
}

CustomString& CustomString::operator+=(const char* a_OtherCharArray)
{
	CustomString convert = a_OtherCharArray;
	CustomString temp = *(this) + convert;
	*(this) = temp;
	return *this;
}

void CustomString::ToLower()
{
	int counter = 0;
	while (m_Chars[counter] != '\0')
	{
		//make sure it's a letter
		if (IsLetter(m_Chars[counter]))
		{
			//make sure its upper case
			if (m_Chars[counter] >= 65 && m_Chars[counter] <= 90)
			{
				//move to lower case range
				m_Chars[counter] += 32;
			}
		}
		counter++;
	}
}

void CustomString::ToUpper()
{
	int counter = 0;
	while (m_Chars[counter] != '\0')
	{
		//make sure it's a letter
		if (IsLetter(m_Chars[counter]))
		{
			//make sure its lower case
			if (m_Chars[counter] >= 97 && m_Chars[counter] <= 122)
			{
				//move to lower case range
				m_Chars[counter] -= 32;
			}
		}
		counter++;
	}
}

bool CustomString::IsLetter(char a_Char)
{
	if ((a_Char >= 65 && a_Char <= 90) || (a_Char >= 97 && a_Char <= 122))
	{
		return true;
	}
	return false;
}

bool CustomString::IsNumber(char a_Char)
{
	if (a_Char >= 48 && a_Char <= 57)
	{
		return true;
	}
	return false;
}

bool CustomString::IsSymbol(char a_Char)
{
	if ((a_Char >= 33 && a_Char <= 47) || 
		(a_Char >= 58 && a_Char <= 64) ||
		(a_Char >= 91 && a_Char <= 96) ||
		(a_Char >= 123 && a_Char <= 126))
	{
		return true;
	}
	return false;
}

//assigns data typed out to console
void CustomString::ReadFromConsole(const char* a_StringBeforeAnswer)
{
	delete [] m_Chars;

	m_Capacity = 1024;
	m_Chars = new char[m_Capacity];

	std::cout << a_StringBeforeAnswer << std::endl;
	std::cin.getline(m_Chars, m_Capacity - 1);

	ToLower();
}

//prints out itself to the console
void CustomString::WriteToConsole() const
{
	std::cout << m_Chars << std::endl;
}

bool CustomString::IsEmpty() const
{
	return Length() == 0;
}

//add to the end of current string
void CustomString::Append(const CustomString& a_OtherString)
{
	CustomString t = CustomString(*(this));
	t += a_OtherString;
	*(this) = t;
}

//add to the beginning of current string
void CustomString::Prepend(const CustomString& a_OtherString)
{
	CustomString t = CustomString(a_OtherString);
	t += *(this);
	*(this) = t;
}

int CustomString::Find(const CustomString& a_OtherString)
{
	return Find(0, a_OtherString);
}

int CustomString::Find(int a_StartIndex, const CustomString& a_OtherString)
{
	if (a_StartIndex < 0 || a_StartIndex > Length())
	{
		return -1;
	}

	//represents the current progression 
	//when comparing letters of this 
	//word with letters other word
	int nextStartingPoint = 0;

	//represents starting point progression through current word
	int currentProgression = a_StartIndex;
	int otherLength = a_OtherString.Length();

	//tracking progression through current word
	while (m_Chars[currentProgression] != '\0')
	{
		//counter for matching letters
		int letters = 0;

		//move to the point where matching will start from
		nextStartingPoint = currentProgression;

		//loop through other word, based on its length
		for (int j = 0; j < otherLength; ++j)
		{
			//compare current letter in current 
			//word with current letter in other word
			if (m_Chars[nextStartingPoint] == a_OtherString.m_Chars[j])
			{
				//if there is a match, increase match counter
				letters++;
			}

			//number of letters matching is equal
			//to number of letters in other word
			if (letters == otherLength)
			{
				return currentProgression;
			}

			//move to the next letter
			nextStartingPoint++;
		}

		//increase progression along current word
		currentProgression++;
	}

	//no matches found, return -1
	return -1;
}

//insert letters, without writing over
void CustomString::Replace(const CustomString& findThis, const CustomString& replaceWith)
{
	int index = 0;

	//keep going as long as index is less than the entire length of word
	while (index < Length())
	{
		//look for the word
		index = Find(index, findThis);

		//couldn't find any instance of the word, so leave function
		if (index == -1)
			return;

		//track progression through other word
		int replaceWordCounter = 0;

		//found a word, now to insert letters, starting from index
		for (int i = index; i < index + replaceWith.Length(); ++i)
		{
			m_Chars[i] = replaceWith.m_Chars[replaceWordCounter];
			replaceWordCounter++;
		}
	}
}
