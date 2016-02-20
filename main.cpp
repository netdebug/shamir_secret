#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>

#include "create_secret.h"
#include "recovery_secret.h"

using namespace std;

int n = 5;
int k = 3;
int secret = 11;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    while (1) {
        cout << QString::fromUtf8("Введите количество участников:").toLocal8Bit().data() << endl;
        cin >> n;
        cout << QString::fromUtf8("Введите количество участников для восстановления секрета:").toLocal8Bit().data() << endl;
        cin >> k;
        cout << QString::fromUtf8("Введите секрет:").toLocal8Bit().data() << endl;
        cin >> secret;

        int* outX = new int[n];
        int* outY = new int[n];
        int p = 0;
        create_secret* crSecret = new create_secret(k, n, secret);
        crSecret->getKeys(outX, outY);
        p = crSecret->getP();
        cout << QString::fromUtf8("p =").toLocal8Bit().data() << p << endl;

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

        cout << QString::fromUtf8("Введите 1 для выхода:").toLocal8Bit().data() << endl;
        cin >> n;
        cout << endl;
        if (n == 1) break;
    }

    return a.exec();
}
