 /*
  * @file a217.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803160141
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

int isSymbol(char c) {
	if(c == ' ' || c == ',' || c == '.' || c == '!' || c == '?') {
		return 1;
	}
	return 0;
}

int main() {
	char line[10001];
	int i, len, flag;
	while(fix_fgets(line, 10001) != NULL) {
		flag = 1;
		len = strlen(line);
		for(i = 0; i < len; i++) {
			if(flag == 1 && ('a' <= line[i] && line[i] <= 'z')) {
				line[i] -= 32;
				flag = 0;
				continue;
			} 
			if(line[i] == '.' || line[i] == '!' || line[i] == '?') {
				flag = 1;
				continue;
			}
			if(line[i] == 'i') {
				if(i > 0) {
					if(isSymbol(line[i - 1]) == 0) {
						continue;
					}
				}
				if(i + 1 < len) {
					if(isSymbol(line[i + 1]) == 0) {
						continue;
					}
				}
				line[i] -= 32;
			}
		}
		printf("%s\n", line);
	}
	return 0;
}
