#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
/** Структрура, хронящая данные о читателе **/
struct reader {
	char last_name[100], name[100], patronymic[100];
	int number;
	enum {
		TheHoundoftheBaskervilles = 1,
		GameofThrones,
		TheChroniclesofNarnia,
		HarryPotter
	}position;
	unsigned y_of_d;
	int num;
};
/**********************************************/
// выведение сведений о данном читателе
void output_read(reader read) {
	cout << "Читатель №" << read.num << endl << endl;
	cout << "Фамилия: " << read.last_name << endl;
	cout << "Имя: " << read.name << endl;
	cout << "Отчество: " << read.patronymic << endl;
	cout << "Читательский билет № " << read.number << endl;
	cout << "Название книги: " << ((read.position == 1) ? "Шерлок Холмс. Собака Баскервиль" : ((read.position == 2) ? "Игра Престолов" : ((read.position == 3) ? "Хроники Нарнии" : "Гарри Поттер и Узник Азкабана"))) << endl;
	cout << "Срок возврата: " << read.y_of_d << endl << endl;
}

void sort(reader* read, int read_num)
{
	for (int i = 0; i < (read_num - 1); i++)
	{
		if (read[i].num > read[i + 1].num)
		{
			int read_i_num = read[i].num;
			read[i].num = read[i + 1].num;
			read[i + 1].num = read_i_num;
			reader temp = read[i];
			read[i] = read[i + 1];
			read[i + 1] = temp;
		}
	}
}

void find(reader* read, int read_num)
{
	int num; cout << "Ввод: "; cin >> num;
	system("cls");
	for (int i = 0; i < read_num; i++)
		if (num == read[i].num)
			output_read(read[i]);
	system("pause");
}

