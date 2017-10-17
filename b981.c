 /*
  * @file b981.c
  * @author Jason3e7
  * @algorithm string
  * @date 201710181009
  */

#include <stdio.h>
#include <string.h>

int main() {
	int i, length, out, temp, dotflag;
	char line[1000];
	while(scanf("%s", line) != EOF) {
		length = strlen(line);
		out = 0;
		if(length >= 5 && strstr(line, "hour") != NULL) { 
			for(i = 0; i < (length - 4); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%d\n", out * 3600000);
		} else if(length >= 4 && strstr(line, "min") != NULL) { 
			for(i = 0; i < (length - 3); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%d\n", out * 60000);
		
		} else if(length >= 3 && strstr(line, "ms") != NULL) { 
			for(i = 0; i < (length - 2); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%d\n", out);
		} else {
			temp = 0;
			dotflag = 0;
			for(i = 0; i < length; i++) {
				if('0' <= line[i] && line[i] <= '9') {
					temp *= 10;
					temp += (line[i] - '0');
				} else if(line[i] == 'h') {
					out += (temp * 3600000);
					temp = 0;
				} else if(line[i] == 'm') {
					out += (temp * 60000);
					temp = 0;
				} else if(line[i] == 's' && dotflag == 0) {
					out += (temp * 1000);
					temp = 0;
				} else if(line[i] == '.') {
					out += (temp * 1000);
					temp = 0;
					dotflag = 1;
				} else if(line[i] == 's' && dotflag == 1) {
					out += (temp * 100);
					temp = 0;
				}
			}
			printf("%d\n", out);
			
		}
	}
	return 0;
}



