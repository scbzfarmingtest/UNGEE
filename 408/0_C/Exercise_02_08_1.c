# include<stdio.h>
int main(){
    int year=1900;
    for(;year<=2000;year++){
        if(year%100==0&&year%400==0) printf("%d ",year);
        else if(year%100!=0&&year%4==0) printf("%d ",year);
        else ;
    }
    return 0;
}