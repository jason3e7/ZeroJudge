/*
 * @file c109.c
 * @author Jason3e7
 * @date 201511041419
 */

#include <stdio.h>
#include <string.h>

int n, num[201];
char str[201];

void encode() {
	int i;
	char temp[201];
	for (i = 0; i < n; i++) 
		temp[num[i] - 1] = str[i];
	temp[n] = '\0';
	strcpy(str, temp);
}

int getTimes() {
	int i, j, temp[201], temp2[201], flag;
	for (i = 0; i < n; i++) 
		temp[i] = i + 1;
	for (i = 1; i <= 200; i++) {
		flag = 1;
		for (j = 0; j < n; j++) {
			temp2[num[j] - 1] = temp[j];
			if (num[j] != temp[j])
				flag = 0;
		}
		if (flag == 1)
			return i;
		for (j = 0; j < n; j++) { 
			temp[j] = temp2[j];
		}
	}
	return 1;
}

int main() {
	int i, k, len, times;
	while(scanf("%d", &n) != EOF) {
		if (n == 0) 
			break;
		for (i = 0; i < n; i++) 
			scanf("%d", &num[i]);
		times = getTimes();
		while(scanf("%d", &k)) {
			if (k == 0) 
				break;
			scanf(" %[^\n]", str);
			len = strlen(str);
			for (i = len; i < n; i++) 
				str[i] = ' ';
			str[n] = '\0';
			if (times != 1)
				k = k % times;
			for (i = 0; i < k; i++) 
				encode();
			printf("%s\n", str);
		}
	}
	return 0;
}
