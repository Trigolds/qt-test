
#include "Msg.hpp"
#include <QMessageBox>
#include <QDebug>

ShowChanges::ShowChanges(QObject* parent) : QObject(parent)
{

}

ShowChanges::~ShowChanges()
{

}
//���ղ���ӡ value �仯�����ֵ
void ShowChanges::RecvValue(double v)
{
  qDebug() << "RecvValue: " << fixed << v;
}