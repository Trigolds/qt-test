
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
  //���� SendVoid() �źŵĲۺ���
  void RecvVoid();
};
