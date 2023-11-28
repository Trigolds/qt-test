
#include <QApplication>
#include <QDebug>
#include <QMetaClassInfo>
#include "header.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);
  Widget w;
  //��ȡ��ĸ�����Ϣ
  const QMetaObject* pMO = w.metaObject();
  //������Ϣ����
  int nInfoCount = pMO->classInfoCount();
  //��ӡ���еĸ�����Ϣ
  for (int i = 0; i < nInfoCount; i++)
  {
    QMetaClassInfo info = pMO->classInfo(i);
    qDebug() << info.name() << "\t" << info.value();
  }

  //������Ϣ
  qDebug() << "Class Name: " << pMO->className();
  qDebug() << "Object Name: " << w.objectName();
  //�ж��Ƿ�Ϊ����
  qDebug() << w.inherits("QWidget");
  qDebug() << w.inherits("nothing");

  w.show();

  return a.exec();
}
