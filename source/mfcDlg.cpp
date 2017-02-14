
// mfcDlg.cpp : 实现文件
//
#include<Windows.h>
#include <opencv/cv.h>  
#include <opencv/cxcore.h>  
#include <opencv/highgui.h>  
#include <iostream>
#include <algorithm>
#include <vector>
#include<string.h>
#include "stdafx.h"
#include "mfc.h"
#include "mfcDlg.h"
#include "afxdialogex.h"
#include"iostream"
#include "winsock.h" 
#include "mysql.h" 
#pragma comment(lib,"libmysql.lib") 
using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcDlg 对话框



char id[100];
CmfcDlg::CmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcDlg::IDD, pParent)
	, TheImage(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CmfcDlg::OnBnClickedReadimg)
	ON_BN_CLICKED(IDC_BUTTON2, &CmfcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmfcDlg::OnBnClickedButton3)

	ON_BN_CLICKED(IDC_BUTTON5, &CmfcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CmfcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CmfcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON7, &CmfcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CmfcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CmfcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON4, &CmfcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON11, &CmfcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CmfcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CmfcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CmfcDlg::OnBnClickedButton13)
	/*ON_BN_CLICKED(IDC_BUTTON15, &CmfcDlg::OnBnClickedButton15)*/
END_MESSAGE_MAP()


// CmfcDlg 消息处理程序
BOOL CmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	 CvSize ImgSize;      
	 ImgSize.height = IMAGE_HEIGHT;    
	 ImgSize.width = IMAGE_WIDTH;     
	 TheImage = cvCreateImage( ImgSize, IPL_DEPTH_8U, IMAGE_CHANNELS );
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint(); 
		CDialog::UpdateWindow();
		//ShowImage( TheImage, IDC_ShowImg ); 
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcDlg::OnBnClickedReadimg()
{
	
    CFileDialog dlg(TRUE,"jpg","*.jpg", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,   
        "JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp|",NULL);   
    if(dlg.DoModal()==IDOK)   
    {   
        //SetDlgItemText(IDC_TXT_PATH,dlg.GetPathName());  
  
        //设置静态控件的样式，使其可以使用位图，并使位图显示居中  
        ((CStatic*)GetDlgItem(IDC_STATIC_IMG))-> ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);  
  
        CDC *pDC=NULL;  
        pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC();  
		s=dlg.GetPathName();
        //ShowJpgGif(pDC,dlg.GetPathName(),0,0);  
        ShowImage(pDC,s,0,0);  
  
        ReleaseDC(pDC); // 记得释放资源，不然会导致内存泄露  
    } 



}




//************************************  
// 方法说明:    显示JPG和GIF、BMP图片  
// 参数说明:    CDC * pDC           设备环境对象  
// 参数说明:    CString strPath     要显示的图片路径   
// 参数说明:    int x               要显示的X位置  
// 参数说明:    int y               要显示的Y位置  
// 返回值:      BOOL                成功返回TRUE,否则返回FALSE  
//************************************  
BOOL CmfcDlg::ShowJpgGif(CDC* pDC,CString strPath, int x, int y)  
  
