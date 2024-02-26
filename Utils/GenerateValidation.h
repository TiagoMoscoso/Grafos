#include <stdlib.h>

class ValidationClass
{
    public:
    int * Validation;
    ValidationClass(int num)
    {
        Validation = (int *)malloc(num * sizeof(int *));
        resetValidation(num);
    }

    void resetValidation(int num)
    {
        for(int i = 0; i < num; i++)
        {
            Validation[i] = 0;
        }
    }
};