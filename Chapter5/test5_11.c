//球从100m落下，每次落地反弹原高度的一半，再落下再反弹，求第十次落地经过的路程和第十次落地反弹的高度
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double H=100;
    double s=0;
    for(int i=1;i<=10;i++)
    {
        s+=H;
        H=H/2;
        s+=H;
    }
    s=s-H;//减去最后第十次反弹回弹的高度
    printf("第十次反弹的高度为：%10.8f m\n",H);  
    printf("经过的路程 s =%10.8f m\n",s);
system("pause");
return 0;
}