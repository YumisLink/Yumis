#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 10000
#define upl(a,b) for(int a = 1; a <= b; a ++)
#define dwl(a,b) for(int a = b; a >= 1; a --)
struct UserInformation
{
	char AccountNumber[100];
	char Password[100];
	int UserPower;
};
struct StaffInformation
{
	char Name[100];
	int Wages;
};


int Flag = 1;

int AccountsMuch;
struct UserInformation Information[MAXN];

int StaffMuch;
struct StaffInformation SInfomation[MAXN];

FILE *dt = NULL;

void PutStar()
{
	puts("****************************************");
}

void SetSystem()
{

}


void LoginSystem()
{
	char _accountNumber[100],_password[100];
	PutStar();
	puts("    请输入您的账号信息");
	printf("账号：  account:");
	scanf("%s",_accountNumber);
	puts("");
	PutStar();
	for (int i = 1; i <= AccountsMuch; i ++)
	{
		if (strcmp(_accountNumber,Information[i].AccountNumber) == 0)
		{	
			printf("密码：  password:");
			scanf("%s",_password);
			if (strcmp(_password,Information[i].Password) == 0)
			{
				printf("登陆成功\n");
				SetSystem();
			}
			else 
			{
				printf("密码错误!\n");
			}
		}
		else 
		{
			printf("输入的账号不存在\n");
		}
	}
	// printf("%s\n",_accountNumber);
	// Flag = 0;

}
void RegisterSystem()
{
	char _accountNumber[100],_password[100];
	PutStar();
	puts("正在注册游客账号");
	puts("如果想要使用正式员工账号，或者管理员账号");
	puts("请联系管理员");
	puts("如果随时想要退出，请输入exit");
	puts("请输入您想要注册的账号");
	printf("账号：");

	scanf("%s",_accountNumber);
	if (strcmp(_accountNumber,"exit") == 0)  {return;}
	puts("请输入密码");
	printf("密码：");
	scanf("%s",_password);
	if (strcmp(_password,"exit") == 0)  {return;}
	puts("注册成功，正在返回————"); 
	AccountsMuch ++;
	strcpy(Information[AccountsMuch].AccountNumber,_accountNumber);
	strcpy(Information[AccountsMuch].Password,_password);
	Information[AccountsMuch].UserPower = 1;
	return ;
}
void ExitSystem()
{
	Flag = 0;
}


void MenuInterface()
{
	char _input = ' ';
	PutStar();
	puts("  欢迎使用JMU工资管理系统");
	puts(" 请按照指示内容点击以下按键");
	puts("            1.登陆账号");
	puts("            2.注册账号");
	puts("            3.退出系统");
	puts("请在任意操作之后点击空格...");
	puts("如果尝试点击其他字符则不会发生任何事情...");
	PutStar();
	while (_input > '3' || _input < '1')
	{
		_input=  getchar();
	}

	if (_input == '1') 
		LoginSystem();
	if (_input == '2')
		RegisterSystem();
	if (_input == '3')	
		ExitSystem();
}

int main ()
{
	dt = fopen("date.dat","r");
	fscanf(dt,"%d\n",&AccountsMuch);
	printf("%d",AccountsMuch);
	upl(k,AccountsMuch)
	{
		fscanf(dt,"%s %s %d",&Information[k].AccountNumber,&Information[k].Password,&Information[k].UserPower);
	}
	//printf("%s",Information[1].AccountNumber);
	fscanf(dt,"%d\n",&StaffMuch);
	upl(k,StaffMuch)
	{
		fscanf(dt,"%s",&SInfomation[k].Name);
		fscanf(dt,"%d",&SInfomation[k].Wages);
	}
	fclose(dt);

	while (Flag)
	{
		MenuInterface();
	}

	SInfomation[1].Wages = 100;

	dt = fopen("date.dat","w");
	fprintf(dt,"%d\n",AccountsMuch);
	upl(k,AccountsMuch)
	{
		fprintf(dt,"%s %s %d\n",Information[k].AccountNumber,Information[k].Password,Information[k].UserPower);
	}
	fprintf(dt,"%d\n",StaffMuch);
	upl(k,StaffMuch)
	{
		fprintf(dt,"%s %d\n",SInfomation[k].Name,SInfomation[k].Wages);
	}
	fclose(dt);


	return 0;
}