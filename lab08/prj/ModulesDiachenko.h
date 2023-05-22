#ifndef MODULESDIACHENKO_H
#define MODULESDIACHENKO_H

float s_calculation(float x, float y, float z);
float getEnergyCost(float energyEPM);
float* getMidYearTemperature(float midMonthsTemperature[12]);
unsigned int* binaryLenghtByBin(unsigned int N);
int parseUaMsg(char* inputText);
int translitterateText(char* inputText);
int addTextToInputText(char* inputText,float x,float y,float z,int b);
#endif
