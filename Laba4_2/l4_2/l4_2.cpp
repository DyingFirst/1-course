
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

void t1(char* line, int size) // получение расширение файла
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (line[i] == '.') 
        {
            flag = 1;
        }
        if (flag == 1) // если точка найдена, то вывести
        {
            cout << line[i];
        }
    }
}

void t2(char* line, int size) // поиск имени файла
{
    int flag = 0;
    int c = 0;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (line[i] == '\\') // счёт "\"
        {
            c++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if(line[i] == '.')
        {
            break;
        }
        if(k == c) // Сравнивание для вывода 
        {
            cout << line[i];
        }
        if(line[i] == '\\')
        {
            k++;
        }

    }
}

void t3(char* line, int size) // получение расположение файла 
{
    int c = 0;
    int k = 0;
 for(int i = 0; i < size ;i++)
 {
    if(line[i] == '\\')
    {
        c++;
    }
 }
 for(int i = 0; i < size; i++)
 {
    if(line[i] == '\\')
    {
        k++;
    }
    if(k != c)
    {
        cout << line[i];
    }
 }
 cout << '\\';
}

void t4(char* line, int size) // получение имени диска
{
for(int i =0; i < size; i++)
{
    if (line[i] == '\\')
    {
        cout << line[i - 2];
        cout << line[i - 1];
        break;
    }
}
}

void t5(char* line, int size) // переименование файла 
{
    int c = 0;
    int k = 0;
    string filename;
    cout << "Enter new file name:";
    cin >> filename;
    for (int i = 0; i < size; i++)
    {
        if (line[i] == '\\')
        {
            c++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (line[i] == '\\')
        {
            k++;
        }
        if (k != c)
        {
            cout << line[i];
        }
    }
    cout << '\\' + filename;
}

int main()
{
    int tnum;

    string path = "";
    cout << "Enter path of file: ";
    cin >> path;
    char *line = new char[path.length() + 1]; // перевод строки в массив char
    for (int i = 0; i < path.length(); i++)
    {
        line[i] = path[i];
    }
    cout << "Task num: ";
    cin >> tnum;
    switch (tnum)
    {
    case 1:
        t1(line, path.length());
        break;
    case 2:
        t2(line, path.length());
        break;
    case 3:
        t3(line, path.length());
        break;
    case 4:
        t4(line, path.length());
        break;
    case 5:
        t5(line, path.length());
        break;
    case 0:
        break;
    }
}