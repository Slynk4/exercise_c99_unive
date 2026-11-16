#include <stddef.h>
#include <stdio.h>

int sum_by_powers(int *arr, size_t lenght, int powerOf);
int get_nums(int *arr, size_t lenght, int powerOf, int pos);

int main (){
     
     int arr[] = {1,2,3,4,5,6,7,8,9,10};
     printf("%d\n", sum_by_powers(arr, 10, 2));

     return 0;
}

int sum_by_powers(int *arr, size_t lenght, int powerOf){
     return get_nums(arr, lenght, powerOf, 1);
}

int get_nums(int *arr, size_t lenght, int powerOf, int pos){
     if(lenght <= pos) return 0;
     if (pos == 0 || pos == 1) ++pos;
     return get_nums(arr, lenght, powerOf, pos << 2) + arr[pos];
}
