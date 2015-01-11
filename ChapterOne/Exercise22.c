#include <stdio.h>

#define TABING 8
#define MAXLINE 10

char line[MAXLINE];
int findblank(int pos);
void printl(int pos);
int newpos(int pos);
int exptab(int pos);

main()
{
	int c,pos,i;

	pos = 0;
	while((c = getchar()) != EOF)
	{
		if (pos >= MAXLINE)
		{
			pos = findblank(pos);
			printl(pos);
			if (pos >= MAXLINE)
				pos = 0;
			else 
				pos = newpos(pos);
		}
		if (c == '\n')
		{
			line[pos] = c;
			printl(pos);
			pos = 0;
		}
		else if (c == '\t')
		{
			pos = exptab(pos);
		}
		else 
		{
			line[pos] = c;
			pos++;
		}
	}
}

int findblank(int pos)
{
	while((line[pos-1] != ' ') && pos>0)
	{
		pos--;
	}/*此处获得的pos是空格的下一位 */
	if (pos == 0)
		return MAXLINE;
	else 
		return pos;
}

void printl(int pos)
{
	int i;
	for (i=0;i<pos;i++)
		putchar(line[i]);
	if (pos > 0)
		putchar('\n');
}

int newpos(int pos)
{
	int j;

	for (j=0;pos<MAXLINE;j++)
	{
		line[j] = line[pos];
		pos++;
	}

	return j++;
}

int exptab(int pos)
{
	int n;
	if (pos >= TABING)
	{
		for(;pos<MAXLINE;pos++)
			line[pos] = ' ';
		return pos;
	}
	else 
	{
		n = pos + TABING - pos % TABING;
		for (;pos<n;pos++)
			line[pos] = ' ';
		return n;
	}
}