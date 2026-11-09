# string 

a small project to understand string in c 

## objective 
[comparazione](main.c)
compare two string returning the percent of the letter that are equal

```c
size_t len1 = strlen(s: str1);
size_t len2 = strlen(s: str2);
size_t size = len1 < len2 ? len1 : len2;
size_t matches = 0;

for (size_t i = 0; i < size; i++) {
    if (str1[i] == str2[i]) {
        matches++;
    }
}
```

[iterazione](alfabetic.c)

per iterare un array si puo utilizzare un _while (*elemento)_ 

```c
while ( *lett ) {
    seen[ *lett - 'a' ] = true;
    lett++;
}    
```

pass all the char in a given string and memorize it in an array of the size of the alfabet 

### N.B.

the array in origin have boolean value, if you use an while cycle that dosen't worck
it dosen't worck because the ``` *arr ``` can assume 0 and go out of the cycle 

```c
while ( *arr ) {
        if (*arr++ == false) {
        printf(format: "arr %d \n", *arr);           
        return false;
    }
}       
```      
