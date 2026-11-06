#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleshort(int* arr, size_t length);  // bubleshot fo ordre the array
void swap(int* x, int* y);                  // swap funtion betwan X and Y
void printArr(int* arr, size_t length);     // print the array 
void populateArr(int* arr, size_t length);  // populate the array whit int

int main() {

    int *ptr = malloc(5 * sizeof(size_t));  // get a space for a array of 5 int in memory and assigning to a pointer 
    size_t length = sizeof(ptr);            // get the size of element for the array 

    srand((unsigned)time(NULL));            // seeding the rand() funtion 

    // control in case malloc() fails
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    populateArr(ptr, length);
    printArr(ptr, length);
    bubbleshort(ptr, length);
    printArr(ptr, length);

    free(ptr);                              // freeing the register of the array

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
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int* x, int* y){          // using pointer for memory efficent
    int temp = *x;
    *x = *y;
    *y = temp;

}
