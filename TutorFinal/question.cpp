/*
 * Name: question.cpp
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: Question implementation for Tutor Program.
 */
#include "question.h"
#include <QList>
#include <QStringList>
#include "IO.h"
#include <QDebug>
#include "filehandler.h" //Only for writing grades.

static IO x; //IO

void Question::addQuestion(QStringList str){
    _Questions.push_back(str);
}

void Question::addAnswer(QStringList str){
    int tmp = str.at(0).toInt(); //Since there is only one answer, QStringList index is hardcoded.
    _Answers.push_back(tmp);
}

void Question::display(int c){ //c for choice of display
    if(c == 0){
        for(int i = 0; i < _Questions.size(); i++){
        QStringList tmp = _Questions.at(i);
            x.print("\nQuestion: " + QString::number(i+1) + "\n"); //Spacer
            for(int l = 0; l < tmp.size(); l++){
                if(l == 0)
                    x.print(tmp.at(l) + "\n"); //Print Question
                else{
                    QString cNum = "[" + QString::number(l) + "] "; //Choice
                    x.print(cNum + tmp.at(l) + "\n"); //Print Question
                }
            }
            ask();
        }
        check(_tmpAnswers); //check() _tmpAnswers after being populated by user.
    }
    else{ //Begin Round 2

        int count = 0;
        if(_Mistakes.size() > 0){
            x.print("\n\n################\nGive it one more shot!\nWelcome to Round 2 (Review)\n");
            for(int l = 0; l < _Mistakes.size(); l++){
                int mQsIndex = _Mistakes.at(l);
                _tmpAnswers.clear(); //Clear answers for second round.
                QStringList tmp = _Questions.at(mQsIndex);
                x.print("\nQuestion: " + QString::number(l+1) + "\n"); //Spacer
                for(int j = 0; j < tmp.size(); j++){
                    if(j == 0)
                        x.print(tmp.at(j) + "\n"); //Print Question
                    else{
                        QString cNum = "[" + QString::number(j) + "] "; //Choice
                        x.print(cNum + tmp.at(j) + "\n"); //Print Question
                    }
                }

                ask();

                if(_tmpAnswers.at(0) == _Answers.at(mQsIndex)){ //Check Answer
                    x.print("\nCorrect!\n");
                count++;
                }
                else
                    x.print("\nOops! The correct answer is: " + tmp.at(_Answers.at(mQsIndex)) + "\n\n");
            }
       }
         double asz = _Answers.size();
         double msz = _Mistakes.size() - count;
         double percent = (((asz - msz)) / asz) * 100;
         QString s = QString::number(percent) + "%\n";

         x.print("Please enter your ID: ");
         QTextStream str(stdin);
         QString id = str.readLine();
         File grades;
         grades.write(percent, id);
         x.print("You scored: " + s);
         x.print("Grades Written!\n");
        }
}
void Question::ask(){
    x.print("\nPlease enter in an answer: ");
    int ans = x.ansQs();
    _tmpAnswers.push_back(ans);
}

void Question::check(QList<int> qlist){
    QList<int> tmp = qlist;
    for (int i = 0; i < _Answers.size(); i++) {
        if(!(tmp.at(i) == _Answers.at(i))){ //If user supplied answer doesn't match Answersheet.
            _Mistakes.push_back(i);// Add its index (question #) to mistakes list.
        }
    }
    display(1); // Passing !0 = Review Mode;
}
