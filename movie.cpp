#include "movie.h"

Movie::Movie(QObject *parent) : QObject(parent)
{

}

void Movie::getMovie(QString seed)
{

    string text = "";

    text = file.grabMovie(seed.toInt());

    QString movie = QString::fromStdString(text);
    QVariant result(movie);
    emit setMovie(result);
}