{  
    CFileStatus fstatus;    
    CFile file;    
    ULONGLONG cb;    
  
    // 打开文件并检测文件的有效性  
     if (!file.Open(strPath,CFile::modeRead))  
     {  
         return FALSE;  
     }  
     if (!file.GetStatus(strPath,fstatus))  
     {  
         return FALSE;  
     }  
     if ((cb =fstatus.m_size)<=0)  
     {  
         return FALSE;  
     }  
  
     // 根据文件大小分配内存空间,记得释放内存  
     HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (unsigned int)cb);    
      if (hGlobal== NULL)   
      {  
          return FALSE;  
      }  
  
      // 锁定刚才分配的内存空间  
      LPVOID pvData = NULL;    
      pvData = GlobalLock(hGlobal);  
      if (pvData == NULL)    
      {    
            GlobalFree(hGlobal);  // 记得释放内存  
            return FALSE;  
      }   
  
      // 将文件放到流中  
      IStream *pStm;    
      file.Read(pvData,(unsigned int)cb);    
      GlobalUnlock(hGlobal);    
      CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);    
   
    // 从流中加载图片  
    // 显示JPEG和GIF格式的图片，GIF只能显示一帧，还不能显示动画，  
    // 要显示动画GIF请使用ACTIVE控件。  
    IPicture *pPic;   
    if(OleLoadPicture(pStm,(LONG)fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)!=S_OK)   
    {   
        GlobalFree(hGlobal);  // 记得释放内存  
        return FALSE;  
    }  
  
    //获取图像宽和高,注意这里的宽和高不是图像的分辨率  
    OLE_XSIZE_HIMETRIC hmWidth;    
    OLE_YSIZE_HIMETRIC hmHeight;    
    pPic->get_Width(&hmWidth);    
    pPic->get_Height(&hmHeight);    
  
    // 将图像宽度和高度单位转化为像素单位  
   //#define HIMETRIC_PER_INCH 2540  
   //int nPicWidth =  MulDiv(hmWidth, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSX),2540);  
   //int nPicHeight = MulDiv(hmHeight, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSY),2540);  
  
     
    //HRESULT Render(  
    //    HDC hdc, //Handle of device context on which to render the image  
    //    long x,  //Horizontal position of image in hdc  
    //    long y,  //Vertical position of image in hdc  
    //    long cx, //Horizontal dimension of destination rectangle  
    //    long cy, //Vertical dimension of destination rectangle  
    //    OLE_XPOS_HIMETRIC xSrc,      //Horizontal offset in source picture  
    //    OLE_YPOS_HIMETRIC ySrc,      //Vertical offset in source picture  
    //    OLE_XSIZE_HIMETRIC cxSrc,    //Amount to copy horizontally in source picture  
    //    OLE_YSIZE_HIMETRIC cySrc,    //Amount to copy vertically in source picture  
    //    LPCRECT prcWBounds           //Pointer to position of destination for a metafile hdc  
    //    );  
  
    //use render function display image  
    RECT rtWnd;  
    pDC->GetWindow()->GetWindowRect(&rtWnd);  
    int iWndWidth=rtWnd.right-rtWnd.left;  
    int iWndHeight=rtWnd.bottom-rtWnd.top;  
      
    if(FAILED(pPic->Render(*pDC,x,y,iWndWidth,iWndHeight,0,hmHeight,hmWidth,-hmHeight,NULL)))    
    {  
        pPic->Release();  
        GlobalFree(hGlobal);  // 记得释放内存  
        return false;  
    }  
  
    pPic->Release();   
    GlobalFree(hGlobal);  // 记得释放内存  
    return true;  
}  

BOOL CmfcDlg::ShowImage(CDC* pDC,CString strPath, int x, int y)  
{  
     
    IPicture *pPic=NULL;   
    OleLoadPicturePath(CComBSTR(strPath.GetBuffer()), (LPUNKNOWN)NULL, 0, 0, IID_IPicture,(LPVOID*)&pPic);  
    if (NULL==pPic)  
    {  
        return FALSE;  
    }  
  
    // 获取图像宽和高,注意这里的宽和高不是图像的分辨率  
    OLE_XSIZE_HIMETRIC hmWidth;    
    OLE_YSIZE_HIMETRIC hmHeight;    
    pPic->get_Width(&hmWidth);    
    pPic->get_Height(&hmHeight);    
  
    // 将图像宽度和高度单位转化为像素单位  
   //#define HIMETRIC_PER_INCH 2540  
   //int nPicWidth =  MulDiv(hmWidth, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSX),2540);  
   //int nPicHeight = MulDiv(hmHeight, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSY),2540);  
  
   // 获取显示图片窗口的宽度和高度  
   RECT rtWnd;  
   pDC->GetWindow()->GetWindowRect(&rtWnd);  
   int iWndWidth=rtWnd.right-rtWnd.left;  
   int iWndHeight=rtWnd.bottom-rtWnd.top;  
  
   if(FAILED(pPic->Render(*pDC,x,y,iWndWidth,iWndHeight,0,hmHeight,hmWidth,-hmHeight,NULL)))    
   {  
       pPic->Release();  
       return false;  
   }  
  
   //记得释放资源，不然会导致内存泄露  
   pPic->Release();   
     
   return true;  
}  


