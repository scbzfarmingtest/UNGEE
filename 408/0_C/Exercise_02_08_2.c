//02.08.2
#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,d,x1,x2;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(d<b*b-4*a*c) printf("Error");
    else {
        x1=-(b+sqrt(b*b-4*a*c))/(2*a);
        x2=-(b-sqrt(b*b-4*a*c))/(2*a);
        printf("x1=%lf,x2=%lf",x1,x2);
    }
    return 0;
}