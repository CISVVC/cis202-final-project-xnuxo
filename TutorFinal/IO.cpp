/*
 * Name: io.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: IO implementation.
 */
#include "IO.h"
#include <QTextStream>

void IO::print(QString s){
    QTextStream out(stdout);
    out << s;
}

int IO::ansQs(){
    QTextStream in(stdin);
    int tmp;
    in >> tmp;
    return tmp;
}
