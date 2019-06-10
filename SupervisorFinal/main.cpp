/*
 * Name: main.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: A Supervisor Program that reads/edits questions.qsv and grabs student grades.
 */
#include <QCoreApplication>
#include "s_filehandler.h"
#include "s_question.h"
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    File f;
    bool cont = true;
    S_Question q = f.open();

    qDebug() << "####################################################"
            "\n\nWelcome to the Supervisor Program!\n"
            "To make sure this runs correctly please place all files"
            "\n(questions.qsv and grades.txt) in the directory:\n\n "
            << QDir::current().absolutePath()
         << "\n\nNote: A generic location for both files would require me to ask you to create "
            "a file on the Desktop, Documents, etc. "
            "and I'd rather not mess with any of your structure.\n";

    while(cont){
        qDebug() << "Options:\n[1]Add a Question\n"
                "[2]Remove a Question\n[3]Print the Questions\n"
                "[4]Save and Write Questions\n[5]Review Student Grades.\n[6]Quit";

        qDebug() << "\nEnter the option number below: ";
        QTextStream str(stdin);
        int ans = 0;
        str >> ans;
        qDebug() << "\n"; //SPACER
        if(ans > 0 && ans < 7){
            switch(ans){
                case 1:	q.sAdd(); //supervisor Add() function
                        break;
                case 2:	q.sRem(); //supervisor Remove() function
                        break;
                case 3: q.display();
                        break;
                case 4:	f.write(q.getQsList(),q.getAnsList());
                        break;
                case 5:	f.readGrades();
                        break;
                case 6: return 0;
                default:qDebug() << "Error: Invalid response, try again.";
                        break;
            }
        }
        else {
            continue;
        }
    }
    return a.exec();
}
