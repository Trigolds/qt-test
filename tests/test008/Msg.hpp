
#pragma once

#include <QObject>

class ShowMsg : public QObject
{
  Q_OBJECT
public:
  explicit ShowMsg(QObject* parent = 0);
  ~ShowMsg();

signals:

public slots:
  //���� SendMsg �źŵĲۺ���
  void RecvMsg(QString str);
};

