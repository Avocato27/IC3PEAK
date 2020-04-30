#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
/** ����������, �������� ������ � �������� **/
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
// ��������� �������� � ������ ��������
void output_read(reader read) {
	cout << "�������� �" << read.num << endl << endl;
	cout << "�������: " << read.last_name << endl;
	cout << "���: " << read.name << endl;
	cout << "��������: " << read.patronymic << endl;
	cout << "������������ ����� � " << read.number << endl;
	cout << "�������� �����: " << ((read.position == 1) ? "������ �����. ������ ����������" : ((read.position == 2) ? "���� ���������" : ((read.position == 3) ? "������� ������" : "����� ������ � ����� ��������"))) << endl;
	cout << "���� ��������: " << read.y_of_d << endl << endl;
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
	int num; cout << "����: "; cin >> num;
	system("cls");
	for (int i = 0; i < read_num; i++)
		if (num == read[i].num)
			output_read(read[i]);
	system("pause");
}

int main() {
	int a;
	setlocale(LC_ALL, "russian");
	reader* read = new reader[1]; // ��������� ��� ������� �������� 
	int read_num; // ���������� ���������
	double isRead = false; // ����������, ���������� �� ��������
	while (1) {
		system("cls");
		/** ���� **/
		int input_menu;
		cout << " 1. ���� ������� ���������\n";
		cout << " 2. ����� ������� ���������\n";
		cout << " 3. ���������� ������� ���������\n";
		cout << " 4. ����� � ������� ��������� �� ��������� ���������\n";
		cout << " 5. ��������� ��������� ��������\n";
		cout << " 6. �������� �������� �� �������\n";
		cout << " 7. �����\n";
		cout << "����: "; cin >> input_menu;
		/***********/
		system("cls");

		if (input_menu == 1) {
			isRead = true;
			// �������� ������� � �������� ����������� ���������
			cout << "������� ���������� ���������: "; cin >> read_num;
			delete[] read;
			read = new reader[read_num];
			// ���������� ��������� ������� ��������
			for (int i = 0; i < read_num; i++) {
				system("cls");
				read[i].num = i + 1;
				cout << "�������� �" << read[i].num << endl << endl;
				cout << "������� �������: "; cin >> read[i].last_name; cout << endl;
				cout << "������� ���: "; cin >> read[i].name; cout << endl;
				cout << "������� ��������: "; cin >> read[i].patronymic; cout << endl;
				cout << "������������ ����� � "; cin >> read[i].number; cout << endl;
				cout << "�������� ����� (1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
				int pos;
				cin >> pos; cout << endl;
				if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
				else if (pos == 2)read[i].position = reader::GameofThrones;
				else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
				else if (pos == 4)read[i].position = reader::HarryPotter;
				else { system("pause");  return 0; };
				int y_of_d;
				cout << "���� ��������: "; cin >> y_of_d; cout << endl;
				read[i].y_of_d = y_of_d;
			}
		}
		else if (input_menu == 2) {
			// ���� ��������� ���, �� ����� ��������� ������ 1-� �����
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; }
			// ����� ������� ��������
			for (int i = 0; i < read_num; i++) {
				output_read(read[i]);
			}
			system("pause");
		}
		// ���� ����� ����������� ������ ��������
		else if (input_menu == 3)
		{
			// ���� ��������� ���
			if (!isRead || (read_num < 2)) { cout << "Error!"; Sleep(1000); continue; }
			int type_read;
			cout << " 1. �� ������� \n 2. �� ������ ������������� ������ \n 3. �� ��������� �����\n����: ";
			cin >> type_read;
			reader read_copy;
			for (int i = 0; i < (read_num - 1); i++)
			{
				// ���������� �� �������
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
				// ���������� �� ������ ������������� ������
				else if (type_read == 2)
				{
					void sort();
					system("cls");
					for (int i = 0; i < read_num; i++) {
						output_read(read[i]);
					}
					system("pause");
				}
				// ���������� �� ��������� �����
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
		// ���� ����� ����������� ����� � ������� �� ��������� ���������
		else if (input_menu == 4)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // ���� ��������� ���
			int type_search; // �������� ������
			cout << " 1. �� �������\n 2. �� �����\n 3. �� ��������\n 4. �� ������ ������������� ������\n 5. �� ��������\n 6. �� ����� ��������\n����: ";
			cin >> type_search;
			system("cls");
			// ����� �� �������
			if (type_search == 1)
			{
				char last_name[100] = ""; cout << "����: "; cin >> last_name;
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
		// ���� ����� �������� �������� ���������
		else if (input_menu == 5)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // ���� ��������� ���
			unsigned short num; // ����� ��������
			cout << "����� ��������: "; cin >> num;
			unsigned short i = num - 1; // ����� �������� - 1 (��� ������ � ��������)
			// ���� ����������� ������ ����� ��������
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			system("cls");
			cout << "�������� �" << read[i].num << endl << endl;
			// �������, ���, ��������
			cout << "������� �������: "; cin >> read[i].last_name; cout << endl;
			cout << "������� ���: "; cin >> read[i].name; cout << endl;
			cout << "������� ��������: "; cin >> read[i].patronymic; cout << endl;
			// ����� ������������� ������
			int number;
			cout << "������� ����� ������������� ������: "; cin >> number; cout << endl;
			read[i].number = number;
			// �����
			int pos;
			cout << "�������� ����� (1 - The Hound of the Baskervilles, 2 - Game of Thrones, 3 - The Chronicles of Narnia, 4 - Harry Potter): ";
			cin >> pos; cout << endl;
			if (pos == 1)read[i].position = reader::TheHoundoftheBaskervilles;
			else if (pos == 2)read[i].position = reader::GameofThrones;
			else if (pos == 3)read[i].position = reader::TheChroniclesofNarnia;
			else if (pos == 4)read[i].position = reader::HarryPotter;
			else { system("pause");  return 0; };
			// ���� ��������
			int y_of_d;
			cout << "������� ���� ��������: "; cin >> y_of_d; cout << endl;
			read[i].y_of_d = y_of_d;
			system("cls");
			cout << "������ ������� ������(1-��, 0-���): "; cin >> a;
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
		// ���� ����� ������� ���������� �� �������
		else if (input_menu == 6)
		{
			if (!isRead) { cout << "Error!"; Sleep(1000); continue; } // ���� ��������� ���
			unsigned short num; // ����� ��������
			cout << "����� ��������: "; cin >> num;
			// ���� ����������� ������ ����� ��������
			if (num > read_num || num == 0) { cout << "Error!"; continue; }
			// ���� � ������� ����� ���� �������
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
			// ����� 
			for (unsigned short i = num - 1; i < read_num; i++)
			{
				int read_i_num = read[i].num;
				read[i].num = read[i + 1].num;
				read[i + 1].num = read_i_num;
				read[i] = read[i + 1];
			}
			// ������ �����, � ������� ��������� ������ ������
			reader * read_copy = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read_copy[i] = read[i];
			}
			// �������� ������������ ������ ���������
			delete[] read;
			read = new reader[read_num];
			for (int i = 0; i < read_num; i++)
			{
				read[i] = read_copy[i];
			}
			cout << "������ ������� ������(1-��, 0-���): "; cin >> a;
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
		// �����
		else if (input_menu == 7)
			break;
		// ���� �� ������ �� ���� ����� ����
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
