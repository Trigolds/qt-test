
#include <QApplication>
#include <QDebug>
#include "header.hpp"
#include "Msg.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);

  Widget w;
  ShowVoid s;
  QObject::connect(&w, SIGNAL(SendVoid()), &s, SLOT(RecvVoid()));

  w.show();

  return a.exec();
}
