#include<stdio.h>

int main(){


    int * ptr;

    int* i=new int(5);
    int &i2=*i;
    i=NULL;
    ptr=&i2;

    printf("%d",ptr);

}