 /*
  * @file b893.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710210038
  * @test case
1 -4 -1 16 -12 0
  */

#include <stdio.h>

int main() {
	long int count, temp;
	int i, j, k, flag, outFlag, n[6];
	while(scanf("%d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5]) != EOF) {
		if(n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0 && n[4] == 0 && n[5] == 0) {
			printf("Too many... = =\"\n");
			continue;
		}
		flag = 0;
		outFlag = 0;
		for(i = -73; i <= 73; i++) {
			count = 0;
			for(j = 0; j < 6; j++) {
				temp = n[j];
				for(k = 5 - j; k > 0; k--) {
					temp *= i; 
				}
				count += temp;
			}
			if(count == 0) {
				printf("%d %d\n", i, i);
				flag = 0;
				outFlag = 1;
				continue;
			}
			if((count > 0 && flag == -1) || (count < 0 && flag == 1)){
				printf("%d %d\n", i - 1, i);
				flag *= -1;
				outFlag = 1;
			} 
			if(count > 0) {
				flag = 1;
			} else if(count < 0){
				flag = -1;
			}
		}
		if(outFlag == 0) {
			printf("N0THING! >\\\\\\<\n");
		}
	}
	return 0;
}

