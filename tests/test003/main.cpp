
#include <QApplication>
#include <QTextBrowser>
#include <QDebug>


void Test_setNum()
{
  QString strTest;
  //to Hex string
  short numHex = 127;
  strTest.setNum(numHex, 16);
  qDebug() << "Hex: " << strTest;

  //to Oct string
  int numOct = 63;
  strTest.setNum(numOct, 8);
  qDebug() << "Oct: " << strTest;

  //to normal Dec string
  long numDec = 800;
  strTest.setNum(numDec);
  qDebug() << "Normal: " << strTest;

  //to float string
  float numFixed = 123.78999f;
  strTest.setNum(numFixed, 'f', 3);
  qDebug() << "Fixed: " << strTest;

  //to scientific double string
  double numScientific = 456.78999;
  strTest.setNum(numScientific, 'e', 6);
  qDebug() << "Scientific: " << strTest;
}


void Test_arg()
{
  //ʹ�� strResult �洢 arg ���ص��¶���
  QString strResult;

  //Dec
  long numDec = 800;
  QString strMod = QObject::tr("Normal: %1");
  strResult = strMod.arg(numDec);  //%1��ռλ������һ��arg������������ת����ַ�����䵽 %1 λ��
  qDebug() << "Mod: " << strMod << " \t Result: " << strResult;

  //Oct
  int numOct = 63;
  strResult = QObject::tr("Oct: %1").arg(numOct, 4, 8, QChar('0'));  //numOctת����Ϊ4�ַ����8���ƣ����0
  qDebug() << strResult;

  //Hex
  short numHex = 127;
  QString strPrefix = QObject::tr("0x");
  //ռλ����������ֵת���ַ�����Ҳ����ֱ�����ԭ�е��ַ���
  strResult = QObject::tr("Hex: %1%2").arg(strPrefix).arg(numHex, 0, 16);  //��������һ��arg����������䵽%1���ڶ���arg��䵽%2
  qDebug() << strResult;

  //double
  double numReal = 123.78999;
  strResult = QObject::tr("Fixed: %1 \t Scientific: %2").arg(numReal, 0, 'f').arg(numReal, 0, 'e', 3);
  qDebug() << strResult;

  //ռλ�����ظ���Ҳ������
  int one = 1;
  int two = 2;
  int three = 3;
  strResult = QObject::tr("%1 С�� %2��%1 С�� %3��%3 ���� %2 ��").arg(one).arg(two).arg(three);
  qDebug() << strResult;
}

void Test_toValue()
{
  bool bok = false;
  //dec
  QString strDec = QObject::tr("800");
  int nDec = strDec.toInt(&bok, 10);
  qDebug() << nDec << "\t" << bok;       //�ɹ�
  //Hex
  QString strHex = QObject::tr("FFFF");
  nDec = strHex.toInt(&bok, 10);  //��������ת��ʧ��
  qDebug() << nDec << "\t" << bok;

  short nHexShort = strHex.toShort(&bok, 16);
  qDebug() << nHexShort << "\t" << bok; //FFFF������̫�󣬳�����Χ��ת��ʧ�ܣ�û�и��� - �Ķ���������

  ushort nHexUShort = strHex.toUShort(&bok, 16);
  qDebug() << nHexUShort << "\t" << bok;//�ɹ�

  //�Զ�ת��
  QString strOct = QObject::tr("0077");
  int nOct = strOct.toInt(&bok, 0);
  qDebug() << nOct << "\t" << bok;  //�ַ� 0 ��ͷ�Զ����˽���ת

  QString strHexWithPre = QObject::tr("0xFFFF");
  int nHexWithPre = strHexWithPre.toInt(&bok, 0);
  qDebug() << nHexWithPre << "\t" << bok;   //�ַ� 0x ��ͷ�Զ���ʮ������ת

  int nDecAuto = strDec.toInt(&bok, 0);   //"800" ���Զ���ʮ����
  qDebug() << nDecAuto << "\t" << bok;

  //������ת��
  QString strFixed = QObject::tr("123.78999");
  double dblFixed = strFixed.toDouble(&bok);
  qDebug() << fixed << dblFixed << "\t" << bok;
  //��ѧ������
  QString strScientific = QObject::tr("1.238e-5");
  double dblScientific = strScientific.toDouble(&bok);
  qDebug() << scientific << dblScientific << "\t" << bok;
}


