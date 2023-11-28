
#include <QtWidgets/qapplication>
#include <QtWidgets/qlabel>

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  QLabel label(QLabel::tr("Hello Qt!"));
  label.show();


  return a.exec();
}
