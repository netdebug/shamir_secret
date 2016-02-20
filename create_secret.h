#ifndef CREATE_SECRET_H
#define CREATE_SECRET_H

#include <QObject>
#include <QTime>

#include "simple_number.h"

class create_secret
{   
public:
    create_secret(int k, int n, int M);
    // вернёт два массива - кол-во элементов равно n
    void getKeys(int *outX, int *outY);

private:
    // количество участников для восстановления
    int k;
    // всего сторон
    int n;
    // число для восстановления
    int p;
    // секрет
    int M;

    int getKey(int x);
    float random(int a, int b);

    void init(int k, int n, int M);
};

#endif // CREATE_SECRET_H
