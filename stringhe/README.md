# string 

a small project to understand string in c 

## objective 

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
