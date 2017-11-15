 /*
  * @file d326.c
  * @author Jason3e7
  * @algorithm bitwise operator 
  * @date 201711161150
  */ 
 
#include <stdio.h>

int set_bit(int v, int b) {
	return (v | (1 << b));
}

int unset_bit(int v, int b) {
	return v - (v & (1 << b));
}

int check_bit(int v, int a, int b) {
	return ((v >> b) & 1);
}

void test() {
	printf("%d\n", set_bit(1, 0));
	printf("%d\n", set_bit(2, 0));
	printf("%d\n", set_bit(3, 0));
	printf("%d\n", set_bit(4, 0));
	
	printf("%d\n", set_bit(1, 1));
	printf("%d\n", set_bit(2, 1));
	printf("%d\n", set_bit(3, 1));
	printf("%d\n", set_bit(4, 1));
	printf("%d\n", set_bit(1, 31));
	
	printf("%d\n", unset_bit(1, 0));
	printf("%d\n", unset_bit(2, 0));
	printf("%d\n", unset_bit(3, 0));
	printf("%d\n", unset_bit(4, 0));
	
	printf("%d\n", unset_bit(1, 1));
	printf("%d\n", unset_bit(2, 1));
	printf("%d\n", unset_bit(3, 1));
	printf("%d\n", unset_bit(4, 1));
	printf("%d\n", unset_bit(-1, 31));
	
	int i;
    for(i=31;i>=0;--i)
        printf( "%d", check_bit(0, 32, i) );
    putchar('\n');
    for(i=31;i>=0;--i)
        printf( "%d", check_bit(1, 32, i) );
    putchar('\n');
    for(i=31;i>=0;--i)
        printf( "%d", check_bit(2147483647, 32, i) );
    putchar('\n');
    for(i=31;i>=0;--i)
        printf( "%d", check_bit(-1, 32, i) );
    putchar('\n');
    for(i=31;i>=0;--i)
        printf( "%d", check_bit(-2147483647, 32, i) );
    putchar('\n');
}

int main(void) {
    int i, v, bit, isSet;
    while(scanf("%d %d %d", &v, &bit, &isSet) == 3)
    {
        if(isSet)
            v = set_bit(v, bit);
        else
            v = unset_bit(v, bit);

        for(i=31;i>=0;--i)
            printf( "%d", check_bit(v, 32, i) );
        putchar('\n');
    }
    return 0;
}

