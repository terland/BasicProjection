// 3DBasic3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "3DBasic3.h"
#include <entities.h>

class World
{
private:
	Camera cam; // Anta cam.dir = (0,0,1) først
	vector<spoint> s;
	spoint v1;
	spoint v2;

public:
	World(Camera c)
	{
		cam = c;
		// Find orthogonal basis
	}

	void addSpoint(spoint sv)
	{
		s.push_back(sv);
	}

	vector<point> generate()
	{
		// Project onto 2D
		vector<point> ans(s.size());
		for (int i = 0; i < s.size(); i++)
		{
			spoint cup = s[i];
			spoint diff = cup + (cam.pos * -1);

			// Solve certain linear equation: cam.dir.x diff.x t+ cam.dir.y * diff.y t + cam.dir.z * diff.z t = 1

			if (cam.dir.dot(diff)*cam.dir.dot(diff) < 0.01)
			{
				// Out of bounds
				ans[i] = point(-1, -1);
				continue;
			}
			spoint sol = diff * (1 / (cam.dir.dot(diff)));
			cout << sol.z << " err..." << endl;
			cout << sol.dot(cam.dir) << endl;
			ans[i] = point(sol.x, sol.y);
		}

		return ans;
	}

};

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	World w(Camera(spoint(0, 0, -1), spoint(0, 0, 1)));
	Cube c(1, spoint(0, 0, 5));


	for (int i = 0; i < c.getPoints().size(); i++)
	{
		w.addSpoint(c.getPoints()[i]);
	}

	spoint ps = spoint(0, 1, 10);
	double add = 0;

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY3DBASIC3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY3DBASIC3));

    MSG msg;

    // Main message loop:
	bool upDre = false;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
			if (msg.message == WM_KEYDOWN)
			{
				if (msg.wParam == VK_LEFT)
				{
					add -= 0.02;
					upDre = false;
				}
				else if (msg.wParam == VK_RIGHT)
				{
					add += 0.02;
					upDre = false;
				}
				else if (msg.wParam == VK_UP)
				{
					add += 0.02;
					upDre = false;
				}
				else if (msg.wParam == VK_DOWN)
				{
					add += 0.02;
					upDre = false;
				}
				else
				{
					continue;
				}

				vector<point> p = w.generate();

				w = Camera(spoint(0, 0, -1), spoint(0, 0, 1));
				spoint s = ps;
				Cube c = Cube(1, s);
				c.RotateY(add);


				for (int i = 0; i < c.getPoints().size(); i++)
				{
					w.addSpoint(c.getPoints()[i]);
				}

				vector<point> p2 = w.generate();


				for (int i = 0; i < p.size(); i++)
				{
					p[i] = p[i] * 800;
					p[i].x += 250;
					p[i].y += 250;
					HDC h = GetDC(msg.hwnd);
					SetPixel(h, p[i].x, p[i].y, RGB(255, 255, 255));
					SetPixel(h, p[i].x + 1, p[i].y, RGB(255, 255, 255));
					SetPixel(h, p[i].x, p[i].y + 1, RGB(255, 255, 255));
					SetPixel(h, p[i].x + 1, p[i].y + 1, RGB(255, 255, 255));
				}

				
				

				for (int i = 0; i < p2.size(); i++)
				{
					p2[i] = p2[i] * 800;
					p2[i].x += 250;
					p2[i].y += 250;
					HDC h = GetDC(msg.hwnd);
					SetPixel(h, p2[i].x, p2[i].y, RGB(0, 0, 0));
					SetPixel(h, p2[i].x + 1, p2[i].y, RGB(0, 0, 0));
					SetPixel(h, p2[i].x, p2[i].y + 1, RGB(0, 0, 0));
					SetPixel(h, p2[i].x + 1, p2[i].y + 1, RGB(0, 0, 0));
				}


				

				

				
				

				for (int i = 0; i < c.getPoints().size(); i++)
				{
					w.addSpoint(c.getPoints()[i]);
				}
				
				

			}
			/*if (!upDre)
			{
				upDre = true;

				vector<point> p = w.generate();

				for (int i = 0; i < p.size(); i++)
				{
					p[i] = p[i] * 300;
					p[i].x += 250;
					p[i].y += 250;
					HDC h = GetDC(msg.hwnd);
					SetPixel(h, p[i].x, p[i].y, RGB(0, 0, 0));
					SetPixel(h, p[i].x+1, p[i].y, RGB(0, 0, 0));
					SetPixel(h, p[i].x, p[i].y+1, RGB(0, 0, 0));
					SetPixel(h, p[i].x+1, p[i].y+1, RGB(0, 0, 0));
				}

			}*/
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3DBASIC3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY3DBASIC3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
