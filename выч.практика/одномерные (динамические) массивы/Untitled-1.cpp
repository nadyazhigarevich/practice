#include <iostream>
#include <fstream>
#include <locale>
#include <ctime>
using namespace std;
const string file_path = "C:\\Users\\Asus\\Desktop\\выч.практика\\одномерные (динамические) массивы\\output.txt";

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));

    char binary_sequence[33] = {0};
    for (int i = 0; i < 32; i++)
    {
        binary_sequence[i] = '0' + (rand() % 2);
    }

    int decimal_number = 0;
    for (int i = 0; i < 32; i++)
    {
        decimal_number = decimal_number * 2 + (binary_sequence[i] - '0');
    }

    ofstream output_file(file_path);
    output_file << decimal_number;
    output_file.close();

    cout << "Случайная последовательность: " << binary_sequence << endl;
    cout << "Соответствующее десятичное число: " << decimal_number << endl;
    return 0;
}