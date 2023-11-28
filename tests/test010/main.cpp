
#include <QApplication>
#include <QDebug>
#include "header.hpp"
#include "Msg.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);
  Widget w;   //源头对象
  //接收端对象
  ShowChanges s;
  //关联
  QObject::connect(&w, SIGNAL(valueChanged(double)), &s, SLOT(RecvValue(double)));

  //属性读写
  //通过写函数、读函数
  w.setNickName("Wid");
  qDebug() << w.nickName();
  w.setCount(100);
  qDebug() << w.count();

  //通过 setProperty() 函数 和 property() 函数
  w.setProperty("value", 2.3456);
  qDebug() << fixed << w.property("value").toDouble();


  // dynamic properties
  //如果动态属性不存在，QVariant 对象的 isValid() 函数返回 false，变量不可用
  qDebug() << w.property("myValue").isValid();

  //添加属性 myValue
  w.setProperty("myValue", 888);
  //获取并打印
  qDebug() << w.property("myValue").toDouble();

  //添加属性 myName
  w.setProperty("myName", "dyName");
  //获取并打印
  qDebug() << w.property("myName").toString();

  //获取所有动态属性名称，打印名称列表
  qDebug() << w.dynamicPropertyNames();

  w.show();

  return a.exec();
}
