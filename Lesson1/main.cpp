#include <QCoreApplication>
#include <iostream>
void myFunc(int a, int b){

    std::cout << a+b << '\n';

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myFunc(5,6);
    return a.exec();
}

