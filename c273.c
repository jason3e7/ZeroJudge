 /*
  * @file c273.c
  * @author Jason3e7
  * @algorithm string
  * @date 201802210932
  */

#include <stdio.h>
#include <string.h>

char* fix_fgets(char* str, int n) {
	char* ret_val;
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
	char line[100];
	int i, len, r, flag = 0;
	while(fix_fgets(line, 100) != NULL) {
		r = 0;
		len = strlen(line);
		for(i = 0; i < len; i++) {
			if(i % 2 == 0) {
				r += (line[i] - '0');
			} else {
				r -= (line[i] - '0');
			}
		}
		flag = 1;
		printf("%d\n", r);
	}
	if(flag == 0) {
		printf("I finish the homework.\n");
	}
	return 0;
}
