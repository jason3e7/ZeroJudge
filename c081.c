 /*
  * @file c081.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 102
  * @date 201710171120
  */

#include <stdio.h>

int main() {
	int bin[6][6] = {
	{0, 2, 3, 4, 7, 8},
	{0, 2, 4, 5, 6, 7},
	{0, 1, 3, 5, 7, 8},
	{0, 1, 4, 5, 6, 8},
	{1, 2, 3, 5, 6, 7},
	{1, 2, 3, 4, 6, 8}};
	char out[6][3] = {
	"GCB",
	"GBC",
	"CGB",
	"CBG",
	"BGC",
	"BCG"};

	int bottle[9], i, j, min, point, sum;
	while(scanf("%d", &bottle[0]) != EOF) {
		for(i = 1; i < 9; i++) {
			scanf("%d", &bottle[i]);
		}
		min = 2147483647;
		point = -1;
		for(i = 0; i < 6; i++) {
			sum = 0;
			for(j = 0; j < 6; j++) {
				sum += bottle[bin[i][j]];
			}
			if(sum <= min) {
				min = sum;
				point = i;
			}
		}
		for(i = 0; i < 3; i++) {
			printf("%c", out[point][i]);
		}
		printf(" %d\n", min);
	}
	return 0;
}



