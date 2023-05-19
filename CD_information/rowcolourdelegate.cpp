#include "rowcolourdelegate.h"
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLineEdit>
//https://doc.qt.io/archives/4.6/itemviews-spinboxdelegate.html

RowColourDelegate::RowColourDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}

RowColourDelegate::~RowColourDelegate()
{
    //delete this;
}

//Where the replacement value is greater than or equal to R250, the row should be made a
//different colour.
void RowColourDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int colorCondition(250);

    QColor colour = Qt::white;

    float costs = index.sibling(index.row(), 2).data(Qt::EditRole).toFloat();

    if(costs >= colorCondition)
        colour = Qt::red;

    painter->fillRect(option.rect, colour);
    painter->drawText(option.rect, index.data().toString());

}

QWidget *RowColourDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *DoubleSpinBox = new QDoubleSpinBox(parent);//editors
    QSpinBox *SpinBox = new QSpinBox(parent);
    QLineEdit *LineEdit = new QLineEdit(parent);

    (void) option;

    if (index.column() == 0 or index.column() == 1)
    {
        return LineEdit;
    }

    else if (index.column() == 2) {
        DoubleSpinBox->setFrame(false);
        DoubleSpinBox->setMinimum(0);
        DoubleSpinBox->setMaximum(999);
        DoubleSpinBox->setDecimals(2);
        return DoubleSpinBox;
    }

    else//index.column() == 3
    {
        SpinBox->setFrame(false);
        SpinBox->setMinimum(0);
        SpinBox->setMaximum(100);
        return SpinBox;
    }
}

void RowColourDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QDoubleSpinBox *DspinBox = static_cast<QDoubleSpinBox*>(editor);
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);

    if (index.column() == 0 or index.column() == 1)
    {
        QString text = index.model()->data(index, Qt::EditRole).toString();
        lineEdit->setText(text);
    }
    if (index.column() == 2)
    {
        float value = index.model()->data(index, Qt::EditRole).toFloat();
        DspinBox->setValue(value);
    }
    if (index.column() == 3)
    {
        float value = index.model()->data(index, Qt::EditRole).toInt();
        spinBox->setValue(value);
    }

}

void RowColourDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *DspinBox = static_cast<QDoubleSpinBox*>(editor);
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);

    if (index.column() == 2)
    {
        DspinBox->interpretText();
        float value = DspinBox->value();
        model->setData(index, QString::number(value,'f',2), Qt::EditRole);
    }

    if (index.column() == 3)
    {
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }

    if (index.column() == 0 or index.column() == 1)
    {
        QString text = lineEdit->text();
        model->setData(index, text, Qt::EditRole);
    }

}


void RowColourDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void) index;
}
