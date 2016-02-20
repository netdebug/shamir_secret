#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>

#include "create_secret.h"

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

    //int x, y, z;

    //Считаем первое число
    //cout << QString::fromUtf8("Введите первое число:").toLocal8Bit().data() << endl;
    //cin >> x;

    //Считаем второе число
    //cout << QString::fromUtf8("Введите второе число:").toLocal8Bit().data() << endl;
    //cin >> y;

    //Посчитаем сумму
    //z = x + y;

    //Выведем результат
    //cout << QString::fromUtf8("Сумма: ").toLocal8Bit().data() << z << endl;

    int* outX = new int[n];
    int* outY = new int[n];
    create_secret* crSecret = new create_secret(k, n, secret);
    crSecret->getKeys(outX, outY);

    for (int i = 0; i < n; i++) {
        cout << outX[i] << QString::fromUtf8(" ").toLocal8Bit().data() << outY[i] << endl;
    }

    return a.exec();
}
