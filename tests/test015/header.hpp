
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

private slots:
  void is_LEMac_textChanged(const QString& arg1);

  void is_LEIP_textChanged(const QString& arg1);

  void is_LEPort_textChanged(const QString& arg1);

private:
  Ui::Widget* ui;
};
