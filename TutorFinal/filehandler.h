/*
 * Name: filehandler.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: File acess helper interface for Tutor Program.
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "question.h"

class File
{
public:
    File() {}
    Question open(); //Opens the file and reads by line, then splits by ":"
    void write(double percent, QString id); //Write Grades
};

#endif // FILEHANDLER_H
