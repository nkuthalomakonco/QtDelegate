#include "cd.h"

CD::CD()
{
    composer = "Unkown";
    rating = 0;
    cost = 0;
    albumName = "Unkown";
}

CD::CD(QString c, int r, double cst, QString album)
{
    composer = c;
    rating = r;
    cost = cst;
    albumName = album;
}

QString CD::toString() const
{
    return QString("Composer: "+ composer +" Album: " + albumName +
                   " Cost: " + QString::number(cost, 'f', 2) + " Rating: " + QString::number(rating));
}

QString CD::getcomposer() const
{
    return  composer;
}

int CD::getrating() const
{
    return  rating;
}

double CD::getcost() const
{
    return  cost;
}

QString CD::getalbumName() const
{
    return  albumName;
}

CD::~CD()
{
    //delete this;
}
