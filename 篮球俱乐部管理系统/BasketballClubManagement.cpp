# include"BasketballClubManagement.h"

using namespace std;

int sum = 0;			//静态成员初始化

Person::Person(string& name, string& gender, int& age, int& ID, string& contict)			//初始化
{
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->ID = ID;
	this->contict = contict;
}

void Person::display(void)			//显示人员基本信息
{
	cout << "姓名：" << name << endl;
	cout << "性别：" << gender << endl;
	cout << "年龄：" << age << endl;
	cout << "编号：" << ID << endl;
	cout << "联系电话：" << contict << endl;
}



//球员类成员函数实现
Player::Player(string& name, string& gender, int& age, int& ID, string& contict, string& position, string& clubName, float& uniformNumber) : Person(name, gender, age, ID, contict)
{
	this->position = position;
	this->clubName = clubName;
	this->uniformNumber = uniformNumber;
}

void Player::display(void)			//显示球员信息
{
	Person::display();
	cout << "球员场上位置：" << position << endl;
	cout << "球员所属俱乐部：" << clubName << endl;
	cout << "球员球衣号码：" << uniformNumber << endl;
}

void Player::save(void)			//保存球员信息（函数重载）
{
	ofstream savefile;

	savefile.open("球员信息.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "球员信息保存失败。" << endl;
		return;
	}

	savefile << "姓名：" << name << endl;
	savefile << "性别：" << gender << endl;
	savefile << "年龄：" << age << endl;
	savefile << "编号：" << ID << endl;
	savefile << "联系电话：" << contict << endl;
	savefile << "球员场上位置：" << position << endl;
	savefile << "球员所属俱乐部：" << clubName << endl;
	savefile << "球员球衣号码：" << uniformNumber << endl << endl;

	savefile.close();			//关闭文件
}

void Player::modify(void)			//修改球员信息（函数重载）
{
	int choice = -1;

	while (1)
	{
		system("cls");			//清屏

		cout << "该球员原信息为：" << endl;			//显示要修改的球员原信息
		Person::display();
		cout << "球员场上位置：" << position << endl;
		cout << "球员所属俱乐部：" << clubName << endl;
		cout << "球员球衣号码：" << uniformNumber << endl;

		cout << endl;
		cout << "请输入要修改的内容：（姓名,性别,编号不可修改）" << endl;
		cout << "1. 年龄	2. 联系电话	   3. 球员场上位置" << endl;
		cout << "4. 球员所属俱乐部	5. 球员球衣号码	6. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//修改球员年龄
			cout << "请输入该球员的年龄：";
			cin >> age;
			cout << "修改成功！";
			break;

		case 2:		//修改球员联系电话
			cout << "请输入该球员的联系电话：";
			cin >> contict;
			cout << "修改成功！";
			break;

		case 3:		//修改球员专业
			cout << "请输入该球员场上的位置：";
			cin >> position;
			cout << "修改成功！";
			break;

		case 4:		//修改球员班级
			cout << "请输入该球员的俱乐部：";
			cin >> clubName;
			cout << "修改成功！";
			break;

		case 5:		//修改球员成绩
			cout << "请输入该球员的球衣号码：";
			cin >> uniformNumber;
			cout << "修改成功！";
			break;

		case 6:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停屏幕
	}
}



//教练类的函数实现
Coach::Coach(string& name, string& gender, int& age, int& ID, string& contict, string& characteristic, string& nickName) : Person(name, gender, age, ID, contict)
{
	this->characteristic = characteristic;
	this->nickName = nickName;
}

void Coach::display(void)			//显示教练信息（函数重载）
{
	Person::display();
	cout << "教练专业特点：" << characteristic << endl;
	cout << "教练别名：" << nickName << endl;
}

void Coach::save(void)			//保存教练信息(函数重载)
{
	ofstream savefile;

	savefile.open("教练信息.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "教练信息保存失败。" << endl;
		return;
	}

	savefile << "姓名：" << name << endl;
	savefile << "性别：" << gender << endl;
	savefile << "年龄：" << age << endl;
	savefile << "教练编号：" << ID << endl;
	savefile << "联系电话：" << contict << endl;
	savefile << "教练专业特点：" << characteristic << endl;
	savefile << "教练别名：" << nickName << endl << endl;

	savefile.close();			//关闭文件
}

void Coach::modify(void)			//修改教练信息（函数重载）
{
	int choice = -1;

	while (1)
	{
		system("cls");			//清屏

		cout << "该教练原信息为：" << endl;			//显示要修改的教练原信息
		Person::display();
		cout << "教练性格特点：" << characteristic << endl;
		cout << "教练别名：" << nickName << endl;

		cout << endl;
		cout << "请输入要修改的内容：（姓名,性别,教练编号不可修改）" << endl;
		cout << "1. 年龄	2. 联系电话	   3. 教练专业特点" << endl;
		cout << "4.教练别名	5. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//修改教练年龄
			cout << "请输入该教练的年龄：";
			cin >> age;
			cout << "修改成功！";
			break;

		case 2:		//修改教练联系电话
			cout << "请输入该教练的联系电话：";
			cin >> contict;
			cout << "修改成功！";
			break;

		case 3:		//修改教练专业特点
			cout << "请输入该教练的专业特点：";
			cin >> characteristic;
			cout << "修改成功！";
			break;

		case 4:		//修改教练别名
			cout << "请输入该教练的别名：";
			cin >> nickName;
			cout << "修改成功！";
			break;

		case 5:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停屏幕
	}
}



//职工类函数实现
Staff::Staff(string& name, string& gender, int& age, int& ID, string& contict, string& department, string& job, int& salary) : Person(name, gender, age, ID, contict)
{
	this->department = department;			//职工部门
	this->job = job;			//职工职务
	this->salary = salary;
}

