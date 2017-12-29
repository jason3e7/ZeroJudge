 /*
  * @file b847.c
  * @author Jason3e7
  * @algorithm float
  * @date 201712301149
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
	char line[10000];
	int len, i, c[26], count;
	while(fix_fgets(line, 10000) != NULL) {
		len = strlen(line);
		for(i = 0; i < 26; i++) {
			c[i] = 0;
		}
		for(i = 0; i < len; i++) {
			if('A' <= line[i] && line[i] <= 'Z') {
				c[line[i] - 'A']++;
			}
			if('a' <= line[i] && line[i] <= 'z') {
				c[line[i] - 'a']++;
			}
		}
		count = c[25];
		for(i = 0; i < 25; i++) {
			printf("%d ", c[i]);
			count += c[i];
		}
		printf("%d\n", c[25]);
		for(i = 0; i < 25; i++) {
			printf("%.2f ", (double)c[i] / count * 100);
		}
		printf("%.2f\n", (double)c[25] / count * 100);
	}
	return 0;
}
