#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

//int main(){
//    int num1 = -5,num2 = 2;
//    num1 = num2++ - --num2;
//    cout<<num1<<" "<<num2;
//}
//int main() {
//    int i, j, t, k, a[10] = {2, 4, 67, 3, 7, 5, 7, 3, 4, 6};
//    for (i = 0; i < 10 - 1; i++) {
//        k = i;
//        for (j = i + 1; j < 10; j++) {
//            if (a[k] > a[j]) {
//                k = j;
//            }
//        }
//        t = a[i];
//        a[i] = a[k];
//        a[k] = t;
//
//    }
//
//    for (i = 0; i < 10; i++) {
//        printf("%d ", a[i]);
//    }
//}

#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "function.h"

///////////////////////////////////////////////////////////////////////////////
/*ѧ����Ϣ������---���ӣ�ɾ�����޸�*/

/* 
�������ܣ�������N��ѧ����Ϣ���������ӵ�ѧ���������޸�ѧ��Ŀǰ����Ŀ 
���������ѧ���ṹ�����飬�γ���������
����ֵ��ѧ����������ָ��������أ���Ϊ���������仯      
����ֵ����ӵ�ѧ������ 
*/
int AddStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
	int n = 0;
	printf("\n\t\t\t����������ѧ����Ϣģ��\n");
	printf("                ��������ӵ�ѧ��������");
	scanf("%d", &n);
	for (int i = 1 + *npStudentNum; i <= n + *npStudentNum; i++)
	{
		printf("                ������� %d ��ѧ��ѧ��:", i);
		scanf("%d", &stu[i].nNumber);
		printf("                ������");
		scanf("%s", &stu[i].szName[STRLENGTH]);
		printf("                ���ĳɼ���");
		scanf("%d", &stu[i].fScore[0]);
		printf("                ��ѧ�ɼ���");
		scanf("%d", &stu[i].fScore[1]);
		printf("                Ӣ��ɼ���");
		scanf("%d", &stu[i].fScore[2]);
		printf("                ======================================\n\n\n");
	}
	*npStudentNum += n;
	return 1; //������ӵ�ѧ����

} //AddSudentInfo��������

/* 
�������ܣ����ѧ����Ϣ���� ������������֣�1������ƽ���ɼ����ܳɼ��ģ�1����û�� 
���������ѧ���ṹ�����飬�γ��������飬ѧ���������ļ���ʽ��־���Ƿ���ƽ���ɼ����ܳɼ���
          û��ƽ���ɼ����ܳɼ��ļ���־Ϊ 0����ƽ���ɼ����ܳɼ��ļ���־Ϊ 1 
         nFrom ��ʾ�ӵڼ�����ʼ�����nTo��ʾ�䵽�ڼ�������  
����ֵ����      
*/

void OutputStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum, int nFlag,
					   int nFrom, int nTo)
{
	printf("\n\t\t\t��������ʾѧ����Ϣģ��\n");
	printf("        �����ļ�studentlist.txt��Ŀǰ����%d��ѧ��\n\n", nStudentNum);
	if (nFlag == 0)
	{
		printf("STL             ѧ��  ����      ����    ��ѧ    Ӣ��\n");
		printf("                ======================================\n");
		for (int i = nFrom; i <= nTo; i++)
		{
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f", stu[i].nNumber, stu[i].szName[STRLENGTH], stu[i].fScore[1], stu[i].fScore[2], stu[i].fScore[3], stu[i].fAveScore, stu[i].fSumScore);
		}
	}
	else if (nFlag == 1)
	{
		printf("STLSA           ѧ��  ����      ����    ��ѧ    Ӣ��    �ܳɼ�    ƽ���ɼ�\n");
		printf("                ============================================================\n");
		for (int i = nFrom; i <= nTo; i++)
		{
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f     %.2f        %.2f", stu[i].nNumber, stu[i].szName[STRLENGTH], stu[i].fScore[1], stu[i].fScore[2], stu[i].fScore[3], stu[i].fAveScore, stu[i].fSumScore);
		}
	}
}
//���ѧ����Ϣ��������

