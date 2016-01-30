#ifndef __VIDEO_VIDCAMADD_H__
#define __VIDEO_VIDCAMADD_H__

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QMimeData>
#include <QDrag>

#define NOMINMAX
#define NOMINMAX 

#include <QWidget>
#include "utility.hpp"
#include <QTimer>
#include <QMovie>
#include <QtWidgets/QMainWindow>
#include "client/clientfactory.hpp"
#include "ui_vidcamadd.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QApplication>

class VidCamTableItem : public QTableWidgetItem
{
public:
	VidCamTableItem(VidCamera &pCam, bool bNew)
	: m_sCam(pCam), m_bNew(bNew)
	{
	}
	~VidCamTableItem(){}
public:
	bool IsNew(){return m_bNew;}
	VidCamera GetCam(){return m_sCam;}
private:
	VidCamera m_sCam;
	bool m_bNew;
};

class VidCamAdd : public QWidget
{
    Q_OBJECT

public:
	VidCamAdd(VidStor &pStor, ClientFactory &pFactory, QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~VidCamAdd();

public:
	void TreeWidgetUpdate();
	void SetCamUI(VidCamera pCam);
	void GetCamUI(VidCamera &pCam);

signals:
	void SignalSectionClicked(int row, int column);

public slots:
	void SlotNewCam();
	void SlotDeleteCam();
	void SlotApplyCam();
	void SlotCancelCam();
	void SlotSectionClicked(int row, int column);
	void SlotRadioButtonClicked();

public:
    Ui::VidCamAdd ui;
private:
	ClientFactory &m_pFactory;
	VidStor m_sStor;

};


#endif // __VIDEO_VIDCAMADD_H__