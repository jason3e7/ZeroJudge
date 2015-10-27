/*
 * @file d681.c
 * @author Jason3e7
 * @date 201510271145
 */

#include <stdio.h>
#include <string.h>

int main() {
	char bin[6], line[1000];
	int i, len, flag, locate;
	while(scanf(" %[^\n]", &line) != EOF) {
		for (i = 0; i < 5; i++) {
			printf("%c", line[i]);
			bin[i] = line[i];
		}
		bin[5] = '\0';
		locate = 0;
		len = strlen(line);
		for (i = 5; i < len; i++) {
			if (line[i] != ' ') {
				if (line[i] == '1' || line[i] == '0') {
					printf("%c", line[i]);
					if (flag == 1) {
						if (bin[locate] == '1' && line[i] == '1')
							bin[locate] = '1';
						else
							bin[locate] = '0';
					} else if (flag == 2) {	
						if (bin[locate] == '1' || line[i] == '1')
							bin[locate] = '1';
						else
							bin[locate] = '0';
					}
					locate++;
				} else if (line[i] == 'a'){
					printf("&&");
					i += 2;
					flag = 1;
					locate = 0;
				} else if (line[i] == 'o') {
					printf("||");
					i += 1;
					flag = 2;
					locate = 0;
				}
			}
		}
		printf(" = %s\n", bin);
	}
	return 0;
}
