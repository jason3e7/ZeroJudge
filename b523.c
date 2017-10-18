 /*
  * @file b523.c
  * @author Jason3e7
  * @algorithm string
  * @date 201710181426
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
	char temp[10001], line[500][10001];
	int point = 0, i, match;
	while(fix_fgets(temp, 100001) != NULL) {
		match = 0;
		for(i = 0; i < point; i++) {
			if(strcmp(line[i], temp) == 0) {
				match = 1;
				break;
			}
		}
		if(match == 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
			strcpy(line[point], temp);
			point++;
		}
	}
	return 0;
}



