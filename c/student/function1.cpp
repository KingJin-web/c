#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////
                              /*�˵���غ���*/

/* 
�������ܣ�һ�����˵�ѡ����ʾ 
���������ѧ���ṹ�����飬�γ�������
���ز�����ѧ����������Ϊ����һֱ�ı䣬��ָ�����ʵ�֣�
*/ 
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum) 
{	
	int nMainchoose;
	//���˵�����ѭ�� 
	while(1)
	{
		system("CLS"); //ϵͳ��Ļ��� 
		//����˵������� 
		printf("\t\t   ------------------------  \n");
		printf("\t\t|      ѧ���ɼ�����ϵͳ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  1.��Ϣ��ʾ   2.��Ϣ����   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  3.�������   4.������ѯ   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  5.�ļ�����   0.�˳�ϵͳ   |\n");
		printf("\t\t   ------------------------  \n");
		//���ݺ궨����ļ�����ѧ��������ʾ 
		printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n",FILENAME,*npStudentNum);
		//���û�����ѡ������� 
		printf("\t\t   ��ѡ�������(0~5):");
		//�û����ݽ�����ʾ�������� 
	    scanf("%d",&nMainchoose);	
		//�����û���������ֿ�����ж�					
		switch(nMainchoose)
		{
		   //��Ϣ��ʾ 
			case 1: printf("\n");
			        //�������ѧ����Ϣ���� 
				    OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);	//ת�������ʾ���� 
				    system("PAUSE");
			        break;
			//ת�������˵�����Ϣ����ģ��˵�ѡ����ʾ 
			case 2: Select_ManageMenu(stu,szCourseName,npStudentNum);
					break;
			//ת�������˵�����������ģ��˵�ѡ����ʾ
			case 3:Select_SortMenu(stu,szCourseName,*npStudentNum);	
					break;
			//ת�������˵���������ѯģ��˵�ѡ����ʾ
			case 4:Select_QueryMenu(stu,szCourseName,*npStudentNum);
					break;
			//ת�������˵����ļ�����ģ��˵�ѡ����ʾ
			case 5:Select_SaveMenu(stu,szCourseName,*npStudentNum);
					break;
			//�û�ѡ���˳�		
			case 0: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
			        exit(0);
					break; 
			//�û�ѡ������ 
			default:printf("ѡ����������ѡ��\n");
		}//switch���� 
	}//while(1)�������� 
}//Select_MainMenu�������� 

/* 
�������ܣ�һ���˵�����Ϣ����ģ��˵�ѡ����ʾ  
���������ѧ���ṹ�����飬�γ�������
���ز�����ѧ����������Ϊ����һֱ�ı䣬��ָ�����ʵ�֣�
*/ 
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum)
{
	int nManageChoose;
	while(1)
	{   system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********��Ϣ����ģ��********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.����ѧ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.ɾ��ѧ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.�޸�ѧ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.�����ϼ��˵�      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t   ------------------------  \n");
		printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n",FILENAME,*npStudentNum);
		printf("\t\t   ��ѡ�������(0~3):");
		//�����û�ѡ�� 
		scanf("%d",&nManageChoose);
		switch(nManageChoose)
		{
			case 1:AddStudentInfo(stu,szCourseName,npStudentNum);//ת������ѧ����Ϣ���� 
			       OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//������û���һ�� 
			       	system("PAUSE");
				   break;
			case 2:DeleteStudentInfo(stu,szCourseName,npStudentNum);//ת��ɾ��ѧ����Ϣ����
			       OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//������û���һ�� 
			       	system("PAUSE");
				   break;
			case 3:ModifyStudentScore(stu,szCourseName,*npStudentNum);//ת���޸�ѧ����Ϣ����
			        OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//������û���һ�� 
			       	system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,npStudentNum);			//����һ�����˵����� 
			        break;
					
			default:printf("\t\tѡ����������ѡ��\n");
		}//switch���� */
	}//while(1)���� 

	
}//Select_ManageMenu�������� 

