// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#define _USE_MATH_DEFINES
#include <cmath>

float s_calculation(float x, float y, float z)
{
    float S1 = sqrt( abs( pow(z, 2) * y/2 ) );
    float S2 = (M_PI * x + pow(M_E, abs(y)) ) / y;
    float S = S1 + S2;
    return S;
}
