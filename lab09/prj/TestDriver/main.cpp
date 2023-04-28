#include <iostream>
#include "ModulesDiachenko.h"
using namespace std;

int main()
{
    // Test Driver for 9.1
    float energyInput[5] = {140,450,800,1000,2500};
    float energyOut[5] = {18318.02,108875.25,193556, 534047, 1335117.5};
    for (int i = 0; i < 5; i++){
    if (getEnergyCost(energyInput[i]) == energyOut[i]){cout<< getEnergyCost(energyInput[i]) <<"\t" << energyOut[i]<<"\tPassed"<<endl;
    }else{ cout<< getEnergyCost(energyInput[i]) <<"\t" << energyOut[i]<<"\tFailed"<<endl;}
    }
    cout<<"======================================================================"<< endl;
    // Test Driver for 9.2
    float tempIN[3][12] = {{1,2,3,4,5,6,7,8,9,10,11,12}, {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12
}, {-10, 20, 30, 40, -27, -7, 30, 22, 11, 0, 0, 2}};
    float tempOUT[3][2] = {{6.5, 14.3667}, {-6.5, -9.0333}, {22}};
    for (int i =0; i < 3; i++){
    float value1 = *getMidYearTemperature(tempIN[i]);
    float value2 = *(getMidYearTemperature(tempIN[i]) + 1);
    if (value1 == tempOUT[i][0] && value2 == tempOUT[i][1]){
        cout << value1 << ", " << value2 << "\tPassed" << endl;
    }else{
        cout << value1 << ", " << value2 << "\tFailed" << endl;
    }
    cout<<"Log: " <<value1 <<", "<<value2 << " | "<< tempOUT[i][0]<<", "<<tempOUT[i][1]<<endl;
    }
    // Test Driver for 9.3
    cout<<"======================================================================"<< endl;
    unsigned int numInput[5]= {0, 1, 1023, 2048, 1111111};
    unsigned int numOutput[5][2]= {{9999999, 9999999}, {31, 0}, {10, 1}, {31, 0}, {22, 0}};
    for (int i = 0; i < 5; i++){
    unsigned int value1 = *binaryLenghtByBin(numInput[i]);
    unsigned int value2 = *(binaryLenghtByBin(numInput[i]) + 1);
    if (value1 == numOutput[i][0] && value2 == numOutput[i][1]){
        cout<< value1 <<", "<< value2<<"\tPassed"<<endl;
    }else{
        cout<< value1 <<", "<< value2<<"\tFailed"<<endl;
        }
    }
    return 0;
}
