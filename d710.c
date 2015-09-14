/*
 * @file d710.c
 * @author Jason3e7
 * @date 201509142219
 */

#include <stdio.h>
#include <string.h>

int main() {
	int n, m, i, j, flag;
	char car[20][2][20], temp[20];
	while(scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%s %s", &car[i][0], &car[i][1]);
		}
		for (i = 0; i < m; i++) {
			scanf("%s", &temp);
			if (strcmp(temp, "brand") == 0) {
				flag = 0;
			} else if (strcmp(temp, "color") == 0) {
				flag = 1;
			}
			scanf("%s", &temp);
			for (j = 0; j < n; j++) { 
				if (strcmp(temp, car[j][flag]) == 0) {
					printf("%s %s\n", car[j][0], car[j][1]);
				}
			}
		}
	}
	return 0;
}
