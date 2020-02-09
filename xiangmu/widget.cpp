#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QCheckBox>
#include<QDateTime>
#include<QComboBox>
#include<pripeople.h>
Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("学生签到表");
    this->Sname=sname;
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("myxm");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
    //双击出现的个人表
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        Pripeople *p=new Pripeople();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });
    showTable("select * from student");
    showclassT();
    showsnoT();
}
Widget::~Widget()
{
    delete ui;
}
Widget::showTable(QString sql)
{
    QSqlQuery q;
    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());
        int i=0;
        while(q.next())
        {
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
            ui->tableWidget->setCellWidget(i,3,c);
            if(Sname!=q.value(1))
            {
                c->setDisabled(true);
            }
            connect(c,QCheckBox::clicked,[=](){
                c->setText("已签到");
                c->setDisabled(true);//点击后设置按钮失效
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
                QSqlQuery q1;
                q1.exec(QString("insert into insign values(%1,now())").arg(sno));
            });
            QSqlQuery q2;
            if(q2.exec("select * from insign where day(itime)=day(curdate()) order by itime desc"))
            {
                while(q2.next())
                {
                    if(q2.value(0)==q.value(0))
                    {
                        QCheckBox *c1=new QCheckBox("已签到");
                        c1->setDisabled(true);
                        ui->tableWidget->setCellWidget(i,3,c1);
                        ui->tableWidget->setItem(i,4,new QTableWidgetItem(q2.value(1).toString()));
                    }
                }
            }
            i++;
       }
    }
}
Widget::showclassT()
{
    QSqlQuery q;
    q.exec("select distinct sclass from student");
    ui->comboBox->addItem("所有人");
    while(q.next())
    {
        ui->comboBox->addItem(q.value(0).toString());
    }
    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
            showTable(QString("select * from student where sclass='%1'").arg(text));
            if(text=="所有人")
            {
                showTable("select * from student");
            }
    });
}
Widget::showsnoT()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->le->text().isEmpty())
        {
            qDebug()<<"输入为空";
        }
        else
        {
           showTable(QString("select * from student where sno=%1").arg(ui->le->text()));
        }
    });
}
