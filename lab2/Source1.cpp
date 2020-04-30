#include <iostream>
#include <ctime>
using namespace std;

int Split2(const int *in_arr, const int in_n, int *& b, int *& c)
{
	int even_n = 0, odd_n = 0;
	for (int i = 0; i < in_n; i++)
	{
		if (!(in_arr[i] % 2))
			++even_n;
		else
			++odd_n;
	}

	b = new int[even_n];
	c = new int[odd_n];

	even_n = 0; odd_n = 0;

	for (int i = 0; i < in_n; i++)
	{
		if (!(in_arr[i] % 2))
			b[even_n++] = in_arr[i];
		else
			c[odd_n++] = in_arr[i];
	}
	return even_n;
}

int main()
{
	int n;
	cout << "input the number of array elements: ";
	cin >> n;
	int *arr = new int[n];

	srand(time(0));
	cout << "source array: ";
	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 101) << " ";
	cout << endl;

	int *arr_even,
		*arr_odd,
		even_n,
		odd_n;

	even_n = Split2(arr, n, arr_even, arr_odd);
	odd_n = n - even_n;

	cout << "array of even elements from source: ";
	for (int i = 0; i < even_n; i++)
		cout << arr_even[i] << " ";
	cout << endl;

	cout << "array of odd elements from source: ";
	for (int i = 0; i < odd_n; i++)
		cout << arr_odd[i] << " ";
	cout << endl;

	delete[] arr;
	delete[] arr_even;
	delete[] arr_odd;

	system("pause");
	return 0;
}