/* 
�������ܣ������˵�������ͼ���˵�ѡ����ʾ  
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ���� 
*/ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	int nSortChoose;

	while(1)
	{	system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********�������ģ��********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   1.��ѧ����������         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   2.�ܳɼ����㼰��������   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   3.����ƽ���ɼ�����           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   4.���Ƴɼ��ֲ�����       |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   0.�����ϼ��˵�           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------  \n");
		printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n",FILENAME,nStudentNum);
		printf("\t\t   ��ѡ�������(0~4):");	
		//�����û�ѡ�� 
		scanf("%d",&nSortChoose);
		
		switch(nSortChoose)
		{
			case 1:SortOnNumAs(stu,nStudentNum);//��ѧ���������� 
			        //����꺯��������Ϳ��Խ⿪ע����	
					OutputStudentInfo(stu,szCourseName,nStudentNum,0,0,nStudentNum);//������û���һ�� 
			       	system("PAUSE");
					break;
			case 2: SortOnSumDs(stu,nStudentNum);//���ܳɼ���������	
			        //����꺯��������Ϳ��Խ⿪ע����	
					printf("\n\t\t\t��������ܳɼ���ƽ���ɼ�......\n");
					OutputStudentInfo(stu,szCourseName,nStudentNum,1,0,nStudentNum);//������û���һ�� 
			       	system("PAUSE");
					break;
			case 3: //����꺯��������Ϳ��Խ⿪ע����	
			        printf("\n\t\t\t�����ܳɼ���ƽ���ɼ�......\n");
			        ComputeAverageScore(stu,szCourseName,nStudentNum);//���ܳɼ���������	
					system("PAUSE");
					break;
			case 4: //����꺯��������Ϳ��Խ⿪ע����	
			        printf("\n\t\t\t�������ƽ���ɼ����ֲ�......\n");
			        ComputeDistribution(stu,szCourseName,nStudentNum);//���ܳɼ���������	
					system("PAUSE");
					break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum);//����һ�����˵�ѡ����ʾ 
					break;
			default:printf("\t\tѡ����������ѡ��\n");
		}//switch���� 
	}//while(1)���� 
}//Select_SortMenu�������� 


/* 
�������ܣ������˵�����Ϣ��ѯ�˵�ѡ����ʾ  
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ���� 
*/ 

void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nQueryChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************��Ϣ��ѯģ��************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.����ѧ�Ų�ѯ��Ϣ          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.����������ѯ��Ϣ          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.�����ϼ��˵�              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   ��ѡ�������(0~2):");
		
		
		scanf("%d",&nQueryChoose);
		
		switch(nQueryChoose)
		{
			case 1: FindByNumber(stu,szCourseName,nStudentNum);	//��ѧ�Ų�ѯѧ����Ϣ 
			        system("PAUSE");
					break;
			case 2: FindByName(stu,szCourseName,nStudentNum); //��������ѯѧ����Ϣ 
			        system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,&nStudentNum); 	//����һ�����˵�ѡ�� 
					break;
			default:printf("\t\tѡ����������ѡ��\n");
		}//switch���� 
		
	}//while���� 
}//��Ϣ��ѯ�˵����� 


/* 
�������ܣ������˵����ļ�����ѡ����ʾ  
���������ѧ���ṹ�����飬�γ������飬ѧ������
����ֵ���� 
*/ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nSaveChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************�ļ�����ģ��************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.��ǰ�ļ�����              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.��������ļ�              |\n");
		printf("\t\t|                                     |\n");
	    printf("\t\t|         3.����ƽ�����ܳɼ�          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.�����ϼ��˵�              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   ��ѡ�������(0~3):");
		scanf("%d",&nSaveChoose);
		switch(nSaveChoose)
		{
			case 1:
				//���´��������ļ�
				CreateFile(stu,nStudentNum,0);
		  		break;
		    case 2:	//���Ϊ�����ļ� 
				CreateFileAs(stu,nStudentNum,0);
		  		break;
		    case 3:	//���Ϊ�����ļ��������ܳɼ��������ɼ� 
				CreateFileAs(stu,nStudentNum,1);
		  		break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum); 				//����һ�����˵�ѡ�� 
					break;
			default:printf("\t\tѡ����������ѡ��\n");
		}//switch���� 
		system("PAUSE");
	}//while���� 
}//�ļ�����˵����� 


