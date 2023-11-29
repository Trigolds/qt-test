
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //������̬����ģʽ
  ui->CB3Show->setTristate(true);

  connect(ui->CBReading, SIGNAL(toggled(bool)), this, SLOT(is_CBReading_toggled(bool)));
  connect(ui->CBHiking, SIGNAL(toggled(bool)), this, SLOT(is_CBHiking_toggled(bool)));
  connect(ui->CBSwimming, SIGNAL(toggled(bool)), this, SLOT(is_CBSwimming_toggled(bool)));
  connect(ui->CBDazing, SIGNAL(toggled(bool)), this, SLOT(is_CBDazing_toggled(bool)));
  connect(ui->CBShopping, SIGNAL(toggled(bool)), this, SLOT(is_CBShopping_toggled(bool)));
  connect(ui->CBEating, SIGNAL(toggled(bool)), this, SLOT(is_CBEating_toggled(bool)));

  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(is_PB_clicked()));
  connect(ui->CLBOpenFolder, SIGNAL(clicked()), this, SLOT(is_CLBOpenFolder_clicked()));
  connect(ui->CLBOpenPage, SIGNAL(clicked()), this, SLOT(is_CLBOpenPage_clicked()));
}

Widget::~Widget()
{
  delete ui;
}

//��� 6 ����Ȥ���ø�ѡ�򣬸�����Ȥ��ѡ��״̬��������̬��ѡ����ʾ
void Widget::CheckHobbies()
{
  int count = 0;  //��Ȥ����
  if (ui->CBReading->isChecked())
  {
    count++;
  }
  if (ui->CBHiking->isChecked())
  {
    count++;
  }
  if (ui->CBSwimming->isChecked())
  {
    count++;
  }
  if (ui->CBDazing->isChecked())
  {
    count++;
  }
  if (ui->CBShopping->isChecked())
  {
    count++;
  }
  if (ui->CBEating->isChecked())
  {
    count++;
  }
  //������Ȥ����������̬��ť��״̬
  if (count <= 0)
  {
    ui->CB3Show->setCheckState(Qt::Unchecked);
    return;
  }
  else if (count <= 3)
  {
    ui->CB3Show->setCheckState(Qt::PartiallyChecked);
    return;
  }
  else
  {
    ui->CB3Show->setCheckState(Qt::Checked);
    return;
  }
}

void Widget::is_CBReading_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Reading");
  }
  CheckHobbies(); //������̬��ѡ��
}
void Widget::is_CBHiking_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Hiking");
  }
  CheckHobbies(); //������̬��ѡ��
}
void Widget::is_CBSwimming_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Swimming");
  }
  CheckHobbies(); //������̬��ѡ��
}
void Widget::is_CBDazing_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Dazing");
  }
  CheckHobbies(); //������̬��ѡ��
}
void Widget::is_CBShopping_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Shopping");
  }
  CheckHobbies(); //������̬��ѡ��
}
void Widget::is_CBEating_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Eating");
  }
  CheckHobbies(); //������̬��ѡ��
}

//������ʾѡ�е���Ȥ����
void Widget::is_PB_clicked()
{
  QString strResult = tr("Hobbies:\r\n");
  if (ui->CBReading->isChecked())
  {
    strResult += tr("Reading\r\n");
  }
  if (ui->CBHiking->isChecked())
  {
    strResult += tr("Hiking\r\n");
  }
  if (ui->CBSwimming->isChecked())
  {
    strResult += tr("Swiming\r\n");
  }
  if (ui->CBDazing->isChecked())
  {
    strResult += tr("Dazing\r\n");
  }
  if (ui->CBShopping->isChecked())
  {
    strResult += tr("Shopping\r\n");
  }
  if (ui->CBEating->isChecked())
  {
    strResult += tr("Eating\r\n");
  }
  //������ʾ
  QMessageBox::information(this, tr("Hobbies"), strResult);
}

void Widget::is_CLBOpenFolder_clicked()
{
  QDesktopServices::openUrl(QUrl("file:///C:/Users/squal/Desktop/Codes/Qt/cmake-test/qt-test/tests/test013"));
}

void Widget::is_CLBOpenPage_clicked()
{
  QDesktopServices::openUrl(QUrl("https://www.163.com/"));
}

