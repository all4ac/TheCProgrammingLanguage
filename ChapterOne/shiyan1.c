#include <stdio.h>
/*本实验关于转义字符*/
main()
{
	int c;
	c = getchar();
	if (c == '\"')
		putchar('1');
	else putchar('0');
}