char*st(IplImage*pBinaryImg,IplImage*pBinaryImg1)
{
	struct ddd {
		int x,y;
		bool operator< (const ddd& d) const{
			return x < d.x;
		}
	};
		CvSeq* contours = NULL;  
        CvMemStorage* storage = cvCreateMemStorage(0);  
	    int count = cvFindContours(pBinaryImg, storage, &contours,sizeof(CvContour),CV_RETR_EXTERNAL);  
        //printf("轮廓个数：%d\n",count); 
		char szName[56] = {0};  
		int idx = 0;  
    
		int tempCount=0;  
		IplImage *pNumberTemplate=NULL;
		
		std::vector<ddd> res;
		 ddd d;
			int max=0;
			int maxi;
			char strtab[] = {'0','1','2','3','4','5','6','7','8','9','10'};
			char filename[] = "0.bmp";

		 for (CvSeq* c = contours; c != NULL; c = c->h_next) 
		 {  
			 IplImage*pCheckImage=NULL;
			
			 
			

            CvRect rc =cvBoundingRect(c,0);                                                                                                                

			cvDrawRect(pBinaryImg, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(255, 0, 0));  
			IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 1);   
			//printf("%d\n",rc.x);
			d.x = rc.x;
			//cvErode(pBinaryImg1,pBinaryImg1);
			
			cvSetImageROI(pBinaryImg1, rc);  
			//cvErode(pBinaryImg1,pBinaryImg1);
			cvCopyImage(pBinaryImg1, imgNo);  
			IplImage* test1=cvCreateImage(cvGetSize(imgNo),imgNo->depth,imgNo->nChannels);
			cvCopy(imgNo,test1,NULL);
			pCheckImage=cvCreateImage(cvSize(40,80),imgNo->depth,imgNo->nChannels);
			cvResize(test1,pCheckImage,CV_INTER_LINEAR);
			cvResetImageROI(pBinaryImg1);   //释放给定图像区域
			//sprintf(szName, "wnd_%d", idx++);   
			//cvNamedWindow(szName);   
			//cvSmooth(pCheckImage,pCheckImage,CV_GAUSSIAN,3,3,0,0);
			//cvShowImage(szName, pCheckImage);
			//cvSmooth(imgNo,imgNo,CV_GAUSSIAN,3,3,0,0);
			CvScalar s;
				max = 0;
			for(int k=0;k<=10;k++)
			{
				filename[0] = strtab[k];
				int count = 0;
				//cvReleaseImage(&pNumberTemplate);
				pNumberTemplate=cvLoadImage(filename,1);
				for (int j=0;j<pNumberTemplate->height;j++)
				{
			
					for (int i=0;i<pNumberTemplate->width;i++)
					{
						 if(cvGet2D(pNumberTemplate,j,i).val[0] ==  cvGet2D(pCheckImage,j,i).val[0]) 
							 count ++;
					}
				}
				if(count > max){
					maxi = k;
					max = count;
				}


			}

			//printf("%d\n",maxi);
			d.y = maxi;
			//printf("%d\n",max);
			res.push_back(d);
			//cvShowImage(szName, imgNo);   
			//cvReleaseImage(&imgNo); 
		 }
		 char temp[100];
		 int q=0;
		 //string temp;
		 std::sort(res.begin(),res.end());
		 for(vector<ddd>::iterator it = res.begin();it != res.end();it++){
			//printf("%c",strtab[it->y]);
			 temp[q]=strtab[it->y];
			 q++;
		 }
		 //cout<<temp;
		 temp[q]='\0';
		 strcpy(id,temp);
		 return temp;

		 //printf("%s",temp);
}


