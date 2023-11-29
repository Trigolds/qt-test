
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

  //检查兴趣爱好，同步更新三态复选框的状态
  void CheckHobbies();

private slots:

  void is_CBReading_toggled(bool checked);

  void is_CBHiking_toggled(bool checked);

  void is_CBSwimming_toggled(bool checked);

  void is_CBDazing_toggled(bool checked);

  void is_CBShopping_toggled(bool checked);

  void is_CBEating_toggled(bool checked);

  void is_PB_clicked();

  void is_CLBOpenFolder_clicked();

  void is_CLBOpenPage_clicked();

private:
  Ui::Widget* ui;
};
