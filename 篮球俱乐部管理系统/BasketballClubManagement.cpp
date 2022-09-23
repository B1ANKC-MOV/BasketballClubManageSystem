# include"BasketballClubManagement.h"

using namespace std;

int sum = 0;			//��̬��Ա��ʼ��

Person::Person(string& name, string& gender, int& age, int& ID, string& contict)			//��ʼ��
{
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->ID = ID;
	this->contict = contict;
}

void Person::display(void)			//��ʾ��Ա������Ϣ
{
	cout << "������" << name << endl;
	cout << "�Ա�" << gender << endl;
	cout << "���䣺" << age << endl;
	cout << "��ţ�" << ID << endl;
	cout << "��ϵ�绰��" << contict << endl;
}



//��Ա���Ա����ʵ��
Player::Player(string& name, string& gender, int& age, int& ID, string& contict, string& position, string& clubName, float& uniformNumber) : Person(name, gender, age, ID, contict)
{
	this->position = position;
	this->clubName = clubName;
	this->uniformNumber = uniformNumber;
}

void Player::display(void)			//��ʾ��Ա��Ϣ
{
	Person::display();
	cout << "��Ա����λ�ã�" << position << endl;
	cout << "��Ա�������ֲ���" << clubName << endl;
	cout << "��Ա���º��룺" << uniformNumber << endl;
}

