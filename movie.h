#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>
#include <iostream>
#include <stack>
#include <QVariant>
#include "readfile.h"
using namespace std;

class Movie : public QObject
{
    Q_OBJECT
public:
    explicit Movie(QObject *parent = nullptr);
    ReadFile file = ReadFile();

signals:
    void setMovie(QVariant num);


public slots:
    void getMovie(QString seed);
};

#endif // MOVIE_H
