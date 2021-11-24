#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <clocale>
#include <string.h>
#include <sstream>
#include <Windows.h>
#include "RoundedRectangleShape.hpp"
#include "Parser.h"
#define PORT 777 // порт сервера

const int WIDTH = 1000;
const int HEIGTH = 800;

using namespace sf;
using namespace std;

DATA* datA;
char fontArr[] = { "Roboto-Bold.ttf" };
int bgColor[3] = { 0, 0, 0 };

DWORD WINAPI execute_command(LPVOID lpParam) {
    RenderWindow window(VideoMode(WIDTH, HEIGTH), "Lr2KSKS");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (datA->number_command == CLEAR_DISPLAY) {
            bgColor[0] = datA->color[0];
            bgColor[1] = datA->color[1];
            bgColor[2] = datA->color[2];
            window.clear(Color(datA->color[0], datA->color[1], datA->color[2]));
        }
        else if (datA->number_command == DRAW_PIXEL) {
            RectangleShape pixel(Vector2f(1, 1));
            pixel.setFillColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            pixel.setOutlineColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            pixel.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(pixel);
        }
        else if (datA->number_command == DRAW_LINE) {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(datA->pointsXYfirst[0], datA->pointsXYfirst[1]), Color(datA->color[0], datA->color[1], datA->color[2])),
                sf::Vertex(sf::Vector2f(datA->pointsXYlast[0], datA->pointsXYlast[0]), Color(datA->color[0], datA->color[1], datA->color[2]))
            };
            window.draw(line, 2, sf::Lines);
        }
        else if (datA->number_command == DRAW_RECTANGLE) {
            RectangleShape rectangle;
            rectangle.setSize(Vector2f(datA->width, datA->height));
            rectangle.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            rectangle.setFillColor(Color(bgColor[0], bgColor[1], bgColor[2]));
            rectangle.setOutlineThickness(1);
            rectangle.setOutlineColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            window.draw(rectangle);
        }
        else if (datA->number_command == FILL_RECTANGLE) {
            RectangleShape rectangle;
            rectangle.setSize(Vector2f(datA->width, datA->height));
            rectangle.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            rectangle.setFillColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            window.draw(rectangle);
        }
        else if (datA->number_command == DRAW_ELLIPSE) {
            CircleShape ellipse(datA->height);
            float sub = (float)(datA->height) / (float)(datA->width);
            ellipse.setFillColor(Color(bgColor[0], bgColor[1], bgColor[2]));
            ellipse.setOutlineThickness(1);
            ellipse.setOutlineColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            ellipse.setScale(1.f, sub);
            ellipse.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(ellipse);
        }
        else if (datA->number_command == FILL_ELLIPSE) {
            CircleShape ellipse(datA->height);
            float sub = (float)(datA->height) / (float)(datA->width);
            ellipse.setFillColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            ellipse.setScale(1.f, sub);
            ellipse.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(ellipse);
        }
        else if (datA->number_command == DRAW_CIRCLE) {
            CircleShape circle;
            circle.setRadius(datA->radius);
            circle.setOutlineColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            circle.setOutlineThickness(1);
            circle.setFillColor(Color(bgColor[0], bgColor[1], bgColor[2]));
            circle.setPosition(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(circle);
        }
        else if (datA->number_command == FILL_CIRCLE) {
            CircleShape circle;
            circle.setRadius(datA->radius);
            circle.setFillColor(Color(bgColor[0], bgColor[1], bgColor[2]));
            circle.setPosition(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(circle);
        }
        else if (datA->number_command == DRAW_ROUNDED_RECTANGLE) {
            RoundedRectangleShape filledRoundedRectangle(Vector2f(datA->width, datA->height), datA->radius, 100);
            filledRoundedRectangle.setFillColor(Color(bgColor[0], bgColor[1], bgColor[2]));
            filledRoundedRectangle.setOutlineThickness(1);
            filledRoundedRectangle.setOutlineColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            filledRoundedRectangle.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(filledRoundedRectangle);
        }
        else if (datA->number_command == FILL_ROUNDED_RECTANGLE) {
            RoundedRectangleShape filledRoundedRectangle(Vector2f(datA->width, datA->height), datA->radius, 100);
            filledRoundedRectangle.setFillColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            filledRoundedRectangle.move(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(filledRoundedRectangle);
        }
        else if (datA->number_command == DRAW_TEXT) {
            Font font;
            if (!font.loadFromFile(fontArr)) {
                cout << "Font upload error" << endl;
            }
            Text text;
            text.setFont(font);
            text.setString(datA->text);
            text.setCharacterSize(datA->font);
            text.setFillColor(Color(datA->color[0], datA->color[1], datA->color[2]));
            text.setPosition(datA->pointsXYfirst[0], datA->pointsXYfirst[1]);
            window.draw(text);
        }
        else if (datA->number_command == DRAW_IMGAGE) {}
        else if (datA->number_command == SET_ORIENTATION) {}
        else if (datA->number_command == GET_WIDTH) {}
        else if (datA->number_command == GET_HEIGTH) {}
        else {}
        window.display();
    }
    return OK;
}

int main(int argc, char* argv[]) {
    DATA d;
    datA = &d;
    DWORD dwThreadId, dwThrdParam = 1;
    HANDLE hThread = CreateThread(NULL, 0, execute_command, &dwThrdParam, 0, &dwThreadId);
    char buff[1024];
    setlocale(LC_ALL, "Rus");
    string command_client, send_command;
    printf("UDP DEMO echo_Server \n");
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        printf("WSAStartup error : %d \n", WSAGetLastError());
        return -1;
    }
    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (my_sock == INVALID_SOCKET)
    {
        printf("Socket() error: %d \n", WSAGetLastError());
        WSACleanup();
        return -1;
    }
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
    while (1) {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int bsize = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
        command_client = string(buff);
        cout << command_client << endl;
        send_command = to_string(HEIGTH) + ":" + to_string(WIDTH) + ":*";
        const char* str = send_command.c_str();
        sendto(my_sock, str, send_command.size(), 0, (sockaddr*)&client_addr, sizeof(client_addr));
        send_command = "";
        if (parser(command_client, datA) == OK) {}
        if (parser(command_client, datA) == INCORRECT_PARAMETERS) {
            cout << "Ошибка! Некорректные парамметры функции!" << endl;
        }
        if (parser(command_client, datA) == COMMAND_NOT_FOUND) {
            cout << "Ошибка! Функция не найдена!" << endl;
        }
        if (bsize == SOCKET_ERROR)
            printf("recvfrom() error: %d \n", WSAGetLastError());
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
    }
    CloseHandle(hThread);
    return 0;
}