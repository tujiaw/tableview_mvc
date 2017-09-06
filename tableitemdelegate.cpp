#include "tableitemdelegate.h"
#include <QtWidgets>

TableItemDelegate::TableItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 1) {
        // 保存绘制前的状态
        painter->save();

        // 抗锯齿
        painter->setRenderHint(QPainter::Antialiasing, true);

        // 字体
        QFont font = painter->font();
        font.setPixelSize(20);
        painter->setFont(font);

        // 颜色
        painter->setPen(QColor(0, 255, 0));

        // 圆角矩形
        QPainterPath painterPath;
        painterPath.addRoundedRect(option.rect, 5, 5);
        painter->fillPath(painterPath,QBrush(QColor(255, 0, 0)));

        // 绘制文本
        painter->drawText(option.rect, Qt::AlignCenter, index.data(Qt::DisplayRole).toString());

        // 恢复绘制前的状态，否则影响到其他列
        painter->restore();
    } else if (index.column() == 2) {
        QRect textRect = option.rect;
        textRect.setX(textRect.x() + 42);
        painter->drawText(textRect, Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

        QStyleOptionButton button;
        QRect btnRect = option.rect;
        btnRect.setWidth(40);
        button.text = "click";
        button.rect = btnRect;
        button.state |= QStyle::State_Enabled | QStyle::State_Active;

        option.widget->style()->drawControl(QStyle::CE_PushButton, &button, painter);
    }
    else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}


bool TableItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (index.column() == 2) {
        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            QRect btnRect = option.rect;
            btnRect.setWidth(40);
            if (btnRect.contains(ev->pos())) {
                QMessageBox::about(nullptr, "title", QString("row:%1, col:%2").arg(index.row() + 1).arg(index.column() + 1));
                return true;
            }
        }
    }
    return false;
}
