#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* --------------------------------------------------------------------------*/
/**
 * @brief 		bubleshot fo ordre the array
 *
 * @Param arr		array to reorder
 * @Param length	length of the arr
 */
/* ----------------------------------------------------------------------------*/
void bubbleshort(int* arr, size_t length); 


/* --------------------------------------------------------------------------*/
/**
 * @brief 		swap funtion betwan X and Y
 *
 * @Param x		pointer to an element
 * @Param y		pointer to another element
 */
/* ----------------------------------------------------------------------------*/
void swap(int* x, int* y);                  


/* --------------------------------------------------------------------------*/
/**
 * @brief 		print the array
 *
 * @Param arr		array to print
 * @Param length	length of the array
 */
/* ----------------------------------------------------------------------------*/
void printArr(int* arr, size_t length);    


/* --------------------------------------------------------------------------*/
/**
 * @brief 		populate the array whit random integar
 *
 * @Param arr		array
 * @Param length	array length	
 */
/* ----------------------------------------------------------------------------*/
void populateArr(int* arr, size_t length);  

int main() {

    int *ptr = malloc(5 * sizeof(size_t));	// get a space for a array of 5 int in memory and assigning to a pointer 
    size_t length = sizeof(ptr);            		// get the size of element for the array 

    srand((unsigned)time(NULL));           // seeding the rand() funtion 

    // control in case malloc() fails
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    populateArr(ptr, length);
    printArr(ptr, length);
    bubbleshort(ptr, length);
    printArr(ptr, length);

    free(ptr);                              		// freeing the register of the array

    return 0;
}

void populateArr(int* arr, size_t length){

    // populate the arr whit num betwean 0 and 100
    for(size_t i = 0; i < length; i++){
        arr[i] = rand() % 100;             
    }
}

void printArr(int* arr, size_t length){

 for (size_t i = 0; i < length ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleshort(int* arr, size_t length){

    size_t i, j;

    // bubbleshort optimizzed 
    for (i = 0; i < length; i++){
        for(j = i; j < length; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);		// pass the pointer to the swap funtion
            }
        }
    }
}

void swap(int* x, int* y){          			// using pointer for memory efficent
    int temp = *x;
    *x = *y;
    *y = temp;

}
