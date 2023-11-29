
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

  //设置密码框的显示模式
  ui->LEPassword->setEchoMode(QLineEdit::Password);

  //connect(ui->CBReading, SIGNAL(toggled(bool)), this, SLOT(is_CBReading_toggled(bool)));
  

  connect(ui->PBLogin, SIGNAL(clicked()), this, SLOT(is_PBLogin_clicked()));
  connect(ui->PBLogout, SIGNAL(clicked()), this, SLOT(is_PBlogout_clicked()));
  
}

Widget::~Widget()
{
  delete ui;
}

//登录按钮
void Widget::is_PBLogin_clicked()
{
  //判断用户名密码是否为空
  if (ui->LEUserName->text().isEmpty()
    || ui->LEPassword->text().isEmpty())
  {
    QMessageBox::warning(this, tr("Warning"), tr("User name and password can't be empty, enable to login"));
    return;
  }
  //用户名
  m_strUser = ui->LEUserName->text();
  //计算密码 Hash
  m_passwordHash = QCryptographicHash::hash(ui->LEPassword->text().toUtf8(),
    QCryptographicHash::Sha3_256);
  //构造消息
  //添加用户名
  QString strMsg = tr("UserName:") + m_strUser + tr("\r\n") + tr("Password Hash:");
  //把每个 Hash 字节转成一对十六进制字符显示
  // 256 bit 对应 32 字节，变成 64 个十六进制字符打印
  strMsg += m_passwordHash.toHex();

  //打印消息
  qDebug() << strMsg;
  //弹窗显示，注意：实际应用中会将用户名和密码 Hash 与数据库或配置文件里的做比较，而不是弹窗
  QMessageBox::information(this, tr("User Info"), strMsg);

}

//退出按钮
void Widget::is_PBlogout_clicked()
{
  this->close();
}