#include <iostream>
#include <iomanip>
#include "ModulesDiachenko.h"
using namespace std;



char getChar();
bool getLogicResult(char, char);
int getDecimalNum(float, float, float);
float getNum();
void showDevInfo();
void getHexNum(float, float, float);
void getCmd();


int main()
{
    showDevInfo();
    cout<<"Введіть число x: "<<endl;
    float x = getNum();
    cout<<"Введіть число y: "<<endl;
    float y = getNum();
    cout<<"Введіть число z: "<<endl;
    float z = getNum();
    cout<<"Введіть символ a: "<<endl;
    char a = getChar();
    cout<<"Введіть символ b: "<<endl;
    char b = getChar();

    cout<<"Результат логічного виразу: "<<boolalpha<<getLogicResult(a, b)<<endl;
    getCmd();

    getDecimalNum(x, y, z);
    getHexNum(x, y, z);
    getCmd();

    cout<<s_calculation(x,y,z)<<endl;
    getCmd();

    return 0;
}


void getCmd()
{
    int cmd = 0;
    cin>>cmd;
}
float getNum()
{
    int num;
    cin>>num;
    return num;
}

char getChar()
{
    char ch;
    cin>>ch;
    return ch;
}
void showDevInfo()
{
    cout<<"Розробник: Дяченко Руслан\n"<<(char)0xA9<<"Всі права захищені"<<endl;
}
bool getLogicResult(char a, char b){
    return a+5>=b;
}
int getDecimalNum(float x, float y, float z)
{
    cout<<"Числа в Десятковій системі числення:"<<endl;
    cout<<"x: "<<setbase(10)<<x<<endl;
    cout<<"y: "<<setbase(10)<<y<<endl;
    cout<<"z: "<<setbase(10)<<z<<endl;
}
void getHexNum(float x, float y, float z)
{
    cout<<"Числа в Шістнадцятковій системі числення:"<<endl;
    cout<<"x: "<<hex<<(int)x<<endl;
    cout<<"y: "<<hex<<(int)y<<endl;
    cout<<"z: "<<hex<<(int)z<<endl;
}

