 /*
  * @file c303.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803011039
  */

#include <stdio.h>
#include <string.h>

int main() {
	int n, i;
	char line[100001];
	while(scanf("%d", &n) != EOF) {
		scanf("%s", line);
		for(i = 0; i < n; i++) {
			if('A' <= line[i] && line[i] <= 'Z') {
				line[i] += 32;
			} else if('a' <= line[i] && line[i] <= 'z') {
				line[i] -= 32;
			}
		}
		printf("%s\n", line);
	}
	return 0;
}
