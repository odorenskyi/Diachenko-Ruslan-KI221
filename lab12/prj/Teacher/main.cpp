#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../ModulesDiachenko.h"

int main() {
    std::string projectPath = "Lab12/prj/main.cpp";

    if (projectPath != "Lab12/prj/main.cpp") {
        std::ofstream outputFile("TestResults.txt");
        outputFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << std::endl;
        outputFile.close();

        for (int i = 0; i < 100; i++) {
           std::cout<<'\a'<<std::endl;
        }
    }
    else {
        ClassLab12_Diachenko testObject;
        double testSuite[2][5] = {{5.5, 1.5, 1, 22.22, 5.555}, {696.91, 14.1372, 4, 45953.7, 718.027}};

        std::ofstream outputFile("TestResults.txt"); // Відкриття файлу для запису

        if (outputFile.is_open()) {
            for(int i = 0; i < 5; i++){
            testObject.changeRadius(testSuite[0][i]);
            testObject.calcVolume();
            if ((int)testObject.getVolume() == (int)testSuite[1][i]) outputFile<< "ID-" << i+1 << ": PASSED"<<std::endl;
            else outputFile<< "ID-" << i+1 << ": FAILED"<<std::endl;
        }
        } else {
            std::cout << "Не вдалося відкрити файл для запису." << std::endl;
    }
    }
    std::cout<< "Програму завершено. Файл знаходиться в prj/Teacher!";
    return 0;
}
