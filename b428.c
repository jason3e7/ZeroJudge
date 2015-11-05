/*
 * @file d428.c
 * @author Jason3e7
 * @date 201509242318
 */

#include <stdio.h>
#include <string.h>

int main() {
	char a[1000], b[1000];
	int output;
	while(scanf("%s", &a) != EOF) {
		scanf("%s", &b);
		output = b[0] - a[0];
		if (output < 0)
			output += 26;
		printf("%d\n", output);
	}
	return 0;
}

