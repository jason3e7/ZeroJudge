 /*
  * @file a135.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 12250
  * @date 201712011514
  */

#include <stdio.h>
#include <string.h>

int main() {
	char line[20];
	int count = 1;
	while(scanf("%s", line) != EOF) {
		if(strcmp(line, "#") == 0) {
			break;
		}
		printf("Case %d: ", count);
		if(strcmp(line, "HELLO") == 0) {	
			printf("ENGLISH\n");
		} else if(strcmp(line, "HOLA") == 0) {
			printf("SPANISH\n");
		} else if(strcmp(line, "HALLO") == 0) {
			printf("GERMAN\n");
		} else if(strcmp(line, "BONJOUR") == 0) {
			printf("FRENCH\n");
		} else if(strcmp(line, "CIAO") == 0) {
			printf("ITALIAN\n");
		} else if(strcmp(line, "ZDRAVSTVUJTE") == 0) {
			printf("RUSSIAN\n");
		} else {
			printf("UNKNOWN\n");
		}
		count++;
	}
	return 0;
}

