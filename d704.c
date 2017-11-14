 /*
  * @file d704.c
  * @author Jason3e7
  * @algorithm basic 
  * @date 201711150953
  * @note
1 => next 1
2 => 0 1 => 1 => 1 * 1 = 1 next 2
3 => 0 1 2 =>  2, 1 => 2 * 2 + 1 = 5 next 6 => 2 * 3
5 => 0 1 2 3 4 => 4, 2, 1 => 4 * 6 + 5 = 29 next 30 => 5 * 6
8 => 0 1 2 3 4 5 6 7 => 7, 4, 2, 1 => 7 * 30 + 4 * 6 + 2 * 2 + 1 = 239 next 240 => 8 * 30
13 => 0 ... 12 => 12, 7, 4, 2, 1 => 12 * 240 + 7 * 30 + 4 * 6 + 2 * 2 + 1 = 3119 next 3120 => 240 * 13	
	div[8] = 10904493600; > 2147483647
  */ 
 
#include <stdio.h>

int main() {
	int f1 = 3, f2 = 2, swap;
	int i, div[8];
	div[0] = 2;
	for(i = 1; i <= 7; i++) {
		div[i] = f1 * div[i - 1];
		swap = f1;
		f1 += f2;
		f2 = swap;
	}

	int n, first, temp;	
	while(scanf("%d", &n) != EOF) {
		if(n == 1) {
			printf("1\n");
			continue;
		}
		first = 1;
		for(i = 7; i >= 0; i--) {
			temp = n / div[i];
			n %= div[i];
			if(first == 0) {
				printf(",%d", temp);
			}
			if(first == 1 && temp != 0) {
				printf("%d", temp);
				first = 0;
			}
		}
		printf(",%d\n", n);
	}
	return 0;
}

