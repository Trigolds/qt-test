
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

  //��ĸ�����Ϣ
  Q_CLASSINFO("Version", "1.0.0")
  Q_CLASSINFO("Author", "Winland")
  Q_CLASSINFO("Site", "https://lug.ustc.edu.cn/sites/qtguide/")

private:
  Ui::Widget* ui;
};
