
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

  //����ְҵ��Ͽ�ɱ༭
  ui->CBJob->setEditable(true);

  //�������ڱ༭���ڱ༭ʱ�Զ���������
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
  if (index < 0)   //index ���� -1����ʾ�û�û��ѡ��������Ŀȫ��ɾ����
  {
    return; //ֱ�ӷ���
  }
  //��ӡ��Ϣ
  qDebug() << "Gender: " << ui->CBGender->itemText(index);
}

void Widget::is_CBJob_currentTextChanged(const QString& arg1)
{
  //���ǻ�����ŵģ�ֱ�ӵõ����µ��ı�
  qDebug() << "Job: " << arg1;
}

void Widget::is_dateEdit_dateChanged(const QDate& date)
{
  qDebug() << date.toString("yyyy-MM-dd");  //�����������ַ�����ʽ
  //yyyy ����λ����ݣ�MM ����λ���·ݣ�dd ����λ�����ӣ����� "2000-01-01"
}

void Widget::is_PB_clicked()
{
  QString strResult;  //����ַ���
  //��ȡ����
  strResult += tr("Name: %1\r\n").arg(ui->LEName->text());
  //�Ա�
  strResult += tr("Gender: %1\r\n").arg(ui->CBGender->currentText());
  //ְҵ
  strResult += tr("Job: %1\r\n").arg(ui->CBJob->currentText());
  //����
  strResult += tr("Brithday: %1\r\n").arg(ui->dateEdit->date().toString());
  //QDate::toString() �������������ʽ���Զ����ձ��ػ����Ե����ڸ�ʽ�����ַ���

  //���⹦�ܣ����ݵ�ǰʱ����û����գ������û���ǰ����
  QDateTime dtCur = QDateTime::currentDateTime();
  //��������
  int nYears = dtCur.date().year() - ui->dateEdit->date().year();
  strResult += tr("Age: %1").arg(nYears);

  //��ʾ��Ϣ��
  QMessageBox::information(this, tr("Info"), strResult);
}

