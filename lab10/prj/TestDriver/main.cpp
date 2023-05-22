#include <string>
#include <locale>
#include <iostream>
#include "ModulesDiachenko.h"

using namespace std;
int main()
{
    cout << "Розробник: Дяченко Руслан Павлович" << endl;
    cout << "Установка: ЦНТУ" << endl;
    cout << "Місто: Кропивницький" << endl;
    cout << "Країна: Україна" << endl;
    cout << "Рік розробки: 2023" << endl;

    locale::global(std::locale("uk_UA.utf8"));
    // Test Driver for 10.1
    char* text[5] = {"text1/tex1.txt","text1/tex2.txt","text1/tex3.txt","text1/tex4.txt","text1/tex5.txt"};
    for(int i = 0; i <5; i++) parseUaMsg(text[i]);
    cout<<"****************************"<<endl;
    // Test Driver for 10.2
    char* uaText[5] = {"uaText/tex1.txt","uaText/tex2.txt","uaText/tex3.txt","uaText/tex4.txt","uaText/tex5.txt"};
    for(int j = 0; j <5; j++) translitterateText(uaText[j]);
    cout<<"****************************"<<endl;
    // Test Driver for 10.3
    char* addText = "addText.txt";
    int numbers[5][4] = {{1,2,3,10}, {10,10,10,2},{0,0,0,0},{-9,9,9,9}, {1,2,3,4}};
    for(int k=0;k<5;k++){
        addTextToInputText(addText,numbers[k][0],numbers[k][1],numbers[k][2],numbers[k][3]);
    }
    cout<<"****************************"<<endl;
    return 0;
}
