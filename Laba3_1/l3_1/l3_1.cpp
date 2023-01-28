#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void bubble(int* arr, int k )
{
    int s;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < (k - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << ' ';
    }
}

void sort_count(char* arr2, int* sort, int p)
{
    int j, i;
    for (i = 0; i < p; i++)
    {
        j = int(arr2[i] - 'a');
        sort[j]++;
    }

    cout << endl;
    for (i = 0; i < p; i++)
    {
        cout << sort[i];
    }

    cout << endl;
    j = 0;
    i = 0;
    while (j < 26)
    {
        if (sort[j] > 0)
        {
            arr2[i] = char(int('a') + j);
            i++;
            sort[j]--;
        }
        else
        {
            j++;
        }
    }
    i = 0;
    for (i = 0; i < p; i++)
    {
        cout << arr2[i];
    }

}

void merge(int data[], const int start, const int stop, const int middle) {
    int first_array = start;    // старт, который можем изменять
    int second_array = middle;  // середина, которую можем изменять
    int tmp_arr[1000];    // массив, в которм хранится результат мёрджа
    int now_ctn = 0;            // счётчик

    while ((first_array < middle) || (second_array < stop)) {
        if (data[first_array] < data[second_array] && (first_array < middle) && (second_array < stop)) {
            tmp_arr[now_ctn] = data[first_array];
            first_array++;
        }
        else if ((first_array < middle) && (second_array < stop)) {
            tmp_arr[now_ctn] = data[second_array];
            second_array++;
            // хвостовые случаи
        }
        else if (first_array < middle) {
            tmp_arr[now_ctn] = data[first_array];
            first_array++;
        }
        else if (second_array < stop) {
            tmp_arr[now_ctn] = data[second_array];
            second_array++;
        }
        now_ctn++;
    }

    //заполнение исходного массива
    for (int i = start; i < stop; i++) {
        data[i] = tmp_arr[i - start];
    }
}
void merge_sort(int data[], int start, int stop) {
    if (stop - start <= 1) {
        return;  // у нас массив состоит из 1 элемента
    }
    else {
        int middle = start + (stop - start) / 2;

        merge_sort(data, start, middle);    // left array
        merge_sort(data, middle, stop);     // right array
        merge(data, start, stop, middle);   // merge 2 array
    }
}
int main()
{
    char switcher;
    int k, p, i = 0;
    int arr[1000];
    char arr2[1000];
    int sort[26] = { 0 };
    cout << "Enter number of program (1-3): ";
    cin >> switcher;
    switch (switcher)
    {
    case '1':
        cout << "Enter size of array: ";
        cin >> k;
        cout << endl;
        for (int i = 0; i < k; i++)
        {
            cout << "Enter element of array: " << endl;
            cin >> arr[i];
        }
        bubble(arr, k);
        cout << endl;
        break;
    case '2':
        cout << "Enter size of array: ";
        cin >> p;
        cout << endl;
        for (i = 0; i < p; i++)
        {
            cout << "Enter symbol: ";
            cin >> arr2[i];
        }
        sort_count(arr2, sort, p);
        cout << endl;
        break;
    case '3':
        int arr3[1000];                                     // Размер массива
        int len;
        cout << "Enter size of array (less 1000 characters) : ";
        cin >> len;
        cout << "Enter array : ";

        for (int i = 0; i < len; i++) {
            cin >> arr3[i];
        }
        merge_sort(arr3, 0, len);

        cout << "Sorted array : ";
        for (auto i = 0; i < len; i++) {
            cout << arr3[i] << " ";
        }
        cout << "\n";
        break;
    default:
        cout << "Error. Reboot program" << '\n';
    }

    return 0;
}