void OnRevise(IplImage* pGrayImg)
{
    
    CvScalar s,s_new;
    double num=0;
    double leftaverage=0;
    double rightaverage=0;
    int iHeight=pGrayImg->height;
    int iWidth=pGrayImg->width;
    double slope=0;
    int pix_new;
    //计算前半部分斜率
    for(int ht=0;ht<iHeight;ht++)
    {
        for(int wt=0;wt<iWidth/2;wt++)
        {
            s=cvGet2D(pGrayImg,ht,wt);
            if(0==s.val[0])
            {
                num+=iWidth/2-wt;
                leftaverage+=ht*(iWidth/2-wt);
            }
        }
    }
    leftaverage/=num;
    num=0;
    //计算后半部分斜率
    for(int ht=0;ht<iHeight;ht++)
    {
        for(int wt=iWidth/2;wt<iWidth;wt++)
        {
            s=cvGet2D(pGrayImg,ht,wt);
            if(0==s.val[0])
            {
                num+=iWidth-wt;
                rightaverage+=ht*(iWidth-wt);
            }
        }
    }
    rightaverage/=num;
    slope=(rightaverage-leftaverage)/ (iWidth/2);
    //图像映射
    for(int ht=0;ht<iHeight;ht++)
    {
        for(int wt=0;wt<iWidth;wt++)
        {
            pix_new=(ht-(wt-iWidth/2)*slope);
            s=cvGet2D(pGrayImg,ht,wt);
            
            if(pix_new<=0||iHeight<=pix_new)
            {
                
                s.val[0]=255;
                cvSet2D(pGrayImg,ht,wt,s);
            }
            else
            {
                s_new=cvGet2D(pGrayImg,pix_new,wt);
                s_new.val[0]=s.val[0];
                cvSet2D(pGrayImg,pix_new,wt,s_new);

            }
            
        }

    }


}

int otsuThreshold(IplImage *frame)  
{  
	
	 const int GrayScale = 256;
	 int width = frame->width;  
	 int height = frame->height;  
	 int pixelCount[GrayScale];  
	 float pixelPro[GrayScale];  
	 int i, j, pixelSum = width * height, threshold = 0;  
	 uchar* data = (uchar*)frame->imageData;  //指向像素数据的指针

	 for(i = 0; i < GrayScale; i++)  
	 {  
	  pixelCount[i] = 0;  
	  pixelPro[i] = 0;  
	 }  
 
	 //统计灰度级中每个像素在整幅图像中的个数  
	 for(i = 0; i < height; i++)  
	 {  
	  for(j = 0;j < width;j++)  
	  {  
	   pixelCount[(int)data[i * width + j]]++;  //将像素值作为计数数组的下标
	  }  
	 }  
 
	 //计算每个像素在整幅图像中的比例  
	 float maxPro = 0.0;
	 int kk=0;
	 for(i = 0; i < GrayScale; i++)  
	 {  
	  pixelPro[i] = (float)pixelCount[i] / pixelSum;  
	  if( pixelPro[i] > maxPro )
	  {
	   maxPro = pixelPro[i];
	   kk = i;
	  }
	 }  


	 //遍历灰度级[0,255]  
	 float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;  
	 for(i = 0; i < GrayScale; i++)     // i作为阈值
	 {  
	  w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;  
	  for(j = 0; j < GrayScale; j++)  
	  {  
	   if(j <= i)   //背景部分  
	   {  
		w0 += pixelPro[j];  
		u0tmp += j * pixelPro[j];  
	   }  
	   else   //前景部分  
	   {  
		w1 += pixelPro[j];  
		u1tmp += j * pixelPro[j];  
	   }  
	  }  
	  u0 = u0tmp / w0;  
	  u1 = u1tmp / w1;  
	  u = u0tmp + u1tmp;  
	  deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);  
	  if(deltaTmp > deltaMax)  
	  {  
	   deltaMax = deltaTmp;  
	   threshold = i;  
	  }  
	 }  
 
 return threshold;  
} 



