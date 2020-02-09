#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QCheckBox>
#include<QDateTime>
#include<QComboBox>
#include<pripeople.h>
#include<zhuce.h>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登陆窗口");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("myxm");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
    //注册模块
    connect(ui->pushButton2,QPushButton::clicked,[=](){
        zhuce *z=new zhuce();
        z->show();
    });
    //登陆模块
    ui->tupian->setPixmap(QPixmap("://dnf.jpg"));
    connect(ui->pushButton,QPushButton::clicked,[=](){
        QSqlQuery q;
        q.exec(QString("select * from student where sname = '%1' and mima ='%2'").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()));
        if(q.size()>0)
        {
            qDebug()<<"登陆成功";
            Widget *w=new Widget(NULL,ui->lineEdit->text());
            w->show();
            login::close();
        }
        else
        {
            qDebug()<<"滚";
        }
    });
}
login::~login()
{
    delete ui;
}
