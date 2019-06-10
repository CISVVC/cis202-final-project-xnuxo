/*
 * Name: question.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: Question manager class interface.
 */
#ifndef S_QUESTION_H
#define S_QUESTION_H

#include <QList>
#include <QStringList>

class S_Question
{
public:
    S_Question() {}
    void display();
    void sAdd(); //Actual class to add Question
    void sRem();//Same just for removing
    void addQuestion(QStringList str);//Helpers
    void addAnswer(QStringList str);
    void remQuestion(int n); //n = _Questions index

    const QList<QStringList> getQsList();
    const QList<int> getAnsList();

private:
    QList<QStringList> _Questions;
    QList<int> _Answers;
};

#endif // S_QUESTION_H
