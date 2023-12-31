
#pragma once

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
  class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget* parent = 0);
  ~Widget();

private slots:

  void is_PBLogin_clicked();

  void is_PBlogout_clicked();

private:
  Ui::Widget* ui;
  //用户名字符串
  QString m_strUser;
  //不能明文保存密码，存储密码 hash 值
  QByteArray m_passwordHash;
};