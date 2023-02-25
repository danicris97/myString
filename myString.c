#include "myString.h"
#include <stdio.h>

enum boolean conditionBelong(int index, char character){
	if(index!=-1 && character!='\0'){
		return true;
	}else if(character!='\0'){
		printf("\nError. Character does not belong in the string");
		return false;
	}else{
		printf("\nError. Character null");
		return false;
	}
}

enum boolean conditionSize(int size, char character){
	if(size<MAX && character!='\0'){
		return true;
	}else if(character!='\0'){
		printf("\nError. Maximum number of character exceeded");
		return false;
	}else{
		printf("\nError. Character null");
		return false;
	}
}

void cleanBuffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
	
void readString(myString string){
	int j,m,size;
	size=MAX;
	
	j=0;
	while(j<size-1 && (m=getchar())!=EOF && m!='\n'){
		string[j]=m;
		j++;
	}
	string[j]='\0';

	if(m!=EOF && m!='\n'){
		while((m=getchar())!=EOF && m!='n');
	}
}
	
void nullString(myString string){
	string[0]='\0';
}
	
void insertCharIndex(myString string, char character, int index){
	int i,n;
	
	n=size(string);
	if(conditionSize(n,character)==true && conditionBelong(index,character)==true){
		for(i=n;i>=index;i--){
			string[i+1]=string[i];
		}
		string[index]=character;
	}
}
	
void insertChar(myString string, char character){
	int n=size(string);
		
	if(conditionSize(n,character)==true){
		insertCharIndex(string,character,n);
	}
}
	
void insertCharFirst(myString string, char character){
	if(conditionSize(size(string),character)==true){
		insertCharIndex(string,character,0);
	}
}
	
void deleteCharIndex(myString string, int index){
	int i,n;
	
	n=size(string);
	if(index<n){
		for(i=index;i<n;i++){
			string[i]=string[i+1];
		}
	}else{
		printf("\nError. Incorrect index");
	}
}
	
void deleteChar(myString string, char character){
	int index=indexOf(string,character);
	
	if(conditionBelong(index,character)==true){
		deleteCharIndex(string,index);
	}
}
	
void deleteAllChar(myString string, char character){
	int index=indexOf(string,character);
	
	if(conditionBelong(index,character)==true){
		while(index!=-1){
			deleteCharIndex(string,index);
			index=indexOf(string,character);
		}
	}
}

void replaceIndex(myString string, char character, int index){
	if(index<size(string) && character!='\0'){
		string[index]=character;
	}else if(character!='\0'){
		printf("\nError. Incorrect index");
	}else{
		printf("\nError. Character null");
	}
}
	
void replaceChar(myString string, char character, char newCharacter){
	int index=indexOf(string,character);
	
	if(conditionBelong(index,character)==true){
		replaceIndex(string,newCharacter,index);
	}
}

void replaceAllChar(myString string, char character, char newCharacter){
	int index=indexOf(string,character);
	
	if(conditionBelong(index,character)==true){
		while(index!=-1){
			replaceIndex(string,newCharacter,index);
			index=indexOf(string,character);
		}
	}
}

void copyString(myString stringOriginal, myString stringCopy){
	int i=0;
	while(stringOriginal[i]!='\0'){
		stringCopy[i]=stringOriginal[i];
		i++;
	}
	stringCopy[i]='\0';
}
	
void copynString(myString stringOriginal, myString stringCopy, int n){
	int i=0;
	while(stringOriginal[i]!='\0' && i<n){
		stringCopy[i]=stringOriginal[i];
		i++;
	}
	stringCopy[i]='\0';
}
	
void concatenation(myString stringA, myString stringB, myString stringResult){
	copyString(stringA,stringResult);
	int i=size(stringResult);
	int j=0;
	
	while(stringB[j]!='\0'){
		insertCharIndex(stringResult,stringB[j],i);
		j++;
		i++;
	}
}
	
void intersectionString(myString stringA, myString stringB, myString stringResult){
	int i=0;
	int j=0;
	
	while(stringA[i]!='\0' && stringB[i]!='\0'){
		if(stringA[i]==stringB[j]){
			insertCharIndex(stringResult,stringA[i],j);
			j++;
		}
		i++;
	}
}
	
void differenceString(myString stringA, myString stringB, myString stringResult){
	copyString(stringA,stringResult);
	int i=0;
	while(stringA[i]!='\0' && stringB[i]!='\0'){
		if(indexOf(stringB,stringA[i])!=-1){
			deleteChar(stringResult,stringA[i]);
		}
		i++;
	}
}
	
void inverseString(myString string, myString result){
	int i;
	int j=0;
	if(size(string)!=0){
		for(i=size(string)-1;i>=0;i--){
			result[j]=string[i];
			j++;
		}
	}
	result[j]='\0';
}

int size(myString string){
	int i=0;
	
	while(string[i]!='\0'){
		i++;
	}
	
	return i;
}

int indexOf(myString string, char character){
	int i=0;
		
	while(string[i]!=character && string[i]!='\0'){
		i++;
	}
		
	if(string[i]==character){
		return i;
	}else{
		return -1;
	}
}
	
int countWords(myString string){
	int counter=0;
	int n=size(string);
	
	if(n!=0){
		int i;
		counter++;
		for(i=0;i<n;i++){
			if((string[i]==' ')||(string[i]==',')||(string[i]=='.')){
				counter++;
			}
		}
	}
	
	return counter;
}
	
int stringInString(myString stringOriginal, myString string){
	int i=0;
	int n=size(string);
	if(size(stringOriginal)>=n){
		myString aux;
		copynString(stringOriginal,aux,n);
		while((stringOriginal[i]!='\0')&&(compareString(string,aux)==true)){
			copynString(stringOriginal,aux,n);
			i++;
		}
		if(stringOriginal[i]=='\0'){
			return i;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

char mostRepeatedChar(myString string){
	char mostRepeated='\0';
	int i,j,counter;
	int beforeCounter=0;
	int n=size(string);
	
	for(i=0;i<n;i++){
		counter=0;
		for(j=i;j<n;j++){
			if(string[i]==string[j]){
				counter++;
			}
		}
		if(beforeCounter<counter){
			beforeCounter=counter;
			mostRepeated=string[i];
		}
	}
	
	return mostRepeated;
}
	
char slice(myString string){
	char character=string[0];
	deleteCharIndex(string,0);
	return character;
}

char pop(myString string){
	char character;
	int n=size(string);
	if(n!=0){
		character=string[n-1];
		deleteCharIndex(string,n-1);
	}else{
		character='\0';
	}
	return character;
}

enum boolean compareString(myString stringA, myString stringB){
	if(size(stringA)==size(stringB)){
		int i=0;
		while(stringA[i]==stringB[i] && stringA[i]!='\0'){
			i++;
		}
			
		if(stringA[i]=='\0'){
			return true;
		}else
			return false;
	}else{
		return false;
	}
}

enum boolean comparenString(myString stringA, myString stringB, int n){
	myString aux;
	copynString(stringB,aux,n);
	if(compareString(stringA,aux)==true){
		return true;
	}else{
		return false;
	}
}

enum boolean determineLargest(myString stringA, myString stringB){
	if(size(stringA)>size(stringB)){
		return true;
	}else{
		return false;
	}
}

enum boolean determineEqualSize(myString stringA, myString stringB){
	if(size(stringA)==size(stringB)){
		return true;
	}else{
		return false;
	}
}

enum boolean determinePalindrome(myString string){
	myString aux;
	inverseString(string,aux);
	if(compareString(string,aux)==true){
		return true;
	}else{
		return false;
	}
}
