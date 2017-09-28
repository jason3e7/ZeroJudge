 /*
  * @file d186.c
  * @author Jason3e7
  * @algorithm number
  * @UVa 11461
  * @date 201709291125
  */

#include <stdio.h>

int main() {
	int a, b, i, out, aPoint, bPoint;
	int square[350] = {0}; 
	for(i = 1; i < 350; i++) {
		square[i] = i * i;
	}
	while(scanf("%d %d", &a, &b) != EOF) {
		if(a == 0 && b == 0)
			break;
		out = 0, aPoint = 0, bPoint = 0;
		for(i = 1; i < 350; i++) {
			if(aPoint != 0 && bPoint != 0)
				break;
			if(aPoint == 0 && a <= square[i]) {
				aPoint = i;
			}
			if(bPoint == 0 && b <= square[i]) {
				bPoint = i;
				if (b < square[i])
					bPoint--;
			}
		}
		printf("%d\n", bPoint - aPoint + 1);
	}
	return 0;
}
