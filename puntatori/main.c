#include <stdio.h>

void azzera(int *p){

	*p = 0;
}

int main(){

	int x = 90;

	printf("%d\n", x);

	azzera(&x);

	printf("%d\n", x);

	
return 0;
}

