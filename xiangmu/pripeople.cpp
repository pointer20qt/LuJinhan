#include "pripeople.h"
#include "ui_pripeople.h"
#include<QSqlQuery>
#include<QTextCharFormat>
Pripeople::Pripeople(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pripeople)
{
    ui->setupUi(this);
    this->setWindowTitle("个人签到表");
}

Pripeople::~Pripeople()
{
    delete ui;
}
void Pripeople::init(QString sno,QString sname)
{
    ui->xue->setText("学号 ："+sno);
    ui->xing->setText("姓名 ："+sname);
    QSqlQuery q;
    q.exec(QString("select itime from insign where sno=%1 and date_format(itime,'%Y-%m')= date_format(curdate(),'%Y-%m')").arg(sno));
    ui->ci->setText("签到次数 :"+QString::number(q.size()));
    //日历上显示签到变色
    QTextCharFormat f;
    f.setBackground(Qt::black);
    f.setForeground(Qt::green);
    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }
    //出勤率
    ui->progressBar->setValue(q.size()*3.32);
}
