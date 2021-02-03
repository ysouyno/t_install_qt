#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowOpacity(0.7);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mousePressEvent(QMouseEvent *event) {
    m_mouse_x = event->x();
    m_mouse_y = event->y();
}

void Dialog::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX() - m_mouse_x, event->globalY() - m_mouse_y);
}
