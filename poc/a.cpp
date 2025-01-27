// #define _CRT_SECURE_NO_WARNINGS //屏蔽vs2017安全警告

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void readfile(void);
void writefile(void);
void scanner(void);
char rbuf[10000] = {'\0'};
char wbuf[10000] = {'\0'};

int main(void)
{
	readfile();
	scanner();
	writefile();
	
	return 0;
}

void readfile(void)
{
	FILE *fp;
	int ch;
	int i;
	if ((fp = fopen("read.txt", "r")) == NULL)
	{
		printf("Can not open read file\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((ch = fgetc(fp)) != EOF)
		rbuf[i++] = ch;
	rbuf[i++] = '#';
	rbuf[i++] = '#';
	fclose(fp);
}

void writefile(void)
{
	FILE *fp;
	if ((fp = fopen("write.txt", "w")) == NULL)
	{
		printf("Can not open write file\n");
		exit(EXIT_FAILURE);
	}
	fputs(wbuf, fp);
	fclose(fp);
}


void scanner(void)
{
	int bg = 0, fd = 0;
	int wi = 0;
	int state = 0;
	char c;
	while (rbuf[fd] != '\0')
	{
		switch (state)
		{
		case 0:
			c = rbuf[fd++];
			if (!isdigit(c) && !isalpha(c))
			{
				state = 0;
				bg++;
			}
			else if (isalpha(c))
				state = 1;
			else if (isdigit(c))
				state = 2;
			break;

		case 1:
			c = rbuf[fd++];
			if (isalpha(c))
				state = 1;
			else
				state = 3;
			break;
		case 2:
			c = rbuf[fd++];
			if (isdigit(c))
				state = 2;
			else
				state = 4;
			break;
		case 3:
			while (bg <= fd - 2)
				wbuf[wi++] = rbuf[bg++];
			wbuf[wi++] = ' ';
			fd--;
			state = 0;
			break;
		case 4:
			while (bg <= fd - 2)
				wbuf[wi++] = rbuf[bg++];
			wbuf[wi++] = ' ';
			fd--;
			state = 0;
			break;
		}
	}
}