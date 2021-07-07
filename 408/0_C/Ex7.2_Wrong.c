// Example7.2 C(EasyV3)
// Rearrage int a,b from larger to smaller
// Changing pointer, rather than changing int value
// Using void swap() function
#include <stdio.h>
int main(){
    void swap(int *,int*);
    int *p1,*p2,a=5,b=9;
    p1=&a;
    p2=&b;
    if(a<b) swap(p1,p2);
    printf("a=%d,b=%d",*p1,*p2);
    return 0;
}
void swap(int *pa,int *pb){
    int *ptemp;
    ptemp=pa;
    pa=pb;
    pb=ptemp;
}