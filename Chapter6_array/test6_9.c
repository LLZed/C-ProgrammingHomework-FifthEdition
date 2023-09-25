/*有15个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法找出该数是数组中第几个元素的值。
如果该数不在数组中，则输出"无此数"。*/
/**************************************
折半查找又叫二分查找，查找的前提是序列中元素必须有序，假设区间使用[left, right)标记，待查找元素为key
具体查找的方式如下：
(1)当区间[left, right)有效时循环进行一下操作
(2)找到[left， right)区间中间位置
(3)如果key等于中间位置元素，则找到，返回该元素在数组中的下标
(4)如果key小于中间位置元素，到数组的左半侧继续二分查找
(5)如果key大于中间位置元素，到数组的右半侧继续二分查找
(6)如果循环结束时还没有找到，则不存在该元素。
 */
#include <stdio.h>
#include "stdlib.h"
void main()
{
    int array[15]={14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int flag;
    for (int i = 0; i < 14; i++)
    {
        if (array[i]>array[i+1])
        {
            flag=1;
        }
       else
       {
            flag=0;
       }
    }
    if(flag==1)
    {
        printf("数组区间有效\n");
        int key,mid;
        int left=0,right=sizeof(array) / sizeof(array[0]);
        printf("输入一个整数：\n");
        scanf("%d",&key);
        while(left<right)
        {
            mid=(left+right)/2;
            if(key==array[mid])
            {
                printf("该数是数组中第%d个元素的值:\n",mid);
                break;
            }
            else if(key>array[mid])
            {
                right=mid;
            }
            else if(key<array[mid])
            {
                left=mid;
            }
        }
        if(left<=right)
        printf("无此数\n");   
    }
    if(flag==0)
    {
        printf("数组区间无效，请排序好数组元素\n");
    }
system("pause");
}
