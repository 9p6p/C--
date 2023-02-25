#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define N 20
struct course
{
	float Chin;
	float Engl;
	float math;
	float prof;
};
struct student 
{
	int num;
	char name[11];
	char sex[3];
	int age;
	struct course score;
	char addr[15];
	char acd[20];
	char tel[15];
	char qq[15];
	char email[20];
}stu[40];
//�������ع�꺯��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

static struct student *st[40],*st_Chi[40],*st_mat[40],*st_Eng[40],*st_pro[40],*st_sum[40],*temp;
static int sum_m=0, sum_w=0;      
int rank;

void quiz(); void total(); void basicput(); void basicdata(); void sort(); void input(); void sort_score(); void inquiry();
void output(struct student *pst[40],char name);                            void information(struct student *pst[40],int i);

main()
{
	HideCursor();
	FILE *fp;
    if((fp=fopen("ѧ������.txt","r"))==NULL)
    {
    	printf("Error on opening this file!\n");     exit(1);
    }
    else printf("�Ѷ����ļ� ");
    fread(stu,sizeof(struct student),N,fp);
    fclose(fp);
    for(int i=0;i<N;i++)  {st[i]=st_Chi[i]=st_mat[i]=st_Eng[i]=st_pro[i]=st_sum[i]=&stu[i];}
    printf("ALL RIGHT\n");quiz();sort();
	char c;
    while((c=getch())!='8')
    switch(c)
	{
		case'1':basicdata();quiz();break;
		case'2':total();quiz();break;
		case'3':input();sort();quiz();break;
		case'4':inquiry();quiz();break;
		case'5':sort_score();quiz();break;
		case'6':printf("*******************************\n");printf("\n   ��������      ��ӡ�ؾ�  \n");printf("\n*******************************\n");quiz();break;
		default:printf("  ��Ч���룡���������룺\n");break;
	}
}

