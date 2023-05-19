#ifndef ROWCOLOURDELEGATE_H
#define ROWCOLOURDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>

class RowColourDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
//    RowColourDelegate();
    RowColourDelegate(QObject *parent = 0);
    ~RowColourDelegate();
//    QString displayText(const QVariant &value, const QLocale &locale) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
//     QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ROWCOLOURDELEGATE_H


