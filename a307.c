 /*
  * @file a307.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801041024
  */

#include <stdio.h>
#include <string.h>

int main() {
	int i, begin, end, first;
	char line[1000];	
	while(scanf("%s", line) != EOF) {
		end = strlen(line) - 1;
		begin = 0;
		first = 1;
		if(line[begin] == '-') {
			printf("-");
			begin++;
		}
		for(i = end; i >= begin; i--) {
			if(line[i] == '0' && first == 1) {
				continue;
			}
			printf("%c", line[i]);
			first = 0;
		}
		printf("\n");
	}
	return 0;
}

