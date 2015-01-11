#include <stdio.h>

int brace,brank,paren;

void in_comment(void);
void in_quote(int c);
void search(int c);

main()
{
	int c;
	extern int brace,brank,paren;

	while((c = getchar()) != EOF)
	{
		if (c == '/')
			if ((c = getchar()) == '*')
				in_comment();
			else search(c);
		else if (c == '\'' || c == '"')
			in_quote(c);
		else search(c);
		if (brace < 0)                   /*检查的过程中出现负值是不对的*/
		{
			printf("error");
			brace = 0;
		}
		if (brank < 0)
		{
			printf("error");
			brank = 0;
		}
		if (paren < 0)
		{
			printf("error");
			paren = 0;
		}
	}
	if (brace > 0)
		{
			printf("error");
			brace = 0;
		}
	if (brank > 0)
		{
			printf("error");
			brank = 0;
		}
	if (paren > 0)
		{
			printf("error");
			paren = 0;
		}
}

void in_comment(void)
{
	int c,d;
	c = getchar();
	d = getchar();
	while(c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

void in_quote(int c)
{
	int d;
	while((d = getchar()) != c)
	{
		if (d == '\\')
			getchar();
	}
}

void search(int c)
{
	extern int brace,brank,paren;
	if (c == '(')
		brace++;
	else if(c == ')')
		brace--;
	else if (c == '[')
		brank++;
	else if (c == ']')
		brank--;
	else if (c == '{')
		paren++;
	else if (c == '}')
		paren--;

}