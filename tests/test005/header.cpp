
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //��ӹ������룬������� setupUi ����֮��
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
  //���ն����ı�����ؼ�
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->textBrowser, SLOT(setText(QString)));
  //���ն��������ڵ� PrintText ��
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(PrintText(QString)));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::PrintText(const QString& text)
{
  qDebug() << text; //��ӡ������������
}