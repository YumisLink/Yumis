#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 10000
#define PutStar() puts("****************************************")
#define upl(a,b) for(int a = 1; a <= b; a ++)
#define dwl(a,b) for(int a = b; a >= 1; a --)
struct UserInformation
{
	char AccountNumber[100];
	char Password[100];
	char Name[100];
	char Id[100];
	int UserPower;
};
struct StaffInformation
{
	char Name[100];
	char Id[100];
	int Wages;
};


int Flag = 1;

int AccountsMuch;
struct UserInformation Information[MAXN];

int StaffMuch;
struct StaffInformation SInfomation[MAXN];

FILE *dt = NULL;
int FindAccount(char* Id)
{
	for (int i = 1; i <= AccountsMuch; i ++)
	{
		if (strcmp(Id,Information[i].AccountNumber) == 0)
			return i;
	}
	return 0;
}

int Findid(char* id)
{
	for (int i = 1; i <= AccountsMuch; i ++)
	{
		if (strcmp(id,Information[i].Id) == 0)
			return i;
	}
	return 0;
}

void PrintWages(char* id)
{
	int k = Findid(id);
	PutStar();
	printf("%s的工资为:%d\n",SInfomation[k].Name,SInfomation[k].Wages);
	puts("最终解释权归JMU公司所有。");
	puts("如有疑问请咨询财务管理员。");
	PutStar();
	puts("按下任意键后回车继续");
	scanf("\n");

}

void FindOtherWages()
{
	puts("请输入您要查询的员工的ID号");
	char inp[100];
	scanf("%s",inp);
	int k = Findid(inp);
	if (k == 0)
	{
		puts("id不存在");
		return;
	}
	else
	{
		PrintWages(inp);
	}
	
	puts("按下任意键后回车继续");
	scanf("\n");
}


void PrintfAllWages()
{
	int ans = 0;
	for (int i = 1; i <= StaffMuch; i ++)
	{
		ans += SInfomation[i].Wages;
	}
	PutStar();
	printf("总工资为：%d\n",ans);
	PutStar();
	
	puts("按下任意键后回车继续");
	scanf("\n");
}

void PrintfAve()
{
	int ans = 0;
	for (int i = 1; i <= StaffMuch; i ++)
	{
		ans += SInfomation[i].Wages;
	}
	PutStar();
	printf("平均工资为：%d\n",ans/StaffMuch);
	PutStar();
	
	puts("按下任意键后回车继续");
	scanf("\n");

}

void PPPP()
{
	PutStar();
	puts("成功打印至同一目录下的date.txt文件夹中");
	dt = fopen("date.txt","w");
	fprintf(dt,"姓名     工资\n");
	for (int i = 1; i <= StaffMuch; i ++)
	{
		fprintf(dt,"%s     %d",SInfomation[i].Name,SInfomation[i].Wages);
	}
	fclose(dt);
	PutStar();
	puts("按下任意键后回车继续");
	scanf("\n");
}

void Printlll()
{
	printf("姓名     工资\n");
	for (int i = 1; i <= StaffMuch; i ++)
	{
		printf("%s     %d\n",SInfomation[i].Name,SInfomation[i].Wages);
	}
	
	puts("按下任意键后回车继续");
	scanf("\n");
}

void CaoZuo()
{
	puts("请输入员工的ID");
	char inp[100];
	scanf("%s",inp);
	int k = Findid(inp);
	if (k == 0)
	{
		puts("id不存在");
		return;
	}
	printf("%s   工资：%d\n",SInfomation[k].Name,SInfomation[k].Wages);

	puts("请输入增加或者减少的工资(仅限正负的整数)");
	int add;
	scanf("%d",&add);
	SInfomation[k].Wages += add;
	
	puts("按下任意键后回车继续");
	scanf("\n");
}






void SetSystem1(char* id)
{
	while (1)
	{
		int k = Findid(id);
		puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");
		PutStar();
		printf("欢迎您，游客%s\n",Information[k].AccountNumber);
		puts("您现在可以操作的内容有:");
		puts("1.查询某个人的工资");
		puts("2.查询该公司在工资方面的支出");
		puts("3.查询工资的平均数");
		puts("4.退出登陆");
		PutStar();
		char _input = ' ';
		while (_input > '4' || _input < '1')
			_input=  getchar();
		if (_input == '1')
			FindOtherWages();
		if (_input == '2')
			PrintfAllWages();
		if (_input == '3')
			PrintfAve();
		if (_input == '4')
			return;
	}
	
}

void SetSystem2(char* id)
{
	while (1)
	{
		int k = Findid(id);
		puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");
		PutStar();
		printf("欢迎您，正式员工%s\n",Information[k].Name);
		puts("您现在可以操作的内容有:");
		puts("1.查询自己的工资");
		puts("2.查询某个人个工资");
		puts("3.查询该公司在工资方面的支出");
		puts("4.查询工资的平均数");
		puts("5.退出登陆");
		PutStar();
		char _input = ' ';
		while (_input > '5' || _input < '1')
			_input=  getchar();
		
		if (_input == '1')
			PrintWages(id);
		if (_input == '2')
			FindOtherWages();
		if (_input == '3')
			PrintfAllWages();
		if (_input == '4')
			PrintfAve();
		if (_input == '5')
			return;
	}
}

