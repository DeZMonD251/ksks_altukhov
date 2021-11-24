#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <sstream>
#include "Display.h"
#include <typeinfo>

#define PORT 777
#define SERVERADDR "127.0.0.1"

using namespace std;

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
int SetColor() {
	string str;
	int rgb[3];
	char rgb_[] = { 'R', 'G', 'B' };
	for (int i = 0; i < 3; i++) {
		bool a = true;
		while (a) {
			cout << "Введите цвет "<< rgb_[i] <<  " (0 - 255): " << endl;
			cin >> str;
			if (!PresenceOfLetters(str) && size(str) > 0) {
				rgb[i] = stoi(str);
				if (rgb[i] >= 0 && rgb[i] <= 255) {
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
	}
	return RGB(rgb[0], rgb[1], rgb[2]);
}
void SetXY(int* arr, int number_coord) {
	string str;
	char XY[] = {'X', 'Y'};
	int xy[2];
	for (int i = 0; i < 2; i++) {
		bool a = true;
		while (a) {
			cout << "Введите координату "<< XY[i] << number_coord <<": " << endl;
			cin >> str;
			if (!PresenceOfLetters(str) && size(str) > 0) {
				xy[i] = stoi(str);
				a = false;
			}
			else {
				cout << "Не верный ввод!" << endl;
			}
		}
		arr[i] = xy[i];
	}
}
int SetWidth() {
	string str;
	int width;
	bool a = true;
	while (a) {
		cout << "Введите ширину: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			width = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	return width;
}
int SetHeigth() {
	string str;
	int heigth;
	bool a = true;
	while (a) {
		cout << "Введите высоту: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			heigth = stoi(str);
			a = false;
		} else {
			cout << "Не верный ввод!" << endl;
		}
	}
	return heigth;
}
int SetRadius() {
	string str;
	int radius;
	bool a = true;
	while (a) {
		cout << "Введите радиус: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			radius = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	return radius;
}
int SetFont() {
	string str;
	int font;
	bool a = true;
	while (a) {
		cout << "Введите размер текста: " << endl;
		cin >> str;
		if (!PresenceOfLetters(str) && size(str) > 0) {
			font = stoi(str);
			a = false;
		}
		else {
			cout << "Не верный ввод!" << endl;
		}
	}
	return font;
}
string SetText() {
	string text;
	cout << "Введите текст: " << endl;
	getline(cin >> ws, text);
	return text;
}
void split_string(string str, string delimiter, string* mas) {
	int i = 0, pos = 0;
	while ((pos = str.find(delimiter)) != string::npos) {
		mas[i] = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
		i++;
	}
}
void command_selection(int command_number, Display *display) {
	string text;
	int xyfirst[2], xylast[2], width, heigth, radius, font;
	int color;
	string str = to_string(command_number);
	switch (command_number){
		/*Clear*/
		case 1:
			cout << "Clear" << endl;
			color = SetColor();
			display->fillScreen(color);
			break;
		/*SetPixel*/
		case 2:
			cout << "SetPixel" << endl;
			SetXY(xyfirst, 0);
			color = SetColor();
			display->drawPixel(xyfirst[0], xyfirst[1], color);
			break;
		/*DrawLine*/
		case 3:
			cout << "DrawLine" << endl;
			SetXY(xyfirst, 0);
			SetXY(xylast, 1);
			color = SetColor();
			display->drawLine(xyfirst[0], xyfirst[1], xylast[0], xylast[1], color);
			break;
		/*DrawRectangle*/
		case 4:
			cout << "DrawRectangle" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			display->drawRect(xyfirst[0], xyfirst[1], width, heigth, color);
			break;
		/*FillRectangle*/
		case 5:
			cout << "FillRectangle" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			display->fillRect(xyfirst[0], xyfirst[1], width, heigth, color);
			break;
		/*DrawEllipse*/
		case 6:
			cout << "DrawEllipse" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			display->drawEllipse(xyfirst[0], xyfirst[1], width, heigth, color);
			break;
		/*FillEllipse*/
		case 7:
			cout << "FillEllipse" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			color = SetColor();
			display->fillEllipse(xyfirst[0], xyfirst[1], width, heigth, color);
			break;
		/*DrawCircle*/
		case 8:
			cout << "DrawCircle" << endl;
			SetXY(xyfirst, 0);
			radius = SetRadius();
			color = SetColor();
			display->drawCircle(xyfirst[0], xyfirst[1], radius, color);
			break;
		/*FillEllipse*/
		case 9:
			cout << "FillCircle" << endl;
			SetXY(xyfirst, 0);
			radius = SetRadius();
			color = SetColor();
			display->fillCircle(xyfirst[0], xyfirst[1], radius, color);
			break;
		/*DrawRoundedRectangle*/
		case 10:
			cout << "DrawRoundedRectangle" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			radius = SetRadius();
			color = SetColor();
			display->drawRoudedRect(xyfirst[0], xyfirst[1], width, heigth, radius, color);
			break;
		/*DrawRoundedRectangle*/
		case 11:
			cout << "DrawRoundedRectangle" << endl;
			SetXY(xyfirst, 0);
			heigth = SetHeigth();
			width = SetWidth();
			radius = SetRadius();
			color = SetColor();
			display->fillRoudedRect(xyfirst[0], xyfirst[1], width, heigth, radius, color);
			break;
		/*DrawString*/
		case 12:
			cout << "DrawString" << endl;
			color = SetColor();
			text = SetText();
			font = SetFont();
			SetXY(xyfirst, 0);
			display->drawText(xyfirst[0], xyfirst[1], font, color, text);
			break;
		/*GetHiegth*/
		case 14:
			display->get_heigth();
			break;
		/*GetWidth*/
		case 15:
			display->get_width();
			break;
		default:
			break;
	}
}
string convert(int value) {
	string str;
	if (value < 10) {
		str = "0" + to_string(value);
	}
	else {
		str = to_string(value);
	}
	return str;
}

int main() {
	char buff[1024];
	int n;
	setlocale(LC_ALL, "Rus");
	printf("UDP DEMO Client \nType quit to quit \n");
	string str;
	if (WSAStartup(0x202, (WSADATA*)&buff[0])) {
		printf("WSAStartup error : %d \n", WSAGetLastError());
		return -1;
	}
	Display display = Display(320, 240, SERVERADDR, PORT);
	while (1) {
		time_t currentTime;
		struct tm* localTime;
		time(&currentTime);
		localTime = localtime(&currentTime);
		str = convert(localTime->tm_hour) + "." + convert(localTime->tm_min) + "." + convert(localTime->tm_sec);
		cout << str << endl;
		display.drawText(15, 15, 54, RGB(255, 255, 255), str);
		Sleep(1000);
	}
	WSACleanup();
	return 0;
}