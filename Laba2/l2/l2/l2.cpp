#include <iostream>
#include <string>

using std::cout;
using std::cin;

void t1() 
{
	int a;
	int b = 0;
	std::string line = "";

	cout << "Enter your number:" << '\n';
	cin >> a;

		while (a >= b)
		{
			line += std::to_string(b);
			b++;
			cout << line << '\n';
		}
	
}

void t2()
{

}

void t3()
{
	int sum = 0, ctn = 0;
	std::string line = "";
	cin >> line;
	while (line != "-")
	{
		sum += std::atoi(line.c_str());
		ctn++;
		cin >> line;
	}
	cout << sum / double(ctn);
}

int main()
{
	char ebal;
	cout << "Enter number of program (1-3): ";
	cin >> ebal;
		switch (ebal)
			{
			case '1':
				t1();
			case '2':
				t2();
			case '3':
				t3();
			default:
				cout << "Ebal tvou mat suka" << '\n';
			}

	return 0;
}