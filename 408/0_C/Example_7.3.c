// Example 7.3 C(EasyV3)
// Rearrage int a,b from larger to smaller
// Changing int value, and do not change pointer
// set up a new function swap
# include <stdio.h>
int main(){
    int *pa,*pb,a=5,b=9,temp;
	void swap(int *,int *);
    pa=&a;
    pb=&b;
    printf("a=%d,b=%d\npointer_a=%d,pointer_b=%d\n",a,b,pa,pb);
    if(a<b) swap(pa,pb);
    printf("a=%d,b=%d\npointer_a=%d,pointer_b=%d",a,b,pa,pb);
    return 0;
}
void swap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}