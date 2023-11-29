
#include "header.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  //新建性别虚拟分组，并添加按钮和id
  m_pGenderGroup = new QButtonGroup(this);
  m_pGenderGroup->addButton(ui->RBMan, 0);   //男
  m_pGenderGroup->addButton(ui->RBWoman, 1); //女

  //新建状态虚拟分组，并添加按钮和id
  m_pStatusGroup = new QButtonGroup(this);
  //不同分组的 id 是无关的，不冲突
  m_pStatusGroup->addButton(ui->RBGood, 0);  //棒棒哒
  m_pStatusGroup->addButton(ui->RBNormal, 1);  //萌萌哒
  m_pStatusGroup->addButton(ui->RBAwful, 2);   //该吃药了

  // Init
  ui->RBMan->setChecked(true);
  ui->RBNormal->setChecked(true);
  ui->RB0019->setChecked(true);

  //关联两个分组的信号和槽
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

//接收性别分组的id
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
//接收状态分组的id
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
//年龄段 0-19
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
//年龄段 20-39
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
//年龄段 40-59
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
//年龄段 60 以上
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

//在单选按钮信号对应的槽函数之外，来获取单选按钮的状态
void Widget::is_PB_clicked()
{
  //结果字符串
  QString strResult;

  //性别分组
  int nGenderID = m_pGenderGroup->checkedId();    //获取被选中的 id
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

  //状态分组
  int nStatusID = m_pStatusGroup->checkedId();    //获取被选中的 id
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

  //年龄段四个按钮判断
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

  //strResult 获取信息完毕，弹窗显示
  QMessageBox::information(this, tr("Info"), strResult);
}