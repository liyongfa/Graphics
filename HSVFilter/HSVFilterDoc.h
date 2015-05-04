
// HSVFilterDoc.h : CHSVFilterDoc ��Ľӿ�
//


#pragma once

using namespace e;

class CHSVFilterDoc : public CDocument
{
protected: // �������л�����
	CHSVFilterDoc();
	DECLARE_DYNCREATE(CHSVFilterDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CHSVFilterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	Bitmap* GetBitmap(const int index) const
	{
		return m_BitmapArray[index];
	}
	BOOL OpenFile(const CString & fileName);
protected:
	Array<Bitmap*> m_BitmapArray;
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ�����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};