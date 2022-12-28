#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxcourse 6
#define maxpeople 30

struct Student {
	char name[20];
	long id;
	int grade[6];
};
struct Student student[maxpeople];
int coursenum = 0, studentnum = 0, ret = 1, dataret = 0;
char *course[maxcourse];
int studenttotal[maxpeople];
int cpy[maxpeople];
int menu();//菜单
void savedata();//录入学生的学号、姓名和各科考试成绩；
void fuction2();//计算每门课程的总分和平均分；
void fuction3();//计算每个学生的总分和平均分
void fuction4();//按每个学生的总分由高到低排出名次表
void fuction5();//按每个学生的总分由低到高排出名次表
void fuction6();//按学号由小到大排出成绩表
void fuction7();//按姓名的字典顺序排出成绩表
void fuction8();//按学号查询学生排名及其考试成绩
void fuction9();//按姓名查询学生排名及其考试成绩
void fuction10();//算百分比
void fuction11();//输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
void back();
void clear();
void Printf(int a[], int studentnum);
void rank(int a[]);

int main(void) {
	system("title 学生成绩管理系统 v 1.0");
	int i;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t请输入课程门数(最大为6):");
	scanf("%d", &coursenum);
	for (int j = 0; j < coursenum; j++) {
		printf("请输入第%d个课程名字:\n", j + 1);
		course[j] = (char *)malloc(30 * sizeof(char));
		scanf("%s", course[j]);
	}
	while (ret == 1) {
		i = menu();
		switch (i) {
			case 1:
				system("cls");
				savedata();
				break;
			case 2:
				system("cls");
				fuction2();
				break;
			case 3:
				system("cls");
				fuction3();
				break;
			case 4:
				system("cls");
				fuction4();
				break;
			case 5:
				system("cls");
				fuction5();
				break;
			case 6:
				system("cls");
				fuction6();
				break;
			case 7:
				system("cls");
				fuction7();
				break;
			case 8:
				system("cls");
				fuction8();
				break;
			case 9:
				system("cls");
				fuction9();
				break;
			case 10:
				system("cls");
				fuction10();
				break;
			case 11:
				system("cls");
				fuction11();
				break;
			case 0:
				system("cls");
				printf("\n\n\n\n\n\n\n");
				printf("\t\t\t______________________________________________________________________________\n\n");
				printf("\t\t\t\t\t\t\t\n\t\t\t\t\t\t\tprogram end!\n\n");
				printf("\t\t\t______________________________________________________________________________\n\n");
				printf("\n\n\n\n\n\n\n");
				exit(0);
		}
	}
	return 0;
}

int menu() { //菜单界面
	int i;
	system("cls");
	printf("\n\n");
	printf("\t\t\t                       学生成绩管理系统    version 1.0\n\n");
	printf("\t\t\t\t\t\t  当前日期:");
	system("date /T");
	printf("\n\t\t\t\t\t\t  当前时间:");
	system("time /T");
	printf("\t\t\t______________________________________________________________________________\n");
	printf("\t\t\t|                                                                            |\n");
	printf("\t\t\t|                1.  Input record                                            |\n");
	printf("\t\t\t|                2.  Caculate total and average score of every course        |\n");
	printf("\t\t\t|                3.  Caculate total and average score of every student       |\n");
	printf("\t\t\t|                4.  Sort in descending order by score                       |\n");
	printf("\t\t\t|                5.  Sort in ascending order by score                        |\n");
	printf("\t\t\t|                6.  Sort in ascending order by number                       |\n");
	printf("\t\t\t|                7.  Sort in dictionary order by name                        |\n");
	printf("\t\t\t|                8.  Search by number                                        |\n");
	printf("\t\t\t|                9.  Search by name                                          |\n");
	printf("\t\t\t|                10. Statistic analysis                                      |\n");
	printf("\t\t\t|                11. List record                                             |\n");
	printf("\t\t\t|                12. Write to a file (暂时未实现)                            |\n");
	printf("\t\t\t|                13. Read from a file(暂时未实现)                            |\n");
	printf("\t\t\t|                0.  Exit                                                    |\n");
	printf("\t\t\t______________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\tPlease Input your choice:");
	scanf("%d", &i);
	return i;
}

void back() { //返回函数
	char a = 32;
	int b = 1;
	printf("请按(Y/y)返回,按0则退出程序: ");
	getchar();
	while (b) {
		scanf("%c", &a);
		if (a == 'y' || a == 'Y' || a == '0') {
			b = 0;
			if (a == '0')
				ret = 0;
		} else {
			printf("输入有误请重新输入\n");
		}
	}
}

void clear() { //初始化数据
	for (int i = 0; i < studentnum; i++) {
		studenttotal[i] = 0;
	}
}

