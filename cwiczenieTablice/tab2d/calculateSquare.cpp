#include <cmath>
float calculateSquare(int z1, int z2, int z3, int z4)
{
    float diagonal = sqrt(pow(abs(z1 - z3), 2) + pow(sqrt(2) * 10, 2));
    float a = sqrt(pow(abs(z1 - z2), 2) + 100);
    float b = sqrt(pow(abs(z2 - z3), 2) + 100);
    float c = sqrt(pow(abs(z3 - z4), 2) + 100);
    float d = sqrt(pow(abs(z4 - z1), 2) + 100);
    
    float s1 = (a + b + diagonal) / 2;
    float s2 = (c + d + diagonal) / 2;

    float p1 = sqrt(s1 * (s1 - a) * (s1 - b) * (s1 - diagonal));
    float p2 = sqrt(s2 * (s2 - c) * (s2 - d) * (s2 - diagonal));

    return p1 + p2;
}