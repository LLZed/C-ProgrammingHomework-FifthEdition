/*
编写一个C程序,运行时输出以下图形:
*****
  *****
    *****
​      *****
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%s", "  ");
		}
		printf("%s\n", "*****");
	}
    system("pause");
	return 0;
}