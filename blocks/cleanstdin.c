 /*
  * @file cleanstdin.c
  * @author Jason3e7
  * @algorithm input
  * @date 201710121255
  */

#include <stdio.h>
void clean_stdin(void)
{
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		clean_stdin();
		printf("'%c'", getchar());
	}
	return 0;
}