void Player::save(void)			//������Ա��Ϣ���������أ�
{
	ofstream savefile;

	savefile.open("��Ա��Ϣ.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "��Ա��Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "������" << name << endl;
	savefile << "�Ա�" << gender << endl;
	savefile << "���䣺" << age << endl;
	savefile << "��ţ�" << ID << endl;
	savefile << "��ϵ�绰��" << contict << endl;
	savefile << "��Ա����λ�ã�" << position << endl;
	savefile << "��Ա�������ֲ���" << clubName << endl;
	savefile << "��Ա���º��룺" << uniformNumber << endl << endl;

	savefile.close();			//�ر��ļ�
}

void Player::modify(void)			//�޸���Ա��Ϣ���������أ�
{
	int choice = -1;

	while (1)
	{
		system("cls");			//����

		cout << "����Աԭ��ϢΪ��" << endl;			//��ʾҪ�޸ĵ���Աԭ��Ϣ
		Person::display();
		cout << "��Ա����λ�ã�" << position << endl;
		cout << "��Ա�������ֲ���" << clubName << endl;
		cout << "��Ա���º��룺" << uniformNumber << endl;

		cout << endl;
		cout << "������Ҫ�޸ĵ����ݣ�������,�Ա�,��Ų����޸ģ�" << endl;
		cout << "1. ����	2. ��ϵ�绰	   3. ��Ա����λ��" << endl;
		cout << "4. ��Ա�������ֲ�	5. ��Ա���º���	6. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�޸���Ա����
			cout << "���������Ա�����䣺";
			cin >> age;
			cout << "�޸ĳɹ���";
			break;

		case 2:		//�޸���Ա��ϵ�绰
			cout << "���������Ա����ϵ�绰��";
			cin >> contict;
			cout << "�޸ĳɹ���";
			break;

		case 3:		//�޸���Աרҵ
			cout << "���������Ա���ϵ�λ�ã�";
			cin >> position;
			cout << "�޸ĳɹ���";
			break;

		case 4:		//�޸���Ա�༶
			cout << "���������Ա�ľ��ֲ���";
			cin >> clubName;
			cout << "�޸ĳɹ���";
			break;

		case 5:		//�޸���Ա�ɼ�
			cout << "���������Ա�����º��룺";
			cin >> uniformNumber;
			cout << "�޸ĳɹ���";
			break;

		case 6:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ��Ļ
	}
}



//������ĺ���ʵ��
Coach::Coach(string& name, string& gender, int& age, int& ID, string& contict, string& characteristic, string& nickName) : Person(name, gender, age, ID, contict)
{
	this->characteristic = characteristic;
	this->nickName = nickName;
}

void Coach::display(void)			//��ʾ������Ϣ���������أ�
{
	Person::display();
	cout << "����רҵ�ص㣺" << characteristic << endl;
	cout << "����������" << nickName << endl;
}

void Coach::save(void)			//���������Ϣ(��������)
{
	ofstream savefile;

	savefile.open("������Ϣ.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "������Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "������" << name << endl;
	savefile << "�Ա�" << gender << endl;
	savefile << "���䣺" << age << endl;
	savefile << "������ţ�" << ID << endl;
	savefile << "��ϵ�绰��" << contict << endl;
	savefile << "����רҵ�ص㣺" << characteristic << endl;
	savefile << "����������" << nickName << endl << endl;

	savefile.close();			//�ر��ļ�
}

void Coach::modify(void)			//�޸Ľ�����Ϣ���������أ�
{
	int choice = -1;

	while (1)
	{
		system("cls");			//����

		cout << "�ý���ԭ��ϢΪ��" << endl;			//��ʾҪ�޸ĵĽ���ԭ��Ϣ
		Person::display();
		cout << "�����Ը��ص㣺" << characteristic << endl;
		cout << "����������" << nickName << endl;

		cout << endl;
		cout << "������Ҫ�޸ĵ����ݣ�������,�Ա�,������Ų����޸ģ�" << endl;
		cout << "1. ����	2. ��ϵ�绰	   3. ����רҵ�ص�" << endl;
		cout << "4.��������	5. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�޸Ľ�������
			cout << "������ý��������䣺";
			cin >> age;
			cout << "�޸ĳɹ���";
			break;

		case 2:		//�޸Ľ�����ϵ�绰
			cout << "������ý�������ϵ�绰��";
			cin >> contict;
			cout << "�޸ĳɹ���";
			break;

		case 3:		//�޸Ľ���רҵ�ص�
			cout << "������ý�����רҵ�ص㣺";
			cin >> characteristic;
			cout << "�޸ĳɹ���";
			break;

		case 4:		//�޸Ľ�������
			cout << "������ý����ı�����";
			cin >> nickName;
			cout << "�޸ĳɹ���";
			break;

		case 5:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ��Ļ
	}
}



//ְ���ຯ��ʵ��
Staff::Staff(string& name, string& gender, int& age, int& ID, string& contict, string& department, string& job, int& salary) : Person(name, gender, age, ID, contict)
{
	this->department = department;			//ְ������
	this->job = job;			//ְ��ְ��
	this->salary = salary;
}

void Staff::display(void)			//��ʾְ����Ϣ���������أ�
{
	cout << endl;
	Person::display();
	cout << "ְ�����ţ�" << department << endl;
	cout << "ְ��������" << job << endl;
	cout << "ְ�����ʣ�" << salary << endl;
}

void Staff::save(void)			//����ְ����Ϣ���������أ�
{
	ofstream savefile;

	savefile.open("ְ����Ϣ.txt", ios::app);
	if (savefile.fail())
	{
		cerr << "ְ����Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "������" << name << endl;
	savefile << "�Ա�" << gender << endl;
	savefile << "���䣺" << age << endl;
	savefile << "ְ����ţ�" << ID << endl;
	savefile << "��ϵ�绰��" << contict << endl;
	savefile << "ְ�����ţ�" << department << endl;
	savefile << "ְ��������" << job << endl;
	savefile << "ְ�����ʣ�" << salary << endl << endl;

	savefile.close();			//�ر��ļ�
}

void Staff::modify(void)			//�޸�ְ����Ϣ���������أ�
{
	int choice = -1;

	while (1)
	{
		system("cls");			//����

		cout << "��ְ��ԭ��ϢΪ��" << endl;			//��ʾҪ�޸ĵ�ְ��ԭ��Ϣ
		Person::display();
		cout << "ְ�����ţ�" << department << endl;
		cout << "ְ��������" << job << endl;
		cout << "ְ�����ʣ�" << salary << endl;

		cout << endl;
		cout << "������Ҫ�޸ĵ����ݣ�������,�Ա�,ְ����Ų����޸ģ�" << endl;
		cout << "1. ����	2. ��ϵ�绰	3. ְ������" << endl;
		cout << "4. ְ������	5. ְ������	6. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�޸�ְ������
			cout << "�������ְ�������䣺";
			cin >> age;
			cout << "�޸ĳɹ���";
			break;

		case 2:		//�޸�ְ����ϵ�绰
			cout << "�������ְ������ϵ�绰��";
			cin >> contict;
			cout << "�޸ĳɹ���";
			break;

		case 3:		//�޸�ְ������
			cout << "�������ְ���Ĳ��ţ�";
			cin >> department;
			cout << "�޸ĳɹ���";
			break;

		case 4:		//�޸�ְ������
			cout << "�������ְ���Ĺ�����";
			cin >> job;
			cout << "�޸ĳɹ���";
			break;

		case 5:		//�޸�ְ������
			cout << "�������ְ���Ĺ��ʣ�";
			cin >> salary;
			cout << "�޸ĳɹ���";
			break;

		case 6:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ��Ļ
	}
}



//��Ա�������Ա������ʵ��
BasketballClubManagement::BasketballClubManagement(void)			//���캯��
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

BasketballClubManagement::~BasketballClubManagement(void)			//��������
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < MAX; j++)
		{
			if (p[i][j])
				delete p[i][j];
			p[i][j] = NULL;
		}
}

//���Ҹ����ݵ�λ�ã�4�������ֱ��Ƿ��ز��ҵ������ݵ�λ�á����ҵ��������ͣ������ֲ��һ��Ǳ�ţ���
//Ҫ���ҵ����ݣ�Ҫ���ҵ���Ա���ͣ�Ĭ����������Ա�в��ң�
void BasketballClubManagement::findPerson(int* plocation, const string& findType, const string& lookedData, const string& personType)
{
	int flag = 0;			//�ж��Ƿ��ҵ�����Ա�������ж��Ƿ��ظ�

	plocation[0] = -1;			//��ʼ��
	plocation[1] = -1;

	if (findType == "name")		//�����ֲ���
	{
		if (personType == "player")			//�����ֲ���֮����Ա�в���
		{
			flag = 0;

			for (int i = 0; i < playerNumber && p[0][i] != NULL; i++)
			{
				if (p[0][i]->name == lookedData)
				{
					if (flag)			//�ж��Ƿ����ظ���������Ա
					{
						cout << "������ͬ��������Ա��ֻ���ҵ�һ��������������Ա��Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 0;			//����Ա���ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "coach")			//�������ڽ����в���
		{
			flag = 0;

			for (int i = 0; i < coachNumber && p[1][i] != NULL; i++)
			{
				if (p[1][i]->name == lookedData)
				{
					if (flag)			//�ж��Ƿ����ظ������Ľ���
					{
						cout << "������ͬ�����Ľ�����ֻ���ҵ�һ�����������Ľ�����Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 1;			//�ڽ������ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "staff")			//�����ֲ���֮��ְ���в���
		{
			flag = 0;

			for (int i = 0; i < staffNumber && p[2][i] != NULL; i++)
			{
				if (p[2][i]->name == lookedData)
				{
					if (flag)			//�ж��Ƿ����ظ�������ְ��
					{
						cout << "������ͬ������ְ����ֻ���ҵ�һ������������ְ����Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 2;			//��ְ�����ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "allPerson")			//�����ֲ���֮��������Ա�в���
		{
			flag = 0;

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < MAX && p[i][j] != NULL; j++)
					if (p[i][j]->name == lookedData)
					{
						if (flag)			//�ж��Ƿ����ظ���������Ա
						{
							cout << "������ͬ�����ĳ�Ա��ֻ���ҵ�һ�����������ľ��ֲ���Ա��Ϣ��" << endl << endl;
							return;
						}
						plocation[0] = i;			//����þ��ֲ���Ա����ݣ���Ա/����/ְ����
						plocation[1] = j;			//�ó�Ա��ŵ�λ��
						flag++;
					}
			}
		}
		else
			cerr << "�������������󣬲����Ӻ���Ҫ���ҵ���Ա���Ͳ�������" << endl;
	}
	else if (findType == "ID")		//����Ų���
	{
		int No = 0;			//������
		istringstream iss(lookedData);			//��string���͵ı��ת��Ϊ���ͱ�����No��
		iss >> No;

		if (personType == "player")			//����Ų���֮����Ա�в���
		{
			flag = 0;

			for (int i = 0; i < playerNumber && p[0][i] != NULL; i++)
			{
				if (p[0][i]->ID == No)
				{
					if (flag)			//�ж��Ƿ����ظ���������Ա
					{
						cout << "������ͬѧ�ŵ���Ա��ֻ���ҵ�һ��������������Ա��Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 0;			//����Ա���ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "coach")			//����Ų���֮�ڽ����в���
		{
			flag = 0;

			for (int i = 0; i < coachNumber && p[1][i] != NULL; i++)
			{
				if (p[1][i]->ID == No)
				{
					if (flag)			//�ж��Ƿ����ظ������Ľ���
					{
						cout << "������ͬ��ŵĽ�����ֻ���ҵ�һ�����������Ľ�����Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 1;			//�ڽ������ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "staff")			//����Ų���֮��ְ���в���
		{
			flag = 0;

			for (int i = 0; i < staffNumber && p[2][i] != NULL; i++)
			{
				if (p[2][i]->ID == No)
				{
					if (flag)			//�ж��Ƿ����ظ�������ְ��
					{
						cout << "������ְͬ���ŵ�ְ����ֻ���ҵ�һ������������ְ����Ϣ��" << endl << endl;
						return;
					}
					plocation[0] = 2;			//��ְ�����ҵ�
					plocation[1] = i;			//����Ա��ŵ�λ��
					flag++;
				}
			}
		}
		else if (personType == "allPerson")			//����Ų���֮�����о��ֲ���Ա�в���
		{
			flag = 0;

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < MAX && p[i][j] != NULL; j++)
					if (p[i][j]->ID == No)
					{
						if (flag)			//�ж��Ƿ����ظ������ľ��ֲ���Ա
						{
							cout << "����ͬ��ŵľ��ֲ���Ա��ֻ���ҵ�һ�����������ľ��ֲ���Ա��Ϣ��" << endl << endl;
							return;
						}
						plocation[0] = i;			//����þ��ֲ���Ա����ݣ���Ա/����/ְ����
						plocation[1] = j;			//����Ա��ŵ�λ��
						flag++;
					}
			}
		}
		else
			cerr << "�������������󣬲����Ӻ���Ҫ���ҵ���Ա���Ͳ�������" << endl;
	}
	else
		cerr << "������������Ӻ���Ҫ���ҵ��������Ͳ�����������ʧ�ܣ�" << endl;
}

//��Ա��Ϣ������ʵ��
void BasketballClubManagement::createPlayer(void)			//�����������Ա��Ϣ
{
	string name, gender, position, contict, clubName;			//�������Ա𣬳���λ�ã���ϵ�绰���������ֲ�
	int age, ID;		float uniformNumber;			//���䣬��Ա��ţ����º���
	char ch = NULL;
	int addNumber;			//��ӵ�����
	int i = 0;

	if (p[0][0])			//�ж��Ƿ������Ա��Ϣ
	{
		cout << "��Ա��Ϣ�Ѿ����������������������Ա��Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
		else
		{
			cout << "������Ҫ��ӵ���Ա��������������" << MAX - playerNumber << "����" << endl;
		}
	}
	else
		cout << "������Ҫ��������Ա��������������" << MAX << "����" << endl;
	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - playerNumber)			//��ȫ�Լ��
	{
		cout << "����������ʧ�ܡ�" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "������� " << i + 1 << " ����Ա������";		cin >> name;
		cout << "������� " << i + 1 << " ����Ա�Ա�";		cin >> gender;
		cout << "������� " << i + 1 << " ����Ա���䣺";		cin >> age;
		cout << "������� " << i + 1 << " ����Ա��ţ�";		cin >> ID;
		cout << "������� " << i + 1 << " ����Ա��ϵ�绰��";		cin >> contict;
		cout << "������� " << i + 1 << " ����Ա����λ�ã�";		cin >> position;
		cout << "������� " << i + 1 << " ����Ա�������ֲ���";		cin >> clubName;
		cout << "������� " << i + 1 << " ����Ա���º��룺";		cin >> uniformNumber;
		cout << endl;

		p[0][playerNumber + i] = new Player(name, gender, age, ID, contict, position, clubName, uniformNumber);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	playerNumber += addNumber;			//������Ա����
	sum += addNumber;			//��������Ա����

	cout << "��Ա��Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::importPlayer(void)
{
	string name[4], gender[4], position[4], contict[4], clubName[4];			//�������Ա���Ա����λ�ã���ϵ�绰���༶
	int age[4], ID[4];		float uniformNumber[4];			//���䣬��Ա��ţ����º���
	char ch = NULL;
	int addNumber;			//��ӵ�����
	int i = 0;

	//������Ա��Ա
	name[0] = "˹�ٷҡ�����";			name[1] = "�ղ��ʡ�ղķ˹";		name[2] = "�����ᡤ��ά˹";			name[3] = "���ġ�������";
	gender[0] = "��";					gender[1] = "��";				gender[2] = "��";					gender[3] = "��";
	position[0] = "�������";			position[1] = "Сǰ��";			position[2] = "��ǰ��/�з�";		position[3] = "Сǰ��";
	contict[0] = "13854532219";			contict[1] = "13453224614";		contict[2] = "18995642658";			contict[3] = "13759426583";
	clubName[0] = "������ʿ��";			clubName[1] = "��ɼ���˶�";	clubName[2] = "��ɼ���˶�";		clubName[3] = "��³��������";
	age[0] = 32;						age[1] = 36;					age[2] = 27;						age[3] = 32;
	ID[0] = 1988314;					ID[1] = 19841230;				ID[2] = 1993311;					ID[3] = 1988929;
	uniformNumber[0] = 30;				uniformNumber[1] = 23;			uniformNumber[2] = 23;				uniformNumber[3] = 35;

	if (p[0][0])			//�ж��Ƿ������Ա��Ϣ
	{
		cout << "��Ա��Ϣ�Ѿ����������������������Ա��Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
	}

	addNumber = 4;

	for (i = 0; i < addNumber; i++)
	{
		p[0][playerNumber + i] = new Player(name[i], gender[i], age[i], ID[i], contict[i], position[i], clubName[i], uniformNumber[i]);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	playerNumber += addNumber;			//������Ա����
	sum += addNumber;			//��������Ա����

	cout << "��Ա��Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::showPlayer(void)			//��ʾ������Ա��Ϣ
{
	for (int i = 0; i < playerNumber; i++)
	{
		cout << endl;
		p[0][i]->display();
	}

	cout << endl << "һ���� " << playerNumber << " ����Ա" << endl;			//ͳ����Ա����
}

void BasketballClubManagement::savePlayer(void)			//����������Ա��Ϣ
{
	ofstream savefile;

	savefile.open("��Ա��Ϣ.txt", ios::out);				//���ļ�
	if (savefile.fail())
	{
		cerr << "��Ա��Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile.close();			//���ļ�֮��ر��ļ������ԭ�ļ��ϴ�����

	for (int i = 0; i < playerNumber; i++)
	{
		p[0][i]->save();				//�����˶�̬ʵ�֣�����ָ��ָ��������
	}

	savefile.open("��Ա��Ϣ.txt", ios::app);				//���ļ�
	if (savefile.fail())
	{
		cerr << "��Ա��Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "һ���� " << playerNumber << " ����Ա" << endl;			//����Ա�������浽�ļ�

	cout << "��Ա��Ϣ�Ѿ������� ����Ա��Ϣ.txt�� �ļ��У���鿴��" << endl;

	savefile.close();			//�ر��ļ�
}

void BasketballClubManagement::seekPlayer(void)			//������Ա��Ϣ
{
	if (playerNumber <= 0)
	{
		cout << "û���κ���Ա��Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ���������Ա���
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "������Ա��Ϣ��" << endl;
		cout << "1. ����������	2. ����Ų���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//����������
			cout << "������Ҫ���ҵ���Ա������";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ����Ա��Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 2:		//����Ų���
			cout << "������Ҫ���ҵ���Ա��ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ����Ա��Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::modifyPlayer(void)			//�޸���Ա��Ϣ
{
	if (playerNumber <= 0)
	{
		cout << "û���κ���Ա��Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ���������Ա���
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "�޸���Ա��Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫ�޸ĵ���Ա	2. ������ҵ�Ҫ�޸ĵ���Ա	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫ�޸ĵ���Ա
			cout << "������Ҫ�޸ĵ���Ա������";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸ���Ա��Ϣ
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 2:		//������ҵ�Ҫ�޸ĵ���Ա
			cout << "������Ҫ�޸ĵ���Ա��ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸ���Ա��Ϣ
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::removePlayer(void)			//ɾ����Ա��Ϣ
{
	if (playerNumber <= 0)
	{
		cout << "û���κ���Ա��Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ���������Ա���
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//����

		cout << "ɾ����Ա��Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫɾ������Ա	2. ������ҵ�Ҫɾ������Ա	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫɾ������Ա
			cout << "������Ҫɾ������Ա������";
			cin >> name;

			findPerson(plocation, "name", name, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ������Ա��Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ������Ա��Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ������Ա
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ������Ա��Ϣ
					delete p[0][location[1]];

					for (int i = location[1]; i < playerNumber - 1; i++)
						p[0][i] = p[0][i + 1];

					p[0][playerNumber - 1] = NULL;

					playerNumber--;
					sum--;

					cout << "����Ա�Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 2:		//������ҵ�Ҫɾ������Ա
			cout << "������Ҫɾ������Ա��ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "player");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ������Ա��Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ������Ա��Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ������Ա
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ������Ա��Ϣ
					delete p[0][location[1]];

					for (int i = location[1]; i < playerNumber - 1; i++)
						p[0][i] = p[0][i + 1];

					p[0][playerNumber - 1] = NULL;

					playerNumber--;
					sum--;

					cout << "����Ա�Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::emptyPlayer(void)			//�����Ա��Ϣ
{
	if (playerNumber == 0 && p[0][0] == NULL)
	{
		cout << "��Ա��Ϣ�Ѿ��ǿյģ�" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[0][i])
			delete p[0][i];
		p[0][i] = NULL;
	}

	sum -= playerNumber;			//��������Ա����
	playerNumber = 0;

	cout << "�����Ա��Ϣ�ɹ���" << endl;
}



//������Ϣ������ʵ��
void BasketballClubManagement::createCoach(void)			//��������ӽ�����Ϣ
{
	string name, gender, characteristic, contict, nickName;		//�������Ա�רҵ�ص㣬��ϵ�绰�����
	int age, ID;			//���䣬�������
	char ch = NULL;
	int addNumber;			//�����Ա������
	int i = 0;

	if (p[1][0])			//�ж��Ƿ���ڽ�����Ϣ
	{
		cout << "������Ϣ�Ѿ�������������������ӽ�����Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
		else
		{
			cout << "������Ҫ��ӵĽ�����������������" << MAX - coachNumber << "����" << endl;
		}
	}
	else
		cout << "������Ҫ�����Ľ�����������������" << MAX << "����" << endl;

	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - coachNumber)			//��ȫ�Լ��
	{
		cout << "����������ʧ�ܡ�" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "������� " << i + 1 << " ������������";		cin >> name;
		cout << "������� " << i + 1 << " �������Ա�";		cin >> gender;
		cout << "������� " << i + 1 << " ���������䣺";		cin >> age;
		cout << "������� " << i + 1 << " ��������ţ�";		cin >> ID;
		cout << "������� " << i + 1 << " ��������ϵ�绰��";		cin >> contict;
		cout << "������� " << i + 1 << " ��������רҵ�ص㣺";		cin >> characteristic;
		cout << "������� " << i + 1 << " �������ı�ƣ�";		cin >> nickName;
		cout << endl;

		p[1][coachNumber + i] = new Coach(name, gender, age, ID, contict, characteristic, nickName);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	coachNumber += addNumber;			//�����������
	sum += addNumber;			//��������Ա����

	cout << "������Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::importCoach(void)			//���������Ϣ
{
	string name[2], gender[2], characteristic[2], contict[2], nickName[2];			//�������Ա�רҵ�ص㣬��ϵ�绰�����
	int age[2], ID[2];			//���䣬�������
	char ch = NULL;
	int addNumber;			//��ӵ�����
	int i = 0;

	//���ý�����Ա
	name[0] = "ʷ�ٷ򡤿ƶ�";				name[1] = "��ɭ������";
	gender[0] = "��";						gender[1] = "��";
	characteristic[0] = "���ָ���";			characteristic[1] = "��Ұ�������ٿ�ȫ��������Ϊͻ��";
	contict[0] = "13966668888";				contict[1] = "18911115555";
	nickName[0] = "ˮ��";					nickName[1] = "��ɭ����";
	age[0] = 55;							age[1] = 47;
	ID[0] = 1965927;						ID[1] = 1973323;

	if (p[1][0])			//�ж��Ƿ���ڽ�����Ϣ
	{
		cout << "������Ϣ�Ѿ�������������������ӽ�����Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
	}

	addNumber = 2;

	for (i = 0; i < addNumber; i++)
	{
		p[1][coachNumber + i] = new Coach(name[i], gender[i], age[i], ID[i], contict[i], characteristic[i], nickName[i]);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	coachNumber += addNumber;			//�����������
	sum += addNumber;			//��������Ա����

	cout << "������Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::showCoach(void)			//��ʾ���н�����Ϣ
{
	for (int i = 0; i < coachNumber; i++)
	{
		cout << endl;
		p[1][i]->display();
	}

	cout << endl << "һ���� " << coachNumber << " ������" << endl;			//ͳ�ƽ�������
}

void BasketballClubManagement::saveCoach(void)			//�������н�����Ϣ
{
	ofstream savefile;

	savefile.open("������Ϣ.txt", ios::out);				//���ļ�
	if (savefile.fail())
	{
		cerr << "������Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile.close();			//���ļ�֮��ر��ļ������ԭ�ļ��ϴ�����

	for (int i = 0; i < coachNumber; i++)
	{
		p[1][i]->save();				//�����˶�̬ʵ�֣�����ָ��ָ��������
	}

	savefile.open("������Ϣ.txt", ios::app);			//���ļ�
	if (savefile.fail())
	{
		cerr << "������Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "һ���� " << coachNumber << " ������" << endl;			//�������������浽�ļ�

	cout << "������Ϣ�Ѿ������� ��������Ϣ.txt�� �ļ��У���鿴��" << endl;

	savefile.close();			//�ر��ļ�
}

void BasketballClubManagement::seekCoach(void)			//���ҽ�����Ϣ
{
	if (coachNumber <= 0)
	{
		cout << "û���κν�����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������������
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "���ҽ�����Ϣ��" << endl;
		cout << "1. ����������	2. ��������Ų���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//����������
			cout << "������Ҫ���ҵĽ���������";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ�ý�����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 2:		//��������Ų���
			cout << "������Ҫ���ҵĽ�����ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ�ý�����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::modifyCoach(void)			//�޸Ľ�����Ϣ
{
	if (coachNumber <= 0)
	{
		cout << "û���κν�����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������������
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "�޸Ľ�����Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫ�޸ĵĽ���	2. ������ҵ�Ҫ�޸ĵĽ���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫ�޸ĵĽ���
			cout << "������Ҫ���ҵĽ���������";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸý�����Ϣ
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 2:		//����������ҵ�Ҫ�޸ĵĽ�������Ϣ
			cout << "������Ҫ�޸ĵĽ�����ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸý�����Ϣ
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::removeCoach(void)			//ɾ��������Ϣ
{
	if (coachNumber <= 0)
	{
		cout << "û���κν�����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������������
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//����

		cout << "ɾ��������Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫɾ���Ľ���	2. ����������ҵ�Ҫɾ���Ľ���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫɾ���Ľ���
			cout << "������Ҫɾ���Ľ���������";
			cin >> name;

			findPerson(plocation, "name", name, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ���ý�����Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ���ý�����Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ���ý���
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ���ý�����Ϣ
					delete p[1][location[1]];

					for (int i = location[1]; i < coachNumber - 1; i++)
						p[1][i] = p[1][i + 1];

					p[1][coachNumber - 1] = NULL;

					coachNumber--;
					sum--;

					cout << "�ý����Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 2:		//����������ҵ�Ҫɾ���Ľ���
			cout << "������Ҫɾ���Ľ�����ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "coach");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 1 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ���ý�����Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ���ý�����Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ���ý���
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ���ý�����Ϣ
					delete p[1][location[1]];

					for (int i = location[1]; i < coachNumber - 1; i++)
						p[1][i] = p[1][i + 1];

					p[1][coachNumber - 1] = NULL;

					coachNumber--;
					sum--;

					cout << "�ý����Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ��ý�����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::emptyCoach(void)			//��ս�����Ϣ
{
	if (coachNumber == 0 && p[1][0] == NULL)
	{
		cout << "������Ϣ�Ѿ��ǿյģ�" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[1][i])
			delete p[1][i];
		p[1][i] = NULL;
	}

	sum -= coachNumber;			//��������Ա����
	coachNumber = 0;

	cout << "��ս�����Ϣ�ɹ���" << endl;
}



//ְ����Ϣ������ʵ��
void BasketballClubManagement::createStaff(void)			//���������ְ����Ϣ
{
	string name, gender, department, contict, job;			//�������Ա𣬲��ţ���ϵ�绰, ����
	int age, ID, salary;			//���䣬ְ���ţ�����
	char ch = NULL;
	int addNumber;			//�����Ա������
	int i = 0;

	if (p[2][0])			//�ж��Ƿ����ְ����Ϣ
	{
		cout << "ְ����Ϣ�Ѿ��������������������ְ����Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
		else
		{
			cout << "������Ҫ��ӵ�ְ����������������" << MAX - staffNumber << "����" << endl;
		}
	}
	else
		cout << "������Ҫ������ְ����������������" << MAX << "����" << endl;

	cin >> addNumber;
	if (addNumber < 1 || addNumber > MAX - staffNumber)			//��ȫ�Լ��
	{
		cout << "����������ʧ�ܡ�" << endl;
		return;
	}

	for (i = 0; i < addNumber; i++)
	{
		cout << endl;
		cout << "������� " << i + 1 << " ��ְ��������";		cin >> name;
		cout << "������� " << i + 1 << " ��ְ���Ա�";		cin >> gender;
		cout << "������� " << i + 1 << " ��ְ�����䣺";		cin >> age;
		cout << "������� " << i + 1 << " ��ְ��ѧ�ţ�";		cin >> ID;
		cout << "������� " << i + 1 << " ��ְ����ϵ�绰��";		cin >> contict;
		cout << "������� " << i + 1 << " ��ְ���Ĳ��ţ�";		cin >> department;
		cout << "������� " << i + 1 << " ��ְ���Ĺ�����";		cin >> job;
		cout << "������� " << i + 1 << " ��ְ���Ĺ��ʣ�";		cin >> salary;
		cout << endl;

		p[2][staffNumber + i] = new Staff(name, gender, age, ID, contict, department, job, salary);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	staffNumber += addNumber;			//����ְ������
	sum += addNumber;			//��������Ա����

	cout << "ְ����Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::importStaff(void)
{
	string name[3], gender[3], department[3], contict[3], job[3];			//�������Ա𣬲��ţ���ϵ�绰, ����
	int age[3], ID[3], salary[3];			//���䣬ְ���ţ�����
	char ch = NULL;
	int addNumber;			//��ӵ�����
	int i = 0;

	//����ְ����Ա
	name[0] = "������";								name[1] = "������";								name[2] = "�Ź�";
	gender[0] = "��";								gender[1] = "Ů";					   			gender[2] = "��";
	department[0] = "��Ʒ��Ӫ��";					department[1] = "����";		  				department[2] = "�칫��";
	contict[0] = "13663639355";						contict[1] = "15977766541";						contict[2] = "13687546156";
	job[0] = "���ܾ���";							job[1] = "�����ܼ�";							job[2] = "�ܾ���";
	age[0] = 32;									age[1] = 33;									age[2] = 50;
	ID[0] = 2010088;								ID[1] = 2010054;								ID[2] = 2010008;
	salary[0] = 6000;								salary[1] = 6000;								salary[2] = 10000;

	if (p[2][0])			//�ж��Ƿ����ְ����Ϣ
	{
		cout << "ְ����Ϣ�Ѿ��������������������ְ����Ϣ���Ƿ�ȡ����(����Y����y����ȡ�����)" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "�Ѿ�ȡ����ӣ�" << endl;
			return;
		}
	}

	addNumber = 3;

	for (i = 0; i < addNumber; i++)
	{
		p[2][staffNumber + i] = new Staff(name[i], gender[i], age[i], ID[i], contict[i], department[i], job[i], salary[i]);			//�û���ָ��ָ�����������ʵ�ֶ�̬
	}

	staffNumber += addNumber;			//����ְ������
	sum += addNumber;			//��������Ա����

	cout << "ְ����Ϣ����ɹ���" << endl;
}

void BasketballClubManagement::showStaff(void)			//��ʾ����ְ����Ϣ
{
	for (int i = 0; i < staffNumber; i++)
	{
		cout << endl;
		p[2][i]->display();
	}

	cout << endl << "һ���� " << staffNumber << " ��ְ��" << endl;			//ͳ��ְ������
}

void BasketballClubManagement::saveStaff(void)			//��������ְ����Ϣ
{
	ofstream savefile;

	savefile.open("ְ����Ϣ.txt", ios::out);				//���ļ�
	if (savefile.fail())
	{
		cerr << "ְ����Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile.close();			//���ļ�֮��ر��ļ������ԭ�ļ��ϴ�����

	for (int i = 0; i < staffNumber; i++)
	{
		p[2][i]->save();				//�����˶�̬ʵ�֣�����ָ��ָ��������
	}

	savefile.open("ְ����Ϣ.txt", ios::app);			//���ļ�
	if (savefile.fail())
	{
		cerr << "ְ����Ϣ����ʧ�ܡ�" << endl;
		return;
	}

	savefile << "һ���� " << staffNumber << " ��ְ��" << endl;			//��ְ���������浽�ļ�

	cout << "ְ����Ϣ�Ѿ������� ��ְ����Ϣ.txt�� �ļ��У���鿴��" << endl;

	savefile.close();			//�ر��ļ�
}

void BasketballClubManagement::seekStaff(void)			//����ְ����Ϣ
{
	if (staffNumber <= 0)
	{
		cout << "û���κ�ְ����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������ְ����
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "����ְ����Ϣ��" << endl;
		cout << "1. ����������	2. ��ְ���Ų���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//����������
			cout << "������Ҫ���ҵ�ְ��������";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ��ְ����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 2:		//��ְ���Ų���
			cout << "������Ҫ���ҵ�ְ���ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ��ְ����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::modifyStaff(void)			//�޸�ְ����Ϣ
{
	if (staffNumber <= 0)
	{
		cout << "û���κ�ְ����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������ְ����
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "�޸�ְ����Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫ�޸ĵ�ְ��	2. ��ְ�����ҵ�Ҫ�޸ĵ�ְ��	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫ�޸ĵ�ְ��
			cout << "������Ҫ�޸ĵ�ְ��������";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸ�ְ����Ϣ
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 2:		//��ְ�����ҵ�Ҫ�޸ĵ�ְ��
			cout << "������Ҫ�޸ĵ�ְ���ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
				p[location[0]][location[1]]->modify();			//�޸ĸ�ְ����Ϣ
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::removeStaff(void)			//ɾ��ְ����Ϣ
{
	if (staffNumber <= 0)
	{
		cout << "û���κ�ְ����Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ�������ְ����
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;
	char ch = NULL;

	while (1)
	{
		system("cls");			//����

		cout << "ɾ��ְ����Ϣ��" << endl;
		cout << "1. �������ҵ�Ҫɾ����ְ��	2. ��ְ�����ҵ�Ҫɾ����ְ��	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//�������ҵ�Ҫɾ����ְ��
			cout << "������Ҫɾ����ְ��������";
			cin >> name;

			findPerson(plocation, "name", name, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ����ְ����Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ����ְ����Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ����ְ��
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ����ְ����Ϣ
					delete p[2][location[1]];

					for (int i = location[1]; i < staffNumber - 1; i++)
						p[2][i] = p[2][i + 1];

					p[2][staffNumber - 1] = NULL;

					staffNumber--;
					sum--;

					cout << "��ְ���Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 2:		//��ְ�����ҵ�Ҫɾ����ְ��
			cout << "������Ҫɾ����ְ��ְ���ţ�";
			cin >> ID;

			findPerson(location, "ID", ID, "staff");		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] == 2 && location[1] >= 0)				//�ҵ��˸�����
			{
				p[location[0]][location[1]]->display();			//��ʾ����ְ����Ϣ
				cout << endl;

				cout << "�Ƿ�ɾ����ְ����Ϣ��(����Y����y����ȷ��ɾ��������ȡ����)" << endl;			//��ʾ�Ƿ�ɾ����ְ��
				cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					//ɾ����ְ����Ϣ
					delete p[2][location[1]];

					for (int i = location[1]; i < staffNumber - 1; i++)
						p[2][i] = p[2][i + 1];

					p[2][staffNumber - 1] = NULL;

					staffNumber--;
					sum--;

					cout << "��ְ���Ѿ��ɹ���ɾ����" << endl;
				}
				else
				{
					cout << "�Ѿ�ȡ��ɾ����" << endl;
					break;
				}
			}
			else
				cout << "δ�ҵ���ְ����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}

void BasketballClubManagement::emptyStaff(void)			//���ְ����Ϣ
{
	if (staffNumber == 0 && p[2][0] == NULL)
	{
		cout << "ְ����Ϣ�Ѿ��ǿյģ�" << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (p[2][i])
			delete p[2][i];
		p[2][i] = NULL;
	}

	sum -= staffNumber;			//��������Ա����
	staffNumber = 0;

	cout << "���ְ����Ϣ�ɹ���" << endl;
}

//�ھ��ֲ�������Ա�в�����Ϣ
void BasketballClubManagement::seekPerson(void)				//�ھ��ֲ�������Ա�в�����Ϣ
{
	if (sum <= 0)
	{
		cout << "û���κξ��ֲ���Ա��Ϣ��" << endl;
		return;
	}

	string name;
	string ID;			//���ַ���������Ա���
	int choice = -1;
	int location[2] = { -1,-1 };
	int* plocation = location;

	while (1)
	{
		system("cls");			//����

		cout << "���Ҿ��ֲ���Ա��Ϣ��" << endl;
		cout << "1. ����������	2. ����Ա��Ų���	3. ����" << endl;

		cin.sync();   //������뻺����������  
		cin.clear();
		cin >> choice;		//����ѡ��

		switch (choice)
		{
		case 1:		//����������
			cout << "������Ҫ���ҵľ��ֲ���Ա��������";
			cin >> name;

			findPerson(plocation, "name", name);		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] >= 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				if (location[0] == 0)
					cout << endl << "����Ա��ϢΪ��" << endl;
				if (location[0] == 1)
					cout << endl << "�ý�����ϢΪ��" << endl;
				if (location[0] == 2)
					cout << endl << "��ְ����ϢΪ��" << endl;

				p[location[0]][location[1]]->display();			//��ʾ�þ��ֲ���Ա����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ��þ��ֲ���Ա����Ϣ��" << endl;
			break;

		case 2:		//����Ա��Ų���
			cout << "������Ҫ���ҵľ��ֲ���Ա�ı�ţ�";
			cin >> ID;

			findPerson(location, "ID", ID);		//���ò����Ӻ�����ø���Ա����Ϣ

			if (location[0] >= 0 && location[1] >= 0)				//�ҵ��˸�����
			{
				if (location[0] == 0)
					cout << endl << "����Ա��ϢΪ��" << endl;
				if (location[0] == 1)
					cout << endl << "�ý�����ϢΪ��" << endl;
				if (location[0] == 2)
					cout << endl << "��ְ����ϢΪ��" << endl;

				p[location[0]][location[1]]->display();			//��ʾ�þ��ֲ���Ա����Ϣ
				cout << endl;
			}
			else
				cout << "δ�ҵ��þ��ֲ���Ա����Ϣ��" << endl;
			break;

		case 3:		//�˳�
			return;

		default:
			cout << "�˵�ѡ�����" << endl;
		}

		cout << endl;
		system("pause");			//��ͣ
	}
}



//�˵������ຯ��ʵ��
void MenuManagement::showMenu_MainMenu(void)			//��ʾ���˵�
{
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "       ������ֲ���Ա����" << endl << endl;

	cout << "1. ��������Ӿ��ֲ���Ա��Ϣ" << endl;
	cout << "2. ��ʾ��ͳ�ƾ��ֲ���Ա��Ϣ" << endl;
	cout << "3. ������ֲ���Ա��Ϣ" << endl;
	cout << "4. ���Ҿ��ֲ���Ա��Ϣ" << endl;
	cout << "5. �޸ľ��ֲ���Ա��Ϣ" << endl;
	cout << "6. ɾ�����ֲ���Ա��Ϣ" << endl;
	cout << "7. ��վ��ֲ���Ա��Ϣ" << endl << endl;

	cout << "0. �˳�" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

//�˵���������ʾ�����Ӳ˵�
void MenuManagement::showMenu_addPerson(void)		//��ʾ�����Ա��Ϣ�Ӳ˵�
{
	cout << "    1. �����������Ա��Ϣ" << endl;
	cout << "    2. ��������ӽ�����Ϣ" << endl;
	cout << "    3. ���������ְ����Ϣ" << endl << endl;

	cout << "    4. �����ڲ���Ա��Ϣ" << endl;
	cout << "    5. �����ڲ�������Ϣ" << endl;
	cout << "    6. �����ڲ�ְ����Ϣ" << endl << endl;

	cout << "    7. �����ڲ����ֲ�������Ա����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_showPerson(void)		//��ʾ��ʾ��Ա��Ϣ�Ӳ˵�
{
	cout << "    1. ��ʾ��Ա��Ϣ" << endl;
	cout << "    2. ��ʾ������Ϣ" << endl;
	cout << "    3. ��ʾְ����Ϣ" << endl << endl;

	cout << "    4. ��ʾ���ֲ�������Ա����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_savePerson(void)		//��ʾ������Ա��Ϣ�Ӳ˵�
{
	cout << "    1. ������Ա��Ϣ" << endl;
	cout << "    2. ���������Ϣ" << endl;
	cout << "    3. ����ְ����Ϣ" << endl << endl;

	cout << "    4. ������ֲ�������Ա����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_seekPerson(void)		//��ʾ������Ա��Ϣ�Ӳ˵�
{
	cout << "    1. ������Ա��Ϣ" << endl;
	cout << "    2. ���ҽ�����Ϣ" << endl;
	cout << "    3. ����ְ����Ϣ" << endl << endl;

	cout << "    4. �ھ��ֲ�������Ա�в�����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_modifyPerson(void)		//��ʾ�޸���Ա��Ϣ�Ӳ˵�
{
	cout << "    1. �޸���Ա��Ϣ" << endl;
	cout << "    2. �޸Ľ�����Ϣ" << endl;
	cout << "    3. �޸�ְ����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_removePerson(void)		//��ʾɾ����Ա��Ϣ�Ӳ˵�
{
	cout << "    1. ɾ����Ա��Ϣ" << endl;
	cout << "    2. ɾ��������Ϣ" << endl;
	cout << "    3. ɾ��ְ����Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

void MenuManagement::showMenu_emptyPerson(void)			//��ʾ�����Ա��Ϣ�Ӳ˵�
{
	cout << "    1. �����Ա��Ϣ" << endl;
	cout << "    2. ��ս�����Ϣ" << endl;
	cout << "    3. ���ְ����Ϣ" << endl << endl;

	cout << "    4. ��վ��ֲ�������Ա��Ϣ" << endl << endl;

	cout << "    0. ����" << endl;
}

//�˵���������Ӧ�����Ӳ˵�
void MenuManagement::respondMenu_addPerson(void)			//��Ӧ�����Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//�����Ա��Ϣ
		club.createPlayer();
		break;

	case 2:		//��ӽ�����Ϣ
		club.createCoach();
		break;

	case 3:		//���ְ����Ϣ
		club.createStaff();
		break;

	case 4:		//�����ڲ���Ա��Ϣ
		club.importPlayer();
		break;

	case 5:		//�����ڲ�������Ϣ
		club.importCoach();
		break;

	case 6:		//�����ڲ�ְ����Ϣ
		club.importStaff();
		break;

	case 7:		//�����ڲ����ֲ�������Ա����Ϣ
		club.importPlayer();
		club.importCoach();
		club.importStaff();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_showPerson(void)			//��Ӧ��ʾ��Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//��ʾ��Ա��Ϣ
		club.showPlayer();
		break;

	case 2:		//��ʾ������Ϣ
		club.showCoach();
		break;

	case 3:		//��ʾְ����Ϣ
		club.showStaff();
		break;

	case 4:		//��ʾ���ֲ�������Ա��Ϣ
		cout << "���ֲ�������Աһ���� " << sum << " ����" << endl << endl;
		club.showPlayer();
		club.showCoach();
		club.showStaff();
		cout << endl << "���ֲ�������Աһ���� " << sum << " ����" << endl;
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_savePerson(void)			//��Ӧ������Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//������Ա��Ϣ
		club.savePlayer();
		break;

	case 2:		//���������Ϣ
		club.saveCoach();
		break;

	case 3:		//����ְ����Ϣ
		club.saveStaff();
		break;

	case 4:		//������ֲ�������Ա��Ϣ
		club.savePlayer();
		club.saveCoach();
		club.saveStaff();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_seekPerson(void)			//��Ӧ������Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//������Ա��Ϣ
		club.seekPlayer();
		break;

	case 2:		//���ҽ�����Ϣ
		club.seekCoach();
		break;

	case 3:		//����ְ����Ϣ
		club.seekStaff();
		break;

	case 4:		//�ھ��ֲ�������Ա�в�����Ϣ
		club.seekPerson();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_modifyPerson(void)		//��Ӧ�޸���Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//�޸���Ա��Ϣ
		club.modifyPlayer();
		break;

	case 2:		//�޸Ľ�����Ϣ
		club.modifyCoach();
		break;

	case 3:		//�޸�ְ����Ϣ
		club.modifyStaff();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_removePerson(void)		//��Ӧɾ����Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//ɾ����Ա��Ϣ
		club.removePlayer();
		break;

	case 2:		//ɾ��������Ϣ
		club.removeCoach();
		break;

	case 3:		//ɾ��ְ����Ϣ
		club.removeStaff();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}

void MenuManagement::respondMenu_emptyPerson(void)			//��Ӧ�����Ա��Ϣ�Ӳ˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//�����Ա��Ϣ
		club.emptyPlayer();
		break;

	case 2:		//��ս�����Ϣ
		club.emptyCoach();
		break;

	case 3:		//���ְ����Ϣ
		club.emptyStaff();
		break;

	case 4:		//��վ��ֲ�������Ա��Ϣ
		club.emptyPlayer();
		club.emptyCoach();
		club.emptyStaff();
		break;

	case 0:		//����
		return;

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}



//���ֲ���Ա����������
void BasketballClubfManagementLaunch::showMainMenu(void)			//��ʾ���˵�
{
	menu.showMenu_MainMenu();
}

void BasketballClubfManagementLaunch::respondMenu(void)			//��Ӧ�˵�
{
	cin.sync();   //������뻺����������  
	cin.clear();

	cin >> choice;		//����ѡ��

	switch (choice)
	{
	case 1:		//��������Ӿ��ֲ���Ա��Ϣ
		menu.showMenu_addPerson();
		menu.respondMenu_addPerson();
		break;

	case 2:		//��ʾ��ͳ�ƾ��ֲ���Ա��Ϣ
		menu.showMenu_showPerson();
		menu.respondMenu_showPerson();
		break;

	case 3:		//������ֲ���Ա��Ϣ
		menu.showMenu_savePerson();
		menu.respondMenu_savePerson();
		break;

	case 4:		//���Ҿ��ֲ���Ա��Ϣ
		menu.showMenu_seekPerson();
		menu.respondMenu_seekPerson();
		break;

	case 5:		//�޸ľ��ֲ���Ա��Ϣ
		menu.showMenu_modifyPerson();
		menu.respondMenu_modifyPerson();
		break;

	case 6:		//ɾ�����ֲ���Ա��Ϣ
		menu.showMenu_removePerson();
		menu.respondMenu_removePerson();
		break;

	case 7:		//��վ��ֲ���Ա��Ϣ
		menu.showMenu_emptyPerson();
		menu.respondMenu_emptyPerson();
		break;

	case 0:
		cout << "ллʹ�ã�" << endl;
		system("pause");			//��ͣ
		exit(0);

	default:
		cout << "�˵�ѡ�����" << endl;
	}
}