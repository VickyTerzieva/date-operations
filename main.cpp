#include <iostream>
#include "dates.h"

using namespace std;

int main()
{
	Date date1;
	Date date2(2,5);
	Date date3(15,4,2017);
	/*cout << date3 << endl;
	cout << date3 - 33 << endl;
	cout << date3 + 60 << endl;
	Date date4("The last", "Sunday", "June", 2014); 
	// ��������
	date2.setDay(15);
	date2.setMonth(3);
	date3.setYear(2015);
	// ��������� 
	cout << date2.getDay() << endl; 
	cout << date2.getMonth() << endl; 
	cout << date3.getYear() << endl;
	// ������������� ��������
	cout << date4 << endl;
	//??????????   cout << date3.getDayOfTheWeek() << endl; // ��� ��� �� ��������� � �������� ����
	cin >> date1;
	cout << date1 << endl; 
    cout << date1 + 5 << endl; // ������ ���
	cout << 5 + date1 << endl;
	date1 +=5;
	cout << date1 << endl;
	cout << date1++ << endl; // ������ ���� ���, �� ����� ������� ����
	cout << ++date1 << endl;
	cout << date3 - 33 << endl; // ���� ���
	date3 -= 33;
	cout << date3 << endl;
	cout << date3-- << endl; // ���� ���� ��� � ����� ������� ����
	cout << --date3 << endl;
	cout << date3 * 26 << endl; // ������ ������
	cout << 2 * date3 << endl;
	date3 *= 22;
	cout << date3 << endl;
	cout << date3 / 13 << endl; // ���� ������
	date3 /= 2;
	cout << date3 << endl;
	cout << (date3 & 4) << endl; // ������ ������
	cout << (4 & date3) << endl;
	date3 &= 4;
	cout << date3 << endl;
	cout << (date3 | 3) << endl; // ���� ������
	date3 |= 4;
	cout << date3 << endl;
	cout << (date3 ^ 1) << endl; // ������ ������� 
	cout << (1 ^ date3) << endl;
	date3 ^= 17;
	cout << date3 << endl;
	cout << date3 % 17 << endl; // ���� ������� 
	date3 %= 5;
	cout << date3 << endl;*/
	date2.setYear(2017);
	cout << date3 << " " << date2 << endl;
	cout << date3 - date2 << endl; // ������ ��������� � ���
	cout << date3 / date2 << endl; // ������� ����� ������ � ������
	cout << (date3 | date2) << endl; // ������� ����� ������ � ������
	cout << date3 % date2 << endl; // ������� ����� ������ � ������� 
	cout << date3.isWorkday() << endl; // �������� ���� ���� � ������� ��� ��
	Date date5(23, 12, 2014);
	date5.setClosestWorkDay(true); // ��������, ����� ������� ������ ����������� �������� 
								   // �� ������ ���-������� ������� ��� ���� ������������ �� ����������
	cout << date5 + 5 << endl;
	date5.setWorkDay(true); // ��������, ����� ������� ������ �� ������ �� ���������� +, +=, -, -=
							// ���� �� ������� ���
	cout << date5 + 15 << endl;
	system("pause");
	return 0;
}