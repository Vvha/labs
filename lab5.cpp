/* ������ ������������ ������ �5 ������� 3 */
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Employee {
protected:
	Employee* next; // ������ �� ����. ������ � ������
	static Employee* top; // ������� �������
	string name; // ��� ����������
public:

	Employee();
	void Add();
	// ����������� ������
	static void see_list();
	virtual void show() = 0;
	virtual ~Employee() = default;
};

Employee* Employee::top = nullptr;

Employee::Employee() { // �������� ������������
	cout << "��� ����������: ";
	cin >> name;
	Add();
}

void Employee::Add() { // �������� ������ ����������
	next = top;
	top = this;
}

void Employee::see_list() { // �������� ������ ��������� �������� ������
	Employee* p = top;
	for (;;) { // ����������� ����
		if (!p) break;
		p->show();
		p = p->next;
	}
}

class Admin : public Employee
{
protected:
	string pos; // ���������
public:
	Admin() {
		pos = "�������������";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Admin() = default;
};

class Engineer : public Employee
{
protected:
	string pos; // ���������
public:
	Engineer() {
		pos = "�������";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Engineer() = default;
};

class Worker : public Employee
{
protected:
	string pos; // ���������
public:
	Worker() {
		pos = "�������";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Worker() = default;
};

int main() {
	SetConsoleCP(1251);        //���������
	SetConsoleOutputCP(1251);   //�������
	for (;;) {
		system("cls"); // ������� �������
		cout << "��� �������?\n1. �������� ������\n2. �������� ��������\n3. �������� ��������\n4. ����������� ������\n0. �����\n";
		int choice; // ���������� ������
		cin >> choice;
		system("cls");
		if (choice == 0) { // ������� ������ �� ���������
			cout << "�� �������? (1/2)\n";
			cin >> choice;
			if (choice == 1) break;
			else continue;
		}
		switch (choice) // ����� ��������
		{
		case 1:
		{auto* p = new Admin;} // �������� ������ ������� Admin
		cout << "����� ��� �������� � ������!";
		system("timeout 2"); // ����� � �������
		break;
		case 2:
		{auto* p = new Worker;} // �������� ������ ������� Worker
		cout << "������� ��� �������� � ������!";
		system("timeout 2");
		break;
		case 3:
		{auto* p = new Engineer;} // �������� ������ ������� Engineer
		cout << "������� ��� �������� � ������!";
		system("timeout 2");
		break;
		case 4:
			Employee::see_list();
			system("pause");
			break;
		default:
			break;
		}
	}

	return 0;
}