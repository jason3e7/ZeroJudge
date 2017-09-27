 /*
  * @file d041.c
  * @author Jason3e7
  * @algorithm IO
  * @UVa 11219
  * @date 201709281021
  */

#include <stdio.h>

int main() {
	int n, i;
	while(scanf("%d", &n) != EOF) {
		for(i = 1; i <= n; i++) {
			int nowD, nowM, nowY, birD, birM, birY, age;
			scanf("%d/%d/%d", &nowD, &nowM, &nowY);
			scanf("%d/%d/%d", &birD, &birM, &birY);
			printf("Case #%d: ", i);
			if((birY > nowY) || (birY == nowY && birM > nowM) || (birY == nowY && birM == nowM && birD > nowD)) {
				printf("Invalid birth date\n");
				continue;
			}
			age = nowY - birY;
			if((birM > nowM) || (birM == nowM && birD > nowD)) {
				age--;
			}
			if(age > 130) {
				printf("Check birth date\n");
				continue;
			}
			printf("%d\n", age);
		}
	}
	return 0;
}
