#include <validator.h>

bool validator(QVector<int>& intVector)
{
    auto sum = 0;
    bool isValid = false;

    for(auto it : intVector){
        sum += (intVector[it]);
    }

    sum %=  10;
    auto vSize = sizeof(intVector)/sizeof(int);

    if(sum == 0 && vSize == 16){
        isValid = true;
    }
    else if(sum == 1 && vSize == 16){
        isValid = true;
    }

    return isValid;
}
