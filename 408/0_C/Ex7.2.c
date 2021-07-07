// Example7.2 C(EasyV3)
// Rearrage int a,b from larger to smaller
// Changing pointer, rather than changing int value
#include <stdio.h>
int main(int a,int b){
    int *p1 , *p2 , *ptemp , a , b;
    scanf("%d%d",&a,&b);
    p1=&a;
    p2=&b;
    if(a<b){
        ptemp=p1;
        p1=p2;
        p2=ptemp;
    }
    printf("a=%d,b=%d",*p1,*p2);
    return 0;
}