int main() {
	int a;
	setlocale(LC_ALL, "russian");
	reader* read = new reader[1]; // указатель для массива структур 
	int read_num; // количество читателей
	double isRead = false; // показывает, существует ли читатель
	while (1) {
		system("cls");
		/** меню **/
		int input_menu;
		cout << " 1. Ввод массива читателей\n";
		cout << " 2. Вывод массива читателей\n";
		cout << " 3. Сортировка массива читателей\n";
		cout << " 4. Поиск в массиве читателей по заданному параметру\n";
		cout << " 5. Изменение заданного читателя\n";
		cout << " 6. Удаление читателя из массива\n";
		cout << " 7. Выход\n";
		cout << "Ввод: "; cin >> input_menu;
		/***********/
		system("cls");

		if (input_menu == 1) {
			isRead = true;
			// создание массива с заданным количеством читателей
			cout << "Введите колическво читателей: "; cin >> read_num;
			delete[] read;
			read = new reader[read_num];
			// заполнение структуры каждого читателя
			for (int i = 0; i < read_num; i++) {
				system("cls");
				read[i].num = i + 1;
				cout << "Читатель №" << read[i].num << endl << endl;
				cout << "Введите фамилию: "; cin >> read[i].last_name; cout << endl;
				cout << "Введите имя: "; cin >> read[i].name; cout << endl;
				cout << "Введите отчество: "; cin >> read[i].patronymic; cout << endl;
				cout << "Читательский билет № "; cin >> read[i].number; cout << endl;
				cout << "Выберите книгу (1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
				int pos;
				cin >> pos; cout << endl;
				if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
				else if (pos == 2)read[i].position = reader::GameofThrones;
				else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
				else if (pos == 4)read[i].position = reader::HarryPotter;
				else { system("pause");  return 0; };
				int y_of_d;
				cout << "Срок возврата: "; cin >> y_of_d; cout << endl;
				read[i].y_of_d = y_of_d;
			}
		}
		else if (input_menu == 2) {
			// если читателей нет, то можно выполнить только 1-й пункт
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; }
			// вывод массива структур
			for (int i = 0; i < read_num; i++) {
				output_read(read[i]);
			}
			system("pause");
		}
		// если нужно сортировать массив структур
		else if (input_menu == 3)
		{
			// если читателей нет
			if (!isRead || (read_num < 2)) { cout << "Error!"; Sleep(1000); continue; }
			int type_read;
			cout << " 1. По фамилии \n 2. По номеру читательского билета \n 3. По выбранной книге\nВвод: ";
			cin >> type_read;
			reader read_copy;
			for (int i = 0; i < (read_num - 1); i++)
			{
				// сортировка по фамилии
				if (type_read == 1)
				{
					if (read[i].last_name[0] > read[i + 1].last_name[0])
					{
						int read_i_num = read[i].num;
						read[i].num = read[i + 1].num;
						read[i + 1].num = read_i_num;
						read_copy = read[i];
						read[i] = read[i + 1];
						read[i + 1] = read_copy;
					}
					system("cls");
					for (int i = 0; i < read_num; i++) {
						output_read(read[i]);
					}
					system("pause");
				}
				// сортировка по номеру читательского билета
				else if (type_read == 2)
				{
					void sort();
					system("cls");
					for (int i = 0; i < read_num; i++) {
						output_read(read[i]);
					}
					system("pause");
				}
				// сортировка по выбранной книге
				else if (type_read == 3)
				{
					void sort();
					system("cls");
					for (int i = 0; i < read_num; i++) {
						output_read(read[i]);
					}
					system("pause");
				}
				else { cout << "Error sorting!"; continue; }
			}
			system("cls");
		}
		// если нужно производить поиск в массиве по заданному параметру
		else if (input_menu == 4)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // если читателей нет
			int type_search; // параметр поиска
			cout << " 1. По фамилии\n 2. По имени\n 3. По отчеству\n 4. По номеру читательского билета\n 5. По названию\n 6. По сроку возврата\nВвод: ";
			cin >> type_search;
			system("cls");
			// поиск по фамилии
			if (type_search == 1)
			{
				char last_name[100] = ""; cout << "Ввод: "; cin >> last_name;
				system("cls");
				for (int i = 0; i < read_num; i++)
					if (!strcmp(last_name, read[i].last_name))
						output_read(read[i]);
				system("pause");
			}

			else if (1 < type_search < 7)
			{
				void find();
			}

			else { cout << "Error searching!"; continue; }
			system("cls");
			Sleep(1000);
		}
		// если нужно изменить заданную структуру
		else if (input_menu == 5)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // если читателей нет
			unsigned short num; // номер читателя
			cout << "Номер читателя: "; cin >> num;
			unsigned short i = num - 1; // номер читателя - 1 (для работы с массивом)
			// если неправильно введен номер читателя
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			system("cls");
			cout << "Читатель №" << read[i].num << endl << endl;
			// фамилия, имя, отчество
			cout << "Введите фамилию: "; cin >> read[i].last_name; cout << endl;
			cout << "Введите имя: "; cin >> read[i].name; cout << endl;
			cout << "Введите отчество: "; cin >> read[i].patronymic; cout << endl;
			// номер читательского билета
			int number;
			cout << "Введите номер читательского билета: "; cin >> number; cout << endl;
			read[i].number = number;
			// книга
			int pos;
			cout << "Выберите книгу (1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
			cin >> pos; cout << endl;
			if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
			else if (pos == 2)read[i].position = reader::GameofThrones;
			else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
			else if (pos == 4)read[i].position = reader::HarryPotter;
			else { system("pause");  return 0; };
			// срок возврата
			int y_of_d;
			cout << "Введите срок возврата: "; cin >> y_of_d; cout << endl;
			read[i].y_of_d = y_of_d;
			system("cls");
			cout << "Хотите вывести массив(1-Да, 0-Нет): "; cin >> a;
			system("cls");
			if (a == 1) {
				for (int i = 0; i < read_num; i++) {
					output_read(read[i]);
				}
				system("pause");
			}
			else if (a == 0)
				system("pause");
		}
		// если нужно удалить структурту из массива
		else if (input_menu == 6)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // если читателей нет
			unsigned short num; // номер читателя
			cout << "Номер читателя: "; cin >> num;
			// если неправильно введен номер читателя
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			// если в массиве всего один элемент
			if (read_num == 1)
			{
				delete[] read;
				read = new reader[1];
				isRead = false;
				system("cls");
				Sleep(1000);
				continue;
			}
			read_num = read_num - 1;
			// сдвиг 
			for (unsigned short i = num - 1; i < read_num; i++)
			{
				int read_i_num = read[i].num;
				read[i].num = read[i + 1].num;
				read[i + 1].num = read_i_num;
				read[i] = read[i + 1];
			}
			// создем копию, в которую размещаем нужный массив
			reader * read_copy = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read_copy[i] = read[i];
			}
			// изменяем существующий массив читателей
			delete[] read;
			read = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read[i] = read_copy[i];
			}
			cout << "Хотите вывести массив(1-Да, 0-Нет): "; cin >> a;
			system("cls");
			if (a == 1) {
				for (int i = 0; i < read_num; i++) {
					output_read(read[i]);
				}
				system("pause");
			}
			else if (a == 0)
				system("pause");
		}
		// выход
		else if (input_menu == 7)
			break;
		// если не выбран ни один пункт меню
		else
		{
			cout << " Error! ";
			Sleep(500);
			system("cls");
		}
	}
	system("pause");
	return 0;
}