void Printf(int a[], int n) { //打印成绩表
	printf("学号\t姓名\t");
	for (int i = 0; i < coursenum; i++)
		printf("%s\t", course[i]);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%ld\t%s\t", student[a[i]].id, student[a[i]].name);
		for (int j = 0; j < coursenum; j++) {
			printf("%3d\t", student[a[i]].grade[j]);
		}
		printf("\n\n");
	}
}

void rank(int a[]) { //排名函数
	int temp;
	clear();
	for (int i = 0; i < studentnum; i++) {
		for (int j = 0; j < coursenum; j++) {
			studenttotal[i] += student[i].grade[j];
		}
	}
	for (int i = 0; i < studentnum; i++) {
		a[i] = i;
		cpy[i] = studenttotal[i];
	}
	int max;
	for (int i = 0; i < studentnum - 1; i++) {
		max = i;
		for (int j = i + 1; j < studentnum; j++) {
			if (cpy[max] < cpy[j]) {
				max = j;
			}
		}
		temp = cpy[max];
		cpy[max] = cpy[i];
		cpy[i] = temp;
		temp = a[max];
		a[max] = a[i];
		a[i] = temp;
	}
}

void savedata() { //写入数据
	int n;
	printf("请输入本次录入数据学生人数(最大为30):");
	scanf("%d", &n);
	studentnum += n;
	for (; dataret < studentnum; dataret++) {
		printf("请输入第%d个学生的名字:", dataret + 1);
		scanf("%s", student[dataret].name);
		printf("请输入第%d个学生的学号:", dataret + 1);
		scanf("%ld", &student[dataret].id);
		for (int j = 0; j < coursenum; j++) {
			printf("请输入第%d个学生的%s成绩:", dataret + 1, course[j]);
			scanf("%d", &student[dataret].grade[j]);
		}
	}
	back();
}

void fuction2() { //计算各科目总分平均分
	int coursetotal[maxcourse];
	for (int i = 0; i < coursenum; i++) {
		coursetotal[i] = 0;
	}
	for (int i = 0; i < coursenum; i++) {
		for (int j = 0; j < studentnum; j++) {
			coursetotal[i] += student[j].grade[i];
		}
	}
	for (int i = 0; i < coursenum; i++) {
		printf("%s的总分为%d\n", course[i], coursetotal[i]);
		printf("%s的平均分为%.2f\n\n", course[i], (float)coursetotal[i] / studentnum);
	}
	back();
}

void fuction3() { //计算学生总分平均分
	clear();
	for (int i = 0; i < studentnum; i++) {
		for (int j = 0; j < coursenum; j++) {
			studenttotal[i] += student[i].grade[j];
		}
	}
	for (int i = 0; i < studentnum; i++) {
		printf("%s的总分为%d,平均分为%.2f\n", student[i].name, studenttotal[i], (float)studenttotal[i] / coursenum);
	}
	back();
}

void fuction4() { //按成绩高到低排名=-=
	int a[maxpeople];
	rank(a);
	for (int i = 0; i < studentnum; i++) {
		printf("[%d]:%s\t总分为:%3d\n", i + 1, student[a[i]].name, studenttotal[a[i]]);
	}
	back();
}

