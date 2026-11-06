# bubble short 

inpementation of bubble short using

## inplementation

passing the pointer of the array 

```c
void bubbleshort(int* arr, size_t length){
    
    size_t i, j;
    
    // bubbleshort optimizzed 

    for (i = 0; i < length; i++){
            for(j = i; j < length; j++){
                if(arr[i] > arr[j]){
                    swap(x: &arr[i], y: &arr[j]);       // pass the pointer to the swap funtion of the element 
                }
            }
        }
}
``` 

used the srand funtion for seading the rand() funtion

```c
srand(seed: (unsigned)time(timer: NULL)); 

for(size_t i = 0; i < length; i++){
        arr[i] = rand() % 100;
    }
```
