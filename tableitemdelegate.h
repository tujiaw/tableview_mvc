#ifndef TABLEITEMDELEGATE_H
#define TABLEITEMDELEGATE_H

#include <QStyledItemDelegate>

class TableItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TableItemDelegate(QObject *parent = 0);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // TABLEITEMDELEGATE_H
