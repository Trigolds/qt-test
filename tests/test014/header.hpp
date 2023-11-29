
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
  //�û����ַ���
  QString m_strUser;
  //�������ı������룬�洢���� hash ֵ
  QByteArray m_passwordHash;
};