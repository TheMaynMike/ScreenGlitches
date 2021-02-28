#include <windows.h>
#include <time.h>
#include <iostream>

int main()
{ 
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetDC(hwnd);
	int ScrW = GetSystemMetrics(SM_CXSCREEN);
	int ScrH = GetSystemMetrics(SM_CYSCREEN);

	while (true)
	{
		for (int i = 0;; i++, i %= 3)
		{
			int y = rand() % ScrH;
			HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
			SelectObject(hdc, brush);
			PatBlt(hdc, 0, y, ScrW, 300, PATINVERT);
			BitBlt(hdc, 0, y, ScrW, 300, hdc, rand() % 31 - 10, y, SRCCOPY);
			if (!i)RedrawWindow(0, 0, 0, 133);
		}
	}

	return 0;
}
