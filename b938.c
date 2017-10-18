 /*
  * @file b938.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710181130
  */

#include <stdio.h>

int main() {
	int n, m, i, j, temp, killFlag;
	int people[1000002];
	while(scanf("%d %d", &n, &m) != EOF) {
		for(i = 0; i < 1000002; i++) {
			people[i] = 1;
		}
		for(i = 0; i < m; i++) {
			scanf("%d", &temp);
			killFlag = 0;
			if(people[temp] != 0) {
				for(j = temp + 1; j <= n; j++) {
					if(people[j] == 1) {
						printf("%d\n", j);
						people[j] = 0;
						killFlag = 1;
						break;
					}
				}
			}
			if(killFlag == 0) {
				printf("0u0 ...... ?\n");
			}
		}
	}
	return 0;
}



