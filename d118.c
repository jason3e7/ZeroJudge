 /*
  * @file d118.c
  * @author Jason3e7
  * @algorithm string
  * @date 201802201002
  */

#include <stdio.h>
#include <string.h>

char line[36000001];

int findNum(int begin, int end, char target) {
	int i;
	for(i = begin; i < end; i++) {
		if(line[i] == target) {
			printf("%c", target);
			return i;
		}
	}
	return findNum(begin, end, target - 1);
}

int main() {
	int n, len, current, i;
	while(scanf("%s %d", line, &n) != EOF) {
		current = 0;
		len = strlen(line);
		while(n--) {
			current = findNum(current, len - n, '9') + 1;
			if((current + n) == len) {
				for(i = current; i < len; i++) {
					printf("%c", line[i]);
				}
				break;
			}
		}
		printf("\n");	
	}
	return 0;
}