void Staff::display(void)			//显示职工信息（函数重载）
{
	cout << endl;
	Person::display();
	cout << "职工部门：" << department << endl;
	cout << "职工工作：" << job << endl;
	cout << "职工工资：" << salary << endl;
}

void Staff::save(void)			//保存职工信息（函数重载）
{
	ofstream savefile;

	savefile.open("职工信息.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "职工信息保存失败。" << endl;
		return;
	}

	savefile << "姓名：" << name << endl;
	savefile << "性别：" << gender << endl;
	savefile << "年龄：" << age << endl;
	savefile << "职工编号：" << ID << endl;
	savefile << "联系电话：" << contict << endl;
	savefile << "职工部门：" << department << endl;
	savefile << "职工工作：" << job << endl;
	savefile << "职工工资：" << salary << endl << endl;

	savefile.close();			//关闭文件
}

void Staff::modify(void)			//修改职工信息（函数重载）
{
	int choice = -1;

	while (1)
	{
		system("cls");			//清屏

		cout << "该职工原信息为：" << endl;			//显示要修改的职工原信息
		Person::display();
		cout << "职工部门：" << department << endl;
		cout << "职工工作：" << job << endl;
		cout << "职工工资：" << salary << endl;

		cout << endl;
		cout << "请输入要修改的内容：（姓名,性别,职工编号不可修改）" << endl;
		cout << "1. 年龄	2. 联系电话	3. 职工部门" << endl;
		cout << "4. 职工工作	5. 职工工资	6. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//修改职工年龄
			cout << "请输入该职工的年龄：";
			cin >> age;
			cout << "修改成功！";
			break;

		case 2:		//修改职工联系电话
			cout << "请输入该职工的联系电话：";
			cin >> contict;
			cout << "修改成功！";
			break;

		case 3:		//修改职工部门
			cout << "请输入该职工的部门：";
			cin >> department;
			cout << "修改成功！";
			break;

		case 4:		//修改职工工作
			cout << "请输入该职工的工作：";
			cin >> job;
			cout << "修改成功！";
			break;

		case 5:		//修改职工工资
			cout << "请输入该职工的工资：";
			cin >> salary;
			cout << "修改成功！";
			break;

		case 6:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停屏幕
	}
}



//人员管理类成员函数的实现
BasketballClubManagement::BasketballClubManagement(void)			//构造函数
{
	for (int i = 0; i < MAX; i++)
	{
		p[0][i] = NULL;
		p[1][i] = NULL;
		p[2][i] = NULL;
	}
	playerNumber = 0;
	coachNumber = 0;
	staffNumber = 0;
}

BasketballClubManagement::~BasketballClubManagement(void)			//析构函数
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < MAX; j++)
		{
			if (p[i][j])
				delete p[i][j];
			p[i][j] = NULL;
		}
}

