//=============================================================
#include <windows.h>  //	������ �������α׷� �������..

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  //	������ ���ν��� �Լ�..
//LRESULT=�׳� longŸ�� ��ȯ��
//CALLBACK=�ٸ� �Լ��� �μ��� �Ѱ��ִ� ���� ������ ��, � �̺�Ʈ�� ���� ȣ��Ǵ� ��

LPCTSTR g_lpszClass = TEXT("First");  //	������ Ŭ���� �̸�..
//LPCTSTR=long pointer constant tchar string
//lpsz=long pointer null terminated ��,NULL�� ������ ���ڿ��� ������

//=============================================================

/*
	----------
    APIENTRY..
	----------
    -	���������� ǥ�� ȣ�� �Ծ��� __stdcall�� ����Ѵٴ� ��.

	---------
	WinMain..
	---------
	-	���α׷� �������� �����ϴ� �����Լ�.
	-	c / c++�� main ����.
	-	������ �ʱ�ȭ �۾�.
	-	���� ������ ���� �����.

*/
int APIENTRY WinMain(
	/*
	hInstance
		-	���α׷� ���� ID.
		-	�ü���� ���� ���α׷��� �ߺ� ���� �Ǿ
			hInstance�� �����Ͽ� ���� �ٸ� ���α׷����� �ν�..
		-	hInstance �ܿ� ������ �Ű������� �� ������ ����..
	*/
	HINSTANCE hInstance,
	
	/*
	hPrevInstance
		-	�ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ�.
		-	���� ��� NULL.
		-	Win32������ �׻� NULL.
		-	16��Ʈ���� ȣȯ���� ���ؼ��� ����.
	*/
	HINSTANCE hPrevInstance,

	/*
	lpszCmdParam
		-	��������� �Էµ� ���α׷� �μ�.
			��) notepad D : \test.txt
	*/
	LPSTR lpszCmdParam,

	/*
	nCmdShow
		-	���α׷��� ����� ����.
		-	�ּ�ȭ, ������ ��.
	*/
	int nCmdShow )
{
	//-----------------------------------
	//	1)	������ Ŭ���� ���� �� ���
	//	WNDCLASS
	//	-	������� �ϴ� �������� �������� Ư���� �����ϴ� ����ü.
	WNDCLASS WndClass;

	//	WndClass.style
	//	-	������ ��Ÿ�� ����.
	//	-	CS_HREDRAW | CS_VREDRAW
	//		-	�������� ����,���� ũ�Ⱑ ���� ��� 
	//			�����츦 �ٽ� �׸���.						
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	//	WndClass.lpfnWndProc
	//	-	������ �޽��� ó�� �Լ� ����.
	//	-	�Լ������ͷ� �Ǿ�����.
	WndClass.lpfnWndProc = WndProc;

	//	WndClass.cbClsExtra / WndClass.cbWndExtra
	//	-	������ ���� ����.
	//	-	���� ������� ����.
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	
	//	WndClass.hInstance
	//	-	������ Ŭ������ ����ϰ��� �ϴ� ���α׷� ���� ID.
	WndClass.hInstance = hInstance;

	//	WndClass.hCursor / WndClass.hIcon
	//	-	�����찡 ����� ���콺 Ŀ���� ������ ����.
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	//	WndClass.hbrBackground
	//	-	�������� ����� ä���� �귯�� ����.
	WndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	
	//	WndClass.lpszMenuName
	//	-	���α׷��� ����� �޴� ����.
	//	-	���ҽ� �����Ϳ��� ������ ����.
	//	-	��ũ�ÿ� ������.
	//	-	������� ���� ��� NULL.
	WndClass.lpszMenuName = NULL;
	
	//	WndClass.lpszClassName
	//	-	������ Ŭ���� �̸�.
	WndClass.lpszClassName = g_lpszClass;
		
	//	������ Ŭ���� ���.
	RegisterClass(&WndClass);
	//-----------------------------------
	//	2)	������ ���� �� ȭ�鿡 ���..
	
	//	hWnd
	//	-	CreateWindow ������ �����Ǵ� �������� ���� ID.
	HWND hWnd;
						//	�����ϰ��� �ϴ� �������� Ŭ����, ������ Ÿ��Ʋ �ٿ� ��Ÿ�� ���ڿ�.
	hWnd = CreateWindow(g_lpszClass, "Hello API!!",
	//hWnd = CreateWindow("aa", "Hello API!!",
						
						//	������ ����, ��Ʈ �ʵ尪.
						//	WS_OVERLAPPEDWINDOW		:	�ý��� �޴� | �ִ�/�ּ� ��ư | Ÿ��Ʋ �� | ��輱
						WS_OVERLAPPEDWINDOW,

						//	�������� ��ġ�� ũ�Ⱚ, �ȼ� ����.
						//	CW_USEDEFAULT
						//	-	�ü���� ȭ��ũ�⿡ �°� ������ ũ��� ��ġ�� ����.
						//100,100,200,200,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
					
						//	�θ� �����찡 �ִ� ��� �θ� �������� �ڵ�(ID).
						//	MDI(���� ����)���α׷�, �˾� �������.
						//	�ڽ��� �ֻ��� �� ��� NULL.
						NULL,
						
						//	�����쿡�� ����� �޴��� �ڵ�.
						//	WndClass.lpszMenuName�� �����ϰ� ����Ϸ��� NULL
						(HMENU)NULL,

						//	�����츦 ����� ��ü�� �ڵ�(ID).
						//	�ü���� �� ���� �����Ͽ��ٰ� ���α׷� �����
						//	�ı����� ���� �����츦 �ڵ����� �ı���.
						hInstance,
		
						//	CREATESTRUCT��� ����ü�� �ּ�.
						//	�������� �����츦 ���鶧 �� �����쿡 ���� �Ķ���� ���� ����.
						//	�� ������ ����.
						NULL);

	//	CreateWindow�� ���� �޸𸮻󿡸� �����찡 �����ϰ� ��.
	//	ȭ������ ���̰��ϴ� ����.
	//	SW_HIDE, SW_MINIMIZE ���� �Ķ���� ����.
	//	���� nCmdShow�� �״�� ����.
	ShowWindow(hWnd, nCmdShow);
	//-----------------------------------
	/*
		3)	�޽��� ����

		GetMessage
			-	�޽��� ť���� �޽����� �о����.
				-	�޽��� ť	:	�ý����̳� ����ڷκ��� �߻��� �޽����� ��� ����ϴ�
									������ �޽��� �ӽ� �����.
			-	�޽��� ť�� ����ִ� ��� ���.
				-	��� �Լ�
					��) scanf, cin ��..
			-	�о���� �޽����� [ MSG����ü ]�� �����.
			-	[ WM_QUIT ]��� �޽����� ������������ �ݺ���.
			-	������ ���ڴ� �� ������ ����.
	
		TranslateMessage	
			-	Ű���� �Է� �޽����� ���α׷����� ����ϱ� ���� ����.
			-	[ WM_KEYDOWN ] �޽����� �߻������� [ ���� ]��� [ WM_CHAR ] �޽����� ��ȯ�Ͽ�
				� ���ڰ� �ԷµǾ����� �˼� �ְ� ��.

		DispatchMessage
			-	�޽��� ť���� ���� �޽����� [ WndProc ]���� ����.
			-	���� �޽��� ó���� [ WndProc ]�� ���.
	*/
	MSG Message;
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	//-----------------------------------
	
	return (int)Message.wParam;

}//	int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance , LPSTR lpszCmdParam, int nCmdShow)
//=============================================================
/*
	4)	������ ���ν��� ó��..

		WndProc
		-	����ڿ� �ý����� ������ �޽��� ó��.
		-	���� ��� ��쿡 [ WinMain ]�� [ WndProc ]�� ��� �����ؾ���.
		-	���α׷��� �������� ó��.

		CALLBACK
		-	[ APIENTRY ]�� ���� ����.

		hWnd
		-	�޽����� ���� �������� �ڵ�.

		iMessage
		-	� ������ �޽�������, � �̺�Ʈ�� �߻��ߴ����� ���� ����.

		wParam, lParam
		-	iMessage�� �ΰ� ����.
			��) WM_LBUTTONDOWN - ȭ�鿡�� ���콺 ���ʹ�ư Ŭ���� ��ǥ ����.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		//	������ ������ �߻�.
	case WM_CREATE:
		MessageBox(hWnd, "WM_CREATE", "", NULL);
		//	�޽��� ó���� �ݵ�� 0�� ����.
		return 0;

		//	���콺 ���� Ŭ���� �߻�.
	case WM_LBUTTONDOWN:
		int x, y;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		TCHAR tmp[100];
		wsprintf(tmp, "x = %d, y = %d", x, y);
		MessageBox(hWnd, tmp, "WM_LBUTTONDOWN", NULL);
		return 0;

		//	������ ����� �߻�.
		//	X��ư(������� �ý��� ��ư), Alt+F4��.
	case WM_DESTROY:
		MessageBox(hWnd, "WM_DESTROY", "", NULL);

		//	WM_QUIT�� �޽��� ť�� ����.
		PostQuitMessage(0);
		return 0;

	}//	switch (iMessage)

	//	�⺻ �̺�Ʈ ó��.
	//	switch (iMessage)���� ó������ ���� �޽��� ó��.
	//	��) ������ �̵�, ������ â ũ�� ���� ��.
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}//	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//=============================================================
/*
	Q > ���� �ҽ��� ���� Ÿ���� �ϸ� ��ü �ҽ��� �帧�� �ٽ��ѹ� �����մϴ�.
*/
//=============================================================