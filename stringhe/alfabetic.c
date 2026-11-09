#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* --------------------------------------------------------------------------*/
/**
 * @brief 		funtion that controllif there is all the alfabetic character in a given string
 *
 * @Param lett		the given string 
 *
 * @Returns  		if there are all alfabetic character in the string 
 */
/* ----------------------------------------------------------------------------*/
bool allAlfabet(char *lett);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		print all the value in an array
 *
 * @Param arr		array to print
 */
/* ----------------------------------------------------------------------------*/
void printArr(bool *arr);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		controll if in the given array the vaule in it  are present or not
 *
 * @Param arr		array of boelan
 *
 * @Returns  		if all the value are true higher of 0 
 */
/* ----------------------------------------------------------------------------*/
bool haveSeenItAll(bool *arr);

int main(int argc, char *argv[]){

	if (allAlfabet(argv[1])){
		printf("sono presenti tutte le lettere dell' alfabeto \n");
	}else {
		printf("non sono presenti tutte le letter dell' lafabeto \n");
	}

	return 0;
}

void printArr(bool *arr){
	for (size_t i=0; *arr; i++, arr++ ) {
		printf("%c: %d \n", (char)('a' + i ), *arr);
	}
} 

bool allAlfabet(char *lett){

	bool *seen = calloc(sizeof(bool), 26);
	
	while ( *lett ) {
		seen[ *lett - 'a' ] = true;	
		lett++;
	}
	
	printArr(seen);

	return haveSeenItAll(seen);
}

bool haveSeenItAll(bool *arr){

	printf("arr %d \n", *arr);

	//while ( *arr ) {
	for(size_t i=0; i < 26; i++){
		if (*arr++ == false) {
			printf("arr %d \n", *arr);
			return false;
		}
	}

	return true;
}
