
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //�ۺ���
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
  //����
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

  //������ť������
  ui->LinkButton->setEnabled(false);      //�Ѿ����������ù�����ť
  ui->UnlinkButton->setEnabled(true);    //�Ѿ�������ֻ�н��������ť����
}

void Widget::unlink_clicked()
{
  //�������
  disconnect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

  //������ť������
  ui->LinkButton->setEnabled(true);       //û�й�����ֻ�й�����ť����
  ui->UnlinkButton->setEnabled(false);   //û�й��������������ť����
}