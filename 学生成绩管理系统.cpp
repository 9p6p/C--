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
//定义隐藏光标函数
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
    if((fp=fopen("学生数据.txt","r"))==NULL)
    {
    	printf("Error on opening this file!\n");     exit(1);
    }
    else printf("已读入文件 ");
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
		case'6':printf("*******************************\n");printf("\n   互加所有      翻印必究  \n");printf("\n*******************************\n");quiz();break;
		default:printf("  无效输入！请重新输入：\n");break;
	}
}

void total()
{   char man[3]="男",woman[3]="女"; 
	for(int i=0;i<N;i++) 
	{
		if(st[i]->sex[0]==man[0]&&st[i]->sex[1]==man[1]) sum_m++;
	    else if(st[i]->sex[0]==woman[0]&&st[i]->sex[1]==woman[1]) sum_w++;
	    else printf("Data is wrong.\n");
    }
	printf("\n  全班总人数:%d 男生人数:%d 女生人数:%d\n",sum_m+sum_w,sum_m,sum_w);
}
inline void basicput()
{   printf("*******************************\n        成绩管理系统:\n  1.查看全班学生信息\n  2.查看全班人数\n  3.输入课程成绩\n");
	printf("  4.查看某学生详细信息\n  5.查看成绩排名\n  6.版权所有\n  8.退出系统\n*******************************\n");
}
void quiz()
{   printf("\n  是否继续操作？是请按 1，否请按 2\n");
	repeat_quiz:
	switch(getch())
	{
		case'1':system("cls");basicput();break;
		case'2':exit(0);
		default:printf("  无效输入！请重新输入：\n");goto repeat_quiz;
	}
}
void input()
{   printf("  输入语文成绩请按 1\n  输入数学成绩请按 2\n  输入英语成绩请按 3\n  输入专业成绩请按 4\n  退出该模块请按 5\n");
	repeat_input:
	switch(getch())
	{
	    case'1':printf("学号   姓名     语文成绩\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.Chin);}break;
	    case'2':printf("学号   姓名     数学成绩\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.math);}break;
	    case'3':printf("学号   姓名     英语成绩\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.Engl);}break;
	    case'4':printf("学号   姓名     专业成绩\n");for(int i=0;i<N;i++){printf("%-7d%-9s",st[i]->num,st[i]->name);scanf("%f",&st[i]->score.prof);}break;
		case'5':system("cls");basicput();break;
	    default:printf("  无效输入！请重新输入：\n");goto repeat_input;
	}
}
void sort()  /*结构指针排序，指向成绩*/ 
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
{   printf("  查看学生基本信息请按 1\n  查看学生成绩信息请按 2\n  退出该模块请按 3\n");
    repeat_data:
	switch(getch())
    {
    	case'1':printf("学号   姓名     性别  年龄  籍贯       所属学院            电话号码     QQ           email\n");
	            for(int i=0;i<N;i++)
	            {printf("%-7d%-9s%-6s%-6d%-11s%-20s%s  %s  %s\n",st[i]->num,st[i]->name,st[i]->sex,st[i]->age,st[i]->addr,st[i]->acd,st[i]->tel,st[i]->qq,st[i]->email);}
		        break;
		case'2':printf("学号   姓名     语文成绩  数学成绩  英语成绩  专业成绩  综合成绩\n");
	            for(int i=0;i<N;i++)	
				{printf("%-7d%-9s%-10.1f%-10.1f%-10.1f%-10.1f%.1f\n",st[i]->num,st[i]->name,st[i]->score.Chin,
	             st[i]->score.math,st[i]->score.Engl,st[i]->score.prof,st[i]->score.Chin+st[i]->score.math+st[i]->score.Engl+st[i]->score.prof);}
				break;
    	case'3':system("cls");basicput();break;
    	default:printf("  无效输入！请重新输入：\n");goto repeat_data;
	}
}
void information(struct student *pst[40],int i)
{   printf("\n学号   姓名     性别  年龄  籍贯       所属学院            电话号码     QQ           email\n");
	printf("%-7d%-9s%-6s%-6d%-11s%-20s%s  %s  %s\n",pst[i]->num,pst[i]->name,pst[i]->sex,pst[i]->age,pst[i]->addr,pst[i]->acd,pst[i]->tel,pst[i]->qq,pst[i]->email);
    printf("\n语文成绩：%.1f 数学成绩：%.1f 英语成绩：%.1f 专业成绩：%.1f 综合成绩：%.1f\n",pst[i]->score.Chin,
	pst[i]->score.math,pst[i]->score.Engl,pst[i]->score.prof,pst[i]->score.Chin+pst[i]->score.math+pst[i]->score.Engl+pst[i]->score.prof);
}
void output(struct student *pst[40],char name)
{   if(name=='O')
    {printf("\n输入排名：");
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
{	printf("  按学号查询请按 1\n  按成绩排名查询请按 2\n  退出该模块请按 3\n");
    repeat_inquiry:
	switch(getch())
	{
		case'1':printf("\n  请输入想要查询的学号： ");
	            scanf("%d",&rank);
	            for(int i=0;i<N;i++)
	            {
		            if(stu[i].num==rank)
		            {   information(st,i);
			            break;
		            }
		            if(i==N-1) printf("\n  未找到该学生\n"); 
	            }break;
		case'2':printf("\n  按语文排名查询请按 1\n  按数学排名查询请按 2\n  按英语排名查询请按 3\n  按专业排名查询请按 4\n  按综合排名查询请按 5\n  退出该模块请按  6\n");
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
		default:printf("  无效输入！请重新输入：\n");goto repeat_inquiry;
	}
}
void sort_score()
{   printf("\n  查看语文成绩排名请按 1\n  查看数学成绩排名请按 2\n  查看英语成绩排名请按 3\n  查看专业成绩排名请按 4\n  查看综合成绩排名请按 5\n  退出该模块请按 6\n");
    repeat_score:
	switch(getch())
	{
	    case'1':printf("学号   姓名     语文成绩 排名\n");output(st_Chi,'C');break;
		case'2':printf("学号   姓名     数学成绩 排名\n");output(st_mat,'M');break;
		case'3':printf("学号   姓名     英语成绩 排名\n");output(st_Eng,'E');break;
		case'4':printf("学号   姓名     专业成绩 排名\n");output(st_pro,'P');break;
		case'5':printf("学号   姓名     综合成绩 排名\n");output(st_sum,'S');break;
		case'6':system("cls");basicput();break;
		default:printf("  无效输入！请重新输入：\n");goto repeat_score;
    }
}