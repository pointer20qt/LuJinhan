#include "zhuce.h"
#include "ui_zhuce.h"
#include<QSqlQuery>
#include<QDebug>
zhuce::zhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    ui->label_5->setPixmap(QPixmap("://1.JPEG"));
}

zhuce::~zhuce()
{
    delete ui;
}

void zhuce::on_pushButton_clicked()
{
    QSqlQuery q;
    q.exec(QString("insert into student values(%1,'%2','%3','%4')").arg(ui->lineEdit_xuehao->text()).arg(ui->lineEditzhanghao->text()).arg(ui->lineEdit_banji->text()).arg(ui->lineEdit_mima->text()));
    qDebug()<<"注册成功";
}

void zhuce::on_pushButton_2_clicked()
{
    this->close();
}
