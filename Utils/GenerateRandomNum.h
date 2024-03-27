#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>

using namespace std;

class GenerateRandomNum
{
    public:
    int GenerateRandomInt(int Max)
    {
        uniform_int_distribution<> dis(0, Max);
        random_device rd;
        mt19937 gen(rd());
        return dis(gen);
    }
};