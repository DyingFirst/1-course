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
	int b, n;
	cout << "Enter the number n whose binomial coefficients you want to calculate\n";
	cin >> b;
	cout << "Your binomial coefficients" << std::endl;
	unsigned long long Cnk = 1;

	for (int k = 1; k <= b + 1; ++k)
	{
		cout << Cnk << " ";
		Cnk = Cnk * (b + 1 - k) / k;
	}
}

	void t3()
{
	int sum = 0, ctn = 0;
	std::string line = "";
	cout << "Enter numbers(for end entering print '-'):";
	cin >> line;
	while (line != "-")
	{
		sum += std::atoi(line.c_str());
		ctn++;
		cin >> line;
	}
	cout << sum / double(ctn) << "\n";
}

int main()
{
	char switcher;
	cout << "Enter number of program (1-3): ";
	cin >> switcher;
		switch (switcher)
			{
			case '1':
				t1();
			case '2':
				t2();
			case '3':
				t3();
			default:
				cout << "Error. Reboot program" << '\n';
			}

		return 0;
}