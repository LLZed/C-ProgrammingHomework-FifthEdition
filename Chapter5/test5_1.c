/*输出4*5矩阵
   1   2   3   4   5
   2   4   6   8  10
   3   6   9  12  15
   4   8  12  16  20
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,n=0;
    for(i=1;i<=4;i++){
        for(j=1;j<=5;j++){
            printf("%4d",i*j);
        }
    printf("\n");
    }

    for(i=1;i<=4;i++){
        for(j=1;j<=5;j++){
            printf("%-4d",i*j);
        } 
    printf("\n");
    }
    system("pause");
    return 0;
}