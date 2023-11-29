
#include "header.hpp"
#include "ui_widget.h"
#include <QDebug>
#include <QIntValidator>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDateTime>
#include <QMessageBox>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //设置职业组合框可编辑
  ui->CBJob->setEditable(true);

  //设置日期编辑器在编辑时自动弹出日历
  ui->dateEdit->setCalendarPopup(true);

  connect(ui->CBGender, SIGNAL(currentIndexChanged(int)), this, SLOT(is_CBGender_currentIndexChanged(int)));
  connect(ui->CBJob, SIGNAL(currentTextChanged(const QString&)), this, SLOT(is_CBJob_currentTextChanged(const QString&)));
  connect(ui->dateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(is_dateEdit_dateChanged(const QDate&)));
  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(is_PB_clicked()));

}

Widget::~Widget()
{
  delete ui;
}


void Widget::is_CBGender_currentIndexChanged(int index)
{
  if (index < 0)   //index 可能 -1，表示用户没有选，或者条目全被删除了
  {
    return; //直接返回
  }
  //打印信息
  qDebug() << "Gender: " << ui->CBGender->itemText(index);
}

void Widget::is_CBJob_currentTextChanged(const QString& arg1)
{
  //不是基于序号的，直接得到了新的文本
  qDebug() << "Job: " << arg1;
}

void Widget::is_dateEdit_dateChanged(const QDate& date)
{
  qDebug() << date.toString("yyyy-MM-dd");  //参数是日期字符串格式
  //yyyy 是四位数年份，MM 是两位数月份，dd 是两位数日子，比如 "2000-01-01"
}

void Widget::is_PB_clicked()
{
  QString strResult;  //结果字符串
  //获取姓名
  strResult += tr("Name: %1\r\n").arg(ui->LEName->text());
  //性别
  strResult += tr("Gender: %1\r\n").arg(ui->CBGender->currentText());
  //职业
  strResult += tr("Job: %1\r\n").arg(ui->CBJob->currentText());
  //生日
  strResult += tr("Brithday: %1\r\n").arg(ui->dateEdit->date().toString());
  //QDate::toString() 如果不带参数格式，自动按照本地化语言的日期格式返回字符串

  //额外功能，根据当前时间和用户生日，计算用户当前岁数
  QDateTime dtCur = QDateTime::currentDateTime();
  //计算岁数
  int nYears = dtCur.date().year() - ui->dateEdit->date().year();
  strResult += tr("Age: %1").arg(nYears);

  //显示消息框
  QMessageBox::information(this, tr("Info"), strResult);
}

