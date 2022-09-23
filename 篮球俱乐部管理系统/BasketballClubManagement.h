#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>    //使用stringstream需要引入这个头文件  

#define MAX 100

using namespace std;

class Person			//抽象person类
{
public:
	friend class BasketballClubManagement;			//定义篮球俱乐部管理类为该类的友元类
	Person(string& name, string& gender, int& age, int& ID, string& contict);
	virtual void display(void) = 0;			//纯虚函数，显示信息
	virtual void save(void) = 0;			//纯虚函数，保存成文件
	virtual void modify(void) = 0;			//纯虚函数，修改信息

	static int sum;			//统计所有人员总数

protected:
	string name;			//姓名
	string gender;          //性别
	int age;				//年龄
	int ID;					//编号
	string contict;			//联系方式
};



class Player : public Person			//球员类
{
public:
	friend class BasketballClubManagement;			//定义篮球俱乐部管理类为该类的友元类
	Player(string& name, string& gender, int& age, int& ID, string& contict, string& speciality, string& clubName, float& uniformNumber);
	void display(void);			//函数重载，显示球员信息
	void save(void);			//函数重载，保存球员信息
	void modify(void);		//函数重载，修改球员信息

protected:
	string position;			//场上位置
	string clubName;			//所属俱乐部
	float uniformNumber;				//球衣号码
};



class Coach : public Person			//教练类
{
public:
	friend class BasketballClubManagement;			//定义篮球俱乐部管理类为该类的友元类
	Coach(string& name, string& gender, int& age, int& ID, string& contict, string& characteristic, string& nikcname);
	void display(void);			//函数重载，显示教练信息
	void save(void);			//函数重载，保存教练信息
	void modify(void);		//函数重载，修改教练信息

protected:
	string characteristic;			//教练的专业特点
	string nickName;				//教练绰号
};



class Staff : public Person			//职工类
{
public:
	friend class BasketballClubManagement;			//定义篮球俱乐部管理类为该类的友元类
	Staff(string& name, string& gender, int& age, int& ID, string& contict, string& department, string& job, int& salary);
	void display(void);			//函数重载，显示职工信息
	void save(void);			//函数重载，保存职工信息
	void modify(void);		//函数重载，修改职工信息

protected:
	string department;			//职工部门
	string job;					//职工工作
	int salary;					//职工工资
};



class BasketballClubManagement			//统一对球员进行管理
{
public:
	BasketballClubManagement(void);			//构造函数
	~BasketballClubManagement(void);			//析构函数

	void createPlayer(void);			//创建或添加球员信息
	void importPlayer(void);			//导入内部球员信息
	void showPlayer(void);				//显示并统计球员信息
	void savePlayer(void);				//保存球员信息
	void seekPlayer(void);				//查找球员信息
	void modifyPlayer(void);			//修改球员信息
	void removePlayer(void);			//删除球员信息
	void emptyPlayer(void);			//清空球员信息

	void createCoach(void);			//创建或添加教练信息
	void importCoach(void);			//创建或添加教练信息
	void showCoach(void);				//显示并统计教练信息
	void saveCoach(void);				//保存教练信息
	void seekCoach(void);				//查找教练信息
	void modifyCoach(void);			//修改教练信息
	void removeCoach(void);			//删除教练信息
	void emptyCoach(void);			//清空教练信息

	void createStaff(void);			//创建或添加职工信息
	void importStaff(void);			//创建或添加职工信息
	void showStaff(void);			//显示并统计职工信息
	void saveStaff(void);			//保存职工信息
	void seekStaff(void);			//查找职工信息
	void modifyStaff(void);			//修改职工信息
	void removeStaff(void);			//删除职工信息
	void emptyStaff(void);			//清空职工信息

	void seekPerson(void);				//在俱乐部所有人员中查找信息

private:
	//查找该数据的位置，4个参数分别是返回查找到的数据的地址，查找的数据类型（按名字查找还是编号），
	//要查找的数据，要查找的俱乐部人员类型（默认在大学所有人员中查找）
	void findPerson(int* plocation, const string& findType, const string& lookedData, const string& personType = "allPerson");

	Person* p[3][MAX];			//基类对象指针

	int playerNumber;			//球员人数
	int coachNumber;			//教练人数
	int staffNumber;			//职工人数
};



class MenuManagement			//菜单管理类
{
public:
	//显示菜单
	void showMenu_MainMenu(void);				//显示主菜单
	void showMenu_addPerson(void);		//显示添加人员信息子菜单
	void showMenu_showPerson(void);		//显示显示人员信息子菜单
	void showMenu_savePerson(void);		//显示保存人员信息子菜单
	void showMenu_seekPerson(void);		//显示查找人员信息子菜单
	void showMenu_modifyPerson(void);	//显示修改人员信息子菜单
	void showMenu_removePerson(void);	//显示删除人员信息子菜单
	void showMenu_emptyPerson(void);	//显示清空人员信息子菜单

	//响应菜单
	void respondMenu_addPerson(void);		//响应添加人员信息子菜单
	void respondMenu_showPerson(void);		//响应显示人员信息子菜单
	void respondMenu_savePerson(void);		//响应保存人员信息子菜单
	void respondMenu_seekPerson(void);		//响应查找人员信息子菜单
	void respondMenu_modifyPerson(void);	//响应修改人员信息子菜单
	void respondMenu_removePerson(void);	//响应删除人员信息子菜单
	void respondMenu_emptyPerson(void);	//响应清空人员信息子菜单

private:
	int choice;			//菜单选项
	BasketballClubManagement club;			//创建球员管理对象
};



class BasketballClubfManagementLaunch			//球员管理启动类
{
public:
	void showMainMenu(void);			//显示主菜单
	void respondMenu(void);				//响应菜单

private:
	int choice;			//菜单选项
	MenuManagement menu;			//创建显示菜单对象	
};