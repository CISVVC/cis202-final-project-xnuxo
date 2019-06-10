/*
 * Name: io.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: This one I'm right confused about. Qt forced me to make my own IO class for stdin/stdout.
 */
#ifndef STDPRINT_H
#define STDPRINT_H
#include <QTextStream>

class IO
{
public:
    void print(QString s);
    int ansQs();
};

#endif // STDPRINT_H
