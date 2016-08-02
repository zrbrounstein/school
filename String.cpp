#include <iostream>
#include "String.h"

using namespace std;

void String::initialize(char* word)
{
	int count = 0;
	while(*word != '\0')
	{
		count++;
		word++;
	}
	wordLength = count;

	for(int i = 0; i < count; i++)
	{
		word--;
	}

	buffer = new char[wordLength+1];
	char* bufferhome;
	bufferhome = buffer;

	while(*word != '\0')
	{
		*buffer = *word;
		word++;
		buffer++;
	}

	*buffer = '\0';
	buffer = bufferhome;
}

void String::deallocate()
{
	delete[] buffer;
	buffer = NULL;
}

void String::copy(const String& newString)
{
	if(wordLength != newString.wordLength)
	{
		deallocate();
		buffer = new char[newString.wordLength + 1];
		wordLength = newString.wordLength;
	}

	char* tempptr;
	tempptr = newString.buffer;

	char* bufferhome;
	bufferhome = buffer;
	
	for(int i = 0; i < wordLength; i++)
	{
		*buffer = *tempptr;
		buffer++;
		tempptr++;
	}
	
	*buffer = '\0';
	buffer = bufferhome;		
}

int String::length()
{
	return wordLength;
}

void String::concat(const String& newString)
{
	char* bufferhome;
	bufferhome = buffer;
	
	char* tempptrhome;
	char* tempptr;
	tempptr = new char[wordLength+1];
	tempptrhome = tempptr;
	while(*buffer != '\0')
	{
		*tempptr = *buffer;
		tempptr++;
		buffer++;
	}
	*tempptr = '\0';
	tempptr = tempptrhome;
	
	buffer = bufferhome;
	if(newString.wordLength != 0)
	{
		deallocate();
		buffer = new char[newString.wordLength + wordLength + 1];
		wordLength += newString.wordLength;
	}

	while(*tempptr != '\0')
	{
		*buffer = *tempptr;
		tempptr++;
		buffer++;
	}
	
	tempptr = newString.buffer;
	while(*tempptr != '\0')
	{
		*buffer = *tempptr;
		tempptr++;
		buffer++;
	}
	*buffer = '\0';
	buffer = bufferhome;

	tempptr = tempptrhome;
	delete[] tempptr;
	tempptr = NULL;
}

int String::compare(const String& newString)
{
	 char* tempptr = newString.buffer;
	 char* bufferhome;
	 bufferhome = buffer;
	 while((*buffer != '\0') && (*tempptr != '\0'))
	 {
	 	if(*buffer > *tempptr)
	 	{
	 		return 1;
	 	}
	 	else if(*buffer < *tempptr)
	 	{
	 		return -1;
	 	}
	 	buffer++;
	 	tempptr++;
	 }

	 if(*buffer != '\0')
	 {
	 	return 1;
	 }
	 else if(*tempptr != '\0')
	 {
	 	return -1;
	 }

	 return 0;
}

void String::print()
{
	cout << endl << buffer << endl;	
}
