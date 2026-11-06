#include <stdio.h>

void azzera(int *p){

	*p = 0;
}

int main(){

	int x = 90;

	printf("x: d\n", x);

	azzera(&x);

	printf("x: %d\n", x);

	
return 0;
}

