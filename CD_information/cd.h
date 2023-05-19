#ifndef CD_H
#define CD_H
#include <QString>

class CD
{
public:
    CD();
    CD(QString composer,int rating,double cost,QString albumName);
    ~CD();//destructor
    QString toString()const;
   /* void setcomposer(QString composer);
    void setrating(int rating);
    void setcost(double cost);
    void setalbumName(QString albumName);*/

    QString getcomposer()const;
    int getrating()const;
    double getcost()const;
    QString getalbumName()const;

private:
    //data members
    QString composer;
    int rating;
    double cost;
    QString albumName;//therealkuhlegee
};

#endif // CD_H
