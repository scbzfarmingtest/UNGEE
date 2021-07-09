#include<stdio.h>
#include<math.h>
int main(){
    double max=-1.0*pow(2,1024),temp;
    for (int i=0;i<10;i++){
        scanf("%lf",&temp);
        if(max<=temp) max=temp;
    }
    printf("%lf",max);
    return 0;
}