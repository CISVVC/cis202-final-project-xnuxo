/*
 * Name: question.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Description: Question interface for Tutor Program.
 */
#ifndef QUESTION_H
#define QUESTION_H
#include <QList>
#include <QStringList>
class Question
{
public:
    Question() {}
    void addQuestion(QStringList str);
    void addAnswer(QStringList str);
    void display(int c);
    void ask();
    void check(QList<int> qlist);

private:
    QList<QStringList> _Questions;
    QList<int> _Answers;
    QList<int> _tmpAnswers;
    QList<int> _Mistakes;
};

#endif // QUESTION_H
