# matrix

understanding to matrix behaveour

## allocation 

1. compleate dinamyc and two dimansional
this worcks whit the arr[][] 

```c
int **arr = malloc(size: row * sizeof *arr);

for (size_t i = 0; i < row; i++) {
    arr[i] = malloc(size: column * sizeof *arr[i]);
}
```

2. mono dimensional
this worck olnly whit arr[] 

```c
int *arr = malloc(size: (row * column) * sizeof(int));
```

for change row use

```c
for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < column; j++) {
        printf(format: "value %d \n", arr[j * (i * sizeof(int))]);
    }
}
```

3. static
worck whit arr[][]

```c
int **arr = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
};
```

