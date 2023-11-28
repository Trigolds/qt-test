
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //添加关联代码，必须放在 setupUi 函数之后
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
  //接收端是文本浏览控件
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->textBrowser, SLOT(setText(QString)));
  //接收端是主窗口的 PrintText 槽
  connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(PrintText(QString)));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::PrintText(const QString& text)
{
  qDebug() << text; //打印到调试输出面板
}