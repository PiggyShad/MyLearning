#include<stdio.h>
#include<io.h>
#include<string.h>

//统计文本中的字符数
void c_num(char *file)
{
	FILE *f;
	char*  a="c_num:";
	f=fopen(file,"r");  //r表示以写的方式读取文件
	char c;   //char
	int num=0;  //char num
	if(f==NULL)
	{
		printf("file is null");
	}
	else
		while(!feof(f))  //feof 检查是否到文件的结束位置
		{
			c=fgetc(f);
			if(c!=' ' && c!= '\n' && c!='\t')
				num++;   //判断是否为字符 是就加一
		}
	fclose(f);   //把文件关闭
	printf("字符数: %d",num);

}

//统计文本中的单词数
void word_num(char *file)
{
	FILE *f;
	char*  a="word_num:";
	f=fopen(file,"r");
	char ch;
	int aword,cword=0;
	if(f==NULL)
	{
		printf("file is null");
	}
	else
		while(!feof(f))
		{
			ch=fgetc(f);  //获取单个字符
			if((ch>='a' &&ch <= 'z')||(ch>= 'A'&&ch<='Z') || ch=='_')
				aword=1;  //如果一直是字符那末aword值为1
			else if(aword)  //检测到不是字符
			{
				cword++;  //单词数加一 
				aword=0;
			}
		}
	fclose(f);
	printf("单词数: %d",cword);

}

//主函数 
int main(int argc, char* argv[])
{
	FILE *fp;
	while(1)
	{
		if((fp=fopen(argv[2],"r"))==NULL)
		{
			printf("FileNull\n\n\n");
			scanf("%s%s%s",argv[0],argv[1],argv[2]);
			continue;
		}
		else if(!strcmp(argv[1],"-w"))
			word_num(argv[2]);
		else if(!strcmp(argv[1],"-c"))
			c_num(argv[2]);
		else
			printf("NullPoint\n");
		printf("\n\n");
		scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}










