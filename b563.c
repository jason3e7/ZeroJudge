/*
 * @file b563.c
 * @author Jason3e7
 * @date 201510271042
 */

#include <stdio.h>

int main() {
	int num, i, change[101][2], j, count;;
	while(scanf("%d", &num) != EOF) {
		count = 0;
		for (i = 0; i < num; i++) {
			scanf("%d", &change[i][0]);
			scanf("%d", &change[i][1]);
		}
		for (i = 0; i < num; i++) {
			if (change[i][0] == 0)
				continue;
			for (j = i + 1;j < num; j++) {
				if (change[j][0] == 0)
					continue;
				if (change[i][0] == change[j][1] && change[i][1] == change[j][0]) {
					count++;
					change[i][0] = 0;
					change[i][1] = 0;
					change[j][0] = 0;
					change[j][1] = 0;
					break;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
