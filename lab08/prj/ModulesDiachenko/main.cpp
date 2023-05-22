#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <bitset>
// LB №8
float s_calculation(float x, float y, float z){
    if (y == 0) return -999;
    float S1 = sqrt( abs( pow(z, 2) * y/2 ) );
    float S2 = (M_PI * x + pow(M_E, abs(y)) ) / y;
    float S = S1 + S2;
    return S;
}

// LB №9
float getEnergyCost(float energyEPM){
    float energyCost{0};
    if (energyEPM <= 150){
        energyCost = energyEPM * 130.843;
    }
    else if(energyEPM > 150 && energyEPM <=800){
        energyCost = energyEPM *241.945;
    }
    else if(energyEPM > 800){
        energyCost = energyEPM *534.047;
    }
    else{
        energyCost = -1;
    }
    return energyCost;
}

float* getMidYearTemperature(float midMonthsTemperature[12]){
    float* temperatureData = new float[2];
    float midYear = 0;
    for(short i{0}; i < 12; i++){
        midYear += midMonthsTemperature[i];
    }
    float midYearC = midYear / 12;
    float midYearF = (32 + (9.0/5.0*midYear))/12.0;
    temperatureData[0] = midYearC;
    temperatureData[1] = midYearF;
    return temperatureData;
}

unsigned int* binaryLenghtByBin(unsigned int N){
    unsigned int* result = new unsigned int[2];
    unsigned int error = 9999999;
    if (N > 0 && N < 5740500){

        unsigned int countElements = 0;
        unsigned int bit10 = (N >>9) & 1;
        result[1] = bit10;
        if (bit10 == 1){
            for (int i = 0; i < sizeof(N) * 8; i++) {
            if ((N & 1) == 1) countElements++;
            N = N >> 1;
            }
            result[0] = countElements;
            return result;
        }else{
            for (int i = 0; i < sizeof(N) * 8; i++) {
            if ((N & 1) == 0) countElements++;
            N = N >> 1;
            }
            result[0] = countElements;
            return result;
        }

    }else{
        result[0] = 9999999;
        result[1] = 9999999;
        return result;
    }
}

// LB №10
using namespace std;

string removeVowels(const string& sentence) {
    string vowels = "aeiouаеєиіїоуюя";
    string result = sentence;

    result.erase(remove_if(result.begin(), result.end(), [&vowels](char c) {
        return vowels.find(tolower(c)) != string::npos;
    }), result.end());

    return result;
}

int parseUaMsg(char* inputText) {
    string filename = inputText;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Помилка відкриття файлу." << endl;
        return 1;
    }
    string line;
    int colonsCount = 0;

    while (getline(file, line)) {
        colonsCount += count(line.begin(), line.end(), ':');

        string lineWithoutVowels = removeVowels(line);
        cout <<"Текст без голосних: " << lineWithoutVowels << endl;
    }

    cout << "Кількість знаків \":\" у тексті: " << colonsCount << endl;

    file.close();

    return 0;
}

map<wchar_t, string> translitMap = {
    {L'а', "a"}, {L'б', "b"}, {L'в', "v"}, {L'г', "h"}, {L'ґ', "g"}, {L'д', "d"}, {L'е', "e"}, {L'є', "ie"},
    {L'ж', "zh"}, {L'з', "z"}, {L'и', "y"}, {L'і', "i"}, {L'ї', "i"}, {L'й', "i"}, {L'к', "k"}, {L'л', "l"},
    {L'м', "m"}, {L'н', "n"}, {L'о', "o"}, {L'п', "p"}, {L'р', "r"}, {L'с', "s"}, {L'т', "t"}, {L'у', "u"},
    {L'ф', "f"}, {L'х', "kh"}, {L'ц', "ts"}, {L'ч', "ch"}, {L'ш', "sh"}, {L'щ', "shch"}, {L'ь', ""}, {L'ю', "iu"},
    {L'я', "ia"}, {L'А', "A"}, {L'Б', "B"}, {L'В', "V"}, {L'Г', "H"}, {L'Ґ', "G"}, {L'Д', "D"}, {L'Е', "E"},
    {L'Є', "IE"}, {L'Ж', "ZH"}, {L'З', "Z"}, {L'И', "Y"}, {L'І', "I"}, {L'Ї', "I"}, {L'Й', "I"}, {L'К', "K"},
    {L'Л', "L"}, {L'М', "M"}, {L'Н', "N"}, {L'О', "O"}, {L'П', "P"}, {L'Р', "R"}, {L'С', "S"}, {L'Т', "T"},
    {L'У', "U"}, {L'Ф', "F"}, {L'Х', "KH"}, {L'Ц', "TS"}, {L'Ч', "CH"}, {L'Ш', "SH"}, {L'Щ', "SHCH"}, {L'Ь', ""},
    {L'Ю', "IU"}, {L'Я', "IA"}
};

string transliterate(const wstring& input) {
    string output;

    for (wchar_t ch : input) {
        auto it = translitMap.find(ch);

        if (it != translitMap.end()) {
            output += it->second;
        } else {
            output += ch;
        }
    }

    return output;
}

int translitterateText(char* inputText) {
    string filename = inputText;
    wifstream file(filename);

    if (!file.is_open()) {
        cout << "Помилка відкриття файлу." << endl;
        return 1;
    }

    wstring line;
    wstring transliteratedText;

    while (getline(file, line)) {
        transliteratedText += line;
    }

    file.close();

    string output = transliterate(transliteratedText);

    cout << output << endl;

    return 0;
}


std::bitset<32> bToBinB(int b) {
    int number = b;
    std::bitset<sizeof(int) * 8> binary(number);
    return binary;
}

int addTextToInputText(char* inputText,float x,float y,float z,int b) {
    string filename = inputText;
    float sCalcResult = s_calculation(x,y,z);
    bitset<32> binB = bToBinB(b);
    ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cout << "Помилка відкриття файлу." << std::endl;
        return 1;
    }

    file << sCalcResult <<"   |   "<<binB << std::endl;
    file.close();

    std::cout << "Дані було успішно додано до файлу." << std::endl;

    return 0;
}



