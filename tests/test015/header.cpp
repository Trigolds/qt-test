
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

  //设置 MAC 输入模板
  ui->LEMac->setInputMask("HH:HH:HH:HH:HH:HH");

  //定义 IPv4 正则表达式，注意 "\\" 就是一个反斜杠字符
  QRegExp re("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}"
    "(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
  //新建正则表达式验证器
  QRegExpValidator* reVali = new QRegExpValidator(re);
  //设置给 lineEditIP
  ui->LEIP->setValidator(reVali);

  //新建整数验证器
  QIntValidator* intVali = new QIntValidator(0, 65535);
  //设置给 lineEditPort
  ui->LEPort->setValidator(intVali);

  //添加关联代码，必须放在 setupUi 函数之后
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
