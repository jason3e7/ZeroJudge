/*
 * @file b677.c
 * @author Jason3e7
 * @date 201511171024
 */

#include <stdio.h>
#include <string.h>

int main() {
	int n, i;
	char str[101][101];
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%s", &str[i]);
		for (i = n - 1; i >= 0; i--)
			printf("%s\n", str[i]);
	}
	return 0;
}

