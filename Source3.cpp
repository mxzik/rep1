#include <iostream>
#include <fstream>
typedef  union Telephone
{
	char name[16];
	char capital[16];
	char popularity[16];
	int area;
	char surname[16];
} ST;
int num;
using namespace std;

void output()
{
	ifstream otf("Tel.DAT");
	cout << "\nНаименование      Столица      Численность населения      Площадь       Фамилия президента \n";
	while (!otf.eof())
	{
		ST buf = { ' ', ' ',' ',' ',' ' };
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.name << "\t        ";
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.capital << "\t      ";
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.popularity << "\t\t  ";
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.area << "\t  ";
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.surname << "\t\t   " << endl;
	}
	cout << endl;
}

void find(char fam[16])
{

	ifstream otf("Tel.DAT");
	int i = 0;
	ST buf = { ' ', ' ',' ',' ',' ' };
	while (!otf.eof())
	{

		otf.read((char *)&buf, sizeof(buf));
		if (strcmp(fam, buf.name) == 0)       //сравнение     
		{
			cout << "\nНаименование      Столица      Численность населения      Площадь       Фамилия президента \n";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.name << "\t        ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.capital << "\t     ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.popularity << "\t\t     ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.area << "\t      ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.surname << "\t\t   " << endl;
			i = 1; break;
		}
	}
	if (i == 0)
		cout << "Ничего не найдено\n";
}

void find1(int ar)
{

	ifstream otf("Tel.DAT");
	int i = 0;
	ST buf = { ' ', ' ',' ',' ',' ' };
	while (!otf.eof())
	{
		otf.read((char *)&buf, sizeof(buf));
		if (ar >= buf.area )           
		{
			cout << "\nНаименование      Столица      Численность населения      Площадь       Фамилия президента \n";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.name << "\t        ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.capital << "\t    ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.popularity << "\t\t   ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.area << "\t   ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.surname << "\t\t  " << endl;
			i = 1; break;
		}
	}
	if (i == 0)
		cout << "Ничего не найдено\n";
}

void input()
{
	ofstream itf;
	itf.open("Tel.DAT", ios_base::app);
	ST buf = { ' ', ' ',' ',' ',' ' };
	for (int p = 0; p < num; p++)
	{
		cout << "Страна: ";
		cin >> buf.name;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Столица: ";
		cin >> buf.capital;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Население: ";
		cin >> buf.popularity;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Площадь: ";
		cin >> buf.area;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Фамилия президента: ";
		cin >> buf.surname;
		itf.write((char *)&buf, sizeof(buf));
	}
}

int main()
{
	int choice;
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по наззванию государсства\n";
		cout << "4 Поиск по площади\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество  ";
			cin >> num;
			input();
			break;
		case 2: output(); break;
		case 3:  char nam[16];
		    cout << "Введите название государства  " << endl;
			cin >> nam;
			find(nam); break;
		case 4: int are;
			cout << "Введите требуемую площадь  " << endl;
			cin >> are;
			find1(are); break;
		case 0: exit(0);  break;
		default: cout << "Неверный выбор. Попробуйте снова" << endl; break;
		}
	} while (choice != 0);
}