//查找该数据的位置，4个参数分别是返回查找到的数据的位置、查找的数据类型（按名字查找还是编号），
//要查找的数据，要查找的人员类型（默认在所有人员中查找）
void BasketballClubManagement::findPerson(int* plocation, const string& findType, const string& lookedData, const string& personType)
{
	int flag = 0;			//判断是否找到该球员，并且判断是否重复

	plocation[0] = -1;			//初始化
	plocation[1] = -1;

	if (findType == "name")		//按名字查找
	{
		if (personType == "player")			//按名字查找之在球员中查找
		{
			flag = 0;

			for (int i = 0; i < playerNumber && p[0][i] != NULL; i++)
			{
				if (p[0][i]->name == lookedData)
				{
					if (flag)			//判断是否有重复姓名的球员
					{
						cout << "存在相同姓名的球员，只查找第一个符合条件的球员信息。" << endl << endl;
						return;
					}
					plocation[0] = 0;			//在球员中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "coach")			//按名字在教练中查找
		{
			flag = 0;

			for (int i = 0; i < coachNumber && p[1][i] != NULL; i++)
			{
				if (p[1][i]->name == lookedData)
				{
					if (flag)			//判断是否有重复姓名的教练
					{
						cout << "存在相同姓名的教练，只查找第一个符合条件的教练信息。" << endl << endl;
						return;
					}
					plocation[0] = 1;			//在教练中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "staff")			//按名字查找之在职工中查找
		{
			flag = 0;

			for (int i = 0; i < staffNumber && p[2][i] != NULL; i++)
			{
				if (p[2][i]->name == lookedData)
				{
					if (flag)			//判断是否有重复姓名的职工
					{
						cout << "存在相同姓名的职工，只查找第一个符合条件的职工信息。" << endl << endl;
						return;
					}
					plocation[0] = 2;			//在职工中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "allPerson")			//按名字查找之在所有人员中查找
		{
			flag = 0;

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < MAX && p[i][j] != NULL; j++)
					if (p[i][j]->name == lookedData)
					{
						if (flag)			//判断是否有重复姓名的人员
						{
							cout << "存在相同姓名的成员，只查找第一个符合条件的俱乐部成员信息。" << endl << endl;
							return;
						}
						plocation[0] = i;			//保存该俱乐部成员的身份（球员/教练/职工）
						plocation[1] = j;			//该成员存放的位置
						flag++;
					}
			}
		}
		else
			cerr << "程序出现意外错误，查找子函数要查找的人员类型参数出错。" << endl;
	}
	else if (findType == "ID")		//按编号查找
	{
		int No = 0;			//保存编号
		istringstream iss(lookedData);			//将string类型的编号转换为整型保存在No中
		iss >> No;

		if (personType == "player")			//按编号查找之在球员中查找
		{
			flag = 0;

			for (int i = 0; i < playerNumber && p[0][i] != NULL; i++)
			{
				if (p[0][i]->ID == No)
				{
					if (flag)			//判断是否有重复姓名的球员
					{
						cout << "存在相同学号的球员，只查找第一个符合条件的球员信息。" << endl << endl;
						return;
					}
					plocation[0] = 0;			//在球员中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "coach")			//按编号查找之在教练中查找
		{
			flag = 0;

			for (int i = 0; i < coachNumber && p[1][i] != NULL; i++)
			{
				if (p[1][i]->ID == No)
				{
					if (flag)			//判断是否有重复姓名的教练
					{
						cout << "存在相同编号的教练，只查找第一个符合条件的教练信息。" << endl << endl;
						return;
					}
					plocation[0] = 1;			//在教练中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "staff")			//按编号查找之在职工中查找
		{
			flag = 0;

			for (int i = 0; i < staffNumber && p[2][i] != NULL; i++)
			{
				if (p[2][i]->ID == No)
				{
					if (flag)			//判断是否有重复姓名的职工
					{
						cout << "存在相同职工号的职工，只查找第一个符合条件的职工信息。" << endl << endl;
						return;
					}
					plocation[0] = 2;			//在职工中找到
					plocation[1] = i;			//该人员存放的位置
					flag++;
				}
			}
		}
		else if (personType == "allPerson")			//按编号查找之在所有俱乐部人员中查找
		{
			flag = 0;

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < MAX && p[i][j] != NULL; j++)
					if (p[i][j]->ID == No)
					{
						if (flag)			//判断是否有重复姓名的俱乐部人员
						{
							cout << "存在同编号的俱乐部成员，只查找第一个符合条件的俱乐部成员信息。" << endl << endl;
							return;
						}
						plocation[0] = i;			//保存该俱乐部人员的身份（球员/教练/职工）
						plocation[1] = j;			//该人员存放的位置
						flag++;
					}
			}
		}
		else
			cerr << "程序出现意外错误，查找子函数要查找的人员类型参数出错。" << endl;
	}
	else
		cerr << "程序出错，查找子函数要查找的数据类型参数出错，查找失败！" << endl;
}

//球员信息管理功能实现
void BasketballClubManagement::createPlayer(void)			//创建或添加球员信息
{
	string name, gender, position, contict, clubName;			//姓名，性别，场上位置，联系电话，所属俱乐部
	int age, ID;		float uniformNumber;			//年龄，球员编号，球衣号码
	char ch = NULL;
	int addNumber;			//添加的人数
	int i = 0;

	if (p[0][0])			//判断是否存在球员信息
	{
		cout << "球员信息已经创建，继续操作将添加球员信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
		else
		{
			cout << "请输入要添加的球员数量：（不超过" << MAX - playerNumber << "个）" << endl;
		}
	}
	else
		cout << "请输入要创建的球员数量：（不超过" << MAX << "个）" << endl;
	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - playerNumber)			//安全性检查
	{
		cout << "输入错误，添加失败。" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "请输入第 " << i + 1 << " 个球员姓名：";		cin >> name;
		cout << "请输入第 " << i + 1 << " 个球员性别：";		cin >> gender;
		cout << "请输入第 " << i + 1 << " 个球员年龄：";		cin >> age;
		cout << "请输入第 " << i + 1 << " 个球员编号：";		cin >> ID;
		cout << "请输入第 " << i + 1 << " 个球员联系电话：";		cin >> contict;
		cout << "请输入第 " << i + 1 << " 个球员场上位置：";		cin >> position;
		cout << "请输入第 " << i + 1 << " 个球员所属俱乐部：";		cin >> clubName;
		cout << "请输入第 " << i + 1 << " 个球员球衣号码：";		cin >> uniformNumber;
		cout << endl;

		p[0][playerNumber + i] = new Player(name, gender, age, ID, contict, position, clubName, uniformNumber);			//用基类指针指向派生类对象实现多态
	}

	playerNumber += addNumber;			//计算球员总数
	sum += addNumber;			//计算总人员个数

	cout << "球员信息输入成功。" << endl;
}

void BasketballClubManagement::importPlayer(void)
{
	string name[4], gender[4], position[4], contict[4], clubName[4];			//姓名，性别，球员场上位置，联系电话，班级
	int age[4], ID[4];		float uniformNumber[4];			//年龄，球员编号，球衣号码
	char ch = NULL;
	int addNumber;			//添加的人数
	int i = 0;

	//内置球员成员
	name[0] = "斯蒂芬·库里";			name[1] = "勒布朗·詹姆斯";		name[2] = "安东尼·戴维斯";			name[3] = "凯文·杜兰特";
	gender[0] = "男";					gender[1] = "男";				gender[2] = "男";					gender[3] = "男";
	position[0] = "控球后卫";			position[1] = "小前锋";			position[2] = "大前锋/中锋";		position[3] = "小前锋";
	contict[0] = "13854532219";			contict[1] = "13453224614";		contict[2] = "18995642658";			contict[3] = "13759426583";
	clubName[0] = "金州勇士队";			clubName[1] = "洛杉矶湖人队";	clubName[2] = "洛杉矶湖人队";		clubName[3] = "布鲁克林篮网";
	age[0] = 32;						age[1] = 36;					age[2] = 27;						age[3] = 32;
	ID[0] = 1988314;					ID[1] = 19841230;				ID[2] = 1993311;					ID[3] = 1988929;
	uniformNumber[0] = 30;				uniformNumber[1] = 23;			uniformNumber[2] = 23;				uniformNumber[3] = 35;

	if (p[0][0])			//判断是否存在球员信息
	{
		cout << "球员信息已经创建，继续操作将添加球员信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
	}

	addNumber = 4;

	for (i = 0; i < addNumber; i++)
	{
		p[0][playerNumber + i] = new Player(name[i], gender[i], age[i], ID[i], contict[i], position[i], clubName[i], uniformNumber[i]);			//用基类指针指向派生类对象实现多态
	}

	playerNumber += addNumber;			//计算球员总数
	sum += addNumber;			//计算总人员个数

	cout << "球员信息导入成功。" << endl;
}

void BasketballClubManagement::showPlayer(void)			//显示所有球员信息
{
	for (int i = 0; i < playerNumber; i++)
	{
		cout << endl;
		p[0][i]->display();
	}

	cout << endl << "一共有 " << playerNumber << " 个球员" << endl;			//统计球员个数
}

void BasketballClubManagement::savePlayer(void)			//保存所有球员信息
{
	ofstream savefile;

	savefile.open("球员信息.txt", ios::out);				//打开文件
	if (savefile.fail())
	{
		cerr << "球员信息保存失败。" << endl;
		return;
	}

	savefile.close();			//打开文件之后关闭文件，清空原文件上次内容

	for (int i = 0; i < playerNumber; i++)
	{
		p[0][i]->save();				//利用了多态实现，基类指针指向派生类
	}

	savefile.open("球员信息.txt", ios::app);				//打开文件
	if (savefile.fail())
	{
		cerr << "球员信息保存失败。" << endl;
		return;
	}

	savefile << "一共有 " << playerNumber << " 个球员" << endl;			//将球员总数保存到文件

	cout << "球员信息已经保存在 《球员信息.txt》 文件中，请查看！" << endl;

	savefile.close();			//关闭文件
}

void BasketballClubManagement::seekPlayer(void)			//查找球员信息
{
	if (playerNumber <= 0)
	{
		cout << "没有任何球员信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存球员编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "查找球员信息：" << endl;
		cout << "1. 按姓名查找	2. 按编号查找	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名查找
			cout << "请输入要查找的球员姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该球员信息
				cout << endl;
			}
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 2:		//按编号查找
			cout << "请输入要查找的球员编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该球员信息
				cout << endl;
			}
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::modifyPlayer(void)			//修改球员信息
{
	if (playerNumber <= 0)
	{
		cout << "没有任何球员信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存球员编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "修改球员信息：" << endl;
		cout << "1. 按姓名找到要修改的球员	2. 按编号找到要修改的球员	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要修改的球员
			cout << "请输入要修改的球员姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该球员信息
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 2:		//按编号找到要修改的球员
			cout << "请输入要修改的球员编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该球员信息
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::removePlayer(void)			//删除球员信息
{
	if (playerNumber <= 0)
	{
		cout << "没有任何球员信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存球员编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//清屏

		cout << "删除球员信息：" << endl;
		cout << "1. 按姓名找到要删除的球员	2. 按编号找到要删除的球员	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要删除的球员
			cout << "请输入要删除的球员姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该球员信息
				cout << endl;

				cout << "是否删除该球员信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该球员
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该球员信息
					delete p[0][location[1]];

					for (int i = location[1]; i < playerNumber - 1; i++)
						p[0][i] = p[0][i + 1];

					p[0][playerNumber - 1] = NULL;

					playerNumber--;
					sum--;

					cout << "该球员已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 2:		//按编号找到要删除的球员
			cout << "请输入要删除的球员编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//调用查找子函数获得该人员的信息

			if (location[0] == 0 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该球员信息
				cout << endl;

				cout << "是否删除该球员信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该球员
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该球员信息
					delete p[0][location[1]];

					for (int i = location[1]; i < playerNumber - 1; i++)
						p[0][i] = p[0][i + 1];

					p[0][playerNumber - 1] = NULL;

					playerNumber--;
					sum--;

					cout << "该球员已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该球员信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::emptyPlayer(void)			//清空球员信息
{
	if (playerNumber == 0 && p[0][0] == NULL)
	{
		cout << "球员信息已经是空的！" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[0][i])
			delete p[0][i];
		p[0][i] = NULL;
	}

	sum -= playerNumber;			//计算总人员个数
	playerNumber = 0;

	cout << "清空球员信息成功！" << endl;
}



//教练信息管理功能实现
void BasketballClubManagement::createCoach(void)			//创建或添加教练信息
{
	string name, gender, characteristic, contict, nickName;		//姓名，性别，专业特点，联系电话，别称
	int age, ID;			//年龄，教练编号
	char ch = NULL;
	int addNumber;			//添加人员的数量
	int i = 0;

	if (p[1][0])			//判断是否存在教练信息
	{
		cout << "教练信息已经创建，继续操作将添加教练信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
		else
		{
			cout << "请输入要添加的教练数量：（不超过" << MAX - coachNumber << "个）" << endl;
		}
	}
	else
		cout << "请输入要创建的教练数量：（不超过" << MAX << "个）" << endl;

	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - coachNumber)			//安全性检查
	{
		cout << "输入错误，添加失败。" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "请输入第 " << i + 1 << " 个教练姓名：";		cin >> name;
		cout << "请输入第 " << i + 1 << " 个教练性别：";		cin >> gender;
		cout << "请输入第 " << i + 1 << " 个教练年龄：";		cin >> age;
		cout << "请输入第 " << i + 1 << " 个教练编号：";		cin >> ID;
		cout << "请输入第 " << i + 1 << " 个教练联系电话：";		cin >> contict;
		cout << "请输入第 " << i + 1 << " 个教练的专业特点：";		cin >> characteristic;
		cout << "请输入第 " << i + 1 << " 个教练的别称：";		cin >> nickName;
		cout << endl;

		p[1][coachNumber + i] = new Coach(name, gender, age, ID, contict, characteristic, nickName);			//用基类指针指向派生类对象实现多态
	}

	coachNumber += addNumber;			//计算教练总数
	sum += addNumber;			//计算总人员个数

	cout << "教练信息输入成功。" << endl;
}

void BasketballClubManagement::importCoach(void)			//导入教练信息
{
	string name[2], gender[2], characteristic[2], contict[2], nickName[2];			//姓名，性别，专业特点，联系电话，别称
	int age[2], ID[2];			//年龄，教练编号
	char ch = NULL;
	int addNumber;			//添加的人数
	int i = 0;

	//内置教练成员
	name[0] = "史蒂夫·科尔";				name[1] = "杰森·基德";
	gender[0] = "男";						gender[1] = "男";
	characteristic[0] = "三分高手";			characteristic[1] = "视野开阔，操控全局能力极为突出";
	contict[0] = "13966668888";				contict[1] = "18911115555";
	nickName[0] = "水井";					nickName[1] = "贾森基德";
	age[0] = 55;							age[1] = 47;
	ID[0] = 1965927;						ID[1] = 1973323;

	if (p[1][0])			//判断是否存在教练信息
	{
		cout << "教练信息已经创建，继续操作将添加教练信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
	}

	addNumber = 2;

	for (i = 0; i < addNumber; i++)
	{
		p[1][coachNumber + i] = new Coach(name[i], gender[i], age[i], ID[i], contict[i], characteristic[i], nickName[i]);			//用基类指针指向派生类对象实现多态
	}

	coachNumber += addNumber;			//计算教练总数
	sum += addNumber;			//计算总人员个数

	cout << "教练信息导入成功。" << endl;
}

void BasketballClubManagement::showCoach(void)			//显示所有教练信息
{
	for (int i = 0; i < coachNumber; i++)
	{
		cout << endl;
		p[1][i]->display();
	}

	cout << endl << "一共有 " << coachNumber << " 个教练" << endl;			//统计教练个数
}

void BasketballClubManagement::saveCoach(void)			//保存所有教练信息
{
	ofstream savefile;

	savefile.open("教练信息.txt", ios::out);				//打开文件
	if (savefile.fail())
	{
		cerr << "教练信息保存失败。" << endl;
		return;
	}

	savefile.close();			//打开文件之后关闭文件，清空原文件上次内容

	for (int i = 0; i < coachNumber; i++)
	{
		p[1][i]->save();				//利用了多态实现，基类指针指向派生类
	}

	savefile.open("教练信息.txt", ios::app);			//打开文件
	if (savefile.fail())
	{
		cerr << "教练信息保存失败。" << endl;
		return;
	}

	savefile << "一共有 " << coachNumber << " 个教练" << endl;			//将教练总数保存到文件

	cout << "教练信息已经保存在 《教练信息.txt》 文件中，请查看！" << endl;

	savefile.close();			//关闭文件
}

void BasketballClubManagement::seekCoach(void)			//查找教练信息
{
	if (coachNumber <= 0)
	{
		cout << "没有任何教练信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存教练编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "查找教练信息：" << endl;
		cout << "1. 按姓名查找	2. 按教练编号查找	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名查找
			cout << "请输入要查找的教练姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该教练信息
				cout << endl;
			}
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 2:		//按教练编号查找
			cout << "请输入要查找的教练编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该教练信息
				cout << endl;
			}
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::modifyCoach(void)			//修改教练信息
{
	if (coachNumber <= 0)
	{
		cout << "没有任何教练信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存教练编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "修改教练信息：" << endl;
		cout << "1. 按姓名找到要修改的教练	2. 按编号找到要修改的教练	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要修改的教练
			cout << "请输入要查找的教练姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该教练信息
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 2:		//按教练编号找到要修改的教练的信息
			cout << "请输入要修改的教练编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该教练信息
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::removeCoach(void)			//删除教练信息
{
	if (coachNumber <= 0)
	{
		cout << "没有任何教练信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存教练编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//清屏

		cout << "删除教练信息：" << endl;
		cout << "1. 按姓名找到要删除的教练	2. 按教练编号找到要删除的教练	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要删除的教练
			cout << "请输入要删除的教练姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该教练信息
				cout << endl;

				cout << "是否删除该教练信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该教练
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该教练信息
					delete p[1][location[1]];

					for (int i = location[1]; i < coachNumber - 1; i++)
						p[1][i] = p[1][i + 1];

					p[1][coachNumber - 1] = NULL;

					coachNumber--;
					sum--;

					cout << "该教练已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 2:		//按教练编号找到要删除的教练
			cout << "请输入要删除的教练编号：";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//调用查找子函数获得该人员的信息

			if (location[0] == 1 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该教练信息
				cout << endl;

				cout << "是否删除该教练信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该教练
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该教练信息
					delete p[1][location[1]];

					for (int i = location[1]; i < coachNumber - 1; i++)
						p[1][i] = p[1][i + 1];

					p[1][coachNumber - 1] = NULL;

					coachNumber--;
					sum--;

					cout << "该教练已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该教练信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::emptyCoach(void)			//清空教练信息
{
	if (coachNumber == 0 && p[1][0] == NULL)
	{
		cout << "教练信息已经是空的！" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[1][i])
			delete p[1][i];
		p[1][i] = NULL;
	}

	sum -= coachNumber;			//计算总人员个数
	coachNumber = 0;

	cout << "清空教练信息成功！" << endl;
}



//职工信息管理功能实现
void BasketballClubManagement::createStaff(void)			//创建或添加职工信息
{
	string name, gender, department, contict, job;			//姓名，性别，部门，联系电话, 工作
	int age, ID, salary;			//年龄，职工号，工资
	char ch = NULL;
	int addNumber;			//添加人员的数量
	int i = 0;

	if (p[2][0])			//判断是否存在职工信息
	{
		cout << "职工信息已经创建，继续操作将添加职工信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
		else
		{
			cout << "请输入要添加的职工数量：（不超过" << MAX - staffNumber << "个）" << endl;
		}
	}
	else
		cout << "请输入要创建的职工数量：（不超过" << MAX << "个）" << endl;

	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - staffNumber)			//安全性检查
	{
		cout << "输入错误，添加失败。" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "请输入第 " << i + 1 << " 个职工姓名：";		cin >> name;
		cout << "请输入第 " << i + 1 << " 个职工性别：";		cin >> gender;
		cout << "请输入第 " << i + 1 << " 个职工年龄：";		cin >> age;
		cout << "请输入第 " << i + 1 << " 个职工学号：";		cin >> ID;
		cout << "请输入第 " << i + 1 << " 个职工联系电话：";		cin >> contict;
		cout << "请输入第 " << i + 1 << " 个职工的部门：";		cin >> department;
		cout << "请输入第 " << i + 1 << " 个职工的工作：";		cin >> job;
		cout << "请输入第 " << i + 1 << " 个职工的工资：";		cin >> salary;
		cout << endl;

		p[2][staffNumber + i] = new Staff(name, gender, age, ID, contict, department, job, salary);			//用基类指针指向派生类对象实现多态
	}

	staffNumber += addNumber;			//计算职工总数
	sum += addNumber;			//计算总人员个数

	cout << "职工信息输入成功。" << endl;
}

void BasketballClubManagement::importStaff(void)
{
	string name[3], gender[3], department[3], contict[3], job[3];			//姓名，性别，部门，联系电话, 工作
	int age[3], ID[3], salary[3];			//年龄，职工号，工资
	char ch = NULL;
	int addNumber;			//添加的人数
	int i = 0;

	//内置职工成员
	name[0] = "王得正";								name[1] = "姜花花";								name[2] = "张桂福";
	gender[0] = "男";								gender[1] = "女";					   			gender[2] = "男";
	department[0] = "产品运营部";					department[1] = "财务部";		  				department[2] = "办公室";
	contict[0] = "13663639355";						contict[1] = "15977766541";						contict[2] = "13687546156";
	job[0] = "副总经理";							job[1] = "财务总监";							job[2] = "总经理";
	age[0] = 32;									age[1] = 33;									age[2] = 50;
	ID[0] = 2010088;								ID[1] = 2010054;								ID[2] = 2010008;
	salary[0] = 6000;								salary[1] = 6000;								salary[2] = 10000;

	if (p[2][0])			//判断是否存在职工信息
	{
		cout << "职工信息已经创建，继续操作将添加职工信息，是否取消？(按‘Y’或‘y’键取消添加)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "已经取消添加！" << endl;
			return;
		}
	}

	addNumber = 3;

	for (i = 0; i < addNumber; i++)
	{
		p[2][staffNumber + i] = new Staff(name[i], gender[i], age[i], ID[i], contict[i], department[i], job[i], salary[i]);			//用基类指针指向派生类对象实现多态
	}

	staffNumber += addNumber;			//计算职工总数
	sum += addNumber;			//计算总人员个数

	cout << "职工信息导入成功。" << endl;
}

void BasketballClubManagement::showStaff(void)			//显示所有职工信息
{
	for (int i = 0; i < staffNumber; i++)
	{
		cout << endl;
		p[2][i]->display();
	}

	cout << endl << "一共有 " << staffNumber << " 个职工" << endl;			//统计职工个数
}

void BasketballClubManagement::saveStaff(void)			//保存所有职工信息
{
	ofstream savefile;

	savefile.open("职工信息.txt", ios::out);				//打开文件
	if (savefile.fail())
	{
		cerr << "职工信息保存失败。" << endl;
		return;
	}

	savefile.close();			//打开文件之后关闭文件，清空原文件上次内容

	for (int i = 0; i < staffNumber; i++)
	{
		p[2][i]->save();				//利用了多态实现，基类指针指向派生类
	}

	savefile.open("职工信息.txt", ios::app);			//打开文件
	if (savefile.fail())
	{
		cerr << "职工信息保存失败。" << endl;
		return;
	}

	savefile << "一共有 " << staffNumber << " 个职工" << endl;			//将职工总数保存到文件

	cout << "职工信息已经保存在 《职工信息.txt》 文件中，请查看！" << endl;

	savefile.close();			//关闭文件
}

void BasketballClubManagement::seekStaff(void)			//查找职工信息
{
	if (staffNumber <= 0)
	{
		cout << "没有任何职工信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存职工号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "查找职工信息：" << endl;
		cout << "1. 按姓名查找	2. 按职工号查找	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名查找
			cout << "请输入要查找的职工姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该职工信息
				cout << endl;
			}
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 2:		//按职工号查找
			cout << "请输入要查找的职工号：";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示该职工信息
				cout << endl;
			}
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::modifyStaff(void)			//修改职工信息
{
	if (staffNumber <= 0)
	{
		cout << "没有任何职工信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存职工号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "修改职工信息：" << endl;
		cout << "1. 按姓名找到要修改的职工	2. 按职工号找到要修改的职工	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要修改的职工
			cout << "请输入要修改的职工姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该职工信息
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 2:		//按职工号找到要修改的职工
			cout << "请输入要修改的职工号：";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
				p[location[0]][location[1]]->modify();			//修改该职工信息
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::removeStaff(void)			//删除职工信息
{
	if (staffNumber <= 0)
	{
		cout << "没有任何职工信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存职工号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//清屏

		cout << "删除职工信息：" << endl;
		cout << "1. 按姓名找到要删除的职工	2. 按职工号找到要删除的职工	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名找到要删除的职工
			cout << "请输入要删除的职工姓名：";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该职工信息
				cout << endl;

				cout << "是否删除该职工信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该职工
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该职工信息
					delete p[2][location[1]];

					for (int i = location[1]; i < staffNumber - 1; i++)
						p[2][i] = p[2][i + 1];

					p[2][staffNumber - 1] = NULL;

					staffNumber--;
					sum--;

					cout << "该职工已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 2:		//按职工号找到要删除的职工
			cout << "请输入要删除的职工职工号：";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//调用查找子函数获得该人员的信息

			if (location[0] == 2 && location[1] >= 0)				//找到了该数据
			{
				p[location[0]][location[1]]->display();			//显示出该职工信息
				cout << endl;

				cout << "是否删除该职工信息？(按‘Y’或‘y’键确定删除，否则取消。)" << endl;			//提示是否删除该职工
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//删除该职工信息
					delete p[2][location[1]];

					for (int i = location[1]; i < staffNumber - 1; i++)
						p[2][i] = p[2][i + 1];

					p[2][staffNumber - 1] = NULL;

					staffNumber--;
					sum--;

					cout << "该职工已经成功被删除！" << endl;
				}
				else
				{
					cout << "已经取消删除！" << endl;
					break;
				}
			}
			else
				cout << "未找到该职工信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}

void BasketballClubManagement::emptyStaff(void)			//清空职工信息
{
	if (staffNumber == 0 && p[2][0] == NULL)
	{
		cout << "职工信息已经是空的！" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[2][i])
			delete p[2][i];
		p[2][i] = NULL;
	}

	sum -= staffNumber;			//计算总人员个数
	staffNumber = 0;

	cout << "清空职工信息成功！" << endl;
}

//在俱乐部所有人员中查找信息
void BasketballClubManagement::seekPerson(void)				//在俱乐部所有人员中查找信息
{
	if (sum <= 0)
	{
		cout << "没有任何俱乐部人员信息！" << endl;
		return;
	}

	string name;
	string ID;			//用字符串保存人员编号
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//清屏

		cout << "查找俱乐部人员信息：" << endl;
		cout << "1. 按姓名查找	2. 按人员编号查找	3. 返回" << endl;

		cin.sync();   //清空输入缓冲区的内容  
		cin.clear();
		cin >> choice;		//输入选择

		switch (choice)
		{
		case 1:		//按姓名查找
			cout << "请输入要查找的俱乐部人员的姓名：";
			cin >> name;

			findPerson(plocation, "name", name);		//调用查找子函数获得该人员的信息

			if (location[0] >= 0 && location[1] >= 0)				//找到了该数据
			{
				if (location[0] == 0)
					cout << endl << "该球员信息为：" << endl;
				if (location[0] == 1)
					cout << endl << "该教练信息为：" << endl;
				if (location[0] == 2)
					cout << endl << "该职工信息为：" << endl;

				p[location[0]][location[1]]->display();			//显示该俱乐部人员的信息
				cout << endl;
			}
			else
				cout << "未找到该俱乐部人员的信息。" << endl;
			break;

		case 2:		//按人员编号查找
			cout << "请输入要查找的俱乐部人员的编号：";
			cin >> ID;

			findPerson(location, "ID", ID);		//调用查找子函数获得该人员的信息

			if (location[0] >= 0 && location[1] >= 0)				//找到了该数据
			{
				if (location[0] == 0)
					cout << endl << "该球员信息为：" << endl;
				if (location[0] == 1)
					cout << endl << "该教练信息为：" << endl;
				if (location[0] == 2)
					cout << endl << "该职工信息为：" << endl;

				p[location[0]][location[1]]->display();			//显示该俱乐部人员的信息
				cout << endl;
			}
			else
				cout << "未找到该俱乐部人员的信息。" << endl;
			break;

		case 3:		//退出
			return;

		default:
			cout << "菜单选择错误。" << endl;
		}

		cout << endl;
		system("pause");			//暂停
	}
}



//菜单管理类函数实现
void MenuManagement::showMenu_MainMenu(void)			//显示主菜单
{
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "       篮球俱乐部人员管理" << endl << endl;

	cout << "1. 创建或添加俱乐部人员信息" << endl;
	cout << "2. 显示并统计俱乐部人员信息" << endl;
	cout << "3. 保存俱乐部人员信息" << endl;
	cout << "4. 查找俱乐部人员信息" << endl;
	cout << "5. 修改俱乐部人员信息" << endl;
	cout << "6. 删除俱乐部人员信息" << endl;
	cout << "7. 清空俱乐部人员信息" << endl << endl;

	cout << "0. 退出" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

//菜单管理——显示各个子菜单
void MenuManagement::showMenu_addPerson(void)		//显示添加人员信息子菜单
{
	cout << "    1. 创建或添加球员信息" << endl;
	cout << "    2. 创建或添加教练信息" << endl;
	cout << "    3. 创建或添加职工信息" << endl << endl;

	cout << "    4. 导入内部球员信息" << endl;
	cout << "    5. 导入内部教练信息" << endl;
	cout << "    6. 导入内部职工信息" << endl << endl;

	cout << "    7. 导入内部俱乐部所有人员的信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_showPerson(void)		//显示显示人员信息子菜单
{
	cout << "    1. 显示球员信息" << endl;
	cout << "    2. 显示教练信息" << endl;
	cout << "    3. 显示职工信息" << endl << endl;

	cout << "    4. 显示俱乐部所有人员的信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_savePerson(void)		//显示保存人员信息子菜单
{
	cout << "    1. 保存球员信息" << endl;
	cout << "    2. 保存教练信息" << endl;
	cout << "    3. 保存职工信息" << endl << endl;

	cout << "    4. 保存俱乐部所有人员的信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_seekPerson(void)		//显示查找人员信息子菜单
{
	cout << "    1. 查找球员信息" << endl;
	cout << "    2. 查找教练信息" << endl;
	cout << "    3. 查找职工信息" << endl << endl;

	cout << "    4. 在俱乐部所有人员中查找信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_modifyPerson(void)		//显示修改人员信息子菜单
{
	cout << "    1. 修改球员信息" << endl;
	cout << "    2. 修改教练信息" << endl;
	cout << "    3. 修改职工信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_removePerson(void)		//显示删除人员信息子菜单
{
	cout << "    1. 删除球员信息" << endl;
	cout << "    2. 删除教练信息" << endl;
	cout << "    3. 删除职工信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

void MenuManagement::showMenu_emptyPerson(void)			//显示清空人员信息子菜单
{
	cout << "    1. 清空球员信息" << endl;
	cout << "    2. 清空教练信息" << endl;
	cout << "    3. 清空职工信息" << endl << endl;

	cout << "    4. 清空俱乐部所有人员信息" << endl << endl;

	cout << "    0. 返回" << endl;
}

//菜单管理——响应各个子菜单
void MenuManagement::respondMenu_addPerson(void)			//响应添加人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//添加球员信息
		club.createPlayer();
		break;

	case 2:		//添加教练信息
		club.createCoach();
		break;

	case 3:		//添加职工信息
		club.createStaff();
		break;

	case 4:		//导入内部球员信息
		club.importPlayer();
		break;

	case 5:		//导入内部教练信息
		club.importCoach();
		break;

	case 6:		//导入内部职工信息
		club.importStaff();
		break;

	case 7:		//导入内部俱乐部所有人员的信息
		club.importPlayer();
		club.importCoach();
		club.importStaff();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_showPerson(void)			//响应显示人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//显示球员信息
		club.showPlayer();
		break;

	case 2:		//显示教练信息
		club.showCoach();
		break;

	case 3:		//显示职工信息
		club.showStaff();
		break;

	case 4:		//显示俱乐部所有人员信息
		cout << "俱乐部所有人员一共有 " << sum << " 个。" << endl << endl;
		club.showPlayer();
		club.showCoach();
		club.showStaff();
		cout << endl << "俱乐部所有人员一共有 " << sum << " 个。" << endl;
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_savePerson(void)			//响应保存人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//保存球员信息
		club.savePlayer();
		break;

	case 2:		//保存教练信息
		club.saveCoach();
		break;

	case 3:		//保存职工信息
		club.saveStaff();
		break;

	case 4:		//保存俱乐部所有人员信息
		club.savePlayer();
		club.saveCoach();
		club.saveStaff();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_seekPerson(void)			//响应查找人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//查找球员信息
		club.seekPlayer();
		break;

	case 2:		//查找教练信息
		club.seekCoach();
		break;

	case 3:		//查找职工信息
		club.seekStaff();
		break;

	case 4:		//在俱乐部所有人员中查找信息
		club.seekPerson();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_modifyPerson(void)		//响应修改人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//修改球员信息
		club.modifyPlayer();
		break;

	case 2:		//修改教练信息
		club.modifyCoach();
		break;

	case 3:		//修改职工信息
		club.modifyStaff();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_removePerson(void)		//响应删除人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//删除球员信息
		club.removePlayer();
		break;

	case 2:		//删除教练信息
		club.removeCoach();
		break;

	case 3:		//删除职工信息
		club.removeStaff();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}

void MenuManagement::respondMenu_emptyPerson(void)			//响应清空人员信息子菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//清空球员信息
		club.emptyPlayer();
		break;

	case 2:		//清空教练信息
		club.emptyCoach();
		break;

	case 3:		//清空职工信息
		club.emptyStaff();
		break;

	case 4:		//清空俱乐部所有人员信息
		club.emptyPlayer();
		club.emptyCoach();
		club.emptyStaff();
		break;

	case 0:		//返回
		return;

	default:
		cout << "菜单选择错误。" << endl;
	}
}



//俱乐部人员管理启动类
void BasketballClubfManagementLaunch::showMainMenu(void)			//显示主菜单
{
	menu.showMenu_MainMenu();
}

void BasketballClubfManagementLaunch::respondMenu(void)			//响应菜单
{
	cin.sync();   //清空输入缓冲区的内容  
	cin.clear();

	cin >> choice;		//输入选择

	switch (choice)
	{
	case 1:		//创建或添加俱乐部人员信息
		menu.showMenu_addPerson();
		menu.respondMenu_addPerson();
		break;

	case 2:		//显示并统计俱乐部人员信息
		menu.showMenu_showPerson();
		menu.respondMenu_showPerson();
		break;

	case 3:		//保存俱乐部人员信息
		menu.showMenu_savePerson();
		menu.respondMenu_savePerson();
		break;

	case 4:		//查找俱乐部人员信息
		menu.showMenu_seekPerson();
		menu.respondMenu_seekPerson();
		break;

	case 5:		//修改俱乐部人员信息
		menu.showMenu_modifyPerson();
		menu.respondMenu_modifyPerson();
		break;

	case 6:		//删除俱乐部人员信息
		menu.showMenu_removePerson();
		menu.respondMenu_removePerson();
		break;

	case 7:		//清空俱乐部人员信息
		menu.showMenu_emptyPerson();
		menu.respondMenu_emptyPerson();
		break;

	case 0:
		cout << "谢谢使用！" << endl;
		system("pause");			//暂停
		exit(0);

	default:
		cout << "菜单选择错误。" << endl;
	}
}