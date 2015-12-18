/*
 * @file d167.c
 * @author Jason3e7
 * @algorithm enumeration
 * @date 201512181132
 */

#include <stdio.h>
#include <string.h>

int main() {
	int i, j, len, temp;
	char ans[10], str[1000];
	while (scanf(" %[^\n]s", &str) != EOF) {
		printf("___________\n");
		len = strlen(str);
		for (i = 0; i < len; i++) {
			temp = str[i];
			for (j = 0; j < 9; j++) {
				if (j == 3) {
					ans[8 - j] = '.';
					continue;
				}
				if (temp % 2 == 1)
					ans[8 - j] = 'o';
				else 
					ans[8 - j] = ' ';
				temp /= 2;
			}
			ans[9] = '\0';
			printf("|%s|\n", ans);
		}
		printf("|    o. o |\n");
		printf("___________\n");
	}
	return 0;
}

