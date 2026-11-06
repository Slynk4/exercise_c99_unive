#include <stddef.h>
#include <stdio.h>
#include <uchar.h>

int main(){

	FILE *fp;
	
	char str[] = "hello world";

	fp = fopen("text.txt", "wr");
	
	for (size_t i = 0; sizeof(str) > i; i++) {
	
		fputc(str[i], fp);
	}


	fclose(fp);

return 0;
}

