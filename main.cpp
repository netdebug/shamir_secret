#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    int x, y, z;

    //Считаем первое число
    cout << QString::fromUtf8("Введите первое число:").toLocal8Bit().data() << endl;
    cin >> x;

    //Считаем второе число
    cout << QString::fromUtf8("Введите второе число:").toLocal8Bit().data() << endl;
    cin >> y;

    //Посчитаем сумму
    z = x + y;

    //Выведем результат
    cout << QString::fromUtf8("Сумма: ").toLocal8Bit().data() << z << endl;

    return a.exec();
}
