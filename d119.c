 /*
  * @file d119.c
  * @author Jason3e7
  * @algorithm DP
  * @date 201710231012
  */

#include <stdio.h>
#include <string.h>

char * fix_fgets(char * str, int n) {
	char * ret_val;
	int i;
	ret_val = fgets(str, n, stdin);
	if(ret_val) {
		for(i = 0; i < n; i++) {
			if(str[i] == '\n' || str[i] == '\r') {
				str[i] = '\0';
				break;
			}
		} 
	}
	return ret_val;
}

int main() {
	unsigned long long int out[50001];
	int coin[10] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
	int i, j, temp;
	for(i = 0; i < 50001; i++) {
		out[i] = 1;
	}
	for(i = 1; i < 10; i++) {
		temp = coin[i];
		for(j = temp; j < 50001; j++) {
			out[j] += out[j - temp];
		}
	}
	int length = 0, tempSum, flag, sum;
	char line[100001];
	while(fix_fgets(line, 100001) != NULL) {
		length = strlen(line);
		tempSum = 0;
		sum = 0;
		flag = 0;
		for(i = 0; i < length; i++) {
			if('0' <= line[i] && line[i] <= '9') {
				tempSum *= 10;
				tempSum += (line[i] - '0');
				flag = 1;
			} else {
				if(flag == 1) {
					sum += tempSum;
					tempSum = 0;
					flag = 0;
				} else {
					flag = 1;
				}
			}
		}
		sum += tempSum;
		if(sum == 0) {
			continue;
		}
		printf("%llu\n", out[sum] - 1);
	}
	return 0;
}

