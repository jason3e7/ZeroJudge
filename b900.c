 /*
  * @file b900.c
  * @author Jason3e7
  * @algorithm array
  * @date 201802120813
  */

#include <stdio.h>
#include <string.h>

int main() {
	int i, j, w, h, number[10], temp, len, local;
	char line[20];
	while(scanf("%d %d", &w, &h) != EOF) {
		for(i = 0; i < w; i++) {
			number[i] = i + 1;
		}
		for(j = 0; j < h; j++) {
			scanf("%s", line);
			len = strlen(line);
			for(i = 0; i < len; i++) {
				if (line[i] == '-') {
					local = i / 2;
					temp = number[local];
					number[local] = number[local + 1];
					number[local + 1] = temp;
				}
			}
		}
		for(i = 1; i <= w; i++) {
			for(j = 0; j < w; j++) {
				if(number[j] == i) {
					if(i == 1) {
						printf("%d", j + 1);
					} else {
						printf(" %d", j + 1);
					}
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}



