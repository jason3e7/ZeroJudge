 /*
  * @file b537.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710191043
  */

#include <stdio.h>

int main() {
	int number[1000][2], i;
	number[1][0] = 1;
	number[1][1] = 1;
	for(i = 2; i < 100; i++) {
		if(i % 2 == 0) {
			number[i][0] = number[i / 2][0] + number[i / 2][1];
			number[i][1] = number[i / 2][1];
		} else {
			number[i][0] = number[i - 1][1];
			number[i][1] = number[i - 1][0];
		}
		printf("%d => %d %d\n", i, number[i][0], number[i][1]);
	}
	return 0;
}



