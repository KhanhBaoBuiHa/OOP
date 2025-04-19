#include "stdio.h"
#include "math.h"
int main(){
    int n,i,rs=0;
    int a[10];
    scanf("%d",&n);
    for(i=9;i>0;i--){
        if((n/pow(10,i))<10 && (n/pow(10,i))>1) break;
    }
    for(int j=0;j<=i;j++){
        a[j]= n%10;
		n /=10;
        printf("%d ",a[j]);
        rs+=a[j];
    }
    printf("tong : %d",rs);
}