#include "test.h"
#include <QDebug>
#include "vector.h"

test::test() {}

void test::Testing() {
    Vector<QString> vec;

    vec.push_back("pizda");

    for (size_t i = 0; i < vec.size(); i++) {
        qDebug() << vec.at(i);
    }
}
