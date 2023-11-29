
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //�½��Ա�������飬����Ӱ�ť��id
  m_pGenderGroup = new QButtonGroup(this);
  m_pGenderGroup->addButton(ui->RBMan, 0);   //��
  m_pGenderGroup->addButton(ui->RBWoman, 1); //Ů

  //�½�״̬������飬����Ӱ�ť��id
  m_pStatusGroup = new QButtonGroup(this);
  //��ͬ����� id ���޹صģ�����ͻ
  m_pStatusGroup->addButton(ui->RBGood, 0);  //������
  m_pStatusGroup->addButton(ui->RBNormal, 1);  //������
  m_pStatusGroup->addButton(ui->RBAwful, 2);   //�ó�ҩ��

  // Init
  ui->RBMan->setChecked(true);
  ui->RBNormal->setChecked(true);
  ui->RB0019->setChecked(true);

  //��������������źźͲ�
  connect(m_pGenderGroup, SIGNAL(buttonClicked(int)), this, SLOT(RecvGenderID(int)));
  connect(m_pStatusGroup, SIGNAL(buttonClicked(int)), this, SLOT(RecvStatusID(int)));

  connect(ui->RB0019, SIGNAL(toggled(bool)), this, SLOT(is_RB0019_toggled(bool)));
  connect(ui->RB2039, SIGNAL(toggled(bool)), this, SLOT(is_RB2039_toggled(bool)));
  connect(ui->RB4059, SIGNAL(toggled(bool)), this, SLOT(is_RB4059_toggled(bool)));
  connect(ui->RB60, SIGNAL(toggled(bool)), this, SLOT(is_RB60_toggled(bool)));
  connect(ui->PBShow, SIGNAL(clicked()), this, SLOT(is_PB_clicked()));
}

Widget::~Widget()
{
  delete ui;
}

//�����Ա�����id
void Widget::RecvGenderID(int id)
{
  switch (id) {
  case 0:
    qDebug() << tr("Sex : Man");
    break;
  case 1:
    qDebug() << tr("Sex : Woman");
    break;
  default:
    break;
  }
}
//����״̬�����id
void Widget::RecvStatusID(int id)
{
  switch (id) {
  case 0:
    qDebug() << tr("Status : Good");
    break;
  case 1:
    qDebug() << tr("Status : Normal");
    break;
  case 2:
    qDebug() << tr("Status : Awful");
    break;
  default:
    break;
  }
}
//����� 0-19
void Widget::is_RB0019_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Age 0-19");
  }
  else
  {
    qDebug() << tr("Not 0-19");
  }
}
//����� 20-39
void Widget::is_RB2039_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Age 20-39");
  }
  else
  {
    qDebug() << tr("Not 20-39");
  }
}
//����� 40-59
void Widget::is_RB4059_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Age 40-59");
  }
  else
  {
    qDebug() << tr("Not 40-59");
  }
}
//����� 60 ����
void Widget::is_RB60_toggled(bool checked)
{
  if (checked)
  {
    qDebug() << tr("Age >60");
  }
  else
  {
    qDebug() << tr("Not >60");
  }
}

//�ڵ�ѡ��ť�źŶ�Ӧ�Ĳۺ���֮�⣬����ȡ��ѡ��ť��״̬
void Widget::is_PB_clicked()
{
  //����ַ���
  QString strResult;

  //�Ա����
  int nGenderID = m_pGenderGroup->checkedId();    //��ȡ��ѡ�е� id
  switch (nGenderID) {
  case 0:
    strResult += tr("Sex : Man\r\n");
    break;
  case 1:
    strResult += tr("Sex : Woman\r\n");
    break;
  default:
    strResult += tr("Sex : Unselected\r\n");
    break;
  }

  //״̬����
  int nStatusID = m_pStatusGroup->checkedId();    //��ȡ��ѡ�е� id
  switch (nStatusID) {
  case 0:
    strResult += tr("Status : Good\r\n");
    break;
  case 1:
    strResult += tr("Status : Normal\r\n");
    break;
  case 2:
    strResult += tr("Status : Awful\r\n");
    break;
  default:
    strResult += tr("Status : Unselected\r\n");
    break;
  }

  //������ĸ���ť�ж�
  if (ui->RB0019->isChecked())
  {
    strResult += tr("Age : 0-19\r\n");
  }
  else if (ui->RB2039->isChecked())
  {
    strResult += tr("Age : 20-39\r\n");
  }
  else if (ui->RB4059->isChecked())
  {
    strResult += tr("Age : 40-59\r\n");
  }
  else if (ui->RB60->isChecked())
  {
    strResult += tr("Age : >60\r\n");
  }
  else
  {
    strResult += tr("Age : Unselected\r\n");
  }

  //strResult ��ȡ��Ϣ��ϣ�������ʾ
  QMessageBox::information(this, tr("Info"), strResult);
}