 /*
  * @file b982.c
  * @author Jason3e7
  * @algorithm string
  * @date 201710181009
  */

#include <stdio.h>
#include <string.h>

int main() {
	unsigned long long out, temp;
	int i, length, dotflag;
	char line[1000];
	while(scanf("%s", line) != EOF) {
		length = strlen(line);
		out = 0;
		if(length >= 5 && strstr(line, "byte") != NULL) { 
			dotflag = 0;
			for(i = 0; i < (length - 4); i++) {
				if (line[i] == '.') {
					out *= 8;
					out += (line[i + 1] - '0');
					dotflag = 1;
					break;
				}
				out *= 10;
				out += (line[i] - '0');
			}
			if(dotflag == 0) {
				out *= 8;
			}
			printf("%llu\n", out);
		} else if(length >= 4 && strstr(line, "bit") != NULL) { 
			for(i = 0; i < (length - 3); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%llu\n", out);
		
		} else if(length >= 3 && strstr(line, "gb") != NULL) { 
			for(i = 0; i < (length - 2); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%llu\n", out * 8000000000);
		} else if(length >= 3 && strstr(line, "mb") != NULL) { 
			for(i = 0; i < (length - 2); i++) {
				out *= 10;
				out += (line[i] - '0');
			}
			printf("%llu\n", out * 8000000);
		} else if(length >= 3 && strstr(line, "kb") != NULL) { 
			dotflag = 0;
			for(i = 0; i < (length - 2); i++) {
				if (line[i] == '.') {
					out *= 8000;
					out += ((line[i + 1] - '0') * 800);
					dotflag = 1;
					break;
				}
				out *= 10;
				out += (line[i] - '0');
			}
			if(dotflag == 0) {
				out *= 8000;
			}
			printf("%llu\n", out);
		} else {
			temp = 0;
			for(i = 0; i < length; i++) {
				if('0' <= line[i] && line[i] <= '9') {
					temp *= 10;
					temp += (line[i] - '0');
				} else if(line[i] == 'g') {
					out += (temp * 8000000000);
					temp = 0;
				} else if(line[i] == 'm') {
					out += (temp * 8000000);
					temp = 0;
				} else if(line[i] == 'k') {
					out += (temp * 8000);
					temp = 0;
				}
			}
			printf("%llu\n", out);
		}
	}
	return 0;
}