void total()
{   char man[3]="��",woman[3]="Ů"; 
	for(int i=0;i<N;i++) 
	{
		if(st[i]->sex[0]==man[0]&&st[i]->sex[1]==man[1]) sum_m++;
	    else if(st[i]->sex[0]==woman[0]&&st[i]->sex[1]==woman[1]) sum_w++;
	    else printf("Data is wrong.\n");
    }
	printf("\n  ȫ��������:%d ��������:%d Ů������:%d\n",sum_m+sum_w,sum_m,sum_w);
}
inline void basicput()
{   printf("*******************************\n        �ɼ�����ϵͳ:\n  1.�鿴ȫ��ѧ����Ϣ\n  2.�鿴ȫ������\n  3.����γ̳ɼ�\n");
	printf("  4.�鿴ĳѧ����ϸ��Ϣ\n  5.�鿴�ɼ�����\n  6.��Ȩ����\n  8.�˳�ϵͳ\n*******************************\n");
}
void quiz()
{   printf("\n  �Ƿ�������������밴 1�����밴 2\n");
	repeat_quiz:
	switch(getch())
	{
		case'1':system("cls");basicput();break;
		case'2':exit(0);
		default:printf("  ��Ч���룡���������룺\n");goto repeat_quiz;
	}
}
void input()
{   printf("  �������ĳɼ��밴 1\n  ������ѧ�ɼ��밴 2\n  ����Ӣ��ɼ��밴 3\n  ����רҵ�ɼ��밴 4\n  �˳���ģ���밴 5\n");
	repeat_input:
	switch(getch())
	{
	    case'1':printf("ѧ��   ����     ���ĳɼ�\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.Chin);}break;
	    case'2':printf("ѧ��   ����     ��ѧ�ɼ�\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.math);}break;
	    case'3':printf("ѧ��   ����     Ӣ��ɼ�\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.Engl);}break;
	    case'4':printf("ѧ��   ����     רҵ�ɼ�\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.prof);}break;
		case'5':system("cls");basicput();break;
	    default:printf("  ��Ч���룡���������룺\n");goto repeat_input;
	}
}
void sort()  /*�ṹָ������ָ��ɼ�*/ 
{   for(int i=1;i<N;i++)
		for(int j=0;j<N-i;j++)
		{
		    if(st_Chi[j]->score.Chin<st_Chi[j+1]->score.Chin)
			{  temp=st_Chi[j];  st_Chi[j]=st_Chi[j+1];  st_Chi[j+1]=temp; }
			if(st_mat[j]->score.math<st_mat[j+1]->score.math)
			{  temp=st_mat[j];  st_mat[j]=st_mat[j+1];  st_mat[j+1]=temp; }
			if(st_Eng[j]->score.Engl<st_Eng[j+1]->score.Engl)
			{  temp=st_Eng[j];  st_Eng[j]=st_Eng[j+1];  st_Eng[j+1]=temp; }
			if(st_pro[j]->score.prof<st_pro[j+1]->score.prof)
			{  temp=st_pro[j];  st_pro[j]=st_pro[j+1];  st_pro[j+1]=temp; }
			if((st_sum[j]->score.Chin+st_sum[j]->score.math+st_sum[j]->score.Engl+st_sum[j]->score.prof)
			<(st_sum[j+1]->score.Chin+st_sum[j+1]->score.math+st_sum[j+1]->score.Engl+st_sum[j+1]->score.prof))
			{  temp=st_sum[j];  st_sum[j]=st_sum[j+1];  st_sum[j+1]=temp; }
		}
}
void basicdata()
{   printf("  �鿴ѧ��������Ϣ�밴 1\n  �鿴ѧ���ɼ���Ϣ�밴 2\n  �˳���ģ���밴 3\n");
    repeat_data:
	switch(getch())
    {
    	case'1':printf("ѧ��   ����     �Ա�  ����  ����       ����ѧԺ            �绰����     QQ           email\n");
	            for(int i=0;i<N;i++)
	            {printf("%-7d%-9s%-6s%-6d%-11s%-20s%s  %s  %s\n",st[i]->num,st[i]->name,st[i]->sex,st[i]->age,st[i]->addr,st[i]->acd,st[i]->tel,st[i]->qq,st[i]->email);}
		        break;
		case'2':printf("ѧ��   ����     ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  רҵ�ɼ�  �ۺϳɼ�\n");
	            for(int i=0;i<N;i++)	
				{printf("%-7d%-9s%-10.1f%-10.1f%-10.1f%-10.1f%.1f\n",st[i]->num,st[i]->name,st[i]->score.Chin,
	             st[i]->score.math,st[i]->score.Engl,st[i]->score.prof,st[i]->score.Chin+st[i]->score.math+st[i]->score.Engl+st[i]->score.prof);}
				break;
    	case'3':system("cls");basicput();break;
    	default:printf("  ��Ч���룡���������룺\n");goto repeat_data;
	}
}
void information(struct student *pst[40],int i)
{   printf("\nѧ��   ����     �Ա�  ����  ����       ����ѧԺ            �绰����     QQ           email\n");
	printf("%-7d%-9s%-6s%-6d%-11s%-20s%s  %s  %s\n",pst[i]->num,pst[i]->name,pst[i]->sex,pst[i]->age,pst[i]->addr,pst[i]->acd,pst[i]->tel,pst[i]->qq,pst[i]->email);
    printf("\n���ĳɼ���%.1f ��ѧ�ɼ���%.1f Ӣ��ɼ���%.1f רҵ�ɼ���%.1f �ۺϳɼ���%.1f\n",pst[i]->score.Chin,
	pst[i]->score.math,pst[i]->score.Engl,pst[i]->score.prof,pst[i]->score.Chin+pst[i]->score.math+pst[i]->score.Engl+pst[i]->score.prof);
}
void output(struct student *pst[40],char name)
{   if(name=='O')
    {printf("\n����������");
	 scanf("%d",&rank); rank-=1;
	 information(pst,rank);}
    else 
	{   rank=1; if(name=='C')	for(int i=0;i<N;i++) printf("%-7d%-9s%5.1f    %-2d\n",pst[i]->num,pst[i]->name,pst[i]->score.Chin,rank++);
	       else if(name=='M')	for(int i=0;i<N;i++) printf("%-7d%-9s%5.1f    %-2d\n",pst[i]->num,pst[i]->name,pst[i]->score.math,rank++);
	       else if(name=='E')	for(int i=0;i<N;i++) printf("%-7d%-9s%5.1f    %-2d\n",pst[i]->num,pst[i]->name,pst[i]->score.Engl,rank++);
	       else if(name=='P')	for(int i=0;i<N;i++) printf("%-7d%-9s%5.1f    %-2d\n",pst[i]->num,pst[i]->name,pst[i]->score.prof,rank++);
	       else if(name=='S')	for(int i=0;i<N;i++) 
	                            printf("%-7d%-9s%5.1f    %-2d\n",pst[i]->num,pst[i]->name,pst[i]->score.Chin+pst[i]->score.math+pst[i]->score.Engl+pst[i]->score.prof,rank++);}
}
void inquiry()
{	printf("  ��ѧ�Ų�ѯ�밴 1\n  ���ɼ�������ѯ�밴 2\n  �˳���ģ���밴 3\n");
    repeat_inquiry:
	switch(getch())
	{
		case'1':printf("\n  ��������Ҫ��ѯ��ѧ�ţ� ");
	            scanf("%d",&rank);
	            for(int i=0;i<N;i++)
	            {
		            if(stu[i].num==rank)
		            {   information(st,i);
			            break;
		            }
		            if(i==N-1) printf("\n  δ�ҵ���ѧ��\n"); 
	            }break;
		case'2':printf("\n  ������������ѯ�밴 1\n  ����ѧ������ѯ�밴 2\n  ��Ӣ��������ѯ�밴 3\n  ��רҵ������ѯ�밴 4\n  ���ۺ�������ѯ�밴 5\n  �˳���ģ���밴  6\n");
				repeat_score_inquiry:
				switch(getch())
				{
					case'1':output(st_Chi,'O');break;
				    case'2':output(st_mat,'O');break;
				    case'3':output(st_Eng,'O');break;
					case'4':output(st_pro,'O');break;
					case'5':output(st_sum,'O');break;
					case'6':system("cls");basicput();goto repeat_score_inquiry;
				}quiz;break;
		case'3':system("cls");basicput();break;
		default:printf("  ��Ч���룡���������룺\n");goto repeat_inquiry;
	}
}
void sort_score()
{   printf("\n  �鿴���ĳɼ������밴 1\n  �鿴��ѧ�ɼ������밴 2\n  �鿴Ӣ��ɼ������밴 3\n  �鿴רҵ�ɼ������밴 4\n  �鿴�ۺϳɼ������밴 5\n  �˳���ģ���밴 6\n");
    repeat_score:
	switch(getch())
	{
	    case'1':printf("ѧ��   ����     ���ĳɼ� ����\n");output(st_Chi,'C');break;
		case'2':printf("ѧ��   ����     ��ѧ�ɼ� ����\n");output(st_mat,'M');break;
		case'3':printf("ѧ��   ����     Ӣ��ɼ� ����\n");output(st_Eng,'E');break;
		case'4':printf("ѧ��   ����     רҵ�ɼ� ����\n");output(st_pro,'P');break;
		case'5':printf("ѧ��   ����     �ۺϳɼ� ����\n");output(st_sum,'S');break;
		case'6':system("cls");basicput();break;
		default:printf("  ��Ч���룡���������룺\n");goto repeat_score;
    }
}