#include "test.h"
#include <QDebug>

Test::Test(QObject *parent) :
    QObject(parent)
{

}

int Test::getValue()
{
    qDebug() << __FUNCTION__ << "__ali__";
    return 13;
}
