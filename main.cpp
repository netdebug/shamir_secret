#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>

#include "create_secret.h"
#include "recovery_secret.h"

using namespace std;

const int n = 5;
const int k = 3;
const int secret = 11;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    int* outX = new int[n];
    int* outY = new int[n];
    int p = 0;
    create_secret* crSecret = new create_secret(k, n, secret);
    crSecret->getKeys(outX, outY);
    p = crSecret->getP();

    for (int i = 0; i < n; i++) {
        cout << outX[i] << QString::fromUtf8(" ").toLocal8Bit().data() << outY[i] << endl;
    }

    double* doutX = new double[n];
    double* doutY = new double[n];
    for (int i = 0; i < n; i++) {
        doutX[i] = outX[i];
        doutY[i] = outY[i];
    }

    recovery_secret* recSecret = new recovery_secret(p);
    cout << QString::fromUtf8("Секрет = ").toLocal8Bit().data() << recSecret->getSecret(doutX, doutY, k) << endl;

    return a.exec();
}

//cout << QString::fromUtf8("Секрет = ").toLocal8Bit().data() << InterpolateLagrangePolynomial(0, doutX, doutY, k) << endl;
/*double InterpolateLagrangePolynomial (double x, double* x_values, double* y_values, int size)
{
    double lagrange_pol = 0;
    double basics_pol;

    for (int i = 0; i < size; i++)
    {
        basics_pol = 1;
        for (int j = 0; j < size; j++)
        {
            if (j == i) continue;
            basics_pol *= (x - x_values[j])/(x_values[i] - x_values[j]);
        }
        lagrange_pol += basics_pol*y_values[i];
    }
    return lagrange_pol;
}*/
