 /*
  * @file learnpointer.c
  * @author Jason3e7
  * @algorithm point
  * @date 20171021828
  */

#include <stdio.h>

void swap_v(int c, int d) {
	int temp = c;
    c = d;
    d = temp;
}

void swap_p(int *c, int *d) {
	printf("c=%p(value=%d) d=%p(value=%d)\n", c, *c, d, *d);
	int temp = *c;
    *c = *d;
    *d = temp;
}

void swap_pp(int **c, int **d) {
	printf("c=%p(value=%p) d=%p(value=%p)\n", c, *c, d, *d);
	int *temp; 
	temp = *c;
    *c = *d;
    *d = temp;
}

void swap_ppp(int **c, int **d) {
	printf("c=%p(value=%p) d=%p(value=%p)\n", c, *c, d, *d);
	int temp; 
	temp = **c;
    **c = **d;
    **d = temp;
}

int main() {
	printf("call by value\n");
	int a = 1, b = 2;
	printf("%d %d\n", a, b);
	swap_v(a, b);
	printf("%d %d\n", a, b);
	printf("\n");
	
	printf("call by value of pointer\n");
	a = 1, b = 2;
	printf("a=%d(add=%p) b=%d(add=%p)\n", a, &a, b, &b);
	swap_p(&a, &b);
	printf("a=%d(add=%p) b=%d(add=%p)\n", a, &a, b, &b);
	printf("\n");
	
	printf("call by (value of pointer) of pointer\n");
	a = 1, b = 2;
	int *aPtr = &a;
	int *bPtr = &b;
	printf("a=%d aPtr=%p(add=%p))) b=%d bPtr=%p(add=%p))\n", a, aPtr, &aPtr, b, bPtr, &bPtr);
	swap_pp(&aPtr, &bPtr);
	printf("a=%d(add=%p(add=%p))) b=%d(add=%p(add=%p))\n", a, aPtr, &aPtr, b, bPtr, &bPtr);
	printf("aPtr => b, bPtr => a, but a and b not change.\n");
	//swap_p(aPtr, bPtr);
	swap_ppp(&aPtr, &bPtr);
	printf("a=%d(add=%p(add=%p))) b=%d(add=%p(add=%p))\n", a, aPtr, &aPtr, b, bPtr, &bPtr);
	return 0;
}

