/*
 * @file d681.c
 * @author Jason3e7
 * @date 201510271145
 */

#include <stdio.h>
#include <string.h>

int main() {
	char bin[6], line[1000], output[1000], outCount;
	int i, len, flag, locate;
	while(scanf(" %[^\n]", &line) != EOF) {
		for (i = 0; i < 1000; i++)
			output[i] = '\0';
		for (i = 0; i < 5; i++) {
			bin[i] = line[i];
			output[i] = line[i];
		}
		outCount = 5;
		locate = 0;
		len = strlen(line);
		for (i = 5; i < len; i++) {
			if (line[i] != ' ') {
				if (line[i] == '1' || line[i] == '0') {
					output[outCount] = line[i];
					outCount++;
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
					output[outCount] = '&';
					output[outCount + 1] = '&';
					outCount += 2;
					i += 2;
					flag = 1;
					locate = 0;
				} else if (line[i] == 'o') {
					output[outCount] = '|';
					output[outCount + 1] = '|';
					outCount += 2;
					i += 1;
					flag = 2;
					locate = 0;
				}
			}
		}
		printf("%s = %s\n", output, bin);
	}
	return 0;
}
