 /*
  * @file c007.c
  * @author Jason3e7
  * @algorithm string 
  * @UVa 272
  * @date 201710311312
  */

#include <stdio.h>
#include <string.h>

char * fix_fgets(char * str, int n) {
	char * ret_val;
	int i;
	ret_val = fgets(str, n, stdin);
	if(ret_val) {
		for(i = 0; i < n; i++) {
			if(str[i] == '\n' || str[i] == '\r') {
				str[i] = '\0';
				break;
			}
		} 
	}
	return ret_val;
}

int main() {
	int flag = 1, i, length;
	char line[10001];
	while(fix_fgets(line, 10001) != NULL) {
		length = strlen(line);
		for(i = 0; i < length; i++) {
			if(line[i] == '"') {
				if(flag == 1) {
					printf("``");
					flag = 2;
				} else {
					printf("''");
					flag = 1;
				}
			} else {
				printf("%c", line[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

