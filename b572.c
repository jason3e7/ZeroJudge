/*
 * @file d572.c
 * @author Jason3e7
 * @date 201510031127
 */

#include <stdio.h>

int main() {
	int bh, bm, eh, em, mins, n;
	while(scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d %d %d %d %d", &bh, &bm, &eh, &em, &mins);
			bm += mins;
			if (bm >= 60) {
				bm -= 60;
				bh++;
			}
			if (bh > eh || (bh == eh && bm > em)) 
				printf("No\n");
			else 
				printf("Yes\n");
		}
	}
	return 0;
}
