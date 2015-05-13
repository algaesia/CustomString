#include <iostream>
#include <time.h>
#include <assert.h>

#include "CustomString.h"

void Test1()
{
	char* words = new char[128];
	for (int i = 0; i < 128; ++i)
	{
		words[i] = rand() % 64 + 64;
	}

	char* moreWords = new char[128];
	for (int i = 0; i < 128; ++i)
	{
		moreWords[i] = rand() % 64 + 64;
	}

	char* anotherWord = new char[128];
	for (int i = 0; i < 128; ++i)
	{
		anotherWord[i] = rand() % 64 + 64;
	}

	char* weirdoConstructor = new char[128]
	{'W', 'e', 'i', 'r', 'd', 'o', ' ', 'C', 'a', 't', 's', 't', 'r', 'u', 'c', 't', 'o', 'r', 'C', 'a', 'n'};

	char* findWord = new char[32]
	{'C', 'a', 't'};

	char* helloWord = new char[32]
	{'H', 'e', 'l', 'l', 'o'};

	CustomString k;

	//default constructor
	CustomString d;

	//constructor taking in const char*
	CustomString f = CustomString(weirdoConstructor);

	//constructor taking in already initialised custom string
	CustomString e = CustomString(f);

	//constructor taking in const char*
	CustomString a = CustomString(moreWords);

	//constructor taking in const char*
	CustomString b = CustomString(words);

	CustomString i = CustomString(words);
	CustomString h = CustomString(words);

	//overloaded + operator
	CustomString c = b.operator+(a);

	CustomString g = CustomString(anotherWord);

	CustomString z = CustomString(findWord);

	CustomString x = CustomString(helloWord);

	CustomString y = CustomString(f);

	//overloaded += operator
	a += f;

	//character length up to null terminator
	int lengthOfA = a.Length();

	//illegal since d used default constructor, returns null terminator
	char charAtAnswer = d.CharacterAt(2);

	//illegal since f not that long, returns null terminator
	char anotherCharAtAnswer = f.CharacterAt(53);

	//returns char at, valid this time
	char moreCharAtAnswer = f.CharacterAt(12);

	//getting char* member variable
	const char* cStringOfA = a.c_str();

	//equality check, false
	bool IsAEqualToB = a == b;

	//equality check, true
	bool IsIEqualToH = i == h;

	//to lower
	g.ToLower();

	//to upper
	c.ToUpper();

	//read from console
	g.ReadFromConsole(helloWord);

	//prints out what a contains to console
	a.WriteToConsole();

	//testing emptiness, using default constructor, it is empty
	bool isDEmpty = d.IsEmpty();

	//testing emptiness, using read from console, it is not empty
	bool isGEmpty = g.IsEmpty();

	//d is created by default constructor, empty
	//append g, which is not empty
	d.Append(g);

	//add to the beginning of empty string
	k.Prepend(d);

	//f = 'Weirdo CatstructorCan' -> starting from index 0
	//Cat present starting index 7
	int anotherFindIndex = f.Find(z);

	//f = 'Weirdo CatstructorCan' -> starting from index 9
	//no other Cat present -> returns -1
	int findIndex = f.Find(9, z);

	//f = 'Weirdo CatstructorCan' -> starting from index -1
	//returns -1, outside bounds of word
	int moreFindIndex = f.Find(-1, z);

	//f = 'Weirdo CatstructorCan' -> starting from index 900
	//returns -1, outside bounds of word
	int moreMoreFindIndex = f.Find(900, z);

	y += y;

	//y = 'Weirdo CatstructorCanWeirdo CatstructorCan'
	//replacing cat with hello
	y.Replace(z, x);

	delete[] findWord;
	delete[] weirdoConstructor;
	delete[] words;
	delete[] anotherWord;
	delete[] moreWords;
}

void TestEqualityOperatorAndEqualToFunction()
{
	char* hello = new char[6]
	{
		'H', 'e', 'l', 'l', 'o'
	};

	char* cat = new char[4]
	{
		'C', 'a', 't'
	};

	char* symbols = new char[4]
	{
		'*', '(', '!'
	};

	char* anotherCat = new char[4]
	{
		'C', 'a', 't'
	};

	CustomString helloString = CustomString(hello);
	CustomString catString = CustomString(cat);
	CustomString symbolString = CustomString(symbols);
	CustomString anotherCatString = CustomString(anotherCat);

	delete[] hello;
	delete[] cat;
	delete[] symbols;
	delete[] anotherCat;

	//if assertion is false, error is shown
	assert(catString == anotherCatString);
	assert(catString.EqualTo(anotherCatString));
	assert(helloString != catString);
	assert(catString != helloString);
	assert(helloString != symbolString);
	assert(catString != symbolString);
	assert(symbolString != helloString);
	assert(symbolString != catString);
}

