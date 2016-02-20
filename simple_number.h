#ifndef SIMPLE_NUMBER_H
#define SIMPLE_NUMBER_H


class simple_number
{
public:
    simple_number();
    // простое число, которое больше M
    static int getFirstPrimeNumber(int M);

private:
    // является ли число простым
    static bool isPrime(int n);
};

#endif // SIMPLE_NUMBER_H
