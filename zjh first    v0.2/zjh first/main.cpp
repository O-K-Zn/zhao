#include<iostream>
#include"all.h"
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;       

#define NameMax 30    //文件名的最大长度
#define WordMax 60    //每个单词的最大长度


typedef struct word       //链表
{
	char w[WordMax];          //单词
	int count;                //个数
	struct word *next;
}link;

int count1 = 0,count2=0,count3=0;
link *head = NULL;    //链表头

FILE *fp;   //文件指针
int a;       //参数
char name[NameMax];


int isnotWord(char a)           //判断是否为字母
{
	if (a <= 'z' && a >= 'a')
	{
		return 0;
	}
	else if (a <= 'Z' && a >= 'A')
	{
		return 0;
	}
	else if (a == ' ')
	{
		return 1;
	}
	else if (a >= '1'&&a <= '9')
	{
		return 1;
	}
	else if (a == '\n')
	{
		return 1;
	}
	else
	{
		return 1;
	}

}

void addWord(char *w1)        //添加单词
{

	link *p1, *p2;
	for (p1 = head; p1 != NULL; p1 = p1->next)    //判断单词在链表中是否存在
	{
		if (!strcmp(p1->w, w1))
		{
			p1->count++;   //存在就个数加1
			return;
		}
	}

	p1 = (struct word *)malloc(sizeof(word));//不存在添加新单词
	strcpy(p1->w, w1);
	p1->count = 1;
	p1->next = NULL;
	count1++;    //总的单词数加加

	if (head == NULL)
	{
		head = p1;
	}
	else
	{
		for (p2 = head; p2->next != NULL; p2 = p2->next);
		p2->next = p1;
	}


}

void wordCount()           //统计单词
{
	int i = 0, j = 0;
	char word[WordMax], c;
	while (!feof(fp))        //若到文件尾部结束
	{
		fscanf(fp, "%c", &c);

		if (isnotWord(c))
		{
			word[j] = '\0';
			if (j > 0)
			{
				addWord(word);
			}
			j = 0;
		}
		else
		{

			word[j] = c;
			j++;
		}
		i++;
	}
}

void readWord()        //读取文件中的单词
{
	
	
	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Open the file failure...\n");
		exit(0);
	}
	fp = fopen(name, "r");    //以可读写方式打开文件
	wordCount();

	fclose(fp);
}



void readLetter(){
	int c;
	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Open the file failure...\n");
		exit(0);
	}
	fp = fopen(name, "r");         //以可读写方式打开文件
	while ((c = fgetc(fp)) != EOF)  //依次读出字符。
		{
			 count2++;
		}

	fclose(fp);

}


void readLine() {
	
	int c;
	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Open the file failure...\n");
		exit(0);
	}
	fp = fopen(name, "r");    //以可读写方式打开文件
	
	while ((c = fgetc(fp)) != EOF) {                   //依次读出字符。
		if (c <= 'Z' && c >= 'A')
		{
			count3++;                                 //若出现大写字母则为一句的开始。
		};       

	}
	fclose(fp);
}




int main(){


	printf("wc.exe ");
	scanf("%d %s",&a, name);//输入数据
	getchar();
	if (a==1)
	{
	readWord();
	printf("The number of word in this file is:%d\n", count1);//输出单词结果
	}
	else if (a==2) {
		readLetter();
		printf("The number of character in this file is:%d\n", count2);//输出字符结果
	}
	else if (a==3) {
		readLine();
		printf("The number of sentence in this file is:%d\n", count3);//输出句子结果
	}
	
	
	return 0;
}

int test::check(int x) {
	return count1;
}