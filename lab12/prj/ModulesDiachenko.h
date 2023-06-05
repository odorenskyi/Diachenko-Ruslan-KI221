#ifndef MODULESDIACHENKO_H_INCLUDED
#define MODULESDIACHENKO_H_INCLUDED

#include <cmath>

class ClassLab12_Diachenko{
public:
    ClassLab12_Diachenko(){}
    ClassLab12_Diachenko(double radius);
    void changeRadius(double radius);
    void changeVolume(double volume);
    double getRadius();
    double getVolume();
    double calcVolume();
private:
    double radius = 0.0;
    double volume = 0.0;
};

ClassLab12_Diachenko::ClassLab12_Diachenko(double radius){
    this->radius = radius;
}

void ClassLab12_Diachenko::changeRadius(double radius){
    this->radius = radius;
}
void ClassLab12_Diachenko::changeVolume(double volume){
    this->volume = volume;
}

double ClassLab12_Diachenko::getRadius(){
    return radius;
}
double ClassLab12_Diachenko::getVolume(){
    return volume;
}

double ClassLab12_Diachenko::calcVolume(){
    this->volume = (4 * M_PI * pow(this->radius, 3)) / 3;
}

#endif // MODULESDIACHENKO_H_INCLUDED
