
// ChessView.cpp: CChessView 클래스의 구현
//

#include "stdafx.h"
#include <atlimage.h>
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Chess.h"
#endif

#include "ChessDoc.h"
#include "ChessView.h"

#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChessView

IMPLEMENT_DYNCREATE(CChessView, CView)

BEGIN_MESSAGE_MAP(CChessView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChessView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CChessView 생성/소멸

CChessView::CChessView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChessView::~CChessView()
{
}

BOOL CChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChessView 그리기

void CChessView::OnDraw(CDC* pDC)
{
	CChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CDC memDC;
	CBitmap MyBit, *pOldBit;
	BITMAP bm;
	MyBit.LoadBitmapW(IDB_WOLF);
	MyBit.GetObject(sizeof(BITMAP), &bm);
	memDC.CreateCompatibleDC(pDC);
	pOldBit = memDC.SelectObject(&MyBit);
	CRect rect;
	GetClientRect(rect);
	int x = (rect.right - bm.bmWidth) / 2;
	int y = (rect.bottom - bm.bmHeight) / 2;
	pDC->BitBlt(x, y, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOldBit);
}


// CChessView 인쇄


void CChessView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CChessView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChessView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChessView 진단

#ifdef _DEBUG
void CChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessDoc* CChessView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessDoc)));
	return (CChessDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessView 메시지 처리기


void CChessView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
}


void CChessView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	Invalidate();
}
