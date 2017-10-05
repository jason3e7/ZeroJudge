 /*
  * @file d166.c
  * @author Jason3e7
  * @algorithm basic and input
  * @date 201710061014
  */

#include <stdio.h>
int main() {
	int n, i, input[51], output[51], j, k, count;
	char temp;
	for(i = 0; i < 51; i++) {
		input[i] = -1;
		output[i] = -1;
	}
	i = 0;
	while(scanf("%d", &n) != EOF) {
		if(n == -1) {
			break;
		}
		input[i] = n;
		i++;
		temp = getchar();
		if(temp != '\n' && temp != '\r') {
			continue;
		}
		for(j = 0; j < i; j++) {
			for(k = 0, count = 0; k < i; k++) {
				if(input[j] == count) {
					while(output[k] != -1) {
						k++;
					}
					output[k] = j + 1;
					break;
				}
				if(output[k] == -1) {
					count++;
				}
			}
		}
		for(j = 0; j < (i - 1); j++) {
			printf("%d ", output[j]);
		}
		printf("%d\n", output[i - 1]);
		for(i = 0; i < 51; i++) {
			input[i] = -1;
			output[i] = -1;
		}
		i = 0;
		continue;
	}
	return 0;
}

