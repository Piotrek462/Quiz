#if defined(UNICODE) && !defined(_UNICODE)
#endif

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

const char *WindowsClassName = "Klasa";
const char *WindowsApplicationName = "Quiz";

MSG Message;

#define ODP_A 100
#define ODP_B 200
#define ODP_C 300
#define ODP_D 400


HWND a_hPrzycisk;
HWND b_hPrzycisk;
HWND c_hPrzycisk;
HWND d_hPrzycisk;

HWND PolePytan;
HWND hWnd;

int nr_pyt=1;
int suma_punktow = 0;
LRESULT CALLBACK WindowProcedure( HWND glowne, UINT msg, WPARAM wParam, LPARAM lParam);

void pytanie(HWND);
void guziki(HWND);
string wczytaj_pyt();
string wczytaj_odp();
int sprawdz(string odp, int ODP);
string j, o;


int WINAPI WinMain( HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR szCmdLine,int iCmdShow )
{
    WNDCLASSEX quiz;
	quiz.cbSize = sizeof(WNDCLASSEX);
	quiz.style = 0;
	quiz.lpfnWndProc = WindowProcedure;
	quiz.cbClsExtra = 0;
	quiz.cbWndExtra = 0;
	quiz.hInstance = hInstance;
	quiz.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	quiz.hCursor = LoadCursor(NULL, IDC_ARROW);
	quiz.hbrBackground = (HBRUSH) ( COLOR_WINDOW + 2);
	quiz.lpszMenuName = NULL;
	quiz.lpszClassName = WindowsClassName;
	quiz.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if ( !RegisterClassEx(&quiz)) {
		MessageBox(NULL, "Nie udalo siÍ zarejestrowac klasy", "Error", 0);

		return 0;
	}

HWND glowne = CreateWindowEx(WS_EX_WINDOWEDGE,WindowsClassName,WindowsApplicationName,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,
CW_USEDEFAULT,800, 600,NULL,NULL,hInstance,NULL);
	{
		ShowWindow( glowne, iCmdShow );
		UpdateWindow( glowne );

		MessageBox(NULL, "Rozpocznijmy Quiz!", "", MB_ICONINFORMATION | MB_OK);

        guziki(glowne);
        pytanie(glowne);

	}

	while (GetMessage(&Message, NULL, 0, 0)) {TranslateMessage(&Message);DispatchMessage(&Message);}

}


LRESULT CALLBACK WindowProcedure( HWND glowne,UINT msg,WPARAM wParam,LPARAM lParam) {

switch (msg) {
case WM_CREATE:
    break;
case WM_COMMAND:
{
switch(wParam){

case ODP_A:
    if(sprawdz(o, ODP_A)==1)
{

    MessageBoxW(glowne, L"Wybrano A dobrze", L"Komunikat", NULL);
    suma_punktow = suma_punktow +1;
    printf ("Uzyskane punkty : %d \n", suma_punktow);
    pytanie(glowne);
}
    else
{
    MessageBox(glowne, "Z≥a odpowiedü! Koniec gry!", "Komunikat", NULL);
    PostQuitMessage(0);
}
    break;
case ODP_B:
    if(sprawdz(o, ODP_B)==1)
{
    MessageBoxW(glowne, L"Wybrano B dobrze", L"Komunikat", NULL);
    suma_punktow = suma_punktow +1;
    printf ("Uzyskane punkty : %d \n", suma_punktow);
    pytanie(glowne);
}
    else
{
    MessageBox(glowne, "Z≥a odpowiedü! Koniec gry!", "Komunikat", NULL);
    PostQuitMessage(0);
}
    break;
case ODP_C:
    if(sprawdz(o, ODP_C)==1)
{
    MessageBoxW(glowne, L"Wybrano C dobrze", L"Komunikat", NULL);
    suma_punktow = suma_punktow +1;
    printf ("Uzyskane punkty : %d \n", suma_punktow);
    pytanie(glowne);
}
    else
{
    MessageBox(glowne, "Z≥a odpowiedü! Koniec gry!", "Komunikat", NULL);
    PostQuitMessage(0);
}
    break;
case ODP_D:
    if(sprawdz(o, ODP_D)==1)
{
    MessageBoxW(glowne, L"Wybrano D dobrze", L"Komunikat", NULL);
    suma_punktow = suma_punktow +1;
    printf ("Uzyskane punkty : %d \n", suma_punktow);
    pytanie(glowne);
}
    else
{
    MessageBox(glowne, "Z≥a odpowiedü! Koniec gry!", "Komunikat", NULL);
    PostQuitMessage(0);
}
    break;

}
}
    break;

case WM_CLOSE:
    DestroyWindow(glowne);
        break;

case WM_DESTROY:
    PostQuitMessage(0);
        break;

default:
    return DefWindowProc(glowne, msg, wParam, lParam);
	}
	return 0;
}


string wczytaj_pyt(){
string linia;
fstream plik;
plik.open("test.txt", ios::in);
for(int i=1; i<=nr_pyt-1; i++)
getline(plik, linia);
getline(plik, linia);
if(plik.eof()) linia = "Koniec Quizu!";
nr_pyt+=2;
return linia;
}

string wczytaj_odp(){
string linia;
fstream plik;
plik.open("test.txt", ios::in);
for(int i=2; i<=nr_pyt-1; i++)
getline(plik, linia);
getline(plik, linia);
    return linia;
}

int sprawdz(string odp, int ODP)
{
    int spr;
    if(odp== "A")  spr = 100;
    else
    if(odp== "B")  spr = 200;
    else
    if(odp== "C")  spr = 300;
    else
    if(odp== "D")  spr = 400;

    if (spr==ODP)
    return 1;
    else
    return 0;
}
void guziki(HWND glowne)
{
        HWND a_hPrzycisk = CreateWindowExW(0, L"BUTTON", L"A", WS_CHILD | WS_VISIBLE, 80, 320, 300, 90, glowne, (HMENU)ODP_A, NULL, NULL);

        HWND b_hPrzycisk = CreateWindowExW(0, L"BUTTON", L"B", WS_CHILD | WS_VISIBLE, 390, 320, 300, 90, glowne, (HMENU)ODP_B, NULL, NULL);

        HWND c_hPrzycisk = CreateWindowExW(0, L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, 80, 420, 300, 90, glowne, (HMENU)ODP_C, NULL, NULL);

        HWND d_hPrzycisk = CreateWindowExW(0, L"BUTTON", L"D", WS_CHILD | WS_VISIBLE, 390, 420, 300, 90, glowne, (HMENU)ODP_D, NULL, NULL);

}
void pytanie(HWND glowne)
{
    j=wczytaj_pyt();
    o=wczytaj_odp();
    LPCSTR k=j.c_str(), m=o.c_str();
    PolePytan = CreateWindowEx(0, "STATIC", k, WS_CHILD|WS_VISIBLE|SS_CENTER, 50, 120, 680, 180, glowne, NULL, NULL, NULL);
}
