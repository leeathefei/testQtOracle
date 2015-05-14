#ifndef CUSRMANAGE_H
#define CUSRMANAGE_H

#include <QDialog>
#include "ui_CTitleDlg.h"
#include <QPoint>
#include <QMouseEvent>

class CTitleDlg1 : public QDialog,public Ui::CTitleDlg
{
	Q_OBJECT

public:
	CTitleDlg1(QWidget *parent=0,QWidget *child=0);
	~CTitleDlg1();

private:

	private slots:
		
		void onMaxWindow();

protected:
	//void paintEvent(QPaintEvent * event)
	//{
	//	//����һ��λͼ
	//	QBitmap objBitmap(size()); 
	//	//QPainter������λͼ�ϻ滭
	//	QPainter painter(&objBitmap); 
	//	//���λͼ���ο�(�ð�ɫ���)
	//	painter.fillRect(rect(),Qt::white);
	//	painter.setBrush(QColor(0,0,0)); 
	//	//��λͼ�ϻ�Բ�Ǿ���(�ú�ɫ���)
	//	painter.drawRoundedRect(this->rect(),10,10);
	//	//ʹ��setmask���˼���
	//	setMask(objBitmap);
	//}

	void mousePressEvent(QMouseEvent *event)
	{ 
		if(event->button() == Qt::LeftButton)  
		{  
			dragPosition = event->globalPos() - frameGeometry().topLeft();  

			//QRect rect = ui.titleFrame->frameRect();  
			QRect rect = horizontalLayout->contentsRect(); 
			if(rect.contains(event->pos()))  
			{  
				m_bMoveable = true;  
			}  
			event->accept();  
		}  
	}  

	void mouseMoveEvent(QMouseEvent *event)   
	{        
		if(event->buttons() & Qt::LeftButton && !isMaximized () && m_bMoveable)  
		{  
			move(event->globalPos() - dragPosition);  
			event->accept();  
		}  

	}  

	void mouseReleaseEvent(QMouseEvent *event)   
	{   
		if(m_bMoveable)  
		{  
			m_bMoveable = false;  
		}  
	}

private:    

	QPoint dragPosition;
	bool m_bMoveable;

	
};

#endif // CUSRMANAGE_H