void fuction5() { //按成绩低到高排名=-=
	int a[maxpeople];
	int temp;
	clear();
	for (int i = 0; i < studentnum; i++) {
		for (int j = 0; j < coursenum; j++) {
			studenttotal[i] += student[i].grade[j];
		}
	}
	for (int i = 0; i < studentnum; i++) {
		a[i] = i;
		cpy[i] = studenttotal[i];
	}
	int min;
	for (int i = 0; i < studentnum - 1; i++) {
		min = i;
		for (int j = i; j < studentnum; j++) {
			if (cpy[min] > cpy[j]) {
				min = j;
			}
		}
		temp = cpy[min];
		cpy[min] = cpy[i];
		cpy[i] = temp;
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
	for (int i = 0; i < studentnum; i++) {
		printf("[%d]:%s\t总分为:%4d\n", i + 1, student[a[i]].name, studenttotal[a[i]]);
	}
	back();
}

void fuction6() { //学号从大到小打成绩表=-=
	int a[maxpeople];
	int temp;
	for (int i = 0; i < studentnum; i++) {
		a[i] = i;
		cpy[i] = student[i].id;
	}
	int max;
	for (int i = 0; i < studentnum - 1; i++) {
		max = i;
		for (int j = i; j < studentnum; j++) {
			if (cpy[max] < cpy[j]) {
				max = j;
			}
		}
		temp = cpy[max];
		cpy[max] = cpy[i];
		cpy[i] = temp;
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}
	Printf(a, studentnum);
	back();
}

void fuction7() { //按姓名字典顺序打成绩表=-=
	int a[maxpeople];
	int temp;
	for (int i = 0; i < studentnum; i++) {
		a[i] = i;
	}
	for (int i = 0; i < studentnum - 1; i++) {
		for (int j = i; j < studentnum; j++) {
			if (strcmp(student[i].name, student[j].name) > 0) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	Printf(a, studentnum);
	back();
}

void fuction8() { //按学号查询排名集成绩
	long a;
	int ret_8 = 1, ret_8_1 = 1;
	int cpy2[maxpeople];
hi:
	printf("请输入想查询成绩的学号: ");
	scanf("%ld", &a);
	int b[maxpeople], c[1];
	rank(b);
	char d;
	for (int i = 0; i < studentnum; i++) {
		cpy2[i] = 1;
	}
	for (int i = 0; i < studentnum; i++) {
		ret_8_1 = 1;
		for (int j = 0; j < studentnum; j++) {
			if (studenttotal[j] > studenttotal[i]) {
				cpy2[i]++;
			}
		}
	}
	while (ret_8) {
		for (int i = 0; i < studentnum; i++) {
			if (a == student[i].id) {
				c[0] = i;
				printf("该学生总分:%d\t排名:%d\n", studenttotal[i], cpy2[i]);
				Printf(c, 1);
				ret_8 = 0;
			}
		}
		if (ret_8 == 0)
			break;
		printf("抱歉,没有找到该学号的数据,是否重新输入(y/Y)?");
		getchar();
		scanf("%c", &d);
		if (d == 'Y' || d == 'y')
			goto hi;
	}
	back();
}

void fuction9() { //按姓名查询学生排名及其考试成绩
	char a[20];
	int ret_8 = 1;
	int b[maxpeople], c[1], cpy2[maxpeople];
	char d;
	rank(b);
	for (int i = 0; i < studentnum; i++) {
		cpy2[i] = 1;
	}
	for (int i = 0; i < studentnum; i++) {
		for (int j = 0; j < studentnum; j++) {
			if (studenttotal[j] > studenttotal[i]) {
				cpy2[i]++;
			}
		}
	}
hi:
	printf("请输入想查询成绩的姓名: ");
	scanf("%s", a);
	while (ret_8) {
		for (int i = 0; i < studentnum; i++) {
			if (strcmp(a, student[i].name) == 0) {
				c[0] = i;
				printf("该学生总分:%d\t排名:%d\n", studenttotal[i], cpy2[i]);
				Printf(c, 1);
				ret_8 = 0;
			}
		}
		if (ret_8 == 0)
			break;
		printf("抱歉,没有找到该学生的数据,是否重新输入(y/Y)?");
		getchar();
		scanf("%c", &d);
		if (d == 'Y' || d == 'y')
			goto hi;
	}
	back();
}

void fuction10() {
	int a[maxcourse][5];
	for (int i = 0; i < maxcourse; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < coursenum; i++) {
		for (int j = 0; j < studentnum; j++) {
			if (student[j].grade[i] <= 59)
				a[i][4]++;
			else if (student[j].grade[i] <= 69)
				a[i][3]++;
			else if (student[j].grade[i] <= 79)
				a[i][2]++;
			else if (student[j].grade[i] <= 89)
				a[i][1]++;
			else if (student[j].grade[i] <= 100)
				a[i][0]++;
		}
	}
	printf("科目\t优秀(90~100)\t良好(80~89)\t中等(70~79)\t及格(60~69)\t不及格(0~59)\n");
	for (int i = 0; i < coursenum; i++) {
		printf("%s\t", course[i]);
		for (int j = 0; j < 5; j++) {
			printf("%d[%.2f%%]\t", a[i][j], (float)a[i][j] * 100 / studentnum);
		}
		printf("\n");
	}
	back();
}

void fuction11() { //输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
	int a[maxpeople];
	int coursetotal[maxcourse];
	for (int i = 0; i < coursenum; i++) {
		coursetotal[i] = 0;
	}
	for (int i = 0; i < coursenum; i++) {
		for (int j = 0; j < studentnum; j++) {
			coursetotal[i] += student[j].grade[i];
		}
	}
	for (int i = 0; i < studentnum; i++) {
		a[i] = i;
	}
	Printf(a, studentnum);
	for (int i = 0; i < coursenum; i++) {
		printf("\t%s\t", course[i]);
	}
	printf("\n");
	printf("总分\t");
	for (int i = 0; i < coursenum; i++) {
		printf("%d\t", coursetotal[i]);
	}
	printf("\n");
	printf("平均分\t");
	for (int i = 0; i < coursenum; i++) {
		printf("%.1f\t\t", (float)coursetotal[i] / studentnum);
	}
	back();
}




