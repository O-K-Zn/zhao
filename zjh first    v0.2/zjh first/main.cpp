#include<iostream>
#include"all.h"
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;       

#define NameMax 30    //�ļ�������󳤶�
#define WordMax 60    //ÿ�����ʵ���󳤶�


typedef struct word       //����
{
	char w[WordMax];          //����
	int count;                //����
	struct word *next;
}link;

int count1 = 0,count2=0,count3=0;
link *head = NULL;    //����ͷ

FILE *fp;   //�ļ�ָ��
int a;       //����
char name[NameMax];


int isnotWord(char a)           //�ж��Ƿ�Ϊ��ĸ
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

void addWord(char *w1)        //��ӵ���
{

	link *p1, *p2;
	for (p1 = head; p1 != NULL; p1 = p1->next)    //�жϵ������������Ƿ����
	{
		if (!strcmp(p1->w, w1))
		{
			p1->count++;   //���ھ͸�����1
			return;
		}
	}

	p1 = (struct word *)malloc(sizeof(word));//����������µ���
	strcpy(p1->w, w1);
	p1->count = 1;
	p1->next = NULL;
	count1++;    //�ܵĵ������Ӽ�

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

void wordCount()           //ͳ�Ƶ���
{
	int i = 0, j = 0;
	char word[WordMax], c;
	while (!feof(fp))        //�����ļ�β������
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

void readWord()        //��ȡ�ļ��еĵ���
{
	
	
	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Open the file failure...\n");
		exit(0);
	}
	fp = fopen(name, "r");    //�Կɶ�д��ʽ���ļ�
	wordCount();

	fclose(fp);
}



void readLetter(){
	int c;
	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Open the file failure...\n");
		exit(0);
	}
	fp = fopen(name, "r");         //�Կɶ�д��ʽ���ļ�
	while ((c = fgetc(fp)) != EOF)  //���ζ����ַ���
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
	fp = fopen(name, "r");    //�Կɶ�д��ʽ���ļ�
	
	while ((c = fgetc(fp)) != EOF) {                   //���ζ����ַ���
		if (c <= 'Z' && c >= 'A')
		{
			count3++;                                 //�����ִ�д��ĸ��Ϊһ��Ŀ�ʼ��
		};       

	}
	fclose(fp);
}




int main(){


	printf("wc.exe ");
	scanf("%d %s",&a, name);//��������
	getchar();
	if (a==1)
	{
	readWord();
	printf("The number of word in this file is:%d\n", count1);//������ʽ��
	}
	else if (a==2) {
		readLetter();
		printf("The number of character in this file is:%d\n", count2);//����ַ����
	}
	else if (a==3) {
		readLine();
		printf("The number of sentence in this file is:%d\n", count3);//������ӽ��
	}
	
	
	return 0;
}

int test::check(int x) {
	return count1;
}