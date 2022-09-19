#include <iostream>
#include <bitset>

void t1()
{
    std::cout << "Vanin Artyom Victorovich, 221-352" << "\n";
}

void t2()
{
    std::cout << "min int:" << INT_MIN
        << "\tmax int:" << INT_MAX
        << "\tsize of int:" << sizeof(int) << "\n";

    std::cout << "min uint:" << "0"
        << "\tmax uint:" << UINT_MAX
        << "\tsize of uint:" << sizeof(unsigned int) << "\n";
    
    std::cout << "min short:" << SHRT_MIN
        << "\tmax short:" << SHRT_MAX
        << "\tsize of short:" << sizeof(short) << "\n";
    
    std::cout << "min ushort:" << "0"
        << "\tmax ushort:" << USHRT_MAX
        << "\tsize of ushort:" << sizeof(unsigned short) << "\n";


    std::cout << "min long:" << LONG_MAX
        << "\tmax long:" << LONG_MIN
        << "\tsize of long:" << sizeof(long) << "\n";


    std::cout << "min long long:" << LLONG_MAX
        << "\tmax long long:" << LLONG_MIN
        << "\tsize of long long:" << sizeof(long long) << "\n";


    std::cout << "min double:" << DBL_MIN
        << "\tmax double:" << DBL_MAX
        << "\tsize of double:" << sizeof(double) << "\n";
    
    std::cout << "min char:" << CHAR_MIN
        << "\tmax char:" << CHAR_MAX
        << "\tsize of char:" << sizeof(char) << "\n";

    std::cout << "min bool:" << 0
        << "\tmax bool:" << 1
        << "\tsize of bool:" << sizeof(bool) << "\n";
     
}

void t3()
{
 int num;
    std::cout << "Your num: ";
    std::cin >> num;

        std::cout << "Bin: 0b" << std::bitset<8 * sizeof(num)>(num) << '\n';
        std::cout << "Hex: 0x" << std::hex << num << '\n';
        std::cout << "Bool: " << bool(num) << "\n";
        std::cout << "Char: " << char(num) << "\n";
        std::cout << "Double: " << double(num) << "\n";
}

void t4()
{
    int a, b;
    std::cout << "Enter a && b: ";
    std::cin >> a >> b;                           // a = 75 b = 2

    std::cout << a << "*x=" << b << "\n";         // 2*x=75
    std::cout << "x=" << b << "/" << a << "\n";   // x=75/2
    std::cout << "x=" << b / a << "\n";             // x=37
    std::cout << "x=" << double(b) / a << "\n";     // x = 37,5
}

void t5()
{
    double x1, x2;
    std::cout << "Enter x1 and x2: ";
    std::cin >> x1 >> x2;
    std::cout << (x1 + x2) / 2 << "\n";
}
int main()
{
    t1();
    t2();
    t3();
    t4();
    t5();
    return 0;
}
