/*
 * @file b524.c
 * @author Jason3e7
 * @date 201510200903
 */

#include <stdio.h>
#include <string.h>


int abs(int n) {
	if (n < 0)
		return -1 * n;
	return n;
}

int main() {
	char str[100001];
	int output, len, i, locate;
	while(scanf("%s", &str) != EOF) {
		len = strlen(str);
		locate = 0;
		output = 0;
		for (i = 0; i < len; i++) {
			if (str[i] == 'y' ) {
				output += abs(i - locate);
				locate += 3;
			}
		}
		printf("%d\n", output);
	}
	return 0;
}
