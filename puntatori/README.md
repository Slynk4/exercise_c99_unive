# pointer

basic project for understand pointer 

## usage 

pass the address of the value for direct modification 

```c
int x = 90;
printf(format: "x: d\n", x);

azzera(p: &x);
printf(format: "x: %d\n", x);
```

funtion that request a integer pointer, and modify the value 
```c
void azzera(int *p){
    
            *p = 0;
    }
```

output: 

```
x: 90
x: 0
```

