#include"BasketballClubManagement.h"

using namespace std;

int main(void)
{
	system("color f0");		//�����׵�

	BasketballClubfManagementLaunch universityLaunch;			//��ѧ��Ա�������������

	while (1)
	{
		system("cls");			//����
		universityLaunch.showMainMenu();			//��ʾ�˵�
		universityLaunch.respondMenu();			//��Ӧ�˵�
		cout << endl;
		system("pause");
	}

	return 0;
}