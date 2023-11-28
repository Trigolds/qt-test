
#pragma once

#include <QObject>

class ShowVoid : public QObject
{
  Q_OBJECT
public:
  explicit ShowVoid(QObject* parent = 0);
  ~ShowVoid();

signals:

public slots:
  //接收 SendVoid() 信号的槽函数
  void RecvVoid();
};
