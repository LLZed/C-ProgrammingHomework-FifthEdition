#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a;
    printf("input a:");
    scanf("%d",&a);
    printf("Hello World!\n");
    printf("你好世界！\n");
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}