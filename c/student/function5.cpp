#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

///////////////////////////////////////////////////////////////////////////////// 
             //��ѯ��غ��� ����2������ѧ�ţ����������� 
                        

/* 
�������ܣ���ѧ�Ų��Ҳ����һ��ѧ���ľ�����Ϣ 
���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������ 
����ֵ����  
*/ 

void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t�����ǰ�ѧ�Ų���һ��ѧ��ģ��\n"); 
 	int  x=0;
 	int flag=0;
	printf("\n\t\t������ѧ��ѧ�ţ�");
	scanf("%d",&x);
	for(int i=0;i<nStudentNum;i++)
	{
		if(x==stu[i].nNumber)
		{
			printf("\n\t\tѧ��  ����      ����    ��ѧ    Ӣ��    �ܳɼ�    ƽ���ɼ�");
			printf("\n\t\t==========================================================");
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f     %.2f        %.2f",stu[i].nNumber,stu[i].szName[STRLENGTH],stu[i].fScore[1],stu[i].fScore[2],stu[i].fScore[3],stu[i].fAveScore,stu[i].fSumScore);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n\t\tû�д�ѧ�ŵ�ѧ�������������룡\n");
	}
	
		
}//��ѧ�Ų�ѯ���� 

/* 
�������ܣ����������Ҳ����һ��ѧ���ľ�����Ϣ 
���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������ 
����ֵ����  
*/ 
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t�����ǰ���������ѧ����Ϣģ��\n"); 
 	char x[STRLENGTH];
 	int flag=0;
	printf("\n\t\t������ѧ��������");
	scanf("%s",&x);
	for(int i=0;i<nStudentNum;i++)
	{
		if(strcmp(x,stu[i].szName) == 0)
		{
			printf("\n\t\tѧ��  ����      ����    ��ѧ    Ӣ��    �ܳɼ�    ƽ���ɼ�");
			printf("\n\t\t==========================================================");
			printf("\n\t\t%d    %s         %f      %f      %f       %f        %f",stu[i].nNumber,stu[i].szName[STRLENGTH],stu[i].fScore[1],stu[i].fScore[2],stu[i].fScore[3],stu[i].fAveScore,stu[i].fSumScore);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n\t\tû�д�������ѧ�������������룡\n");
	}	
}//��������ѯ���� 
