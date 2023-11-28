
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //������ť���źŶ������� FoodIsComing �ۺ���
  connect(ui->pushButtonAnderson, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
  connect(ui->pushButtonBruce, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
  connect(ui->pushButtonCastiel, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::FoodIsComing()
{
  //��ȡ�ź�Դͷ���������
  QString strObjectSrc = this->sender()->objectName();
  qDebug() << strObjectSrc; //��ӡԴͷ��������

  //��Ҫ��ʾ����Ϣ
  QString strMsg;
  //�ж����ĸ���ť�����ź�
  if ("pushButtonAnderson" == strObjectSrc)
  {
    strMsg = tr("Hello Anderson! Your food is coming!");
  }
  else if ("pushButtonBruce" == strObjectSrc)
  {
    strMsg = tr("Hello Bruce! Your food is coming!");
  }
  else if ("pushButtonCastiel" == strObjectSrc)
  {
    strMsg = tr("Hello Castiel! Your food is coming!");
  }
  else
  {
    //do nothing
    return;
  }
  //��ʾ�Ͳ���Ϣ
  QMessageBox::information(this, tr("Food"), strMsg);
}