
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
  connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(SendVoid()));
}

Widget::~Widget()
{
  delete ui;
}