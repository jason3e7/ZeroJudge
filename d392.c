 /*
  * @file d392.c
  * @author Jason3e7
  * @algorithm input
  * @date 201710061459
  */

#include <stdio.h>
#include <string.h>
int main() {
	char line[100000];
	int length, i, flag;
	long int sum = 0, temp;
 	while(fgets(line, 100000, stdin) != NULL) {
		length = strlen(line);
		line[length-1] = '\0';
		temp = 0;
		flag = 0;
		for(i = 0; i < length; i++) {
			if('0' <= line[i] && line[i] <= '9') {
				flag = 1;
				temp *= 10;
				temp += (line[i] - '0');
			} else {
				if(flag == 1) {
					sum += temp;
					temp = 0;
					flag = 0;
				}
			}
		}
		printf("%ld\n",sum);
		sum = 0;
	}
	return 0;
}

