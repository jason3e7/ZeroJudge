/*
 * @file b558.c
 * @author Jason3e7
 * @date 201511051007
 */

#include <stdio.h>

int main() {
	int i, num[502], n;
	num[1] = 1;
	for (i = 2; i <= 500; i++) 
		num[i] = num[i - 1] + i - 1;
	while(scanf("%d", &n) != EOF) 
		printf("%d\n", num[n]);
	return 0;
}
