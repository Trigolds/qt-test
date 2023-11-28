
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //��ӹ������룬������� setupUi ����֮��
  //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
  connect(ui->pushButton, &QPushButton::clicked, this, &Widget::FoodIsComing);
}

Widget::~Widget()
{
  delete ui;
}

//�ۺ���������룬����ͨ��Ա��������
void Widget::FoodIsComing()
{
  QMessageBox::information(this, QString::fromLocal8Bit("�Ͳ�"), QString::fromLocal8Bit("���ˣ��������ʹ�"));
}