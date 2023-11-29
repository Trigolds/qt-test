
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QUrl>
#include <QCryptographicHash>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //������������ʾģʽ
  ui->LEPassword->setEchoMode(QLineEdit::Password);

  //connect(ui->CBReading, SIGNAL(toggled(bool)), this, SLOT(is_CBReading_toggled(bool)));
  

  connect(ui->PBLogin, SIGNAL(clicked()), this, SLOT(is_PBLogin_clicked()));
  connect(ui->PBLogout, SIGNAL(clicked()), this, SLOT(is_PBlogout_clicked()));
  
}

Widget::~Widget()
{
  delete ui;
}

//��¼��ť
void Widget::is_PBLogin_clicked()
{
  //�ж��û��������Ƿ�Ϊ��
  if (ui->LEUserName->text().isEmpty()
    || ui->LEPassword->text().isEmpty())
  {
    QMessageBox::warning(this, tr("Warning"), tr("User name and password can't be empty, enable to login"));
    return;
  }
  //�û���
  m_strUser = ui->LEUserName->text();
  //�������� Hash
  m_passwordHash = QCryptographicHash::hash(ui->LEPassword->text().toUtf8(),
    QCryptographicHash::Sha3_256);
  //������Ϣ
  //����û���
  QString strMsg = tr("UserName:") + m_strUser + tr("\r\n") + tr("Password Hash:");
  //��ÿ�� Hash �ֽ�ת��һ��ʮ�������ַ���ʾ
  // 256 bit ��Ӧ 32 �ֽڣ���� 64 ��ʮ�������ַ���ӡ
  strMsg += m_passwordHash.toHex();

  //��ӡ��Ϣ
  qDebug() << strMsg;
  //������ʾ��ע�⣺ʵ��Ӧ���лὫ�û��������� Hash �����ݿ�������ļ�������Ƚϣ������ǵ���
  QMessageBox::information(this, tr("User Info"), strMsg);

}

//�˳���ť
void Widget::is_PBlogout_clicked()
{
  this->close();
}