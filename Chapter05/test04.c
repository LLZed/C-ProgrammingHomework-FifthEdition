/*
输入一行字符,分别统计出其中英文字母、空格、数字和其他字符的个数。
答案解析：
该题可以调用getchar函数，从stdin流中读入一个字符，当输入多个字符时，getchar()再执行时就会直接从缓冲区中读取了。
等同于getc(stdin)。所以，我们循环调用getchar，直到将标准输入的内容读到换行符\n为止。
同时判断，读取到的字符是英文字母、空格、数字或者其他字符，并计数；
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char c;
	//定义eng_char为英文字母的个数，初始值为0
	//定义space_char为空格字符的个数，初始值为0
	//定义digit_char为数字字符的个数，初始值为0
	//定义other_char为其他字符的个数，初始值为0
	int eng_char = 0, space_char = 0, digit_char = 0, other_char = 0;
	printf("请输入一行字符：");
	while ((c = getchar()) != '\n')
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		{
			eng_char++;
		}
		else if (c == ' ')
		{
			space_char++;
		}
		else if (c >= '0' && c <= '9')
		{
			digit_char++;
		}
		else
		{
			other_char++;
		}
	}

	printf("英文字母数量:%d\n空格数量:%d\n数字数量:%d\n其他字符数量:%d\n", eng_char, space_char, digit_char, other_char);
	system("pause");
    return 0;
}
