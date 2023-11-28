
#include <QApplication>
#include <QDebug>
#include "header.hpp"
#include "Msg.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);
  Widget w;   //Դͷ����
  //���ն˶���
  ShowChanges s;
  //����
  QObject::connect(&w, SIGNAL(valueChanged(double)), &s, SLOT(RecvValue(double)));

  //���Զ�д
  //ͨ��д������������
  w.setNickName("Wid");
  qDebug() << w.nickName();
  w.setCount(100);
  qDebug() << w.count();

  //ͨ�� setProperty() ���� �� property() ����
  w.setProperty("value", 2.3456);
  qDebug() << fixed << w.property("value").toDouble();


  // dynamic properties
  //�����̬���Բ����ڣ�QVariant ����� isValid() �������� false������������
  qDebug() << w.property("myValue").isValid();

  //������� myValue
  w.setProperty("myValue", 888);
  //��ȡ����ӡ
  qDebug() << w.property("myValue").toDouble();

  //������� myName
  w.setProperty("myName", "dyName");
  //��ȡ����ӡ
  qDebug() << w.property("myName").toString();

  //��ȡ���ж�̬�������ƣ���ӡ�����б�
  qDebug() << w.dynamicPropertyNames();

  w.show();

  return a.exec();
}
