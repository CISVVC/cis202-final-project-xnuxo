/*
 * Name: s_filehandler.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: File access helper interface.
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "s_question.h"

class File
{
public:
    File() {}
    S_Question open(); //Opens the file and splices by line
    void write(QList<QStringList> qs, QList<int> ans); //Internal mode: 0 = Questions | 1 = Answers
    void readGrades();
};

#endif // FILEHANDLER_H