void CmfcDlg::OnBnClickedButton2()
{
	
	 /*CDC* pDC = this->GetDC();
	 char buffer[]=("dsadasdqwdqwd");
	 
	 pDC->TextOut(100,100, buffer, sizeof(buffer)-1);
	 this->ReleaseDC(pDC);*/

	 /*CString str;
	 str="可是你并不在意!";
	 pDC->TextOut(100,130,str);*/

	 //this->ReleaseDC(pDC);
	/*
	 CDC* pDC = this->GetDC();
	 char buffer[] = "123445675675675678";
	 pDC->TextOut(400,300, buffer, sizeof(buffer)-1);*/
/*
	 CString str;
	 str="可是你并不在意!";
	 pDC->TextOut(100,130,str);*/

	/* this->ReleaseDC(pDC);*/
		IplImage* test;
		IplImage* img;

		IplImage* pSrcImg=NULL;  
		IplImage* pGrayImg=NULL;  
		IplImage* pBinaryImg=NULL;

		IplImage* timgID1=NULL;
	 
	    
		buf = (LPSTR)(LPCTSTR)s;
	
	   //pSrcImg=cvLoadImage(buf,1); 
    //   pGrayImg= cvCreateImage(cvGetSize(pSrcImg), IPL_DEPTH_8U, 1); 
	   //pBinaryImg=cvCreateImage(cvGetSize(pGrayImg), IPL_DEPTH_8U, 1);
    //   cvCvtColor(pSrcImg,pGrayImg,CV_RGB2GRAY); 
	   //int threshold =  otsuThreshold(pGrayImg);  
	   //OnRevise(pSrcImg); //倾斜矫正；
	   //cvThreshold(pGrayImg,pBinaryImg, threshold, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
	   IplImage* pBinaryImg1=cvCreateImage(cvGetSize(binary),IPL_DEPTH_8U, 1);
	   cvCopy(binary,pBinaryImg1,NULL);
	 
	   /*timgID1=cvCloneImage(pBinaryImg);

	   cvSetImageROI(timgID1,cvRect(220,320,380,50));*/
	   //cvSaveImage("gg.jpg",timgID1);


	  
	   IplImage* timgID=cvCreateImage(cvGetSize(pBinaryImg1),IPL_DEPTH_8U, 1);
	   cvCopy(pBinaryImg1,timgID,NULL);
	 
	   CDC* pDC = this->GetDC();
 TextOut(pDC->GetSafeHdc(),540,300,st(pBinaryImg1,timgID),18);
	
	 
	 //pDC->TextOut(100,100, st(timgID1,timgID), sizeof(st(timgID1,timgID))-1);
	 this->ReleaseDC(pDC);
	 
	  /* char *buffer = st(timgID1,timgID);*/
	  
	  
	   
  
  
       
       //cvSaveImage("Gray_Image.jpg",pGrayImg);  
 
       
       /*while(true)  
           if(cvWaitKey(100)==27)  
               break;  */
  
        
      /* cvDestroyWindow("原图像");  
       cvDestroyWindow("灰度图像");  
       cvDestroyWindow("二值化图像");  */
  
        
       cvReleaseImage(&pSrcImg);  
       cvReleaseImage(&pGrayImg);  
       cvReleaseImage(&pBinaryImg);  
	
        
	
    
		

}


void CmfcDlg::OnBnClickedButton3()
{
	/* CDC* pDC = this->GetDC();
	 char buffer[] = "123445675675675678";
	 pDC->TextOut(400,300, buffer, sizeof(buffer)-1);
	 this->ReleaseDC(pDC);*/
	MYSQL mysql;
	MYSQL_RES *res;    MYSQL_ROW row;    char *query;     int t,r;
	
	//char*age="dsa";
	//query="insert into t1(id,name)values(3,'"+b+)";
	mysql_init(&mysql);  
	

// localhost:服务器 root为账号密码 test为数据库名 3306为端口  
if(!mysql_real_connect(&mysql,"localhost","root","123","mysql",3306,NULL,0))     {  
AfxMessageBox(_T("数据库连接失败!"));
}
else
{
		char sql_insert[1000];
 
		  sprintf(sql_insert, "INSERT INTO test(id,address) values('%s','%s');",id,buf );
 
		  t=mysql_query(&mysql, sql_insert);
	  
	//t=mysql_real_query(&mysql,query,(unsigned int)strlen(query));
	//AfxMessageBox(_T("数据库连接成功!"));
	
		if(t)
		{
	
			AfxMessageBox(_T("失败!"));
		}
		else
		{
			
		  AfxMessageBox(_T("存储成功!"));

		}

		//else
		//{

		//	AfxMessageBox(_T("数据库连接成功!"));

		//}

	
}
mysql_close(&mysql);



	
}

void rotateImagei(IplImage* img, IplImage *img_rotate,int degree)  
{  
    //旋转中心为图像中心  
    CvPoint2D32f center;    
    center.x=float (img->width/2.0+0.5);  
    center.y=float (img->height/2.0+0.5);  
    //计算二维旋转的仿射变换矩阵  
    float m[6];              
    CvMat M = cvMat( 2, 3, CV_32F, m );  
    cv2DRotationMatrix( center, degree,1, &M);  
    //变换图像，并用黑色填充其余值  
    cvWarpAffine(img,img_rotate, &M,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS,cvScalarAll(0) );  
}  



	


