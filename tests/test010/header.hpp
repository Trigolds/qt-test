
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

  //��������
  //��ֱ�ӱ����Ա��������ʽ
  Q_PROPERTY(QString nickName READ nickName WRITE setNickName NOTIFY nickNameChanged)
  //ֱ�ӱ����Ա��������ʽ
  Q_PROPERTY(int count MEMBER m_count READ count WRITE setCount NOTIFY countChanged)
  //�����Ա����������ʡ�Զ�д����
  Q_PROPERTY(double value MEMBER m_value NOTIFY valueChanged)
  //nickName����������
  const QString& nickName();
  //count������
  int count();

  //value��������ʱ��ָ���˳�Ա������ʡ���˶�д���������Ķ�д������moc�����Զ�����
  //value��ֵ���޸�ʱ��valueChanged�źŻ��Զ�����
  //�Զ����ɵĶ�д����ֻ�м򵥵Ķ�д���ܣ���������ֵ��Ч�Լ��

signals:
  //����������ֵ�仯ʱ���ź�
  void nickNameChanged(const QString& strNewName);
  void countChanged(int nNewCount);
  void valueChanged(double dblNewValue);

public slots:
  //д����ͨ��������Ϊ�ۺ����������������źŹ������Զ�������ֵ
  //nickNameд��������
  void setNickName(const QString& strNewName);
  //countд��������
  void setCount(int nNewCount);
  //valueд������ moc �Զ����ɣ�û��д����

private:
  Ui::Widget* ui;
  //����˽�б�������Ӧ����������
  QString m_nickName;
  int m_count;
  double m_value;
};

