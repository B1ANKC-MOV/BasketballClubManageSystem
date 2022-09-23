#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ�  

#define MAX 100

using namespace std;

class Person			//����person��
{
public:
	friend class BasketballClubManagement;			//����������ֲ�������Ϊ�������Ԫ��
	Person(string& name, string& gender, int& age, int& ID, string& contict);
	virtual void display(void) = 0;			//���麯������ʾ��Ϣ
	virtual void save(void) = 0;			//���麯����������ļ�
	virtual void modify(void) = 0;			//���麯�����޸���Ϣ

	static int sum;			//ͳ��������Ա����

protected:
	string name;			//����
	string gender;          //�Ա�
	int age;				//����
	int ID;					//���
	string contict;			//��ϵ��ʽ
};



class Player : public Person			//��Ա��
{
public:
	friend class BasketballClubManagement;			//����������ֲ�������Ϊ�������Ԫ��
	Player(string& name, string& gender, int& age, int& ID, string& contict, string& speciality, string& clubName, float& uniformNumber);
	void display(void);			//�������أ���ʾ��Ա��Ϣ
	void save(void);			//�������أ�������Ա��Ϣ
	void modify(void);		//�������أ��޸���Ա��Ϣ

protected:
	string position;			//����λ��
	string clubName;			//�������ֲ�
	float uniformNumber;				//���º���
};



class Coach : public Person			//������
{
public:
	friend class BasketballClubManagement;			//����������ֲ�������Ϊ�������Ԫ��
	Coach(string& name, string& gender, int& age, int& ID, string& contict, string& characteristic, string& nikcname);
	void display(void);			//�������أ���ʾ������Ϣ
	void save(void);			//�������أ����������Ϣ
	void modify(void);		//�������أ��޸Ľ�����Ϣ

protected:
	string characteristic;			//������רҵ�ص�
	string nickName;				//�����º�
};



class Staff : public Person			//ְ����
{
public:
	friend class BasketballClubManagement;			//����������ֲ�������Ϊ�������Ԫ��
	Staff(string& name, string& gender, int& age, int& ID, string& contict, string& department, string& job, int& salary);
	void display(void);			//�������أ���ʾְ����Ϣ
	void save(void);			//�������أ�����ְ����Ϣ
	void modify(void);		//�������أ��޸�ְ����Ϣ

protected:
	string department;			//ְ������
	string job;					//ְ������
	int salary;					//ְ������
};



class BasketballClubManagement			//ͳһ����Ա���й���
{
public:
	BasketballClubManagement(void);			//���캯��
	~BasketballClubManagement(void);			//��������

	void createPlayer(void);			//�����������Ա��Ϣ
	void importPlayer(void);			//�����ڲ���Ա��Ϣ
	void showPlayer(void);				//��ʾ��ͳ����Ա��Ϣ
	void savePlayer(void);				//������Ա��Ϣ
	void seekPlayer(void);				//������Ա��Ϣ
	void modifyPlayer(void);			//�޸���Ա��Ϣ
	void removePlayer(void);			//ɾ����Ա��Ϣ
	void emptyPlayer(void);			//�����Ա��Ϣ

	void createCoach(void);			//��������ӽ�����Ϣ
	void importCoach(void);			//��������ӽ�����Ϣ
	void showCoach(void);				//��ʾ��ͳ�ƽ�����Ϣ
	void saveCoach(void);				//���������Ϣ
	void seekCoach(void);				//���ҽ�����Ϣ
	void modifyCoach(void);			//�޸Ľ�����Ϣ
	void removeCoach(void);			//ɾ��������Ϣ
	void emptyCoach(void);			//��ս�����Ϣ

	void createStaff(void);			//���������ְ����Ϣ
	void importStaff(void);			//���������ְ����Ϣ
	void showStaff(void);			//��ʾ��ͳ��ְ����Ϣ
	void saveStaff(void);			//����ְ����Ϣ
	void seekStaff(void);			//����ְ����Ϣ
	void modifyStaff(void);			//�޸�ְ����Ϣ
	void removeStaff(void);			//ɾ��ְ����Ϣ
	void emptyStaff(void);			//���ְ����Ϣ

	void seekPerson(void);				//�ھ��ֲ�������Ա�в�����Ϣ

private:
	//���Ҹ����ݵ�λ�ã�4�������ֱ��Ƿ��ز��ҵ������ݵĵ�ַ�����ҵ��������ͣ������ֲ��һ��Ǳ�ţ���
	//Ҫ���ҵ����ݣ�Ҫ���ҵľ��ֲ���Ա���ͣ�Ĭ���ڴ�ѧ������Ա�в��ң�
	void findPerson(int* plocation, const string& findType, const string& lookedData, const string& personType = "allPerson");

	Person* p[3][MAX];			//�������ָ��

	int playerNumber;			//��Ա����
	int coachNumber;			//��������
	int staffNumber;			//ְ������
};



class MenuManagement			//�˵�������
{
public:
	//��ʾ�˵�
	void showMenu_MainMenu(void);				//��ʾ���˵�
	void showMenu_addPerson(void);		//��ʾ�����Ա��Ϣ�Ӳ˵�
	void showMenu_showPerson(void);		//��ʾ��ʾ��Ա��Ϣ�Ӳ˵�
	void showMenu_savePerson(void);		//��ʾ������Ա��Ϣ�Ӳ˵�
	void showMenu_seekPerson(void);		//��ʾ������Ա��Ϣ�Ӳ˵�
	void showMenu_modifyPerson(void);	//��ʾ�޸���Ա��Ϣ�Ӳ˵�
	void showMenu_removePerson(void);	//��ʾɾ����Ա��Ϣ�Ӳ˵�
	void showMenu_emptyPerson(void);	//��ʾ�����Ա��Ϣ�Ӳ˵�

	//��Ӧ�˵�
	void respondMenu_addPerson(void);		//��Ӧ�����Ա��Ϣ�Ӳ˵�
	void respondMenu_showPerson(void);		//��Ӧ��ʾ��Ա��Ϣ�Ӳ˵�
	void respondMenu_savePerson(void);		//��Ӧ������Ա��Ϣ�Ӳ˵�
	void respondMenu_seekPerson(void);		//��Ӧ������Ա��Ϣ�Ӳ˵�
	void respondMenu_modifyPerson(void);	//��Ӧ�޸���Ա��Ϣ�Ӳ˵�
	void respondMenu_removePerson(void);	//��Ӧɾ����Ա��Ϣ�Ӳ˵�
	void respondMenu_emptyPerson(void);	//��Ӧ�����Ա��Ϣ�Ӳ˵�

private:
	int choice;			//�˵�ѡ��
	BasketballClubManagement club;			//������Ա�������
};



class BasketballClubfManagementLaunch			//��Ա����������
{
public:
	void showMainMenu(void);			//��ʾ���˵�
	void respondMenu(void);				//��Ӧ�˵�

private:
	int choice;			//�˵�ѡ��
	MenuManagement menu;			//������ʾ�˵�����	
};