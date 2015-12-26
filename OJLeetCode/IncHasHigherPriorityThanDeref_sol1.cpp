#include <cstdio>
#include <iostream>

using namespace std;


int main(void)
{
	int a = 0, b = 0;
	printf("[a++<10] a = ");
	while (a++ < 10) printf("%d, ", a);
	printf(", after while, a = %d", a);
	
	printf("\n[++b<10] b = ");
	while (++b < 10) printf("%d, ", b);
	printf(", after while, b = %d", b);

    int arr[5];
	arr[0] = 1000;
	arr[1] = 100;
	arr[2] = 10;
	int *ptr_1 = arr, *ptr_2 = arr, *ptr_3 = arr;
	printf("\n++ has higher priority than dereference *\n");
	printf("*++ptr_1 = %d, (ptr inc -> show ptr new val) deref\n", *++ptr_1);
	printf("*ptr_1 = %d\n", *ptr_1);
	printf("*ptr_2++ = %d, (show ptr cur val -> ptr inc) deref\n", *ptr_2++);
	printf("*ptr_2 = %d\n", *ptr_2);
	printf("++*ptr_3 = %d, ptr deref -> val inc -> val show\n", ++*ptr_3);
	printf("*ptr_3 = %d\n", *ptr_3);
	system("pause");
	return 0;
}