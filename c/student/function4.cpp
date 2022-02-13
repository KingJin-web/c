#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////////// 
                         /*���������غ���*/ 
/* 
�������ܣ�ѡ��ʵ�ְ�ѧ���������� 
���������ѧ���ṹ�����飬ѧ������ 
����ֵ���޸Ĺ��õ�ѧ���ṹ������ÿ��ѧ����˳��     
*/ 

void SortOnNumAs(struct student stu[],int nStudentNum)
{
	printf("\n\t\t\t�����ǰ�ѧ����������ģ��\n"); 
	struct student temp;
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=i+1;j<nStudentNum;j++)
		{
			if(stu[j].nNumber>stu[i].nNumber)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}
	}
}
//��ѧ�������������

/* 
�������ܣ�ѡ��ʵ�ְ��ܳɼ��������� 
���������ѧ���ṹ�����飬ѧ������ 
����ֵ���޸Ĺ��õ�ѧ���ṹ������ÿ��ѧ����˳��    
*/ 
void SortOnSumDs(struct student stu[],int nStudentNum)
{
	printf("\n\t\t\t�����Ǽ����ܳɼ��������ܳɼ���������ģ��\n"); 
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=0;j<COURSENUM;j++)
		{
			stu[i].fSumScore+=stu[i].fScore[j];
		}
	}
	struct student temp;
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=i+1;j<nStudentNum;j++)
		{
			if(stu[j].fSumScore<stu[i].fSumScore)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}
	}
}
//�ܳɼ������������ 


/* 
�������ܣ��������ƽ���� 
���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������ 
����ֵ���޸Ĺ��õ�ѧ���ṹ�������ÿ����Ա��ƽ����    
*/ 

void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t�����Ǽ���ѧ������ƽ������ģ��\n"); 
	float x[COURSENUM];
	for(int i=0;i<COURSENUM;i++)
	{
		for(int j=0;j<nStudentNum;j++)
		{
			x[i]+=stu[j].fScore[i];
		}
	}
	for(int i=0;i<COURSENUM;i++)
	{
		printf("\n\t\t\t�༶��%sƽ���֣�%.2f\n",szCourseName[i],(double)x[i]/nStudentNum);
	}
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=0;j<COURSENUM;j++)
		{
			stu[i].fAveScore+=stu[i].fScore[j];
		}
		stu[i].fAveScore=stu[i].fAveScore/COURSENUM;
	}
}

/* 
�������ܣ����㲢����༶���ĳɼ��������ηֲ���� 
    ����ѧ���ɼ��ֲ��ȼ����£�
    60�����£�fail
    60~70�� ��pass
    70~80�� ��good
    80~90�� ��great
    90�����ϣ�excellent 
���������ѧ���ṹ�����飬�γ��������ݣ�ѧ������ 
����ֵ����  
*/ 
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t �����Ǽ���������ηֲ�ģ��\n"); 
 	int x[5]={0},y[5]={0},z[5]={0};
 	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[0]<60)
		{
			x[0]++;
		} 
		else if(stu[i].fScore[0]>=60&&stu[i].fScore[0]<70)
		{
			x[1]++;
		}
		else if(stu[i].fScore[0]>=70&&stu[i].fScore[0]<80)
		{
			x[2]++;
		}
		else if(stu[i].fScore[0]>=80&&stu[i].fScore[0]<90)
		{
			x[3]++;
		}
		else if(stu[i].fScore[0]>=90)
		{
			x[4]++;
		}
	} 
	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[1]<60)
		{
			y[0]++;
		} 
		else if(stu[i].fScore[1]>=60&&stu[i].fScore[1]<70)
		{
			y[1]++;
		}
		else if(stu[i].fScore[1]>=70&&stu[i].fScore[1]<80)
		{
			y[2]++;
		}
		else if(stu[i].fScore[1]>=80&&stu[i].fScore[1]<90)
		{
			y[3]++;
		}
		else if(stu[i].fScore[1]>=90)
		{
			y[4]++;
		}
	} 
	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[2]<60)
		{
			z[0]++;
		} 
		else if(stu[i].fScore[2]>=60&&stu[i].fScore[2]<70)
		{
			z[1]++;
		}
		else if(stu[i].fScore[2]>=70&&stu[i].fScore[2]<80)
		{
			z[2]++;
		}
		else if(stu[i].fScore[2]>=80&&stu[i].fScore[2]<90)
		{
			z[3]++;
		}
		else if(stu[i].fScore[2]>=90)
		{
			z[4]++;
		}
	} 
	printf("\n                        �༶���ĳɼ��ֲ�Ϊ:\n\n");
	printf("90~100������������%d��, ռ�� %.2f%%;  80~90������������%d��, ռ�� %.2f%%;\n",x[0],(double)x[0]/nStudentNum*100,x[1],(double)x[1]/nStudentNum*100);
	printf("70~80 ������������%d��, ռ�� %.2f%%;  60~70������������%d��, ռ�� %.2f%%\n;",x[2],(double)x[2]/nStudentNum*100,x[3],(double)x[3]/nStudentNum*100);
	printf("60���²�����������%d��, ռ�� %.2f%%;\n",x[4],(double)x[4]/nStudentNum*100);
	printf("**************************************************************************\n");
	printf("\n                        �༶��ѧ�ɼ��ֲ�Ϊ:\n\n");
	printf("90~100������������%d��, ռ�� %.2f%%;  80~90������������%d��, ռ�� %.2f%%;\n",y[0],(double)y[0]/nStudentNum*100,y[1],(double)y[1]/nStudentNum*100);
	printf("70~80 ������������%d��, ռ�� %.2f%%;  60~70������������%d��, ռ�� %.2f%%;\n",y[2],(double)y[2]/nStudentNum*100,y[3],(double)y[3]/nStudentNum*100);
	printf("60���²�����������%d��, ռ�� %.2f%%;\n",y[4],(double)y[4]/nStudentNum*100);
	printf("**************************************************************************\n");
	printf("\n                        �༶Ӣ��ɼ��ֲ�Ϊ:\n\n");
	printf("90~100������������%d��, ռ�� %.2f%%;  80~90������������%d��, ռ�� %.2f%%;\n",z[0],(double)z[0]/nStudentNum*100,z[1],(double)z[1]/nStudentNum*100);
	printf("70~80 ������������%d��, ռ�� %.2f%%;  60~70������������%d��, ռ�� %.2f%%;\n",z[2],(double)z[2]/nStudentNum*100,z[3],(double)z[3]/nStudentNum*100);
	printf("60���²�����������%d��, ռ�� %.2f%%;\n",z[4],(double)z[4]/nStudentNum*100);
}// ����ɼ��ֲ������������ 
