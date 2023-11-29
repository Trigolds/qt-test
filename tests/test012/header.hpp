
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

public slots:
  void RecvGenderID(int id); //接收性别单选按钮分组信号
  void RecvStatusID(int id); //接收状态单选按钮分组信号

private slots:
  void is_RB0019_toggled(bool checked);
  void is_RB2039_toggled(bool checked);
  void is_RB4059_toggled(bool checked);
  void is_RB60_toggled(bool checked);
  void is_PB_clicked();

private:
  Ui::Widget* ui;
  //按钮分组
  QButtonGroup* m_pGenderGroup;   //性别单选按钮分组
  QButtonGroup* m_pStatusGroup;   //状态单选按钮分组
};