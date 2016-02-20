#ifndef RECOVERY_SECRET_H
#define RECOVERY_SECRET_H

#include <QObject>

class recovery_secret
{
public:
    recovery_secret(int p);
    int getSecret(double *masX, double *masY, int size);

private:
    // число для восстановления
    int p;
    // многочлен лагранжа
    double lagrange(double x, double *masX, double *masY, int size);

    void init(int p);
};

#endif // RECOVERY_SECRET_H