//if(!mysql_real_connect(&mysql,"localhost","root","123","mysql",3306,NULL,0))     {  
//AfxMessageBox(_T("数据库连接失败!"));
//}
//else
//{
//	  char sql_select[1000];
//	  //char *sql="select passwd from user_info where user_id='account'";
// 
//      //sprintf(sql_select, "INSERT INTO test(id,address) values('%s','%s');",id,buf );
//	  sprintf(sql_select, "select address from test where id='%s'","430523197603204314" );
// 
// 
//      t=mysql_query(&mysql, sql_select);
//	  result = mysql_store_result(&mysql);
//	  if(result==NULL)
//	  {
//		  AfxMessageBox(_T("失败!"));
//
//	  }
//	 
//	  if(row=mysql_fetch_row(result))
//	  {
//		  //char buff[18];
//		 
//		  //printf("%s",row[0]);
//		  
//		   //strcpy(buff,row[0]);
//		   /* CDC* pDC = this->GetDC();*/
//			int count=sizeof(row[1]);
//			IplImage*pSrcImg=NULL;
//			pSrcImg=cvLoadImage(row[1],1); 
//			 cvShowImage("二值图像",pSrcImg);
//
// /*TextOut(pDC->GetSafeHdc(),430,200,row[1],count);
//		  result=0;*/
//	  }
//	  mysql_free_result(result);
//
//	
//}
//mysql_close(&mysql);
//
//}


void CmfcDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	   /* IplImage* pGrayImg1=NULL;  
	    IplImage* pSrcImg=NULL; */
	    pSrcImg=cvLoadImage(/*"F:\\opencv\\test\\mfc\\mfc\\ID9.jpg"*/s,1); 
		//cvShowImage(" pSrcImg",pSrcImg);
		pGrayImg1= cvCreateImage(cvGetSize(pSrcImg), IPL_DEPTH_8U, 1);
		ori= cvCreateImage(cvGetSize(pSrcImg), IPL_DEPTH_8U, 3);
		ori1= cvCreateImage(cvGetSize(pSrcImg), IPL_DEPTH_8U, 3);
		//cvSaveImage("src",ori1);
		 cvCopy(pSrcImg,ori,NULL);
		 cvCopy(pSrcImg,ori1,NULL);
		 cvCvtColor(pSrcImg,pGrayImg1,CV_RGB2GRAY); 
		//cvShowImage("pGrayImg1",pGrayImg1);
		cvSaveImage(s,pGrayImg1);
	    CDC *pDC=NULL;  
        pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
		ShowImage(pDC,/*"F:\\opencv\\test\\mfc\\mfc\\pGrayImg.jpg"*/s,0,0); 
}


void CmfcDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	   
	   pBinaryImg=cvCreateImage(cvGetSize(pGrayImg1), IPL_DEPTH_8U, 1);
	   int threshold =  otsuThreshold(pGrayImg1);  
	   OnRevise(pSrcImg); //倾斜矫正；
	   cvThreshold(pGrayImg1,pBinaryImg, threshold, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
	   	 binary=cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1);
		  cvCopy(pBinaryImg,binary,NULL);

	   cvSaveImage(s,pBinaryImg);
	    CDC *pDC=NULL;  
        pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
		ShowImage(pDC,s,0,0); 

}


void CmfcDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	   //IplImage* rotate=cvCreateImage(cvGetSize(pBinaryImg),IPL_DEPTH_8U, 1);
	   IplImage* temp;
	   temp=cvCloneImage(pBinaryImg);
	   cvSetImageROI(temp,cvRect(220,320,380,50));
	   int b= cvCountNonZero( temp );
	   printf("%d\n",b);
	   if(b<1500)
	   {
		    rotateImagei(pBinaryImg, pBinaryImg,180);
			cvSaveImage(s,pBinaryImg);
			CDC *pDC=NULL;  
			pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
			ShowImage(pDC,s,0,0); 
			AfxMessageBox(_T("已矫正!"));

	   }
	   //cvShowImage("旋转图像",pBinaryImg);
	   else
	   {
			cvSaveImage(s,pBinaryImg);
			CDC *pDC=NULL;  
			pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
			ShowImage(pDC,s,0,0); 
			AfxMessageBox(_T("无须矫正!"));
	   }
	  

}


