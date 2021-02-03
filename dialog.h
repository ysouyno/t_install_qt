#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_mouse_x;
    int m_mouse_y;
};
#endif // DIALOG_H