void SetSystem3(char* id)
{
	while (1)
	{
		int k = Findid(id);
		puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");puts("");
		PutStar();
		printf("欢迎您，管理员%s\n",Information[k].Name);
		puts("您现在可以操作的内容有:");
		puts("1.查询自己的工资");
		puts("2.查询某个人个工资");
		puts("3.查询该公司在工资方面的支出");
		puts("4.查询工资的平均数");
		puts("5.将所有员工的工资打印到.txt文档");
		puts("6.列出工资列表");
		puts("7.对工资进行增减操作");
		puts("8.退出登陆");
		PutStar();
		char _input = ' ';
		while (_input > '9' || _input < '1')
			_input=  getchar();

		if (_input == '1')
			PrintWages(id);
		if (_input == '2')
			FindOtherWages();
		if (_input == '3')
			PrintfAllWages();
		if (_input == '4')
			PrintfAve();
		if (_input == '5')
			PPPP();
		if (_input == '6')
			Printlll();
		if (_input == '7')
			CaoZuo();
		if (_input == '8')
			return;
	}
}


void LoginSystem()
{
	char _accountNumber[100],_password[100];
	PutStar();
	puts("    请输入您的账号信息");
	printf("账号：  account:");
	scanf("%s",_accountNumber);
	puts("");
	for (int i = 1; i <= AccountsMuch; i ++)
	{
		if (strcmp(_accountNumber,Information[i].AccountNumber) == 0)
		{	
			printf("密码：  password:");
			scanf("%s",_password);
			if (strcmp(_password,Information[i].Password) == 0)
			{
				printf("登陆成功\n");
				if(Information[i].UserPower == 1) SetSystem1(Information[i].Id);
				if(Information[i].UserPower == 2) SetSystem2(Information[i].Id);
				if(Information[i].UserPower == 3) SetSystem3(Information[i].Id);
				return ;
			}
			else 
			{
				printf("密码错误!\n");
			}
		}
		printf("输入的账号不存在\n");
	PutStar();
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
	if (FindAccount(_accountNumber) == 1){printf("该账号已经存在！\n");return;}
	puts("请输入密码");
	printf("密码：");
	scanf("%s",_password);
	if (strcmp(_password,"exit") == 0)  {return;}
	puts("注册成功，正在返回————"); 
	AccountsMuch ++;
	strcpy(Information[AccountsMuch].AccountNumber,_accountNumber);
	strcpy(Information[AccountsMuch].Password,_password);
	strcpy(Information[AccountsMuch].Id,"GAME");
	strcpy(Information[AccountsMuch].Name,"GAME");
	Information[AccountsMuch].UserPower = 1;
	return ;
}
void ExitSystem()
{
	Flag = 0;
}


void MenuInterface()
{
	PutStar();
	puts("  欢迎使用JMU工资管理系统");
	puts(" 请按照指示内容点击以下按键");
	puts("            1.登陆账号");
	puts("            2.注册账号");
	puts("            3.退出系统");
	puts("请在任意操作之后点击空格...");
	puts("如果尝试点击其他字符则不会发生任何事情...");
	PutStar();
	char _input = ' ';
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

void Load()
{
	
}

void Save()
{
	

}
int main ()
{
	dt = fopen("date.dat","r");
	fscanf(dt,"%d\n",&AccountsMuch);
	printf("%d",AccountsMuch);
	upl(k,AccountsMuch)
	{
		fscanf(dt,"%s %s %s %s %d\n",&Information[k].AccountNumber,&Information[k].Password,&Information[k].Name,&Information[k].Id,&Information[k].UserPower);
	}
	//printf("%s",Information[1].AccountNumber);
	fscanf(dt,"%d\n",&StaffMuch);
	upl(k,StaffMuch)
	{
		fscanf(dt,"%s %s %d\n",&SInfomation[k].Name,&SInfomation[k].Id,&SInfomation[k].Wages);
	}
	fclose(dt);

	while (Flag)
	{
		MenuInterface();
	}

	dt = fopen("date.dat","w");
	fprintf(dt,"%d\n",AccountsMuch);
	upl(k,AccountsMuch)
	{
		fprintf(dt,"%s %s %s %s %d\n",Information[k].AccountNumber,Information[k].Password,Information[k].Name,Information[k].Id,Information[k].UserPower);
	}
	fprintf(dt,"%d\n",StaffMuch);
	upl(k,StaffMuch)
	{
		fprintf(dt,"%s %s %d\n",SInfomation[k].Name,SInfomation[k].Id,SInfomation[k].Wages);
	}
	fclose(dt);

	return 0;
}