
#include "header.hpp"
#include "ui_widget.h"
#include <QDebug>
#include <QIntValidator>
#include <QRegExp>
#include <QRegExpValidator>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //���� MAC ����ģ��
  ui->LEMac->setInputMask("HH:HH:HH:HH:HH:HH");

  //���� IPv4 ������ʽ��ע�� "\\" ����һ����б���ַ�
  QRegExp re("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}"
    "(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
  //�½�������ʽ��֤��
  QRegExpValidator* reVali = new QRegExpValidator(re);
  //���ø� lineEditIP
  ui->LEIP->setValidator(reVali);

  //�½�������֤��
  QIntValidator* intVali = new QIntValidator(0, 65535);
  //���ø� lineEditPort
  ui->LEPort->setValidator(intVali);

  //��ӹ������룬������� setupUi ����֮��
  connect(ui->LEMac, SIGNAL(textEdited(QString)), this, SLOT(is_LEMac_textChanged(QString)));
  connect(ui->LEIP, SIGNAL(textEdited(QString)), this, SLOT(is_LEIP_textChanged(QString)));
  connect(ui->LEPort, SIGNAL(textEdited(QString)), this, SLOT(is_LEPort_textChanged(QString)));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::is_LEMac_textChanged(const QString& arg1)
{
  qDebug() << "MAC: " << arg1;
}
void Widget::is_LEIP_textChanged(const QString& arg1)
{
  qDebug() << "IP: " << arg1;
}
void Widget::is_LEPort_textChanged(const QString& arg1)
{
  qDebug() << "Port: " << arg1;
}
