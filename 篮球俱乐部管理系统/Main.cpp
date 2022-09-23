#include"BasketballClubManagement.h"

using namespace std;

int main(void)
{
	system("color f0");		//背景白底

	BasketballClubfManagementLaunch universityLaunch;			//大学人员管理启动类对象

	while (1)
	{
		system("cls");			//清屏
		universityLaunch.showMainMenu();			//显示菜单
		universityLaunch.respondMenu();			//响应菜单
		cout << endl;
		system("pause");
	}

	return 0;
}