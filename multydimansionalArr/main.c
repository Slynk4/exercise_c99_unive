#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* --------------------------------------------------------------------------*/
/**
 * @brief 		a trsuct for point to an element on a 2 dimansion array 
 */
/* ----------------------------------------------------------------------------*/
struct point{
	size_t x;
	size_t y;
};


/* --------------------------------------------------------------------------*/
/**
 * @brief 		swap two elements in the array
 *
 * @Param arr		the array
 * @Param a		location of the first point
 * @Param b		location of the second point
 *
 * @Returns  		if the array whit the two elements swapped
 */
/* ----------------------------------------------------------------------------*/
int swapTwoPoint2D(int **arr, struct point a, struct point b);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		a funtion for swap two point 
 *
 * @Param x		an element in the array
 * @Param y		an other element in the array 
 *
 * @Returns  		if the two element are swapped
 */
/* ----------------------------------------------------------------------------*/
int swapPoint(int *x, int *y);

/* --------------------------------------------------------------------------*/
/**
 * @brief 		mirror the array in it and every element into the array
 *
 * @Param arr		array of element
 * @Param rows		the rows of array 
 * @Param column	the column of array
 *
 * @Returns  		if the array swapped 
 */
/* ----------------------------------------------------------------------------*/
int mirrorAll2D(int **arr, size_t row, size_t column);


/* --------------------------------------------------------------------------*/
/**
 * @brief 		print all elements into the array
 *
 * @Param arr		array to print
 * @Param row		row into the array
 * @Param column	column into the array
 */
/* ----------------------------------------------------------------------------*/
void printAll(int **arr, size_t row, size_t column);

/* --------------------------------------------------------------------------*/
/**
 * @brief 		populate the array whit random number
 *
 * @Param arr		array to populate
 * @Param row		the rows of array
 * @Param column	the column of array
 *
 * @Returns  		populated array
 */
/* ----------------------------------------------------------------------------*/
int populate(int **arr, size_t row, size_t column);

/* --------------------------------------------------------------------------*/
/**
 * @brief 		main of the proggram
 *
 * @Param argc		argument counter	-> int argv.lenght
 * @Param argv[]	argument vallue  	-> array of input element
 *
 * @Returns 		exit of the proggram of error 0  		
 */
/* ----------------------------------------------------------------------------*/
int main(int argc, char* argv[]){

	srand(14072007);

	size_t row = 9;
	size_t column = 9;

	int **arr = malloc(row * sizeof *arr);
	if (arr == NULL) return 1;

	for (size_t i = 0; i < row; i++) {
	    arr[i] = malloc(column * sizeof *arr[i]);
	    if (arr[i] == NULL) {
	        for (size_t j = 0; j < i; j++) {
	            free(arr[j]);
        	}
	        free(arr);
        	return 1;
    	}
	}

	populate(arr, row, column);
	printAll(arr, row, column);

	mirrorAll2D(arr, row, column);
	printAll(arr,row, column);

	struct point a = {0,0};
	struct point b = {1,1};

	swapTwoPoint2D(arr, a, b);
	printAll(arr, row, column); 

	for (size_t i = 0; i < row; i++) {
    		free(arr[i]);
	}
	free(arr);

	return 0;
}

int populate(int **arr, size_t row, size_t column){

	for(size_t i=0; i < row; i++){
		for (size_t j=0; j < column; j++) {
			arr[i][j] = rand() % 100;
		}
	}

	return 1;
}

void printAll(int **arr, size_t row, size_t column){
	
	for(size_t i=0; i < row; i++){
		for (size_t j=0; j < column; j++) {
    	       		printf("%d ", arr[i][j]);
           	
		}
		printf("\n");
          }

	printf("\n");
}

int mirrorAll2D(int **arr, size_t row, size_t column){

	for (size_t i=0; i < row; i++) {
		for (size_t j=0; j < column/2; j++) {
			swapPoint( &arr[i][j] , &arr[row - i - 1][column - j - 1]); 
		}
	}

	return 0;

}

int swapPoint(int *x, int *y){

	int temp = *x;
	*x = *y;
	*y = temp;

	return 1;
}

int swapTwoPoint2D(int **arr, struct point a, struct point b){

	swapPoint(&arr[a.x][a.y], &arr[b.x][b.y]);

	return 1;
}
