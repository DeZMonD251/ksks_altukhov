#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <clocale>
#include <string.h>
#include <sstream>
#include <Windows.h>
#define PORT 777 // порт сервера
#define sHELLO "Hello,%s [%s] Student  \n"

using namespace std;
string myarray[16][2] = {
        {"1","clear display",},
        {"2","draw pixel"},
        {"3","draw line"},
        {"4","draw rectangle"},
        {"5","fill rectangle"},
        {"6","draw ellipse"},
        {"7","fill ellipse"},
        {"8","draw circle"},
        {"9","fill circle"},
        {"10","draw rounded rectangle"},
        {"11","fill rounded rectangle"},
        {"12","draw text"},
        {"13","draw image"},
        {"14","set orientation"},
        {"15","get width"},
        {"16","get height"}
};
void highlightingTheMainLine(string str, string delimiter, string* mas) {
    int i = 0, pos = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
        mas[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
}
void command_selection(string str, HDC hdc) {
    int pointsXYfirst[2], pointsXYlast[2], wigth, heidth, font, color[3], radius, angle;
    string text;
    string* temp = new string[50];
    string* main_line = new string[50];/*2:12#12#12:50@48@:*МММММ => 2:12#12#12:50@48@: and МММММ*/
    highlightingTheMainLine(str, "*", main_line);
    string* sub_line = new string[50];/*2:12#12#12:50@48@: => 2 and 12#12#12 and 50@48@*/
    highlightingTheMainLine(main_line[0], ":", sub_line);
    int number_command = stoi(sub_line[0]);
    switch (number_command) {
        /*clear display*/
    case 1:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        cout << "Введена команда " << myarray[number_command][1] << " с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        //system("cls");
        break;
        /*draw pixel*/
    case 2:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        //SetPixel(hdc, pointsXYfirst[0], pointsXYfirst[1], RGB(color[0], color[1], color[2]));
        break;
        /*draw line*/
    case 3:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[3], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYlast[i] = stoi(temp[i]);
        }
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "x1 - " << pointsXYlast[0] << "; y1 - " << pointsXYlast[1] << endl;
        break;
        /*draw rectangle*/
    case 4:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "w - " << wigth << "; y - " << heidth << endl;
        break;
        /*fill rectangle*/
    case 5:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "w - " << wigth << "; y - " << heidth << endl;
        break;
        /*draw ellipse*/
    case 6:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "r_x - " << wigth << "; r_y - " << heidth << endl;
        break;
        /*fill ellipse*/
    case 7:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "r_x - " << wigth << "; r_y - " << heidth << endl;
        break;
        /*draw circle*/
    case 8:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        radius = stoi(sub_line[3]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "radius - " << radius << endl;
        break;
        /*fill circle*/
    case 9:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        radius = stoi(sub_line[3]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "radius - " << radius << endl;
        break;
        /*draw rounded rectangle*/
    case 10:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        radius = stoi(sub_line[5]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "w - " << wigth << "; y - " << heidth << endl;
        cout << "radius - " << radius << endl;
        break;
        /*fill rounded rectangle*/
    case 11:
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        wigth = stoi(sub_line[3]);
        heidth = stoi(sub_line[4]);
        radius = stoi(sub_line[5]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:\n" << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "w - " << wigth << "; y - " << heidth << endl;
        cout << "radius - " << radius << endl;
        break;
        /*draw text*/
    case 12:
        highlightingTheMainLine(sub_line[1], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            pointsXYfirst[i] = stoi(temp[i]);
        }
        text = sub_line[2];
        font = stoi(sub_line[3]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:" << endl;
        //cout << "color: R - " << color[0] << "; G - " << color[1] << "; B - " << color[2] << endl;
        cout << "x0 - " << pointsXYfirst[0] << "; y0 - " << pointsXYfirst[1] << endl;
        cout << "font - " << font << endl;
        cout << "text - " << text << endl;
        break;
        /*set orientation*/
    case 14:
        angle = stoi(sub_line[1]);
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:" << endl;
        cout << "angle - " << angle << endl;
        break;
        /*get width*/
    case 15:
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:" << endl;
        cout << "w - 1000" << endl;
        break;
        /*get height*/
    case 16:
        cout << "Введена команда " << myarray[number_command][1] << "с параметрами:" << endl;
        cout << "y - 800" << endl;
        break;
    default:
        break;
    }
    delete[] main_line;
    delete[] sub_line;
    delete[] temp;
}
int main(int argc, char* argv[])
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    char buff[10 * 1014];
    setlocale(LC_ALL, "Rus");
    string command_client;
    printf("UDP DEMO echo_Server \n");
    
    // Крок 1 - підключення бібліотеки
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        printf("WSAStartup error : %d \n", WSAGetLastError());
        return -1;
    }
    // Крок 2 - створення сокета
    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (my_sock == INVALID_SOCKET)
    {
        printf("Socket() error: %d \n", WSAGetLastError());
        WSACleanup();
        return -1;
    }
    // Крок 3 - зв'язування сокета з локальною адресою
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);
    if (bind(my_sock, (sockaddr*)&local_addr, sizeof(local_addr)))
    {
        printf("bind error : %d \n", WSAGetLastError());
        closesocket(my_sock);
        WSACleanup();
        return -1;
    }
    // Крок 4 - обробка пакетів, надісланих клієнтами
    while (1)
    {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int bsize = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
        command_client = string(buff);
        command_selection(command_client, hdc);
        /////
        if (bsize == SOCKET_ERROR)
            printf("recvfrom() error: %d \n", WSAGetLastError());
        // Визначаємо IP-адреса клієнта і інші атрибути
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
        //printf(" + %s[%s:%d] new DATAGRAM!\n", (hst) ? hst->h_name : "Unknown host", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Додавання завершального нуля
        buff[bsize] = 0;
        // Вивід на екран
        //printf("C = > S: %s \n", &buff[0]);
        // Посилка дейтаграми клієнту
        sendto(my_sock, &buff[0], bsize, 0, (sockaddr*)&client_addr, sizeof(client_addr));
    }
    ReleaseDC(hwnd, hdc);
    std::cin.ignore();
    return 0;
}