void TestLengthOperator()
{
	char* weirdoConstructor = new char[25]
	{
		'W', 'e', 'i', 'r', 'd', 'o', ' ', 'C', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', 'o', 'r', ' ', 'C', 'a', 't'
	};

	char* helloWorld = new char[12]
	{
		'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'
	};

	CustomString weirdoConstructorCatString = CustomString(weirdoConstructor);
	CustomString helloWorldString = CustomString(helloWorld);
	CustomString emptyString;

	delete[] weirdoConstructor;
	delete[] helloWorld;

	assert(weirdoConstructorCatString.Length() == 22);
	assert(helloWorldString.Length() == 11);
	assert(emptyString.Length() == 0);
}

void TestPrepend()
{
	char* hello = new char[6]
	{
		'H', 'e', 'l', 'l', 'o'
	};

	char* world = new char[6]
	{
		'W', 'o', 'r', 'l', 'd'
	};

	char* helloWorld = new char[11]
	{
		'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd'
	};

	char* worldHello = new char[11]
	{
		'W', 'o', 'r', 'l', 'd', 'H', 'e', 'l', 'l', 'o'
	};

	CustomString helloString = CustomString(hello);
	helloString.Prepend(world);

	//a CustomString object gets created for worldHello char*,
	//allowing for comparison operator to be used
	assert(helloString == worldHello);

	CustomString worldString = CustomString(world);
	worldString.Prepend(hello);
	
	assert(worldString == helloWorld);

	delete[] worldHello;
	delete[] helloWorld;
	delete[] world;
	delete[] hello;
}

void TestAppend()
{
	char* hello = new char[6]
	{
		'H', 'e', 'l', 'l', 'o'
	};

	char* world = new char[6]
	{
		'W', 'o', 'r', 'l', 'd'
	};

	char* helloWorld = new char[11]
	{
		'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd'
	};

	char* worldHello = new char[11]
	{
		'W', 'o', 'r', 'l', 'd', 'H', 'e', 'l', 'l', 'o'
	};

	CustomString helloString = CustomString(hello);
	helloString.Append(world);

	//a CustomString object gets created for worldHello char*,
	//allowing for comparison operator to be used
	assert(helloString == helloWorld);

	CustomString worldString = CustomString(world);
	worldString.Append(hello);

	assert(worldString == worldHello);

	delete[] worldHello;
	delete[] helloWorld;
	delete[] world;
	delete[] hello;
}

void TestCharacterAtAndSubscriptOverload()
{
	char* helloWorld = new char[11]
	{
		'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd'
	};

	CustomString stringHelloWorld = CustomString(helloWorld);

	assert(stringHelloWorld.CharacterAt(2) == 'l');
	assert(stringHelloWorld.CharacterAt(7) == 'r');
	assert(stringHelloWorld.CharacterAt(-1) == '\0');
	assert(stringHelloWorld.CharacterAt(100) == '\0');
	assert(stringHelloWorld.CharacterAt(stringHelloWorld.Length()) == '\0');

	assert(stringHelloWorld[2] == 'l');
	assert(stringHelloWorld[7] == 'r');
	assert(stringHelloWorld[-1] == '\0');
	assert(stringHelloWorld[100] == '\0');
	assert(stringHelloWorld[stringHelloWorld.Length()] == '\0');

	delete[] helloWorld;
}

void TestToLowerAndToUpper()
{
	char* helloUpper = new char[6]
	{
		'H', 'E', 'L', 'L', 'O'
	};

	char* helloLower = new char[6]
	{
		'h', 'e', 'l', 'l', 'o'
	};

	char* symbols = new char[4]
	{
		'*', '(', '!'
	};

	CustomString stringHelloUpper = CustomString(helloUpper);
	stringHelloUpper.ToLower();
	
	assert(stringHelloUpper == helloLower);

	CustomString stringHelloLower = CustomString(helloLower);
	stringHelloLower.ToUpper();
	
	assert(stringHelloLower == helloUpper);

	CustomString stringSymbols = CustomString(symbols);
	stringSymbols.ToLower();
	
	assert(stringSymbols == symbols);
	
	stringSymbols.ToUpper();

	assert(stringSymbols == symbols);

	delete[] symbols;
	delete[] helloLower;
	delete[] helloUpper;
}

void main()
{
	TestEqualityOperatorAndEqualToFunction();
	TestLengthOperator();
	TestPrepend();
	TestAppend();
	TestCharacterAtAndSubscriptOverload();
	TestToLowerAndToUpper();

	CustomString t;
	t.ReadFromConsole("THIS IS A QUESTION");
	t.WriteToConsole();

	system("pause");
}
