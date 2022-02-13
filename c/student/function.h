#define COURSENUM 3//�γ����� 
#define STRLENGTH 30//�ַ������� 
#define STUDENTNUM 100//ѧ������ 
#define FILENAME "studentlist.txt"//ȱʡ�����ļ��� 
#define FILEFLAG1  "STL" //�����ļ���ʽ��ǣ�����ѧ�����ݱ�
#define  FILEFLAG2 "STLSA" //�����ļ���ʽ��ǣ�����ѧ�����ݱ�+�ܳɼ���ƽ���ɼ� 

/* ѧ���ṹ�嶨�� */ 
struct student   
{
  int nNumber;  	//ѧ��,4λ
  char szName[STRLENGTH];	//������2-3������
  float fScore[COURSENUM];//ѧ�����ſεĳɼ�
  float fAveScore;	//ƽ����  
  float fSumScore;	//�ܳɼ� 
};

/*�˵���غ��� ����5��*/ 
//һ�����˵�ѡ����ʾ
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);	
/* �����˵�����Ϣ����ģ��˵�ѡ����ʾ  */
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);
/* �����˵����������˵�ѡ����ʾ */ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* �����˵���������ѯ�˵�ѡ����ʾ */ 
void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* �����˵����ļ�����˵�ѡ����ʾ */ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
////////////////////////////////////////////////////////////////////////////////////////

/*��Ϣ������غ���������4��*/ 
//��Ӹ�ѧ����Ϣ 
int AddStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum);
//���ѧ����Ϣ				
void OutputStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int num,int flag,int nFrom,int nTo);
// ɾ��1��ѧ����Ϣ,��������ɾ���˻���û��ɾ�� 
int DeleteStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum); 
/* �޸�ָ��ѧ���ĳɼ���Ϣ */ 
int ModifyStudentScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);  
/////////////////////////////////////////////////////////////////////////////////////////////

/*�ļ���غ���������4��*/
//�����ļ����������е�����д���ļ�				
int CreateFile(struct student stu[],int nStudentNum,int nFlag);
//�������Ϊ�����ļ��� 
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag);
//��ȡ�ļ�������ȡ�ļ��е�Ԫ����Ϣ���浽ѧ���ṹ����				
int ReadFromFile(FILE* fp,struct student stu[]);
//����ǰ��ѧ����Ϣд���ļ� 
void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag);
////////////////////////////////////////////////////////////////////////////////

/* ���������غ���������4��  */ 
//��ѧ���������� 
void SortOnNumAs(struct student stu[],int nStudentNum);
// ѡ��ʵ�ְ��ܳɼ���������   
void SortOnSumDs(struct student stu[],int nStudentNum);
// �������ƽ���� */ 
void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
//������Ƶĳɼ��ֲ�
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
/////////////////////////////////////////////////////////////////////////////////////////////

/*��ѯ��غ���������2��*/
/*��ѧ�Ų��� */
void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ; 
/*���������� */
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ;
/////////////////////////////////////////////////////////////////////////////////////////////
