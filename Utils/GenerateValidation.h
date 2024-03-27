#ifndef VALIDATION_CLASS_H
#define VALIDATION_CLASS_H
#include <stdlib.h>

class ValidationClass
{
    public:
    int * Validation;
    ValidationClass(int num)
    {
        Validation = (int *)malloc(num * sizeof(int *));
        //Validation = (int *)calloc(num , sizeof(int *));
        resetValidation(num);
    }

    void resetValidation(int num)
    {
        for(int i = 0; i < num; i++)
        {
            Validation[i] = 0;
        }
    }

    bool verifyValidation(int num)
    {
        for(int i = 0; i < num; i++)
        {
            if(Validation[i] == 0) return false;
        }
        return true;
    }
};
#endif