 /*
  * @file b593.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710262344
  * @note c077
  */

#include <stdio.h>
#include <string.h>

int num[26];

void nextArray(int lineNum) {
	int i; 
	int temp[26], count = num[25];
	temp[25] = count;
	for(i = 24; i >= lineNum; i--) {
		count += num[i];
		temp[i] = count;
	}
	for(i = 0; i < lineNum; i++) {
		temp[i] = 0;
	}
	memcpy(num, temp, sizeof(temp));
	return;
}

int getBase(int length) {
	int i, base = 1, lineNum = 1;
	for(i = 0; i < 26; i++) {
		num[i] = 1;
	}
	length -= 1;
	while(length--) {
		for(i = 0; i < 26; i++) {
			base += num[i];
		}
		nextArray(lineNum);
		lineNum++;
	}
	return base;
}

int getDiff(int length, char line[]) {
	int i, j, lineNum = 1, bitDiff = 0, diffSum = 0, begin = 0;
	for(i = 0; i < 26; i++) {
		num[i] = 1;
	}
	for(i = length - 1; i > 0; i--) {
		bitDiff = line[i] - line[i - 1] - 1; 
		begin = line[i - 1] - 'a' + lineNum;
		for(j = 0; j < bitDiff; j++) {
			diffSum += num[begin + j];
		}
		nextArray(lineNum);
		lineNum++;
	}
	bitDiff = line[0] - 'a';
	begin = lineNum - 1;
	for(i = 0; i < bitDiff; i++) {
		diffSum += num[begin + i];
	}
	return diffSum;
}

int main() {
	int i, length, flag;
	char line[26];
	while(scanf("%s", line) != EOF) {
		if(line[0] == '0') {
			break;
		}
		length = strlen(line);
		flag = 0;
		for(i = 1; i < length; i++) {
			if(line[i - 1] > line[i]) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("0\n");
			continue;
		}
		printf("%d\n", getBase(length) + getDiff(length, line));
	}
	return 0;
}

