
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
  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::ButtonClicked()
{
  //�� emit ���ź�
  emit SendMsg(tr("This is the message!"));
}