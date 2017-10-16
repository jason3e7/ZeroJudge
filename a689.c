 /*
  * @file a689.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710161924
  */

#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		
		if(n > 100) {
			printf("Hey, DO NOT CHEAT.\n");
		} else if(n == 100) {
			printf("PERFECT >///<\n");
		} else if(90 <= n && n < 100) {
			printf("Good Job!\n");
		} else if(60 <= n && n < 90) {
			printf("Pass :)\n");
		} else if(n < 60) {
			printf("Need +%d Q_Q...\n", 60 - n);
		}
	}
	return 0;
}



