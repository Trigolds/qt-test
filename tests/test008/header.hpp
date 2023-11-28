
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
  void SendMsg(QString str);

  //�����һ�δ���
public slots:       //�ۺ���������־
  void ButtonClicked();

private:
  Ui::Widget* ui;
};

