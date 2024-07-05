#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct Worker {
    string surname;
    string initials;
    string position;
    int salary;
};

bool isPositionEqual(const Worker& worker, const string& position) {
    return worker.position == position;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Worker workers[] = {
        {"Иванов", "И.И.", "слесарь", 35000},
        {"Петров", "П.П.", "инженер", 50000},
        {"Сидоров", "С.С.", "слесарь", 37000},
        {"Кузнецов", "К.К.", "слесарь", 39000},
        {"Смирнова", "С.А.", "бухгалтер", 45000}
    };
    const int numWorkers = sizeof(workers) / sizeof(Worker);

    ofstream file("workers.bin", ios::binary);
    file.write(reinterpret_cast<const char*>(workers), sizeof(workers));
    file.close();

    ifstream inputFile("workers.bin", ios::binary);
    int totalSalary = 0;
    int slisersCount = 0;
    Worker worker;
    while (inputFile.read(reinterpret_cast<char*>(&worker), sizeof(Worker))) {
        if (isPositionEqual(worker, "слесарь")) {
            totalSalary += worker.salary;
            slisersCount++;
        }
    }
    inputFile.close();

    if (slisersCount > 0) {
        double averageSalary = static_cast<double>(totalSalary) / slisersCount;
        cout << "Средняя зарплата слесарей: " << averageSalary << endl;
        cout << "Количество слесарей: " << slisersCount << endl;
    } else {
        cout << "Нет слесарей в списке." << endl;
    }

    return 0;
}