void Test_operator()
{
  // =
  QString strE1, strE2, strE3;
  strE1 = QObject::tr("abcd");
  strE2 = strE1;
  strE3 = strE2;
  //��ӡ����ָ��
  qDebug() << strE1.data_ptr() << "\t" << strE2.data_ptr() << "\t" << strE3.data_ptr();
  //�ı��ַ�����׷��
  strE2.append(QObject::tr("1234"));
  //�ٴδ�ӡ����ָ�룬˭�޸������ݣ�˭������ָ��ͱ�
  qDebug() << strE1.data_ptr() << "\t" << strE2.data_ptr() << "\t" << strE3.data_ptr();

  // += �� append ��������
  strE3 += QObject::tr("1234");
  qDebug() << strE2 << "\t" << strE3;

  //�Ƚ� 1 vs 2
  qDebug() << "strE1 < strE2: " << (strE1 < strE2);
  qDebug() << "strE1 <= strE2: " << (strE1 <= strE2);
  qDebug() << "strE1 == strE2: " << (strE1 == strE2);
  qDebug() << "strE1 != strE2: " << (strE1 != strE2);
  //2 vs 3
  qDebug() << "strE2 > strE3" << (strE2 > strE3);
  qDebug() << "strE2 >= strE3" << (strE2 >= strE3);
  qDebug() << "strE2 == strE3" << (strE2 == strE3);

  //��������ȡ��
  qDebug() << strE1[0];
  strE1[0] = QChar('?');  //�޸�
  qDebug() << strE1;

  //ƴ��
  QString strPlus;
  strPlus = strE1 + strE2 + strE3;
  qDebug() << strPlus;
}

void Test_substring()
{
  QString strOne = QObject::tr("abcd");
  QString strThree = strOne.repeated(3); //abcd �ظ�����
  qDebug() << strThree.isEmpty();   //�Ƿ�Ϊ��
  qDebug() << strThree.length() << "\t" << strThree.size(); //���ǳ���
  qDebug() << strThree;

  //�Ӵ���ѯ
  qDebug() << strThree.contains(strOne);    //�Ƿ����
  qDebug() << strThree.count(strOne);       //��������
  qDebug() << strThree.startsWith(strOne);  //��ͷ���Ӵ�
  qDebug() << strThree.indexOf(strOne);     //��߿�ʼ���Ӵ�λ��
  qDebug() << strThree.lastIndexOf(strOne); //�ұ߿�ʼ���Ӵ�λ��

  //�޳����˵Ŀհ�
  QString strComplexFileName = QObject::tr("   /home/user/somefile.txt  \t\t ");
  QString strFileName = strComplexFileName.trimmed();
  qDebug() << strComplexFileName;
  qDebug() << strFileName;
  if (strFileName.endsWith(QObject::tr(".txt")))
  {
    qDebug() << "This is a .txt file";
  }
  //�ָ��Ӵ�
  QStringList subsList = strFileName.split(QChar('/'));
  for (int i = 0; i < subsList.length(); i++)  //��ӡ�����Ӵ�
  {
    qDebug() << i << "\t" << subsList[i];
  }
  //��ȡ����
  QString subsections = strFileName.section(QChar('/'), 2, 3);
  qDebug() << subsections;
}


void Test_QTextStream()
{
  //�ڴ������
  QString strOut;
  QTextStream streamOut(&strOut);
  //��ӡ���ֽ�������
  streamOut << 800 << endl;
  streamOut << hex << 127 << endl;
  streamOut << oct << 63 << endl;
  //��ԭΪʮ����
  streamOut << dec;

  //������������ַ�
  streamOut << qSetFieldWidth(8) << qSetPadChar('0') << 800;
  //��ԭĬ���������
  streamOut << qSetFieldWidth(0) << qSetPadChar(' ') << endl;

  //���þ���
  streamOut << qSetRealNumberPrecision(3) << fixed << 123.789999 << endl;
  streamOut << qSetRealNumberPrecision(6) << scientific << 123.789999 << endl;

  //��ӡ�ַ��������ֻ��
  streamOut << QObject::tr("7*7 == ") << 7 * 7 << endl;
  //��ʾ���ڵ��ַ�������
  qDebug() << strOut;


  //�ڴ�������
  QString strIn = QObject::tr("800  abcd  123.789999");
  QTextStream streamIn(&strIn);
  int numDec = 0;
  QString strSub;
  double dblReal = 0.0;
  //���뵽������
  streamIn >> numDec >> strSub >> dblReal;
  //��ʾ
  qDebug() << numDec;
  qDebug() << strSub;
  qDebug() << fixed << dblReal;   //��������ʾ
}

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);

  qDebug() << "**********************************************\n";
  Test_setNum();
  qDebug() << "**********************************************\n";
  Test_arg();
  qDebug() << "**********************************************\n";
  Test_toValue();
  qDebug() << "**********************************************\n";
  Test_operator();
  qDebug() << "**********************************************\n";
  Test_substring();
  qDebug() << "**********************************************\n";
  Test_QTextStream();

  QString strText = QString::fromLocal8Bit("1234��ӡ����");
  QTextBrowser tb;
  tb.setText(strText);
  tb.setGeometry(40, 40, 400, 300);
  tb.show();

  return a.exec();
}
