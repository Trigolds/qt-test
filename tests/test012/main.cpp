
#include <QApplication>
#include <QDebug>
#include <QMetaClassInfo>
#include "header.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);
  Widget w;

  w.show();

  return a.exec();
}
