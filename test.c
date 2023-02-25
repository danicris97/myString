#include <stdio.h>
#include "myString.h"

int main(){
	myString string;
	myString string2;
	myString result;
	myString aux;
	nullString(aux);
	
	printf("\nIngrese una cadena: ");
	readString(string);
	
	printf("\nIngrese otra cadena: ");
	readString(string2);
	
	if(compareString(string,string2)==true){
		printf("\nCadenas iguales");
	}else{
		printf("\nCadenas distintas");
	}
	
	differenceString(string,string2,result);
	printf("\nCadena diferencia: %s",result);
	
	concatenation(string,string2,result);
	printf("\nCadena concatenada: %s",result);
	
	intersectionString(string,string2,result);
	printf("\nCadena interseccion: %s",result);
	
	printf("\nCadena ingresada: %s",string);
	printf("\nCantidad de caracteres de la cadena: %d",size(string));
	
	insertChar(string, 'a');
	printf("\nCadena: %s",string);
	
	insertCharFirst(string, 'c');
	printf("\nCadena: %s",string);
	
	insertCharIndex(string, '\0', 2);
	printf("\nCadena: %s",string);
	
	printf("\nPosicion letra en a: %d", indexOf(string,'a'));
	
	deleteCharIndex(string,size(string));
	printf("\nCadena: %s", string);
	
	deleteChar(string, '\0');
	printf("\nCadena: %s", string);
	
	deleteAllChar(string, 'a');
	printf("\nCadena: %s", string);
	
	replaceIndex(string, 'f', 2);
	printf("\nCadena: %s", string);
	
	replaceChar(string, 'c', 's');
	printf("\nCadena: %s", string);
	
	myString copy;
	copyString(string,copy);
	printf("\nCadena: %s", string);
	printf("\nCadena copia: %s",copy);
	
	myString cadena3;
	printf("\nIngrese otra cadena: ");
	readString(cadena3);
	
	printf("\nCantidad de palabras: %d",countWords(cadena3));
	printf("\nCaracter mas repetido: %c",mostRepeatedChar(cadena3));
	
	printf("\nPrimer char: %c",slice(cadena3));
	printf("\nUltimo char: %c",pop(cadena3));
	printf("\nCadena: %s",cadena3);
	
	myString cadena4;
	copynString(string,cadena4,3);
	printf("\nCadena: %s",cadena4);
	
	nullString(aux);
	inverseString(cadena4,aux);
	printf("\nCadena: %s",aux);
	
	return 0;
}
