 /*
  * @file d486.c
  * @author Jason3e7
  * @algorithm basic 
  * @date 201711142017
  */ 
 
#include <stdio.h>

int num[1001] = {0}, point = 0;

void f() {
	int i, temp[1001], tPoint = 0, flag = 0;
	for(i = 0; i < point; i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("f(%d)", num[i]);

		if(num[i] >= 2) {
			temp[tPoint] = num[i] - 1;
			temp[tPoint + 1] = num[i] - 2;
			tPoint += 2;
			flag = 1;
		} else {
			temp[tPoint] = num[i];
			tPoint++;
		}	
	}
	printf("\n");

	for(i = 0; i < tPoint; i++) {
		num[i] = temp[i];
	}
	point = tPoint;	
	if(flag == 1) {
		f();
	}
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		if(n == 1) {
			printf("f(1)\nf(1) = 1\n\n");
			continue;
		}	
		printf("f(%d)\n", n);
		num[0] = n - 1;
		num[1] = n - 2;
		point = 2;
		f();
		printf("f(%d) = %d\n\n", n, point);
	}
	return 0;
}

