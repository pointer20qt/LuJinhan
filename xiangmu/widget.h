#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString sname=NULL);
    showTable(QString sql);
    showclassT();
    QString Sname;
    showsnoT();
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
