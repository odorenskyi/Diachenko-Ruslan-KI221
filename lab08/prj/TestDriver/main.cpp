#include <iostream>
#include "ModulesDiachenko.h"
#include <iomanip>

using namespace std;

int main()
{
    float input[5][3] =
    {
        {0.0,1.0,2.0},
        {1.0,1.0,0.0},
        {2.0,2.0,2.0},
        {3.0,1.0,0.0},
        {0.0,-2.0,5.0}
    };

    float output[5] =
    {
        4.132495391,
        5.859874482,
        8.836120703,
        12.143059789,
        1.305471951
    };

    cout<<"|"<<"IN"<<setw(12)<<"|"<<"OUT"<<setw(12)<<"|"<<"STATUS"<<"|"<<endl;
    for (int i = 0; i < 5; i++){
        if (s_calculation(input[i][0], input[i][1], input[i][2]) == output[i]){
            cout<<s_calculation(input[i][0], input[i][1], input[i][2])<<setw(15)<<output[i]<<setw(16)<<"Passed"<<endl;
        }
        else{
            cout<<s_calculation(input[i][0], input[i][1], input[i][2])<<setw(15)<<output[i]<<setw(16)<<"Failed"<<endl;
        }
    }
    return 0;
}
