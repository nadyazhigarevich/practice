#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

void mergeFiles(const char* file1, const char* file2, const char* outputFile) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    ifstream in1(file1);
    ifstream in2(file2);
    ofstream out(outputFile, ios::out | ios::trunc);

    if (!in1 || !in2 || !out) {
        cout << "Ошибка при открытии файлов!" << endl;
        return;
    }

    char buffer1[1024], buffer2[1024];
    bool useBuffer1 = true;

    while (true) {
        if (useBuffer1 && in1.getline(buffer1, sizeof(buffer1), '.')) {
            out << buffer1 << ". ";
        } else if (in2.getline(buffer2, sizeof(buffer2), '.')) {
            out << buffer2 << ". ";
        } else {
            break;
        }
        useBuffer1 = !useBuffer1;
    }
}

int main() {
    mergeFiles("file1.txt", "file2.txt", "output.txt");
    cout << "Файл output.txt создан/перезаписан." << endl;
    return 0;
}