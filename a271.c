 /*
  * @file a271.c
  * @author Jason3e7
  * @algorithm basic and input
  * @date 201710071024
  */

#include <stdio.h>
#include <string.h>
void clean_stdin(void)
{
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int main() {
	int x, y, z, w, n, m, number;
	char line[1000];
	int length, i, poison;
	while(scanf("%d", &number) != EOF) {
		while(number--) {
			scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &n ,&m);
			clean_stdin();
			fgets(line, 1000, stdin);
			length = strlen(line);
			poison = 0;
			for(i = 0; i < length; i++) {
				if('0' <= line[i] && line[i] <= '4') {
					m -= poison; 
				}
				if(m <= 0) {
					break;
				}
				switch(line[i]) {
					case '0' :
						break;
					case '1' :
						m += x; 
						break;
					case '2' :
						m += y; 
						break;
					case '3' :
						m -= z; 
						break;
					case '4' :
						m -= w;
						poison += n; 
						break;
					default :
						break;
				}
			}
			if(m <= 0) {
				printf("bye~Rabbit\n");
			} else {
				printf("%dg\n", m);
			}
		}
	}
	return 0;
}

