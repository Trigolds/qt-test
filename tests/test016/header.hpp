
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

  void is_CBGender_currentIndexChanged(int index);

  void is_CBJob_currentTextChanged(const QString& arg1);

  void is_dateEdit_dateChanged(const QDate& date);

  void is_PB_clicked();

private:
  Ui::Widget* ui;
};
