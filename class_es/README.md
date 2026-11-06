# file and arrays

a progect for understand read files and basic allocation of dynamic array

## objective 

find in a past month the range of days the are more profittable on a crypto value, buyDay and sellDay

## execution 

open the file in read mode, and store in a pointer

```c
// opene the file that contain the value 
FILE *fl = fopen(filename: "valori.txt", modes: "r");
```
    
memorize the values of the file in the array, 

```c
// populate the array
for (size_t j = 0; j < nData && fscanf(stream: fl, format: " %f ,", &nums[j]) == 1; j++);
```  
    
get the min and MAX on a certain range and return an array of two value minDay and MAXDay

```c
size_t *get_minMax(float *arr, size_t start, size_t end){
    
    size_t *minMax = malloc(size: 2 * sizeof(size_t));
    
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
```
    
if the two value have no value, buyDay after sellDay, recontrol the two range and control which is more valuable 

```c
size_t *minMax_1 = get_minMax(arr: nums, start: 0, end: minMax[1]); // start to Max value
size_t *minMax_2 = get_minMax(arr: nums, start: minMax[0], end: nData); // min value to the end
``` 
    
at the end od the program remember to close the file and free the array

```c
// free memory
free(ptr: nums);
fclose(stream: fl);
return 0;
```
