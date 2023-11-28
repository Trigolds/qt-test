
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //槽函数
  link_clicked();
  connect(ui->LinkButton, SIGNAL(clicked()), this, SLOT(link_clicked()));
  connect(ui->UnlinkButton, SIGNAL(clicked()), this, SLOT(unlink_clicked()));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::link_clicked()
{
  //关联
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

  //调整按钮可用性
  ui->LinkButton->setEnabled(false);      //已经关联，禁用关联按钮
  ui->UnlinkButton->setEnabled(true);    //已经关联，只有解除关联按钮可用
}

void Widget::unlink_clicked()
{
  //解除关联
  disconnect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

  //调整按钮可用性
  ui->LinkButton->setEnabled(true);       //没有关联，只有关联按钮可用
  ui->UnlinkButton->setEnabled(false);   //没有关联，解除关联按钮禁用
}