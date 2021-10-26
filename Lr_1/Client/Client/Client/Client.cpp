#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <sstream>

#define PORT 777
#define SERVERADDR "127.0.0.1"

using namespace std;

string uncorrect_simv = "ghijklmnopqrstuvwxyz";
string uncorrect_simv_1 = "abcdefghijklmnopqrstuvwxyz";
void info_command() {
	cout << "Список команд:\n";
	cout << "1-clear\n2-SetPixel\n3-DrawLine\n4-DrawRectangle\n5-FillRectangle\n";
	cout << "6-DrawEllipse\n7-FillEllipse\n8-DrawCircle\n9-FillEllipse\n10-DrawRoundedRectangle\n";
	cout << "11-DrawRoundedRectangle\n12-DrawString\n13-RotateTransform\n14-GetWidth\n15-GetHigth\n";
}
void help() {
	cout << "Для вывода списка команд введите - command" << endl;
	cout << "Для завершения программы введите - quit" << endl;
}
bool PresenceOfLetters(string str) {
	/*true - если есть буква*/
	int count = 0;
	bool answer = false;
	for (size_t i = 0; i < size(uncorrect_simv_1); i++) {
		if (str.find(uncorrect_simv_1[i]) != string::npos) {
			answer = true;
			count++;
			break;
		}
	}
	return answer;
}
string SetColor() {
	string color, r, g, b;
	int r_, g_, b_;
	bool a = true;
	while (a) {
		cout << "Введите цвет R (0 - 255): " << endl;
		cin >> r;
		if (!PresenceOfLetters(r) && size(r) > 0) {
			r_ = stoi(r);
			if (r_ >= 0 && r_ <= 255) {
				a = false;
			} else {
				cout << "Не верный ввод!" << endl;
			}
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	a = true;
	while (a) {
		cout << "Введите цвет G (0 - 255): " << endl;
		cin >> g;
		if (!PresenceOfLetters(g) && size(g) > 0) {
			g_ = stoi(g);
			if (g_ >= 0 && g_ <= 255) {
				a = false;
			}
			else {
				cout << "Не верный ввод!" << endl;
			}
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	a = true;
	while (a) {
		cout << "Введите цвет B (0 - 255): " << endl;
		cin >> b;
		if (!PresenceOfLetters(b) && size(b) > 0) {
			b_ = stoi(b);
			if (b_ >= 0 && b_ <= 255) {
				a = false;
			}
			else {
				cout << "Не верный ввод!" << endl;
			}
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	color = r + "#" + g + "#" + b + "#";
	return color;
}
string SetXYFirst() {
	string xyfirst, str;
	int x0, y0;
	bool a = true;
	while (a) {
		cout << "Введите координату x0: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			x0 = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	a = true;
	while (a) {
		cout << "Введите координату y0: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			y0 = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	xyfirst = to_string(x0) + "@" + to_string(y0) + "@";
	return xyfirst;
}
string SetXYLast() {
	string xylast, str;
	int x1, y1;
	bool a = true;
	while (a) {
		cout << "Введите координату x0: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			x1 = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	a = true;
	while (a) {
		cout << "Введите координату y0: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			y1 = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	xylast = to_string(x1) + "@" + to_string(y1) + "@";
	return xylast;
}
string SetWidth() {
	string width, str;
	int w;
	bool a = true;
	while (a) {
		cout << "Введите ширину: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			w = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	width = to_string(w);
	return width;
}
string SetHeigth() {
	string heigth, str;
	int h;
	bool a = true;
	while (a) {
		cout << "Введите высоту: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			h = stoi(str);
			a = false;
		} else {
			cout << "Не верный ввод!" << endl;
		}
	}
	heigth = to_string(h);
	return heigth;
}
string SetRadius() {
	string radius, str;
	int r;
	bool a = true;
	while (a) {
		cout << "Введите радиус: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			r = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	radius = to_string(r);
	return radius;
}
string SetAngle() {
	string angle, str;
	int angle_;
	bool a = true;
	while (a) {
		cout << "Введите угол поворота: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			angle_ = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	angle = to_string(angle_);
	return angle;
}
string SetFont() {
	string font, str;
	int font_;
	bool a = true;
	while (a) {
		cout << "Введите угол размер текста: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			font_ = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	font = to_string(font_);
	return font;
}
string SetText() {
	string text;
	cout << "Введите текст: " << endl;
	cin >> text;
	return text;
}
string command_selection(int command_number) {
	string command, color, xyfirst, xylast, width, heigth, radius, text, font, angle;
	string str = to_string(command_number);
	switch (command_number){
		/*Clear*/
		case 1:
			cout << "Clear" << endl;
			color = SetColor();
			command = str + ":" + color;
			break;
		/*SetPixel*/
		case 2:
			cout << "SetPixel" << endl;
			xyfirst = SetXYFirst();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst;
			break;
		/*DrawLine*/
		case 3:
			cout << "DrawLine" << endl;
			xyfirst = SetXYFirst();
			xylast = SetXYLast();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + xylast;
			break;
		/*DrawRectangle*/
		case 4:
			cout << "DrawRectangle" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + heigth + ":" + width;
			break;
		/*FillRectangle*/
		case 5:
			cout << "FillRectangle" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + heigth + ":" + width;
			break;
		/*DrawEllipse*/
		case 6:
			cout << "DrawEllipse" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + heigth + ":" + width;
			break;
		/*FillEllipse*/
		case 7:
			cout << "FillEllipse" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + heigth + ":" + width;
			break;
		/*DrawCircle*/
		case 8:
			cout << "DrawCircle" << endl;
			xyfirst = SetXYFirst();
			radius = SetRadius();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + radius;
			break;
		/*FillEllipse*/
		case 9:
			cout << "FillEllipse" << endl;
			xyfirst = SetXYFirst();
			radius = SetRadius();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + ":" + radius;
			break;
		/*DrawRoundedRectangle*/
		case 10:
			cout << "DrawRoundedRectangle" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			radius = SetRadius();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + heigth + ":" + width + ":" + radius;
			break;
		/*DrawRoundedRectangle*/
		case 11:
			cout << "DrawRoundedRectangle" << endl;
			xyfirst = SetXYFirst();
			heigth = SetHeigth();
			width = SetWidth();
			radius = SetRadius();
			color = SetColor();
			command = str + ":" + color + ":" + xyfirst + heigth + ":" + width + ":" + radius;
			break;
		/*DrawString*/
		case 12:
			cout << "DrawString" << endl;
			text = SetText();
			font = SetFont();
			xyfirst = SetXYFirst();
			command = str + ":" + xyfirst + ":" + text + ":" + font;
			break;
			/*RotateTransform*/
		case 13:
			cout << "RotateTransform" << endl;
			angle = SetAngle();
			command = str + ":" + angle;
			break;
		/*GetHiegth*/
		case 14:
			cout << "GetHiegth" << endl;
			command = str + ";";
			break;
		/*GetWidth*/
		case 15:
			cout << "GetWidth" << endl;
			command = str + ";";
			break;
		default:
			break;
	}
	return command + ":*";
}

int main()
{
	char buff[10 * 1014];
	setlocale(LC_ALL, "Rus");
	printf("UDP DEMO Client \nType quit to quit \n");
	string str, command;
	// Крок 1 - ініціалізація бібліотеки Winsock
	if (WSAStartup(0x202, (WSADATA*)&buff[0]))
	{
		printf("WSAStartup error : %d \n", WSAGetLastError());
		return -1;
	}

	// Крок 2 - відкриття сокета
	SOCKET my_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (my_sock == INVALID_SOCKET)
	{
		printf("socket() error: %d \n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	// Крок 3 - обмін повідомлень з сервером
	HOSTENT* hst;
	sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(PORT);
	// Визначення IP_адреса вузла
	if (inet_addr(SERVERADDR)){
		dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	} else {
		if (hst = gethostbyname(SERVERADDR)) {
			dest_addr.sin_addr.s_addr = ((unsigned long**)hst->h_addr_list)[0][0];
		} else {
			printf("Unknown host : %d \n", WSAGetLastError());
			closesocket(my_sock);
			WSACleanup();
			return -1;
		}
	}
	help();
	while (1) {
		cout << "////////////////////\nВведите команду или номер команды:" << endl;
		cin >> str;
		if (str == "command") {
			info_command();
		} else if (!PresenceOfLetters(str)) {
			int command_number = stoi(str);
			if (command_number >= 1 && command_number <= 15) {
				command = command_selection(command_number);
				if (size(command) < 10140) {
					strcpy(buff, command.c_str());

					// Передача повідомлень на сервер
					sendto(my_sock, &buff[0], strlen(&buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
					sockaddr_in server_addr;
					int server_addr_size = sizeof(server_addr);
					int n = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&server_addr, &server_addr_size);
					if (n == SOCKET_ERROR)
					{
						printf("recvfrom() error: %d \n", WSAGetLastError());
						closesocket(my_sock);
						WSACleanup();
						return -1;
					}
					buff[n] = 0;
				}
			}
		} else if (str == "quit") {
			break;
		} else {
			cout << "Не верный ввод!" << endl;
		}
	}
	closesocket(my_sock);
	WSACleanup();
	return 0;
}