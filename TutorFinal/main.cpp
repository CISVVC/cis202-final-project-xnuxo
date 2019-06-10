/*
 * Name: main.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: A Tutor Program that reads questions.qsv and prints grades.
 */
#include <QCoreApplication>
#include "question.h"
#include "filehandler.h"
#include "IO.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    File f;
    Question q = f.open();
    q.display(0);
    return 0;

    //return a.exec();
}
