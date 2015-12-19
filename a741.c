/*
 * @file a741.c
 * @author Jason3e7
 * @algorithm divideAndConquer
 * @date 201512192019
 */

#include <stdio.h>
#include <string.h>

char num[20];

int getSubNum(int begin, int digit) {
	int temp = num[begin] - '0';
	if (digit == 1 || begin == 0)
		return temp;
	return temp + (num[begin - 1] - '0') * 10;
}

int main() {
	int i, len, subNum[20], index, first, caseNum = 1;
	int map[4] = {2, 1, 2, 2};
	while (scanf("%s", &num) != EOF) {
		len = strlen(num);
		i = len - 1; 
		index = 0;
		while (i >= 0) {
			subNum[index] = getSubNum(i, map[index % 4]);
			i -= map[index % 4];
			index++;
		}
		printf("%4d. ", caseNum);
		first = 1;
		for (i = index - 1; i >= 0; i--) {
			if (subNum[i] == 0) {
				if (i % 4 == 0 && i != 0)
					printf(" kuti");
				continue;
			}
			if (first == 0)
				printf(" ");
			first = 0;
			if (i == 0) {
				printf("%d", subNum[i]);
				break;
			}
			switch (i % 4) {
				case 0:
					printf("%d kuti", subNum[i]);
					break;
				case 1:
					printf("%d shata", subNum[i]);
					break;
				case 2:
					printf("%d hajar", subNum[i]);
					break;
				case 3:
					printf("%d lakh", subNum[i]);
					break;
			}
		}
		if (first == 1)
			printf("0");
		printf("\n");
		caseNum++;
	}
	return 0;
}

