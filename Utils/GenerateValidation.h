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

    void negativeValidation(int num)
    {
        for(int i = 0; i < num; i++)
        {
            Validation[i] = -1;
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

    bool verifyValidationDiferentZero(int num)
    {
        for(int i = 0; i < num; i++)
        {
            if(Validation[i] != 0) return false;
        }
        return true;
    }

    void printValidation(int num)
    {
        for(int i = 0; i < num; i++)
        {
            cout<< "[ "<<i<<" ]";
        }
        cout<< endl;
        for(int i = 0; i < num; i++)
        {
            if(Validation[i] >= 0 && Validation[i] < 10)
                cout<< "[ "<<Validation[i]<<" ]";
            else if(Validation[i] >= 10 || ( Validation[i] < 0 && Validation[i] > -10 ) )
                cout<< "[ "<<Validation[i]<<"]";
            else
                cout<< "["<<Validation[i]<<"]";
        }  
        cout<< endl;
        
    }
};
#endif