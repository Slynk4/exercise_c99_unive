#include <inttypes.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// or get the buy and sell point in a certain interval
size_t *get_minMax(float *arr, size_t start, size_t end);

int main(){
	
	// opene the file that contain the value 
	FILE *fl = fopen("valori.txt", "r");
	
	if (fl == NULL) {
		printf("unable to open file");
		
		// free memory
		fclose(fl);
		return 1;
	}
	
	// obtaining the lenght of the array 
	float temp;
	size_t i;
	for ( i = 0; fscanf(fl, " %f ,", &temp) == 1; i++);

	rewind(fl); // relocate the pointer of the start of the file

	// create the array on malloc
	float *nums = malloc(i * sizeof(float));

	//  controll if the malloc worcks and in case fre the memory and return an error
	if (nums == NULL){
		printf("unable to malloc");
		
		// free memory
		free(nums);
		fclose(fl);
		return 2;
	}
	
	// populate the array
	for (size_t j = 0; j < i && fscanf(fl, " %f ,", &nums[j]) == 1; j++);
	
	// get the max and min value
	size_t *minMax = get_minMax(nums, 0, i);

	// controll if can buy and sell if not controll other path	
	 if (minMax[1] < minMax[0]) {

		 // controll the two end of the array if the minimun value is after the Maximun
		size_t *minMax_1 = get_minMax(nums, 0, minMax[1]); // start to Max value
		size_t *minMax_2 = get_minMax(nums, minMax[0], i); // mi value to the end   
		
		// see the percentage of the earning
		float guadagno_1 = nums[minMax_1[0]] / nums[minMax_1[1]];
		float guadagno_2 = nums[minMax_2[0]] / nums[minMax_2[1]];
		
		// see what is greater 
		if (guadagno_1 >= guadagno_2) {
			minMax = minMax_1;
		} else {
			minMax = minMax_2;
		}
}
	// print the value 
	printf("puoi comprare a %zu giorni a %.2f $ \nvendere a %zu giorni per %.2f $ \n", minMax[0], nums[minMax[0]] , minMax[1], nums[minMax[1]]);
	
	// free memory
	free(nums);
	fclose(fl);		
	return 0;

}

size_t *get_minMax(float *arr, size_t start, size_t end){

	size_t *minMax = malloc(2 * sizeof(size_t));

	if (minMax == NULL){
		return minMax;
	}

	size_t iMax = start;
       	size_t iMin = start;
   
       	for (size_t j=start; end > j; ++j ){		

                if(arr[iMax] < arr[j] ) iMax = j;
        	if (arr[iMin] > arr[j]) iMin = j;
        }
	
	minMax[0] = iMin;
	minMax[1] = iMax;
	
	return minMax;
}
