#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowOpacity(0.7);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::gray));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width());
    rect.setHeight(rect.height());
    painter.drawRoundedRect(rect, 15, 15);
    {
        QPainterPath painter_path;
        painter_path.addRoundedRect(rect, 15, 15);
        painter.drawPath(painter_path);
    }
    QWidget::paintEvent(event);
}

void Dialog::mousePressEvent(QMouseEvent *event) {
    m_mouse_x = event->x();
    m_mouse_y = event->y();
}

void Dialog::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX() - m_mouse_x, event->globalY() - m_mouse_y);
}