void CmfcDlg::OnBnClickedButton7()
{
	cvSmooth(pBinaryImg,pBinaryImg,CV_BLUR,3,3,0,0); 
	CDC *pDC=NULL;  
	pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
	ShowImage(pDC,s,0,0); 

	// TODO: 在此添加控件通知处理程序代码

}


void CmfcDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	 
	clone = cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1);  
	 cvCopy(pBinaryImg,clone,NULL);
	// cvShowImage("二值图像2",dialate);
	 cvDilate(pBinaryImg,pBinaryImg,0,2);
	 tempdialte=cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1);
	  tempdialte1=cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1);
	  tempdialte2=cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1);
	  cvCopy(pBinaryImg,tempdialte,NULL);
	  cvCopy(pBinaryImg,tempdialte1,NULL);
	  cvCopy(pBinaryImg,tempdialte2,NULL);

	  //cvShowImage("二值图像2",pBinaryImg);
	 cvSaveImage(s,pBinaryImg);
	  
	  clone2=cvCreateImage(cvGetSize(pBinaryImg), IPL_DEPTH_8U, 1); 
	 cvCopy(pBinaryImg,clone2,NULL);
	 CDC *pDC=NULL;  
	pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
	ShowImage(pDC,s,0,0); 
	
}


void CmfcDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	
    clone1=cvCreateImage(cvGetSize(clone), IPL_DEPTH_8U, 1); 
	 cvCopy(clone,clone1,NULL);
	
	 
	 // cvShowImage("二值图像2",clone2);

    CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0);   
	  //cvShowImage("ThresholdImg",img_gray);
    int count = cvFindContours(clone2, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
    //cvReleaseMemStorage(& storage);   
    //printf("轮廓个数：%d",count);  
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(pBinaryImg, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(220,150, 220));  
		
	}
	cvSaveImage(s,pBinaryImg);
	 CDC *pDC=NULL;  
	pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
	ShowImage(pDC,s,0,0); 


}


void CmfcDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	 clone1=cvCreateImage(cvGetSize(clone), IPL_DEPTH_8U, 1); 
	 cvCopy(clone,clone1,NULL);
	
	 
	 // cvShowImage("二值图像2",clone2);

    CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0);   
	 IplImage* temp = cvCreateImage(cvGetSize(tempdialte), IPL_DEPTH_8U, 1);  
	 cvCopy(tempdialte,temp,NULL);

	  //cvShowImage("ThresholdImg",img_gray);
    int count = cvFindContours(tempdialte, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
    //cvReleaseMemStorage(& storage);   
    //printf("轮廓个数：%d",count);  
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(temp, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(220,120, 136));  
		//cvShowImage ("Contour", pBinaryImg);  
	
			//IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 3);   
			//////printf("%d ",rc.x);

			//////d.x = rc.x;
			//////cvErode(pBinaryImg1,pBinaryImg1);
			////
			//cvSetImageROI(imgSrc, rc);  
			//////cvErode(pBinaryImg1,pBinaryImg1);
			//cvCopyImage(imgSrc, imgNo); 
			//sprintf(szName, "wnd_%d", idx++);   
			//cvNamedWindow(szName); 
			//cvShowImage(szName, imgNo);
  //       CvRect rc =cvBoundingRect(c,0);  
  //       cvDrawRect(imgSrc, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(255, 0, 0));  
  //////
       if (rc.width>100	)  
	   {
		   IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 3);   
			////printf("%d ",rc.x);

			////d.x = rc.x;
			////cvErode(pBinaryImg1,pBinaryImg1);
			//
			cvSetImageROI(ori, rc);  
			////cvErode(pBinaryImg1,pBinaryImg1);
			cvCopyImage(ori, imgNo); 
			//cvSaveImage("gg.jpg",imgNo);
			sprintf(szName, "wnd_%d", idx++);   
			cvNamedWindow(szName); 
			cvShowImage(szName, imgNo);
	   }

	   
	}
	/*cvSaveImage("pBinaryImg.jpg",pBinaryImg);
	 CDC *pDC=NULL;  
	pDC=GetDlgItem(IDC_STATIC_IMG)->GetDC(); 
	ShowImage(pDC,"F:\\opencv\\test\\mfc\\mfc\\pBinaryImg.jpg",0,0); */


}


