
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

signals:
  void SendVoid();

  //添加这一段代码
public slots:       //槽函数声明标志

private:
  Ui::Widget* ui;
};