/* 
�������ܣ�ɾ��ĳλѧ����Ϣ�ĺ����������ڲ��Դ����� 
���������ѧ���ṹ�����飬�γ���������
����ֵ��ѧ����������ָ�������ʽ����Ϊ������仯�� 
         nFrom ��ʾ�ӵڼ�����ʼ�����nTo��ʾ�䵽�ڼ�������  
����ֵ���Ƿ�ɹ�ɾ����0Ϊû�ɹ�ɾ����1Ϊ�ɹ�ɾ��      
*/
int DeleteStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
	int num = 0;
	int flag = 0;
	printf("\n\t\t\t������ɾ��ѧ����Ϣģ��\n");
	printf("                ������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d", &num);
	for (int i = 0; i < *npStudentNum; i++)
	{
		if (num == stu[i].nNumber)
		{
			for (int j = i; j < *npStudentNum; j++)
			{
				stu[j] = stu[j + 1];
				flag = 1;
				return 1;
			}
		}
		if (flag == 0)
		{
			return 0;
		}
		return 1;
	} //DeleteStudentInfo��������

	/* 
�������ܣ��޸�ĳλѧ���ĳɼ���Ϣ�������ڲ��Դ����� 
���������ѧ���ṹ�����飬�γ��������飬ѧ������ 
����ֵ���Ƿ�ɹ��޸ģ�0Ϊû�ɹ��޸ģ�1Ϊ�ɹ��޸�     
*/
	int ModifyStudentScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
	{
		int num = 0;
		printf("\n\t\t\t �������޸�ѧ����Ϣģ��\n");
		int flag = 1;
		printf("                ������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		scanf("%d", &num);
		for (int i = 0; i < nStudentNum; i++)
		{
			if (stu[i].nNumber == num)
			{
				flag = 0;
				printf("\n");
				printf("                        ************************************\n");
				printf("                        *         0.���ĳɼ�               *\n");
				printf("                        *         1.��ѧ�ɼ�               *\n");
				printf("                        *         2.Ӣ��ɼ�               *\n");
				printf("                        ************************************\n");
				printf("                ��ѡ��Ҫ�޸�ʲô�ɼ�(press 0.1.2)��");
				int x = 0;
				scanf("%d", &x);
				printf("                �������޸ĺ�ĳɼ�(0-100):");
				scanf("%d", &stu[i].fScore[x]);
				printf("                ......���޸�%d��ѧ������ѧ�ɼ�......", num);
			}
		}
		if (flag == 1)
		{
			printf("                û�������ѧ�ţ���������ȷ��ѧ��");
		}
		return 1;
	} //ModifyScore��������

	//
	//
	//void Srand(int a, int b, int r[]);
	//
	//void Adder(int *p);
	//
	//int main() {
	//    int x, y, num[N], tz;
	//    printf("����(m,n)��Χ�ڵ�N���������������m,n(m<n&&n-m>N):");
	//    scanf("%d%d", &x, &y);
	//    do {
	//        Srand(x, y, num);
	//        Adder(num);
	//        printf("�Ƿ������\n1.��\t2.��\n");
	//        scanf("%d", &tz);
	//        system("cls");
	//    } while (tz == 1);
	//    return 0;
	//}
	//
	//void Srand(int a, int b, int r[]) {
	//    srand(time(nullptr));
	//    int i;
	//    for (i = 1; i < 2 * N + 1; i++) {
	//        r[i] = a + rand() % (b - a + 1);        //����һ�������
	//    }
	////    for(i=1;i<2*N+1;i++)
	////      {
	////        printf("%d\t",r[i]);
	////        if(i%5==0)
	////            printf("\n");
	////      }
	//}
	//
	//void Adder(int *p) {
	//    int answer[N], error[N];
	//
	//    int i, j = 0, k = 0, gg = 0;
	//    for (i = 1; i < N + 1; i++, p += 2) {
	//        printf("%d: %d + %d =", i, *(p + 1), *(p + 2));
	//        scanf("%d", answer + i);
	//        if (*(p + 2) + *(p + 1) == *(answer + i)) {
	//            gg++;
	//        } else {
	//            error[j] = i;
	//            j++;
	//        }
	//        k = j;
	//    }
	//    if (!k) {
	//        printf("��ϲ��,ȫ���ˣ�");
	//        gg = 0;
	//    } else {
	//        printf("��ĵ÷���%d\n", gg);
	//        gg = 0;
	//        printf("������Ĵ�����:\n");
	//        for (j = 0; j < k; j++)
	//            printf("%d��\t", error[j]);
	//
	//    }
	//    printf("\n");
	//}
