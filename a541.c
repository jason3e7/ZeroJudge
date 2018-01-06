 /*
  * @file a541.c
  * @author Jason3e7
  * @algorithm string
  * @date 201801061859
  * @note array 20 NA
  */

#include <stdio.h>
#include <string.h>

int main() {
	char w[70000][30], temp[30];
	int n, i, q, flag;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", w[i]);
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%s", temp);
		flag = 0;
		for(i = 0; i < n; i++) {
			if(strcmp(temp, w[i]) == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("yes\n");
		} else {
			printf("no\n");
			strcpy(w[n], temp);
			n++;
		}
	}
	return 0;
}

