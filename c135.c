/*
 * @file c135.c
 * @author Jason3e7
 * @algorithm controlFlow
 * @date 201512121341
 */

#include <stdio.h>
#include <string.h>

char output[230][130];
int s, len;

void setDigit(int local, int line) {
	int i, baseL, baseH;
	baseL = local * (s + 2) + local;
	switch(line) {
		case 0:
			for(i = baseL + 1; i <= baseL + s; i++)
				output[0][i] = '-';
			return;
		case 1:
			for(i = 1; i <= s; i++)
				output[i][baseL] = '|';
			return;
		case 2:
			baseL += (s + 1);
			for(i = 1; i <= s; i++)
				output[i][baseL] = '|';
			return;
		case 3:
			baseH = s + 1;
			for(i = baseL + 1; i <= baseL + s; i++)
				output[baseH][i] = '-';
			return;
		case 4:
			for(i = s + 2; i < (2 * s) + 2; i++)
				output[i][baseL] = '|';
			return;
		case 5:
			baseL += (s + 1);
			for(i = s + 2; i < (2 * s) + 2; i++)
				output[i][baseL] = '|';
			return;
		case 6:
			baseH = (s + 1) * 2;
			for(i = baseL + 1; i <= baseL + s; i++)
				output[baseH][i] = '-';
			return;	
	}
	return;
}

int main() {
	int digit[10][7] = {
	1, 1, 1, 0, 1, 1, 1,
	0, 0, 1, 0, 0, 1, 0,
	1, 0, 1, 1, 1, 0, 1,
	1, 0, 1, 1, 0, 1, 1,
	0, 1, 1, 1, 0, 1, 0,
	1, 1, 0, 1, 0, 1, 1,
	1, 1, 0, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 1, 0,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 1, 1
	};

	int i, j, k, width, height;
	char num[9];
	while(scanf("%d", &s) != EOF) {
		scanf("%s", &num);
		if (s == 0 && strcmp(num, "0") == 0)
			break;
		for (i = 0; i < 230; i++)
			for (j = 0; j < 130; j++)
				output[i][j] = ' ';

		len = strlen(num);
		
		for (i = 0; i < len; i++) {
			for (j = 0; j < 7; j++) {
				if (digit[num[i] - '0'][j] == 1) {
					setDigit(i, j);
				}
			}
		}
				
		width = (s + 2) * len + (len - 1);
		height = 2 * s + 3;
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++) {
				printf("%c", output[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
