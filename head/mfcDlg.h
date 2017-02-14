#include "cv.h"
#include "highgui.h"
#include "CvvImage.h"

#define IMAGE_WIDTH 256 
#define IMAGE_HEIGHT 256
#define IMAGE_CHANNELS 3
// mfcDlg.h : ͷ�ļ�
//

#pragma once


// CmfcDlg �Ի���
class CmfcDlg : public CDialogEx
{
// ����
public:
	CmfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	char *buf; 
	IplImage* TheImage;
	IplImage* pGrayImg1;  
	IplImage* pSrcImg; 
	IplImage* pBinaryImg;
	IplImage* clone;
	IplImage* clone1;
	IplImage* clone2;
	IplImage* tempdialte;
	IplImage* tempdialte1;
	IplImage* tempdialte2;
	IplImage* ori1;
	IplImage* ori;
	IplImage* binary;
	IplImage* binary1;





	//char *id;
	IplImage* mat1;
	afx_msg void OnBnClickedReadimg();
	/*void ShowImage(IplImage* img, UINT ID);
	void ResizeImage(IplImage* img);*/
	//void renderScene(void);
	BOOL ShowJpgGif(CDC* pDC,CString strPath, int x, int y);
	BOOL ShowImage(CDC* pDC,CString strPath, int x, int y) ;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton15();
};
