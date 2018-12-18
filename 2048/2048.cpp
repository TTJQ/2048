#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;

void showx(int b[4][4])
{
	for(int i=0;i<4;i++)
		{for(int j=0;j<4;j++)
			cout<<b[i][j];
	cout<<endl;
	}
}
int getlim(int a)
{
	int sum=0;
	for(int i=1;;i++)
	{
		if(a!=0)
			sum+=1;
		else
			break;
		a=a/10;
	}
	return sum;
}
int getlim(int a[])
{
	for(int i=0;;i++)
		if(a[i]==-1)
			return i-1;
}
void show_2()
{
		cout<<"■";
	    for(int i=1;i<=4;i++)
		    cout<<setw(8)<<"■";
	    cout<<endl;
}
void show_1()
{
	for(int i=1;i<=17;i++)
		cout<<"■";
	cout<<endl;
}
void show_4(int a)
{
	int n;
	n=getlim(a);
	switch(n)
	{
	case 1:cout<<"■"<<setw(3)<<a<<setw(3)<<' ';break;
	case 2:cout<<"■"<<setw(4)<<a<<setw(2)<<' ';break;
	case 3:cout<<"■"<<setw(4)<<a<<setw(2)<<' ';break;
	case 4:cout<<"■"<<setw(5)<<a<<' ';break;
	case 0:cout<<"■"<<setw(6)<<' ';
	}
}
void show_3(int a[])
{
	show_4(a[0]);show_4(a[1]);show_4(a[2]);show_4(a[3]);
	cout<<"■"<<endl;
}
void show(int a[4][4])
{
	for(int i=0;i<4;i++)
	{
		int b[4];
		for(int j=0;j<4;j++) b[j]=a[i][j];
		show_1();show_2();show_3(b);show_2();
	}
	show_1();
}
void left_right(int a[4][4])
{
	int b[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			b[i][j]=a[i][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			a[i][3-j]=b[i][j];
}
void left_up(int a[4][4])
{
	int b[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			b[i][j]=a[i][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			a[i][j]=b[j][i];
}
int check_1(int a[4],int b[4])
{
	int flag=0;
	for(int i=0;i<4;i++) b[i]=0;
	if(a[0]!=0)
	{
		if(a[0]==a[1]&&a[2]==a[3]&&a[2]!=0)
	    {b[0]=1;b[2]=1;flag=1;}
		else if(a[0]==a[1])
		{b[0]=1;flag=1;}
	    else if(a[1]==0&&a[0]==a[2])
		{b[0]=1;flag=1;}
		else if(a[1]==0&&a[2]==0&&a[0]==a[3])
		{b[0]=1;flag=1;}
		else if(a[1]==a[2]&&a[1]!=0)
		{b[1]=1;flag=1;}
		else if(a[1]==a[3]&&a[1]!=0&&a[2]==0)
		{b[1]=1;flag=1;}
		else if(a[2]==a[3]&&a[2]!=0)
		{b[2]=1;flag=1;}
	}
	else
	{
		if(a[1]!=0)
		{
			if(a[1]==a[2])
			{b[1]=1;flag=1;}
			else if(a[1]==a[3]&&a[2]==0)
			{b[1]=1;flag=1;}
			else if(a[2]==a[3]&&a[2]!=0)
			{b[2]=1;flag=1;}
		}
		else
		{
			if(a[2]==a[3]&&a[2]!=0)
			{b[2]=1;flag=1;}
		}
	}
	if(flag==0)
	{
		if(a[0]==0&&(a[1]!=0||a[2]!=0||a[3]!=0))
			flag=1;
		else if(a[1]==0&&(a[2]!=0||a[3]!=0))
			flag=1;
		else if(a[2]==0&&a[3]!=0)
			flag=1;
	}
	return flag;
}
int check_left(int a[4][4],int b[4][4])
{
	int flag[4],flagx=0;
	for(int i=0;i<4;i++)
		flag[i]=check_1(a[i],b[i]);
	for(int i=0;i<4;i++)
		if(flag[i]==1){flagx=1;}
	return flagx;
}
int check_right(int a[4][4],int b[4][4])
{
	left_right(a);
	int flag;
	flag=check_left(a,b);
	left_right(a);
	left_right(b);
	return flag;
}
int check_up(int a[4][4],int b[4][4])
{
	left_up(a);
	int flag;
	flag=check_left(a,b);
	left_up(a);
	left_up(b);
	return flag;
}
int check_down(int a[4][4],int b[4][4])
{
	left_up(a);
	int flag;
	flag=check_right(a,b);
	left_up(a);
	left_up(b);
	return flag;
}
void check_zero(int a[4][4],int x[],int y[])
{
	int sum=0;
	for(int i=0;i<16;i++)
	{x[i]=-1;y[i]=-1;}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(a[i][j]==0)
			{x[sum]=i;y[sum]=j;sum++;}
}
int check(int a[4][4],int b[4][4])
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(a[i][j]==0)
				return 1;
	int flag1,flag2;
	flag1=check_left(a,b);
	flag2=check_up(a,b);
	if(flag1==0&&flag2==0)
		return 0;
	return 1;
}
void change_1(int a[4],int b[4])
{
	for(int i=0;i<4;i++)
		if(b[i]==1)
		{
			if(a[i]==a[i+1])
			{a[i]=a[i]*2;a[i+1]=0;}
			else if(a[i]==a[i+2])
			{a[i]=a[i]*2;a[i+2]=0;}
			else if(a[i]==a[i+3])
			{a[i]=a[i]*2;a[i+3]=0;}
		}
}
void change_left(int a[4][4],int b[4][4])
{
	for(int i=0;i<4;i++)
		change_1(a[i],b[i]);
}
void change_right(int a[4][4],int b[4][4])
{
	left_right(a);
	left_right(b);
	change_left(a,b);
	left_right(a);
	left_right(b);
}
void change_up(int a[4][4],int b[4][4])
{
	left_up(a);
	left_up(b);
	change_left(a,b);
	left_up(a);
	left_up(b);
}
void change_down(int a[4][4],int b[4][4])
{
	left_up(a);
	left_up(b);
	change_right(a,b);
	left_up(a);
	left_up(b);
}
void reshape_1(int a[4])
{
	int b[4],sum=0;
	for(int i=0;i<4;i++)
	{b[i]=a[i];a[i]=0;}
	for(int i=0;i<4;i++)
	{
		if(b[i]!=0)
			a[sum++]=b[i];
	}
}
void reshape_left(int a[4][4])
{
	for(int i=0;i<4;i++)
		reshape_1(a[i]);
}
void reshape_right(int a[4][4])
{
	left_right(a);
	reshape_left(a);
	left_right(a);
}ssss
void reshape_up(int a[4][4])
{
	left_up(a);
	reshape_left(a);
	left_up(a);
}
void reshape_down(int a[4][4])
{
	left_up(a);
	reshape_right(a);
	left_up(a);
}
void interp(int a[4][4])
{
	int x[16],y[16],t,nan,lim,x1,y1;
	check_zero(a,x,y);
	lim=getlim(x);
	if(lim!=0)
	{
		t=GetTickCount();
		srand(t);
		nan=rand()%lim;
	}
	else
		nan=0;
	x1=x[nan];y1=y[nan];
	a[x1][y1]=2;
}
void movex(int a[4][4],int b[4][4],char p)
{
	int flag;
	switch(p)
	{
	case'w':case'W':
		flag=check_up(a,b);
		if(flag)
		{
        change_up(a,b);
	    reshape_up(a);
		interp(a);
		}
		break;
	case's':case'S':
		flag=check_down(a,b);
		if(flag)
		{
	    change_down(a,b);
		reshape_down(a);
		interp(a);
		}
		break;
	case'a':case'A':
		flag=check_left(a,b);
		if(flag)
		{
		change_left(a,b);
	    reshape_left(a);
		interp(a);
		}
		break;
	case'd':case'D':
		flag=check_right(a,b);
		if(flag)
		{
		change_right(a,b);
		reshape_right(a);
		interp(a);
		}
		break;
	}
}
void beginx(int a[4][4])
{
	int t,x1,x2,y1,y2;
	t=GetTickCount();srand(t);x1=rand()%4;y1=rand()%4;
	do
	{x2=rand()%4;y2=rand()%4;}while(x1==x2&&y1==y2);
	a[x1][y1]=2;a[x2][y2]=2;
	show(a);
}
int main()
{
	while(1)
	{
		cout<<"输入w开始游戏，输入s退出游戏，游戏中输入q结束游戏"<<endl;
		char q;
		q=getch();
		if(q=='s'||q=='S')
			break;
		int a[4][4]={0},b[4][4]={0},flag=1;
		system("cls");
		beginx(a);
		while(1)
		{
			char p;
			p=getch();
			movex(a,b,p);
			system("cls");
			show(a);
			flag=check(a,b);
			if(flag==0)
			{
				cout<<"游戏结束"<<endl;
				break;
			}
			if(p=='q')
			{
				cout<<"游戏结束"<<endl;
				break;
			}
		}
	}
	return 0;
}