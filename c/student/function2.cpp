#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////////// 
                            /*�ļ���غ���*/
 /* 
�������ܣ������ļ����������е�����д���ļ� 
���������ѧ���ṹ�����飬ѧ���������ļ���ʽ��־ 
           ע�������ִ洢�ļ���ʽ,1����û��ƽ���ɼ����ܳɼ���,1�����е�
		   Ϊ�����������ļ���ʽ,���ļ���ʽ��־д�������ļ����� 
          �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ� (���ܳɼ���ƽ���ɼ�) 
                        1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ� 
            ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���studentlist.txt���Կ����洢�������� 
����ֵ��0: �����ɹ���1���������ɹ� 
*/ 

int CreateFile(struct student stu[],int nStudentNum,int nFlag)
{
		//����д���ļ�
		FILE* fp=fopen(FILENAME,"w");
		if(fp!=NULL)
		{	
			WriteToFile(fp,stu,nStudentNum,nFlag);
			printf("\t\t�ѳɹ���%d��ѧ������д�������ļ�%s.......\n",nStudentNum,FILENAME);
			//���û���ʾĿǰ����Ϣ
	 		return 1;
		}
		  
		else //�ļ��������ɹ� 
			return 0;
		
	
}//�����ļ����� 

 /* 
�������ܣ����Ϊ�ļ����������е�����д���ļ� 
���������ѧ���ṹ�����飬ѧ���������ļ���ʽ��־ 
          �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ� 
                        1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ� 
            ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���dd.txt����  
			    Studentscore.data���Կ����洢�������� 
����ֵ��0: �����ɹ���1���������ɹ� 
*/ 
			
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag)
{
    char szFileName[STRLENGTH];
    if(nStudentNum<1)
	{
			printf("\t\t��ǰû��ѧ�����ݣ��뵽��Ϣ����ģ��������ݣ�\n");
			return 0;
	}
	if(nFlag==1&&stu[0].fSumScore<1)
	{
			printf("\t\t��ǰû���ܳɼ���ƽ���ɼ���Ϣ���뵽�������ģ�����ɼ���\n");
			return 0;
	}
	 
	while(1)
   {
	    printf("\n\t\t�������Ᵽ����ļ���: ");
	  
	    scanf("%s",szFileName);
	    if(strcmp(szFileName,FILENAME)==0)
	    	printf("\n\t\t���ļ���Ϊϵͳ�ļ���������ʹ�ã�\n");
	    else
	    	break; 
	}
	//����д���ļ�
	FILE* fp=fopen(szFileName,"w");
	if(fp!=NULL)
	{
		WriteToFile(fp,stu,nStudentNum,nFlag);
		printf("\t\t�ѳɹ���%d��ѧ������д�������ļ�%s.......\n",nStudentNum,szFileName);
		fclose(fp);
		//���û���ʾĿǰ����Ϣ
 		return 1;
	}
	  
	else //�ļ��������ɹ� 
		return 0;
		
	
}//�������Ϊ�ļ����� 


/* 
�������ܣ���ȡ�ļ�������ȡ�ļ��е�Ԫ����Ϣ���浽ѧ���ṹ����
   ע�⣺����������ļ��ж�������ʼ�ַ�����"STL" ��ʾ�ǻ���ѧ�����ݱ���Ϣ�ļ� 
                          ���� "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ� 
            ***�ļ���ʽ��־Ϊ����Ա�Լ��涨�ģ��ü��±���dd.txt����  
			    Studentscore.data���Կ����洢��������  
����������ļ�ָ�룬ѧ���ṹ������
          
����ֵ��������ѧ���� 
*/ 

int ReadFromFile(FILE *fp,struct student stu[])
{
	int i=0;
	char szFileFlag[STRLENGTH];//�ȶ��ļ����
	fscanf(fp,"%s",szFileFlag) ;
	int nFlag=-1;
	if(strcmp(szFileFlag,FILEFLAG1)==0)
		nFlag=0;
	if(strcmp(szFileFlag,FILEFLAG2)==0)
		nFlag=1;
	if (nFlag==-1)
	  return 0; //�����δ֪���ļ�ͷ������0 
	do
	{
		int nReadNum=0;
		//��ѧ�ź����� 
		nReadNum+=fscanf(fp,"%d%s",&stu[i].nNumber,&stu[i].szName);
		//�����Ƴɼ� 
		for(int j=0;j<COURSENUM;j++)
		  nReadNum+=fscanf(fp,"%f",&stu[i].fScore[j]);
		//�����STLSA�����ܳɼ���ƽ���ɼ�
		if(nFlag==1)
		  fscanf(fp,"%f%f",&stu[i].fSumScore,&stu[i].fAveScore); 
		//�ɹ���ȡ��������+1 
		if (nReadNum==(COURSENUM+2))
			i++;
		else
			break;
	}
	while(1);
	return i;//���ض�����ѧ���� 
	
}
//ReadFromFile ��������		



/* 
�������ܣ���Ŀǰѧ���ṹ������ݣ�д��һ���ļ�
����������ļ�ָ�룬ѧ���ṹ�����飬ѧ���������ļ���ʽ��־ 
          �ļ���ʽ��־��0 ��ʾ "STL" �Ǵ洢Ϊ����ѧ�����ݱ���Ϣ�ļ� 
                        1 ��ʾ "STLSA" �ǻ���ѧ�����ݱ�+�ܳɼ���ƽ���ɼ� 
            ***�ļ���ʽ��־Ϊ����Ա�Լ�����ģ��ü��±���dd.txt����  
			    Studentscore.data���Կ����洢�������� 
          
����ֵ��������ѧ���� 
*/ 
 void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag)
{
	//������� 
	if(nFlag==0)
		fprintf(fp,FILEFLAG1);
	else if(nFlag==1)
		fprintf(fp,FILEFLAG2);
	fprintf(fp,"\n");
	for(int i=0;i<nStudentNum;i++)	
 	{
  		//д�������ļ� 
  		fprintf(fp,"%d %s ",stu[i].nNumber,stu[i].szName);
  		//д���Ƴɼ� 
		for(int j=0;j<COURSENUM;j++)
			fprintf(fp,"%.2f ",stu[i].fScore[j]);
		if(nFlag==1) 
			fprintf(fp,"%.2f %.2f",stu[i].fSumScore,stu[i].fAveScore);
		fprintf(fp,"\n");  		

 	}//forѭ������  
	
}//Write to File ��������

