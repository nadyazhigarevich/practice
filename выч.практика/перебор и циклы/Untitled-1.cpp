#include <iostream>
#include <fstream>
#include <ctime>
#include <locale>

using namespace std;

const int n = 10;
const string filePath = "C:\\Users\\Asus\\Desktop\\выч.практика\\перебор и циклы\\data.txt";

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(static_cast<int>(time(NULL)));

    ofstream outFile(filePath);

    for (int i = 0; i < n; i++)
    {
        double weight = static_cast<double>(rand() % 100 + 1);
        outFile << weight << "\n";
    }
    outFile.close();

    ifstream inFile(filePath);

    double sumWeights = 0;
    for (int i = 0; i < n; i++)
    {
        double weight;
        inFile >> weight;
        sumWeights += weight;
    }
    inFile.close();

    double average = sumWeights / n;

    cout << "Среднее взвешенное: " << average << endl;

    return 0;
}