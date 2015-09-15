/*
 * @file d566.c
 * @author Jason3e7
 * @date 201509142245
 */

#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, k, nameArray[10000] = {0}, point, AC, ACfirst, flag;
	char name[10000][30], status[10000][3];
	while(scanf("%d", &n) != EOF) {
		point = 0;
		AC = 0;
		ACfirst = 0;
		for (i = 0; i < n; i++) 
			scanf("%s %s", &name[i], &status[i]);
		for (i = n - 1; i >= 0; i--) {
			flag = 0;
			for (j = 0; j < point; j++) 
				if (strcmp(name[i], name[nameArray[j]]) == 0) {
					flag = 1;
					break;
				}
			if (flag == 1)
				continue;
			if (strcmp(status[i], "AC") == 0) { 
				ACfirst++;
			} else {
				for (j = i - 1; j >= 0; j--) 
					if (strcmp(name[i], name[j]) == 0 && strcmp(status[j], "AC") == 0) { 
						AC++;
						break;
					}
			}
			nameArray[point] = i;
			point++;	
		}
		printf("%d%%\n", 100 * ACfirst / (AC + ACfirst));
	}
	return 0;
}
