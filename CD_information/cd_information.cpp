#include "cd_information.h"

#include "rowcolourdelegate.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>


CD_Information::CD_Information(QWidget *parent) : QWidget(parent)
{
    setUpGui();
    connect(add, SIGNAL(clicked()),this, SLOT(Add()));
    connect(mdelete, SIGNAL(clicked()), this, SLOT(Delete()));
}

CD_Information::~CD_Information()
{
    //delete this;
}

void CD_Information::getFromGui()//cd.
{

//     QString cd_composer = composer->text();
//     QString cd_album = album->text();
//     double cd_costs = costs->value();
//     int cd_rating = rating->value();

//     CD(QString composer,int rating,double cost,QString albumName);
//     CD *cd = new CD(cd_composer,cd_rating,cd_costs,cd_album);
//     qDebug() << cd->toString();
}

void CD_Information::Add()
{
    QString cd_composer = composer->text();
    QString cd_album = album->text();
    double cd_costs = costs->value();
    int cd_rating = rating->value();

    if (cd_composer.isEmpty() or cd_album.isEmpty())
    {
        QMessageBox::warning(this, tr("Invalid"),
                                      tr("Invalid entry.\n"
                                         "Can not add empty entries?"),QMessageBox::Cancel);
        return;}
    clear();

    CD *cd = new CD(cd_composer,cd_rating,cd_costs,cd_album);
    qDebug() << cd->toString();

    // add to model
    QList<QStandardItem*> newRow;
    QStandardItem *cmp = new QStandardItem(cd->getcomposer());
    QStandardItem *csts = new QStandardItem();
    //csts->setData(QVariant(cd_costs), Qt::DisplayRole);
    csts->setData(QString::number(cd->getcost(),'f',2), Qt::DisplayRole);
    QStandardItem *albm = new QStandardItem(cd->getalbumName());
    QStandardItem *rate = new QStandardItem();
    rate->setData(QVariant(cd->getrating()), Qt::DisplayRole);
    newRow <<cmp<<albm<<csts<<rate;
    model->appendRow(newRow);

    // resize columns
    //tableView->resizeColumnsToContents();
    //tableView->horizontalHeader()->setStretchLastSection(true);
}

void CD_Information::Delete()
{
    QModelIndex index = tableView->currentIndex();
    if (!index.isValid())
        return;
    if (QMessageBox::Yes == QMessageBox::warning(this,
                                                 "Delete row",
                                                 "Are you sure?",
                                                 QMessageBox::Yes | QMessageBox::No))
    {
        int row = index.row();
        model->removeRow(row);
    }
}

void CD_Information::setUpGui()
{
    setWindowTitle("CD Information");

    QLabel *composerLabel = new QLabel("Composer");
    QLabel *albumnameLabel = new QLabel("Album title");
    QLabel *costLabel = new QLabel("Replacement cost");
    QLabel *ratingLabel = new QLabel("Rating");

    add = new QPushButton("Add");
    mdelete = new QPushButton("Delete");

    composer = new QLineEdit;composer->setText("Composer");//Test inputs
    album = new QLineEdit;album->setText("Album title");//Test inputs

    costs = new QDoubleSpinBox;costs->setRange(0,999);costs->setValue(250.00);//Test inputs
    rating = new QSpinBox;rating->setRange(0,100);rating->setValue(50);//Test inputs

    tableView = new QTableView() ;
    model = new QStandardItemModel;
    m_RowColourDelegate = new RowColourDelegate;
    QStringList headerRow;
    headerRow.append("Composer");
    headerRow.append("Album title");
    headerRow.append("Replacement cost");
    headerRow.append("Rating");
    model->setHorizontalHeaderLabels(headerRow);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setModel(model);
    tableView->setSortingEnabled(true);
    tableView->setItemDelegate(m_RowColourDelegate);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(composerLabel, 0, 0);
    layout->addWidget(composer, 1, 0);
    layout->addWidget(albumnameLabel, 0, 1);
    layout->addWidget(album, 1, 1);
    layout->addWidget(costLabel, 0, 2);
    layout->addWidget(costs, 1, 2);
    layout->addWidget(ratingLabel, 0, 3);
    layout->addWidget(rating, 1, 3);
    layout->addWidget(add, 1, 4);
    //void	addWidget ( QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = 0 )
    layout->addWidget(tableView, 2, 0, 2, 5);
    layout->addWidget(mdelete, 4, 4);

    this->setLayout(layout);

}

void CD_Information::clear()
{
    // reset GUI
    composer->clear();
    album->clear();
    costs->setValue(0);
    rating->setValue(0);
    composer->setFocus();
}
