/*
 * Name: filehandler.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: File acess helper interface for Tutor Program.
 */
#include "filehandler.h"
#include <QFile>
#include <QTextStream>
#include "question.h"
#include <QDebug>
#include <QDir>
#include "IO.h"
#include <QDateTime> //For grade file dates

static IO x; //Debug

Question File::open(){
    QFile qsfile(QDir::current().absolutePath() + "/questions.qsv"); //THIS IS THE BUILD DIR
    if (!qsfile.open(QIODevice::ReadOnly))
    {

       x.print("Oops! Make sure questions.qsv is in:\n\n" + QDir::current().absolutePath());
       x.print("\n\nError reading the file! Exiting.\n");
       exit(1);
    }

    Question tmp; //Stores Question for use.
    QTextStream in(&qsfile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList tmpList = line.split(":");
        //QStringList tmpList = sortQs(line);
        if(tmpList.size() > 1){ //Lines read with a size greater than 1 are questions.
            tmp.addQuestion(tmpList);
        }
        else
            tmp.addAnswer(tmpList);
    }
    qsfile.close();
    return tmp;
}

void File::write(double percent, QString id){
    QFile grdfile(QDir::current().absolutePath() + "/grades.txt"); //THIS IS THE BUILD DIR
    if(grdfile.open(QIODevice::ReadWrite)){
        QTextStream str(&grdfile);
        QString oldcont = str.readAll(); //Read whole file into oldcont.
        QString date = QDate::currentDate().toString();
        str << oldcont << date << " | ID: " << id << " | Score on Test: " << QString::number(percent) << "%\n";
    }
}
