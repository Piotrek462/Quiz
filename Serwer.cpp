
#include <iostream>
#include <WinSock2.h>
SOCKET NowePolaczenie;
SOCKET Polaczenia [100];
int IloscPolaczen = 0;

void KolejnePolaczenia(int x)
{
char buffer[256];
while (true)
{
    recv(Polaczenia[x], buffer, sizeof(buffer), NULL);
        for (int i = 0; i < 100; i++)
{
    if (i == x)
        continue;
            send(Polaczenia[i], buffer, sizeof(buffer), NULL);
}

}
}
    using namespace std;
    int main()
{
    WSAData wsaData;
    WORD ver = MAKEWORD(2, 2);
        if (WSAStartup(ver, &wsaData) != 0)
{
MessageBoxA(NULL, "Winsock fail", "Error", MB_OK | MB_ICONERROR);
exit(1);
}

	sockaddr_in abc;
	int hintlen = sizeof(abc);
	abc.sin_family = AF_INET;
	abc.sin_port = htons(1111);
	abc.sin_addr.S_un.S_addr = INADDR_ANY;

	SOCKET Czy_Polaczono = socket(AF_INET, SOCK_STREAM, NULL);

	bind(Czy_Polaczono, (SOCKADDR*)&abc, sizeof(abc));

	listen(Czy_Polaczono, SOMAXCONN);

	for (int i = 0; i <100; i++)
	{
		NowePolaczenie = accept(Czy_Polaczono, (SOCKADDR*)&abc, &hintlen);
		if (NowePolaczenie == 0)
		{
			std::cout << "Nie udalo sie nawiazac polaczenia z klientem" << std::endl;
		}
		else
		{
			std::cout << "Client polaczony!" << std::endl;

			char POWITANIE[256] = "Witamy w Quizie!";
			send(NowePolaczenie, POWITANIE, sizeof(POWITANIE), NULL);
			Polaczenia[i] = NowePolaczenie;
			IloscPolaczen += 1;

			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)KolejnePolaczenia, (LPVOID)(i), NULL, NULL);
		}
	}

	system("pause");
	return 0;
}




