
// GraphicsDoc.h : CGraphicsDoc 类的接口
//

#pragma once

using namespace e;

class CGraphicsDoc : public CDocument
{
protected: // 仅从序列化创建
	CGraphicsDoc();
	DECLARE_DYNCREATE(CGraphicsDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CGraphicsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	Bitmap* LoadBitmap(const CString & filePath);

	Bitmap* CloneBitmap(const Bitmap* bitmap, int x0, int y0, int x1, int y1);

	void SetSrcBitmap(Bitmap* bitmap)
	{
		if (m_pSrcBitmap != 0)
			delete m_pSrcBitmap;
		m_pSrcBitmap = bitmap;
	}

	void SetDstBitmap(Bitmap* bitmap)
	{
		if (m_pDstBitmap != 0)
			delete m_pDstBitmap;
		m_pDstBitmap = bitmap;
	}

	Bitmap* GetSrcBitmap(void) const
	{
		return m_pSrcBitmap;
	}

	Bitmap* GetDstBitmap(void) const
	{
		return m_pDstBitmap;
	}

protected:
	Bitmap* m_pSrcBitmap;
	Bitmap* m_pDstBitmap;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
