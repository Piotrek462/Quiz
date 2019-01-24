
#include <iostream>
#include <WinSock2.h>
#include <string>
#include "Milion.cpp"
using namespace std;
char buffer[256];
char sendbuf[256];
SOCKET Polaczenie;
void ClientThread()
{

	while (true)
	{
		recv(Polaczenie, buffer, sizeof(buffer), NULL);
		cout << buffer << endl;

	}

}
int main()

{


	WSAData data;
	WORD wersja = MAKEWORD(2, 2);

	if (WSAStartup(wersja, &data) != 0)
	{
		MessageBox(NULL, "Cos poszlo nie tak!","BLAD!!!", MB_OK | MB_ICONERROR);
		exit(1);
	}

	sockaddr_in abc;
	abc.sin_family = AF_INET;
	abc.sin_port = htons(1111);
	abc.sin_addr.s_addr = inet_addr("127.0.0.1");

	Polaczenie = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(Polaczenie, (sockaddr*)&abc, sizeof(abc)))

	{
		cout << "Nie udalo sie nawiazac polaczenia. Serwer nie odpowiada." << endl;
	}
	else
	{
		cout << "Polaczony z serwerem! " << endl;
		char POWITANIE[256];
		recv(Polaczenie, POWITANIE, sizeof(POWITANIE), NULL);
		cout << "HOST: " << POWITANIE <<endl;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL);


	}
char Odpowiedz[256] = "Uzyskalem punkt!";




	while(true)
	{
     if (sprawdz(o,ODP_D)==1)
        {


		send(Polaczenie, Odpowiedz, sizeof(Odpowiedz), NULL);
        }
    cin.getline(buffer,sizeof(buffer));
    send(Polaczenie,buffer,sizeof(buffer),0);

	}
	system("pause");
	return 1;

}
