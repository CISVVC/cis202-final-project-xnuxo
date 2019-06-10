/*
 * Name: question.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: Question manager class implementation.
 */
#include "s_question.h"
#include<QList>
#include<QTextStream>
#include <QDebug>
#include <QStringList>

//Helpers

void S_Question::addQuestion(QStringList str){
    _Questions.push_back(str);
}

void S_Question::addAnswer(QStringList str){
    int tmp = str.at(0).toInt(); //Since there is only one answer, QStringList index is hardcoded.
    _Answers.push_back(tmp);
}

void S_Question::remQuestion(int n){
    if(n < _Questions.size()){
        _Questions.removeAt(n); //If answers and questions ever mismatch there is an error.
        _Answers.removeAt(n);// Every question has an answer.
    }
}

void S_Question::display(){
    for(int i = 0; i < _Questions.size(); i++){
    QStringList tmp = _Questions.at(i);
    qDebug() << "Question: " << i+1;
        for(int l = 0; l < tmp.size(); l++){
            //x.print(tmp.at(l) + "\n"); //Print Question
            qDebug() << tmp.at(l); //Print Question
        }
    qDebug() << "The answer is: " << tmp.at(_Answers.at(i)) << "\n\n";
    }
}

//User Actually Invokes These in main()

void S_Question::sAdd(){ //Add QS
    bool cont = true;
    QStringList qlist;
    int count = 0;
    qDebug() << "Enter the question: ";
    QTextStream str(stdin);
    QString s = str.readLine();
    qlist.push_back(s);
    while(cont){
        QTextStream str2(stdin);
        qDebug() << "\nEnter an choice: ";
        QString c = str2.readLine();
        qlist.push_back(c);
        count++; //Keep count of choices.

        qDebug() << "\nEnter another?(y/n): ";
        QString ans = str2.readLine(1);
        if(ans == 'Y' || ans == 'y')
            continue;
        else{
            c = ""; //reset c
            cont = false;
        }
    }
    addQuestion(qlist); //Add The Question to _Question's
    qDebug() << "\nOut of: " << count << "choices, which is the correct answer (#): ";
    int ans;
    str >> ans;
    _Answers.push_back(ans); //Add the answer to _Answer's.
}

void S_Question::sRem(){ //Remove QS
    display();
    qDebug() << "\nWhat question would you like to remove? (#): ";
    QTextStream in(stdin);
    int c;
    in >> c;
    remQuestion(c-1); //Plus one error fix. Allows removing Question "1" instead of qs "0"
}

const QList<QStringList> S_Question::getQsList(){  //Get QsList (writing)
        return _Questions;
}

const QList<int> S_Question::getAnsList(){ //GetAnsList (writing)
        return _Answers;
}
