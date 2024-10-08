#include <iostream>
#include <string>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "rus");
	int number = 0;
	int startSystem = 0;
	cout << "Введите число: ";
	cin >> number;
	string numberString = to_string(number);
	cout << "Введите систему счисления числа: ";
	cin >> startSystem;
	int result = 0, index = 15;
	switch(startSystem) {
		case 2:
			for (int i = numberString.length()-1, degree = 0; i >= 0; i--, degree++) {
				if (numberString[i] == '1'){
					result += pow(2, degree);
				}
			}
			cout << "Результат перевода в двоичную: " << result;
			return;
		case 10:
			string* str;
			str = new string[16];
			do
			{
				str[index] += char('0'+(int)number % 2); // добавляем в конец
				number = number / 2;
				index--;
			} while (number > 0);
			cout << "Результат перевода в десятичную: ";
			for (int i = 0; i < 16; i++) {
				cout << str[i];
			}
			return;
		default:
			cout << "Введена некорректная система счисления!";
			return;
	}
}