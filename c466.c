 /*
  * @file c466.c
  * @author Jason3e7
  * @algorithm string
  * @date 201802222305
  */

#include <stdio.h>
#include <string.h>

int main() {
	char line[1000001];
	int len;
	while(scanf("%s", line) != EOF) {
		len = strlen(line);
		if(line[len - 1] == '0') {
			printf("0\n");
			continue;
		}
		if(len % 2 == 1) {
			printf("%c\n", line[len - 1]);
		} else {
			printf("-%c\n", line[len - 1]);
		}
	}
	return 0;
}