void CmfcDlg::OnBnClickedButton11()
{

	// TODO: 在此添加控件通知处理程序代码
	CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0);   
	  //cvShowImage("ThresholdImg",img_gray);
    int count = cvFindContours(tempdialte1, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
	 IplImage* temp = cvCreateImage(cvGetSize(tempdialte1), IPL_DEPTH_8U, 1);  
	 cvCopy(tempdialte1,temp,NULL);
    //cvReleaseMemStorage(& storage);   
    //printf("轮廓个数：%d",count);  
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(temp, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(255,0, 0));  
		
       if (rc.height>220	)  
	   {
		   IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 3);   
			
			cvSetImageROI(ori1, rc);  
		
			cvCopyImage(ori1, imgNo); 
			sprintf(szName, "wnd_%d", idx++);   
			cvNamedWindow(szName); 
			cvShowImage(szName, imgNo);
	   }

	   
	}
}


void CmfcDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0); 
	 IplImage* temp = cvCreateImage(cvGetSize(tempdialte2), IPL_DEPTH_8U, 1);  
	 cvCopy(tempdialte2,temp,NULL);

    int count = cvFindContours(tempdialte2, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
	
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(temp, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(255,0, 0));  
		
       if ((rc.width/rc.height)>6	)  
	   {
		   IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 1);   
			
			cvSetImageROI(binary, rc);  
		
			cvCopyImage(binary, imgNo); 
			sprintf(szName, "wnd_%d", idx++);   
			cvNamedWindow(szName); 
			cvShowImage(szName, imgNo);
	   }

	   
	}
	 binary1 = cvCreateImage(cvGetSize(binary), IPL_DEPTH_8U, 1); 
	 cvCopy(binary,binary1,NULL);
	// cvShowImage("ds", binary1);



	 



}


void CmfcDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	binary1 = cvCreateImage(cvGetSize(binary), IPL_DEPTH_8U, 1); 
	cvCopy(binary,binary1,NULL);
	  IplImage* temp;
	  temp=cvCreateImage(cvGetSize(binary), IPL_DEPTH_8U, 1); 
	cvCopy(binary,temp,NULL);

	CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0); 
	 

    int count = cvFindContours(temp, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
	
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(binary1, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(0,0, 200));  
			 cvShowImage("ThresholdImg",binary1);
		
      

	   
	}
	

}
//void CmfcDlg::OnBnClickedButton15()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	system("F:\\tesseract\\tesseract.exe F:\\opencv\\test\\mfc\\mfc\\q.jpg F:\\opencv\\test\\mfc\\mfc\\r -1");
//	Sleep(1000);
//
//}


void CmfcDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	IplImage*binary3 = cvCreateImage(cvGetSize(binary), IPL_DEPTH_8U, 1); 
	cvCopy(binary,binary3,NULL);
	  IplImage* temp1;
	  temp1=cvCreateImage(cvGetSize(binary), IPL_DEPTH_8U, 1); 
	cvCopy(binary,temp1,NULL);

	CvSeq* contours = NULL;  
    CvMemStorage* storage = cvCreateMemStorage(0); 
	 

    int count = cvFindContours(temp1, storage, &contours,  
        sizeof(CvContour),CV_RETR_EXTERNAL);  
	
    int idx = 0;  
    char szName[200] = {0};  
    int tempCount=0;  
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {  
		   CvRect rc =cvBoundingRect(c,0);
	

			cvDrawRect(binary3, cvPoint(rc.x, rc.y), cvPoint(rc.x + rc.width, rc.y + rc.height), CV_RGB(0,0, 200));  
			 //cvShowImage("ThresholdImg",binary1);
			 IplImage*  imgNo = cvCreateImage(cvSize(rc.width, rc.height), IPL_DEPTH_8U, 1);   
			
			cvSetImageROI(binary3, rc);  
		
			cvCopyImage(binary3, imgNo); 
			sprintf(szName, "wnd_%d", idx++);   
			cvNamedWindow(szName); 
			cvShowImage(szName, imgNo);
		
      

	   
	}

}


//void CmfcDlg::OnBnClickedButton15()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	system("F:\\tesseract\\tesseract.exe F:\\opencv\\test\\mfc\\mfc\\q.jpg F:\\opencv\\test\\mfc\\mfc\\r -1");
//	Sleep(1000);
//
//}
