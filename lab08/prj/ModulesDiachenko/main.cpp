#define _USE_MATH_DEFINES
#include <cmath>

float s_calculation(float x, float y, float z){
    if (y == 0) return -999;
    float S1 = sqrt( abs( pow(z, 2) * y/2 ) );
    float S2 = (M_PI * x + pow(M_E, abs(y)) ) / y;
    float S = S1 + S2;
    return S;
}

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
