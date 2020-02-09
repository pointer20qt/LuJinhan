#ifndef PRIPEOPLE_H
#define PRIPEOPLE_H

#include <QWidget>

namespace Ui {
class Pripeople;
}

class Pripeople : public QWidget
{
    Q_OBJECT

public:
    explicit Pripeople(QWidget *parent = 0);
    ~Pripeople();
    void init(QString sno,QString sname);

private:
    Ui::Pripeople *ui;
};

#endif // PRIPEOPLE_H
