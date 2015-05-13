
// GLFilterView.h : CGLFilterView ��Ľӿ�
//

#pragma once

class CGLFilterView : public CView
{
protected: // �������л�����
	CGLFilterView();
	DECLARE_DYNCREATE(CGLFilterView)

// ����
public:
	CGLFilterDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CGLFilterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void UpdateView(void);
protected:
	CSliderCtrl m_ctrlRadius;
	CSliderCtrl m_ctrlSigma;
	CEdit		m_editRadius;
	CEdit		m_editSigma;
	CButton		m_btnGray;
	CBitmap*    m_pSrcBitmap;
	CBitmap*	m_pDstBitmap;
	BOOL		m_bLoadBitmap;
	BOOL		m_bNeedUpdateBitmap;
	e::ImageFilter* m_pImagerFitler;
	CString		m_strParamText;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // GLFilterView.cpp �еĵ��԰汾
inline CGLFilterDoc* CGLFilterView::GetDocument() const
   { return reinterpret_cast<CGLFilterDoc*>(m_pDocument); }
#endif
