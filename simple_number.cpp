#include "simple_number.h"

simple_number::simple_number()
{

}

int simple_number::getFirstPrimeNumber(int M)
{
    int temp = M;

    while (1) {
        if (isPrime(++temp))
            break;
    }

    return temp;
}

bool simple_number::isPrime(int n){
    if(n==1) // 1 - не простое число
        return false;

    // перебираем возможные делители от 2 до sqrt(n)
    for(int d=2; d*d<=n; d++){
        // если разделилось нацело, то составное
        if(n%d==0)
            return false;
    }

    // если нет нетривиальных делителей, то простое
    return true;
}
