
#pragma once

#include <QObject>

class ShowChanges : public QObject
{
  Q_OBJECT
public:
  explicit ShowChanges(QObject* parent = 0);
  ~ShowChanges();

signals:

public slots:
  //�ۺ��������� value �仯�ź�
  void RecvValue(double v);
};

