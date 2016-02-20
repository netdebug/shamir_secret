#include "recovery_secret.h"

recovery_secret::recovery_secret(int p)
{
    init(p);
}

int recovery_secret::getSecret(double *masX, double *masY, int size)
{
    if (masX == NULL || masY == NULL) return -1;

    return lagrange(0, masX, masY, size);
}

double recovery_secret::lagrange(double x, double *masX, double *masY, int size)
{
    double lagr = 0;

    for (int i = 0; i < size; i++) {
        double l_temp = 1;

        for (int j = 0; j < size; j++) {
            if (i == j) continue;

            l_temp *= (x - masX[j]) / (masX[i] - masX[j]);
        }

        l_temp = ((int)l_temp)%p;
        lagr += l_temp * masY[i];
    }

    return ((int)lagr)%p;
    //return lagr;
}

void recovery_secret::init(int p)
{
    this->p = p;
}
