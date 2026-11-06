#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* --------------------------------------------------------------------------*/
/**
 * @brief 	compare two string, string1 and string2 
 *
 * @Param str1		
 * @Param str2		
 *
 * @Returns  	the percent of the equals of the two strings range 0 ... 100
 */
/* ----------------------------------------------------------------------------*/
float compare(char *str1, char *str2);

int main(){

	printf("equals %.2f \n", compare("ciao1", "ciao2"));

	return 0;
}

float compare(char *str1, char *str2){
	
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
    	size_t size = len1 < len2 ? len1 : len2;
    	size_t matches = 0;

    	for (size_t i = 0; i < size; i++) {
        	if (str1[i] == str2[i]) {
            		matches++;
        	}
    	}

    	size_t longest = len1 > len2 ? len1 : len2;

    	if (longest == 0) {
        	return -1;  // Both strings are empty
    	}

    	return 100.0f * (float)matches / (float)longest;
}

