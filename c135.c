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
	int i, j, beginL = 0, beginH = 0, endL = 0, endH = 0;
	char symbol;

	beginL = local * (s + 3);
	switch(line) {
		case 0:
		case 3:
		case 6:
			symbol = '-';
			beginH = (s + 1) * (line / 3);
			endH = beginH;
			
			beginL += 1;
			endL = beginL + s - 1;
			break;
		case 1:
		case 4:
		case 2:
		case 5:
			symbol = '|';
			if (line == 2 || line == 5) 	
				beginL += (s + 1);
			endL = beginL;
			
			beginH = 1;
			endH = s;
			if (line == 4 || line == 5) {
				beginH += (s + 1);
				endH += (s + 1);
			}
			break;
	}
	for (i = beginH; i <= endH; i++)
		for (j = beginL; j <= endL; j++)
			output[i][j] = symbol;
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
				
		width = (s + 3) * len - 1;
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
