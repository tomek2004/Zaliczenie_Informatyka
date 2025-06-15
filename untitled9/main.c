#include <stdio.h>

//void printVariables(int a, int b){
//    printf("\ta = %d\n",a);
//    printf("\tb = %d\n",b);
//    printf("\t&a = %p\n",&a);
//    printf("\t&b = %p\n",&b);
//}

void printVariables(const int *ptr1,const int *ptr2){
    printf("\ta = %d\n",*ptr1);
    printf("\tb = %d\n",*ptr2);
}

void swap(int *ptr1, int *ptr2){
    printf("\tptr1 = %d\n", *ptr1);
    printf("\tptr2 = %d\n", *ptr2);
    int temp = *ptr1;
    *ptr1=*ptr2;
    *ptr2 = temp;
    printf("\t*ptr1 = %d\n", *ptr1);
    printf("\t*ptr2 = %d\n", *ptr2);
}


int main() {
    int a = 10;
    int b = 20;

    printf("a = %d\n",a);
    printf("b = %d\n",b);

    swap(&a,&b);

    printf("a = %d\n",a);
    printf("b = %d\n",b);

    printVariables(&a,&b);




//    int a = 10;
//    int b = 20;
//    int *ptr = NULL;
//
//    printf("a = %d\n",a);
//    printf("b = %d\n",b);
//    printf("&a = %p\n",&a);
//    printf("&b = %p\n",&b);
//    printf("ptr = %p\n",ptr);
//    printf("&ptr = %p\n",&ptr);
//
//    a = 15;
//    printf("a = %d\n",a);
//    printf("&a = %p\n",&a);
//
//    ptr = &a;
//    *ptr = 50;
//    printf("a = %d\n",a);
//    printf("&a = %p\n",&a);
//    printf("ptr = %p\n",ptr);

    return 0;
} 