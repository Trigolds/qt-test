
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
}

Widget::~Widget()
{
  delete ui;
}

//����������
//��nickName��ֵ
const QString& Widget::nickName()
{
  return m_nickName;
}
//��count��ֵ
int Widget::count()
{
  return m_count;
}

//д����������ֵ�����仯�ǲŷ��ź�
void Widget::setNickName(const QString& strNewName)
{
  if (strNewName == m_nickName)
  {
    //��ֵû�仯��ֱ�ӷ���
    return;
  }
  //�޸���ֵ�������ź�
  m_nickName = strNewName;
  emit nickNameChanged(strNewName);
}

void Widget::setCount(int nNewCount)
{
  if (nNewCount == m_count)
  {
    //��ֵû�仯��ֱ�ӷ���
    return;
  }
  //�޸���ֵ�������ź�
  m_count = nNewCount;
  emit countChanged(nNewCount);
}