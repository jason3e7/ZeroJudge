 /*
  * @file a687.c
  * @author Jason3e7
  * @algorithm big number
  * @date 201711091042
  */

#include <stdio.h>
#include <string.h>

int main() {
	int length, i, overFlag;
	char temp[10001], line[10001];
	while(scanf("%s", temp) != EOF) {
		if(strlen(temp) == 1 && temp[0] == 'A') {
			continue;
		}
		scanf("%s", line);
		scanf("%s", temp);
		length = strlen(line);
		overFlag = 0;
		for(i = length - 1; i >= 0; i--) {
			line[i] += (temp[i] - 'A');
			if(line[i] > 'Z') {
				line[i] -= 26;
				if(i == 0) {
					overFlag = 1;
					break;
				} 
				line[i - 1]++;
			} 
		}
		if(overFlag == 1) {
			printf("B%s\n", line);
		} else {
			printf("%s\n", line);
		}			
	}
	return 0;
}

