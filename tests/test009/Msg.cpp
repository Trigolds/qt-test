
#include "Msg.hpp"
#include <QMessageBox>

ShowVoid::ShowVoid(QObject* parent) : QObject(parent)
{

}

ShowVoid::~ShowVoid()
{

}
//²Ûº¯Êý£¬µ¯´°
void ShowVoid::RecvVoid()
{
  QMessageBox::information(NULL, tr("Show"), tr("Just void."));
}