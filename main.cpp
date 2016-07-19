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
	// мутатори
	date2.setDay(15);
	date2.setMonth(3);
	date3.setYear(2015);
	// селектори 
	cout << date2.getDay() << endl; 
	cout << date2.getMonth() << endl; 
	cout << date3.getYear() << endl;
	// предефинирани операции
	cout << date4 << endl;
	//??????????   cout << date3.getDayOfTheWeek() << endl; // кой ден от седмицата е дадената дата
	cin >> date1;
	cout << date1 << endl; 
    cout << date1 + 5 << endl; // добавя дни
	cout << 5 + date1 << endl;
	date1 +=5;
	cout << date1 << endl;
	cout << date1++ << endl; // добавя един ден, но връща старата дата
	cout << ++date1 << endl;
	cout << date3 - 33 << endl; // вади дни
	date3 -= 33;
	cout << date3 << endl;
	cout << date3-- << endl; // вади един ден и връща старата дата
	cout << --date3 << endl;
	cout << date3 * 26 << endl; // добавя месеци
	cout << 2 * date3 << endl;
	date3 *= 22;
	cout << date3 << endl;
	cout << date3 / 13 << endl; // вади месеци
	date3 /= 2;
	cout << date3 << endl;
	cout << (date3 & 4) << endl; // добавя години
	cout << (4 & date3) << endl;
	date3 &= 4;
	cout << date3 << endl;
	cout << (date3 | 3) << endl; // вади години
	date3 |= 4;
	cout << date3 << endl;
	cout << (date3 ^ 1) << endl; // добавя седмици 
	cout << (1 ^ date3) << endl;
	date3 ^= 17;
	cout << date3 << endl;
	cout << date3 % 17 << endl; // вади седмици 
	date3 %= 5;
	cout << date3 << endl;*/
	date2.setYear(2017);
	cout << date3 << " " << date2 << endl;
	cout << date3 - date2 << endl; // намира разликата в дни
	cout << date3 / date2 << endl; // разлика между датите в месеци
	cout << (date3 | date2) << endl; // разлика между датите в години
	cout << date3 % date2 << endl; // разлика между датите в седмици 
	cout << date3.isWorkday() << endl; // определя дали деня е работен или не
	Date date5(23, 12, 2014);
	date5.setClosestWorkDay(true); // селектор, който променя всички аритметични операции 
								   // да връщат най-близкия работен ден след извършването на операцията
	cout << date5 + 5 << endl;
	date5.setWorkDay(true); // селектор, който промяна режима на работа на операциите +, +=, -, -=
							// само на работни дни
	cout << date5 + 15 << endl;
	system("pause");
	return 0;
}