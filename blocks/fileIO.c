 /*
  * @file IO.c
  * @author Jason3e7
  * @algorithm fileIO
  * @date 201711071457
  */

#include <stdio.h>

char* fix_fgets(char* str, int n) {
	char* ret_val;
	int i;
	ret_val = fgets(str, n, stdin);
	if(ret_val) {
		for(i = 0; i < n; i++) {
			if(str[i] == '\n' || str[i] == '\r') {
				str[i] = '\0';
				break;
			}
		} 
	}
	return ret_val;
}

int main() {
	char line[10001];
	FILE* fpInput;
	FILE* fpOutput;
	fpInput = fopen("./input.txt", "r");
	fpOutput = fopen("./output.txt", "a");
	//while(fix_fgets(line, 10001) != NULL) {
	while(fgets(line, 10001, fpInput) != NULL) {
		//printf("%s\n", line);
		fputs(line, fpOutput);
	}
	fclose(fpInput);
	fclose(fpOutput);
	return 0;
}

