 /*
  * @file d392_2.c
  * @author Jason3e7
  * @algorithm basic and input
  * @date 201710061532
  */

#include <stdio.h>
int main() {
	long int n, sum = 0;
	char temp = ' ';
	while(scanf("%ld", &n) != EOF) {
		sum += n;
		while(temp != EOF) {
			temp = getchar();
			if('0' <= temp && temp <= '9') {
				ungetc(temp, stdin);
				break;
			}
			if(temp == '\n' || temp == '\r') {
				printf("%ld\n", sum);
				sum = 0;
				break;
			}
		}
	}
	return 0;
}

