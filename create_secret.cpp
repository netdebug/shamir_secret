#include "create_secret.h"

create_secret::create_secret(int k, int n, int M)
{
    init(k, n, M);
}

void create_secret::getKeys(int *outX, int *outY)
{
    if (outX == NULL || outY == NULL) return;

    for (int i = 1; i <= n; i++) {
        outX[i - 1] = i;
        outY[i - 1] = getKey(i);
    }
}

int create_secret::getKey(int x)
{
    int a;
    int f_x = 0;

    for (int i = k - 1; i > 0; i--) {
        f_x += pow(x, i) * (int) random(1, 1000);
    }
    f_x += M;
    f_x = f_x % p;

    return f_x;
}

float create_secret::random(int a, int b)
{
    static int k = 1;
    if (k == 1) {
        k = 2;
        return 7;
    }
    else {
        k = 1;
        return 8;
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return qrand()%(b-a+1)+a;
}

void create_secret::init(int k, int n, int M)
{
    this->M = M;
    this->k = k;
    this->n = n;
    p = simple_number::getFirstPrimeNumber(M);
}
