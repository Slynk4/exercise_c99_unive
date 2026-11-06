# arrays 

## objective

understand the behaviour of the arrays in c99
for matrix see [matrix](../multydimansionalArr/README.md)

## behaviour

case of study dinamyc pre-initialize, dinamyc not initialize and static

```c
int *arr = malloc(size: lenght * sizeof(int));                                      // dinamyc not initialize
    
int arr1[] = {[0]=1, [1]=2, [2]=3, [3]=4, [4]=5,[5]=6, [6]=7, [7]=8, [8]=9, [9]=10};// static
    
int *arr2 = calloc(nmemb: lenght, size: sizeof(int));                               // dinamyc pre-initialize
```

cases of the arrays:
- malloc    - dinamyc size and take the values in the free memory, not sure of the value in it 
- arr[]     - static size and take the value given
- calloc    - dinamyc size and heve the value all at 0, initialized on the

--- 

reallcation of the size of the arrays 

```c
arr = realloc(ptr: arr,size: lenght * sizeof(int));
arr2 = realloc(ptr: arr2, size: lenght * sizeof(int));

// give an error    
arr1 = realloc(arr1, 5 * sizeof(int)); // get an error array create statically
```

behaviour of the arrays:
- malloc, calloc    - resize because have dinamyc allocation
- arr[]             - give an error, because is static can't resize it 

## attention 

1. contro if the dinamyc allocation is gone well

```c 
if (arr == NULL)
    return 1;
```

2. free the dinamyc allocation array whene you stop using it 

```c
free(ptr: arr);
```
