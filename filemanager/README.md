# file understand 

## how to use it

- open the stream for write and/or read a file 

w   - for write in a file 
r   - for read in a file 
wr  - for read and write in a file 

```c
FILE  *fp = fopen(filename: "text.txt", modes: "wr");
``` 

- for write into a file 

fputc   - write an element at the time 

```c
char str[] = "hello world";

for (size_t i = 0; sizeof(str) > i; i++) {

    fputc(c: str[i], stream: fp);

    }
```

- for read a file see [read file](../class_es/README.md) 
