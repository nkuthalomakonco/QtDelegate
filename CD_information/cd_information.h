#ifndef CD_INFORMATION_H
#define CD_INFORMATION_H

#include <QObject>
#include <QWidget>

class QLineEdit;
class QPushButton;
class QSpinBox;
class QDoubleSpinBox;
class QTableView;
class QStandardItemModel;

class RowColourDelegate;

#include "cd.h"

class CD_Information : public QWidget
{
    Q_OBJECT
public:
    explicit CD_Information(QWidget *parent = nullptr);
    ~CD_Information();


public slots:
    void getFromGui();
    void Add();
    void Delete();
signals:

private:
    void setUpGui();
    void clear();
    QTableView *tableView;
    QStandardItemModel *model;
    QLineEdit *composer;
    QLineEdit *album;
    QPushButton *add;
    QPushButton *mdelete;
    QDoubleSpinBox *costs;
    QSpinBox *rating;
    RowColourDelegate *m_RowColourDelegate;
    CD *cd;

};

#endif // CD_INFORMATION_H
