#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string dec_to_bin(unsigned int n)
{
	if (n == 0)
		return "0";

	string res;

	do
	{
		res.push_back(n % 2 ? '1' : '0');
		n /= 2;

	} while (n != 0);

	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	const int cnt = 5;
	int val;

	for (int i = 1; i <= cnt; ++i)
	{
		cout << "[" << i << "\\" << cnt << "]: ";
		cin >> val;
		cout << val << "(dec) -> " << dec_to_bin(val) << "(bin)\n" << std::endl;
	}
	system("pause");
}
