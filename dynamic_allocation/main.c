#include <stab.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/* --------------------------------------------------------------------------*/
/**
 * @brief controll if the malloc funtion is gone well
 *
 * @Param arr
 *
 * @Returns	1 if is gone well
 * 		0 if is isen't
 */		
/* ----------------------------------------------------------------------------*/
int allocControl(int *arr);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		print funtion for array
 *
 * @Param arr		Array that you want to print
 * @Param lenght	lenght of the Array
 */
/* ----------------------------------------------------------------------------*/
void getElements(int *arr, size_t lenght);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		mirror the elements of the array 
 *
 * @Param arr		Array that you want to invert 
 * @Param lenght	lenght of the Array
 *
 * @Returns 		the array inverted 
 */
/* ----------------------------------------------------------------------------*/
int *swap(int *arr, size_t lenght);



/* --------------------------------------------------------------------------*/
/**
 * @brief  	main funtion
 *
 * @Returns	
 */
/* ----------------------------------------------------------------------------*/
int main(){

	size_t lenght = 10; 
	int *arr = malloc(lenght * sizeof(int));	

	int arr1[] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10};
		
	int *arr2 = calloc(lenght, sizeof(int));
	
	printf("-- allocate with calloc --\n" );
	getElements(arr2, lenght);
	
	printf("-- allocate wiht malloc --\n");
	getElements(arr, lenght);
	
	printf("-- allocate statically --\n");	
	getElements(arr1, 10);

	lenght = 5;

	arr = realloc(arr,lenght * sizeof(int));
	arr2 = realloc(arr2, lenght * sizeof(int));

	// arr1 = realloc(arr1, 5 * sizeof(int)); // get an error array create statically
	
	printf("-- malloc --\n");
	getElements(arr2, lenght);
	
	printf("-- calloc --\n");
	getElements(arr, lenght);

	printf("-- swap static -- \n");
	getElements(swap( arr1, 10), 10);

	free(arr2);
	free(arr);
}

int allocControl(int *arr){
	
	if (arr == NULL)
		return 0;
	return 1;

}

void getElements(int *arr, size_t lenght){
	
	for(size_t i=0; lenght > i; i++){
		printf("elemento in %zu = %d\n",i, *(arr++));
	}

	printf("\n");

	return;
}

int *swap(int *arr,size_t lenght){

	int *swapArr = malloc(lenght * sizeof(int));
	
	if (allocControl(swapArr) == 0)
		return NULL;

	int *write = swapArr;
    	int *read = arr + lenght - 1;

    	for (size_t i = 0; i < lenght; i++) {
        	*write = *read;
     
        	write++;
       	 	read--;
    	}

 	   return swapArr;

}
