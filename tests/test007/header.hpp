
#pragma once

#include <QWidget>

namespace Ui {
  class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget* parent = 0);
  ~Widget();

  //�����һ�δ���
public slots:       //�ۺ���������־
  void link_clicked();
  void unlink_clicked();

private:
  Ui::Widget* ui;
};

