
#include "Msg.hpp"
#include <QMessageBox>

ShowMsg::ShowMsg(QObject* parent) : QObject(parent)
{

}

ShowMsg::~ShowMsg()
{

}

//str ���Ǵ��ź��﷢�������ַ���
void ShowMsg::RecvMsg(QString str)
{
  QMessageBox::information(NULL, tr("Info"), str);
}