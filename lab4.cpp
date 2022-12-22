/* ������ ������������ ������ �4 ������� 3 */
#include <iostream>
#include <cmath>

using namespace std;

class Circle { // ���������� ������ Circle
	double R; // ���������� ����, ��������� ������ ����������
	static int count; // �������
	const int ind; // ������ ��������
public:

	Circle() : ind(++count) { // �����������
		SetRadius(); // ���� ������� ����������
	}

	double GetRadius() { // ������ �������
		return R;
	}
	// ������ ������ ������
	int GetInd() {
		return ind;
	}
	// ������ ���������� �������
	static int GetTotal() {
		return count;
	}
	void SetRadius() { // ������ �������
		cout << "������� ������: ";
		cin >> R;
	}


	double Ploshad() {
		return 3.14 * pow(GetRadius(), 2);
	}

	double GetLength() {  // ����� ����������
		return 2 * 3.14 * GetRadius();
	}

	void show() { // ����� ���� ��������
		cout << "������: " << GetRadius() << "\n����� ����������: " << GetLength() << "\n�������: " << Ploshad() << endl;
	}

};

int Circle::count = 0;

class Cone : public Circle { // ���������� ��������� ������ Cone �� ������������� ������ Circle
	double h; // ���������� ���� ��� �������� ������

public:
	Cone() { // �����������, ��������������� ��������� id � ���������� ������ ��������
		cout << "������� ������: ";
		SetHeight(); // ���� ������ ������
	}
	// ������ ������
	void SetHeight() {
		cin >> h;
	}
	// ������ ������
	double GetHeight() {
		return h;
	}
	// �������
	double Ploshad() {
		return 3.14 * sqrt(pow(GetRadius(), 2) + pow(GetHeight(), 2)) * GetRadius() + Circle::Ploshad(); // ������� (Circle::Ploshad() - ����� ������ Ploshad() �� ������������� ������ Circle)
	}
	// ����� ������
	double OBbem() {
		return (Ploshad() * GetHeight()) / 3;
	}

	void show() { // ����� ���� ��������
		cout << "������ � ������: " << GetRadius() << ", " << GetHeight();
		cout << "\n������� � �����: " << Ploshad() << ", " << OBbem();
		cout << "\n����� ����������: " << GetLength() << endl;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	int N, M;
	cout << "���������� �����������: ";
	cin >> N;
	cout << "���������� �������: ";
	cin >> M;
	Circle* okr = new Circle[N]; // ������ �������� ������ Circle
	Cone* conus = new Cone[M]; // ������ �������� ������ Cone
	// ������� ���������� ����������� � �������� ������ ��������
	double sum = 0;
	// ����� �������� �����������
	for (int i = 0; i < N; i++)
	{
		sum = okr[i].Ploshad();
	}
	sum /= N; // ������� ��������
	int count = 0; // �������
	for (int i = 0; i < N; i++)
	{
		if (okr[i].Ploshad() < sum)
		{
			count++;
		}
	}
	// ���������� ������ � ���������� �������
	int m = 0;
	for (int i = 0; i < M; i++) {
		if (conus[m].OBbem() < conus[i].OBbem()) m = i;
	}
	//����� 
	cout << "���������� �����������, ������� ������� ������ �������: " << count << endl;
	cout << "���������� ����� � ������ ��� ������� " << conus[m].GetInd() - N << endl;

	system("pause");
}