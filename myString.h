#ifndef MYSTRING_H
#define MYSTRING_H

#define MAX 1000

typedef char myString[MAX];
enum boolean {false,true};

void cleanBuffer();
void readString(myString);
void nullString(myString);

void insertCharIndex(myString, char, int);//insert a character at a given position
void insertChar(myString, char);
void insertCharFirst(myString, char);

void deleteAllChar(myString, char);
void deleteChar(myString, char);//deletes the first occurrence of a given character
void deleteCharIndex(myString, int);

void replaceIndex(myString, char, int);
void replaceChar(myString, char, char);//replace the first occurrence of a given character
void replaceAllChar(myString, char, char);
//all operations return the result in the last parameter myString
void copyString(myString, myString);
void copynString(myString, myString, int);//copies n characters from a string
void concatenation(myString, myString, myString);
void intersectionString(myString, myString, myString);
void differenceString(myString, myString, myString);
void inverseString(myString, myString);

int size(myString);
int indexOf(myString, char);
int countWords(myString);//count a word separated by: ' ' ',' '.'
int stringInString(myString, myString);
char mostRepeatedChar(myString);
char slice(myString);
char pop(myString);

enum boolean compareString(myString, myString);
enum boolean comparenString(myString, myString, int);
enum boolean determineLargest(myString, myString);//determines if the first string is greater than
enum boolean determineEqualSize(myString, myString);//Determine if they are the same size
enum boolean determinePalindrome(myString);

#endif
