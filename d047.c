 /*
  * @file d047.c
  * @author Jason3e7
  * @algorithm big number 
  * @UVa 10070
  * @date 201711010942
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
	char line[100001];
	int length, i, number, flag, sum, bitDiff;
	while(fix_fgets(line, 100001) != NULL) {
		length = strlen(line);
		flag = 0;
		sum = 0;
		bitDiff = 0;
		number = 0;
		for(i = 0; i < length; i++) {
			sum += (line[i] - '0');
			if(i % 2 == 0) {
				bitDiff += (line[i] - '0');
			} else {
				bitDiff -= (line[i] - '0');
			}
		}
		number += line[length - 1] - '0';
		number += (line[length - 2] - '0') * 10;
		number += (line[length - 3] - '0') * 100;
		number += (line[length - 4] - '0') * 1000;
		if ((number % 4 == 0 && number % 100 != 0) || (number % 400 == 0)) {
			printf("This is leap year.\n");
			flag += 1;
		}
		if (number % 5 == 0 && sum % 3 == 0) {
			printf("This is huluculu festival year.\n");
			flag += 2;
		}
		if (number % 5 == 0 && bitDiff % 11 == 0 && flag % 2 == 1) {
			printf("This is bulukulu festival year.\n");
			flag += 4;
		}
		if (flag == 0) {
			printf("This is an ordinary year.\n");
		}
		printf("\n");
	}
	return 0;
}

