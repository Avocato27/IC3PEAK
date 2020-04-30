#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
/** Reader chronicle **/
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
// displaying information about this reader
void output_read(reader read) {
	cout << "Reader №" << read.num << endl << endl;
	cout << "Surname: " << read.last_name << endl;
	cout << "Name: " << read.name << endl;
	cout << "Patronymic: " << read.patronymic << endl;
	cout << "Library card № " << read.number << endl;
	cout << "Name of the book: " << ((read.position == 1) ? "Sherlock Holmes.Hound of baskerville" : ((read.position == 2) ? "Game of Thrones" : ((read.position == 3) ? "The Chronicles of Narnia" : "Harry Potter and the prisoner of Azkaban"))) << endl;
	cout << "Return date: " << read.y_of_d << endl << endl;
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
	int num; cout << "Enter: "; cin >> num;
	system("cls");
	for (int i = 0; i < read_num; i++)
		if (num == read[i].num)
			output_read(read[i]);
	system("pause");
}

int main() {
	int a;
	setlocale(LC_ALL, "russian");
	reader* read = new reader[1]; // pointer to an array of structures
	int read_num; // number of readers
	double isRead = false; // indicates whether the reader exists
	while (1) {
		system("cls");
		/** menu **/
		int input_menu;
		cout << " 1. Entering an array of readers\n";
		cout << " 2. Reader array outputn";
		cout << " 3. Reader array sorting\n";
		cout << " 4. Search in an array of readers for a given parameter\n";
		cout << " 5. Modify a given reader\n";
		cout << " 6. Removing a reader from an array\n";
		cout << " 7. Output\n";
		cout << "Enter: "; cin >> input_menu;
		/***********/
		system("cls");

		if (input_menu == 1) {
			isRead = true;
			// creating an array with a given number of readers
			cout << "Enter the number of readers : "; cin >> read_num;
			delete[] read;
			read = new reader[read_num];
			// filling out the structure of each reader
			for (int i = 0; i < read_num; i++) {
				system("cls");
				read[i].num = i + 1;
				cout << "Reader №" << read[i].num << endl << endl;
				cout << "Enter surname: "; cin >> read[i].last_name; cout << endl;
				cout << "Enter name: "; cin >> read[i].name; cout << endl;
				cout << "Enter patronomic: "; cin >> read[i].patronymic; cout << endl;
				cout << "Library card № "; cin >> read[i].number; cout << endl;
				cout << "Choose a book(1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
				int pos;
				cin >> pos; cout << endl;
				if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
				else if (pos == 2)read[i].position = reader::GameofThrones;
				else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
				else if (pos == 4)read[i].position = reader::HarryPotter;
				else { system("pause");  return 0; };
				int y_of_d;
				cout << "Return date: "; cin >> y_of_d; cout << endl;
				read[i].y_of_d = y_of_d;
			}
		}
		else if (input_menu == 2) {
			// if there are no readers, then only the 1st item can be completed
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; }
			// output of an array of structures
			for (int i = 0; i < read_num; i++) {
				output_read(read[i]);
			}
			system("pause");
		}
		// if you need to sort an array of structures
		else if (input_menu == 3)
		{
			// if there are no readers
			if (!isRead || (read_num < 2)) { cout << "Error!"; Sleep(1000); continue; }
			int type_read;
			cout << " 1. By last name \n 2. By library card number \n 3. By selected book \nВвод: ";
			cin >> type_read;
			reader read_copy;
			for (int i = 0; i < (read_num - 1); i++)
			{
				// sorting by last name
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
				// sorting by library card number
				else if (type_read == 2)
				{
					void sort();
					system("cls");
					for (int i = 0; i < read_num; i++) {
						output_read(read[i]);
					}
					system("pause");
				}
				// sort by selected book
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
		// if you need to search the array for a given parameter
		else if (input_menu == 4)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // if there aren't reader
			int type_search; // search parameter
			cout << " 1. Be last name\n 2. By name\n 3. By patronomic\n 4. By library card number \n 5. By name of book\n 6. By return date \nВвод: ";
			cin >> type_search;
			system("cls");
			// search by last name
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
		// if you need to change the specified structure
		else if (input_menu == 5)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // if there aren't reader
			unsigned short num; // numder of reader
			cout << "Номер читателя: "; cin >> num;
			unsigned short i = num - 1; // numder of reader - 1 (to work with an array)
			// if the reader number is entered incorrectly
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			system("cls");
			cout << "Reader №" << read[i].num << endl << endl;
			// lastname, name, patronomic
			cout << "Enter lastname: "; cin >> read[i].last_name; cout << endl;
			cout << "Enter name: "; cin >> read[i].name; cout << endl;
			cout << "Enter patronomic: "; cin >> read[i].patronymic; cout << endl;
			// namber of library card
			int number;
			cout << "Enter number of library card: "; cin >> number; cout << endl;
			read[i].number = number;
			// book
			int pos;
			cout << "Choose a book (1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
			cin >> pos; cout << endl;
			if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
			else if (pos == 2)read[i].position = reader::GameofThrones;
			else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
			else if (pos == 4)read[i].position = reader::HarryPotter;
			else { system("pause");  return 0; };
			// return date
			int y_of_d;
			cout << "Enter return date: "; cin >> y_of_d; cout << endl;
			read[i].y_of_d = y_of_d;
			system("cls");
			cout << "Want to print an array(1-Yes, 0-No): "; cin >> a;
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
		// if you need to remove the structure from the array
		else if (input_menu == 6)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // if thre aren't reader
			unsigned short num; // number of reader
			cout << "Number of reader: "; cin >> num;
			// if the reader number is entered incorrectly
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			// if there is only one element in the array
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
			// shift 
			for (unsigned short i = num - 1; i < read_num; i++)
			{
				int read_i_num = read[i].num;
				read[i].num = read[i + 1].num;
				read[i + 1].num = read_i_num;
				read[i] = read[i + 1];
			}
			// create a copy in which we place the desired array
			reader * read_copy = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read_copy[i] = read[i];
			}
			// modify an existing array of readers
			delete[] read;
			read = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read[i] = read_copy[i];
			}
			cout << "Want to print an array(1-Yes, 0-No): "; cin >> a;
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
		// output
		else if (input_menu == 7)
			break;
		// if no menu item is selected
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