
#include <QApplication>
#include "header.hpp"

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);
  HelloWidget hw;
  hw.setWindowTitle("Test Title");
  hw.show();

  return a.exec();
}
