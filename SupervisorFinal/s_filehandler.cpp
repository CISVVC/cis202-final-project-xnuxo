/*
 * Name: s_filehandler.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: File access helper implementation.
 */
#include "s_filehandler.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include "s_question.h"

//static IO x; //Debug

S_Question File::open(){
    QFile qsfile(QDir::current().absolutePath() + "/questions.qsv");
    if (!qsfile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error accessing file! Exiting.";
        exit(1);
    }

    S_Question tmp;
    QTextStream in(&qsfile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList tmpList = line.split(":");
        if(tmpList.size() > 1){ //Lines read with a size greater than 1 are questions.
            tmp.addQuestion(tmpList);
        }
        else
            tmp.addAnswer(tmpList);
    }
    return tmp;
}

void File::write(QList<QStringList> qs, QList<int> ans){

    QFile old(QDir::current().absolutePath() + "/questions.qsv"); //Remove old "questions.qsv"
    if (old.open(QIODevice::ReadOnly))
        old.remove();

    QFile qsfile(QDir::current().absolutePath() + "/questions.qsv"); //Create new "questions.qsv"
    if (!qsfile.open(QIODevice::WriteOnly)){
        qDebug() << "Error accessing file to write! Exiting.";
        exit(1);
    }

    QTextStream in(&qsfile);

    for(int i = 0; i< qs.size(); i++){
        QStringList tmp = qs.at(i);
        for(int l = 0; l<tmp.size(); l++){
            if(l != tmp.size()-1) // If not the last field add a ":"
                in << tmp.at(l) << ":";
            else
                in << tmp.at(l) << "\n"; //IF THIS ADDS EXTRA SPACE REMOVE!!!
        }
        in << ans.at(0) << "\n"; //There is only 1 answer.
    }
}

void File::readGrades(){
    QFile grdFile(QDir::current().absolutePath() + "/grades.txt"); //Remove old "questions.qsv"
    if (!grdFile.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot read grades file! Make sure it exsits in directory.";
    }
    else{
        QTextStream str(&grdFile);
        QTextStream out(stdout);
        out << str.readAll();
    }
}
