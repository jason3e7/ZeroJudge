 /*
  * @file b893.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710210038
  */

#include <stdio.h>
#include <math.h>

int main() {
	long int a, b, c, d, e, f, count;
	int i, flag, outFlag;
	while(scanf("%ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e, &f) != EOF) {
		if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
			printf("Too many... = =\"\n");
			continue;
		}
		flag = 0;
		outFlag = 0;
		for(i = -73; i <= 73; i++) {
			count = 0;
			count += a * pow(i, 5);
			count += b * pow(i, 4);
			count += c * pow(i, 3);
			count += d * pow(i, 2);
			count += e * pow(i, 1);
			count += f;
			if(flag == 0) {
				if(count > 0) {
					flag = 1;
				} else if(count < 0){
					flag = -1;
				}
				continue;
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
		}
		if(outFlag == 0) {
			printf("N0THING! >\\\\\\<\n");
		}
	}
	return 0;
}

