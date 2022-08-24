#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); //memory
    ui->pbcoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbMango->setEnabled(false);
    //ui->pbcoffee->setEnabled(false);
    //ui->pbcoffee->isEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money +=diff;
   ui->lcdNumber->display(money);
   if(money<100){
       ui->pbcoffee->setEnabled(false);
   }
   else{
       ui->pbcoffee->setEnabled(true);
   }
   if(money<300){
       ui->pbMilk->setEnabled(false);
   }
   else{
       ui->pbMilk->setEnabled(true);
   }
   if(money<500){
       ui->pbMango->setEnabled(false);
   }
   else{
       ui->pbMango->setEnabled(true);
   }
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbcoffee_clicked()
{

changeMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbMango_clicked()
{
    changeMoney(-500);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString remoney;
    remoney=QString::number(money);
    msg.information(nullptr,"Return coin","Return"+remoney);

    changeMoney(-money);
    ui->lcdNumber->display(money);
}

