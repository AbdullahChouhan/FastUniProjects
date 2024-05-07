#include <iostream>

int main()
{
    int *speed = new int;
    double *travelTime = new double;
    double *distance;
    *speed = 65;
    *travelTime = 8.5;
    distance = new double;
    *distance = (*speed)*(*travelTime);
    std::cout << *distance << std::endl;
    delete speed, travelTime, distance;
    return 0;
}