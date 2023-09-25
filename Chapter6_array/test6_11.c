/*输出一下图案：
* * * *
  * * * *
    * * * *
      * * * *
        * * * *
*/
#include <stdio.h>
#include "stdlib.h"
void main()
{
    char array[5]={'*','*','*','*','*'};
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<i;j++)
            printf(" ");
        for(int k=0;k<5;k++)
            printf("%c",array[k]);
        printf("\n");
    }
    printf("\n");
system("pause");
}