
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
  void RecvGenderID(int id); //�����Ա�ѡ��ť�����ź�
  void RecvStatusID(int id); //����״̬��ѡ��ť�����ź�

private slots:
  void is_RB0019_toggled(bool checked);
  void is_RB2039_toggled(bool checked);
  void is_RB4059_toggled(bool checked);
  void is_RB60_toggled(bool checked);
  void is_PB_clicked();

private:
  Ui::Widget* ui;
  //��ť����
  QButtonGroup* m_pGenderGroup;   //�Ա�ѡ��ť����
  QButtonGroup* m_pStatusGroup;   //״̬��ѡ��ť����
};