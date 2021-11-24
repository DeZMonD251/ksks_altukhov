#pragma once
#ifndef Display_h
#define Display_h

#include <iostream>
#include "stdio.h"
#include <string.h>
#include "GraphicsLib.h"
using namespace std;

const int CLEAR_DISPLAY = 1;
const int DRAW_PIXEL = 2;
const int DRAW_LINE = 3;
const int DRAW_RECTANGLE = 4;
const int FILL_RECTANGLE = 5;
const int DRAW_ELLIPSE = 6;
const int FILL_ELLIPSE = 7;
const int DRAW_CIRCLE = 8;
const int FILL_CIRCLE = 9;
const int DRAW_ROUNDED_RECTANGLE = 10;
const int FILL_ROUNDED_RECTANGLE = 11;
const int DRAW_TEXT = 12;
const int GET_WIDTH = 15;
const int GET_HEIGTH = 16;
const int COMMAND_NOT_FOUND = -2;
const int INCORRECT_PARAMETERS = -1;
const int OK = 0;

void hexToRGB(uint16_t hexValue, int* arr) {
    int r = ((hexValue >> 11) & 0x1F);  // Extract the 5 R bits
    int g = ((hexValue >> 5) & 0x3F);   // Extract the 6 G bits
    int b = ((hexValue) & 0x1F);        // Extract the 5 B bits
    r = ((r * 255) / 31);
    g = ((g * 255) / 63);
    b = ((b * 255) / 31);
    arr[0] = r;
    arr[1] = g;
    arr[2] = b;
}

class Display : public GraphicsLib
{
public:
    Display(uint_least16_t w, uint_least16_t h, string servaddr_, int port_) : GraphicsLib(w, h) {
        servaddr = servaddr_;
        port = port_;
    };

    void fillScreen(uint_least16_t color) {
        hexToRGB(color, colorArr);
        snprintf(buffer, buffer_length, "1:%i#%i#%i#:*", colorArr[0], colorArr[1], colorArr[2]);
        sendCommand(buffer);
    };

    void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) {
        snprintf(buffer, buffer_length, "2:%i#%i#%i#:%i@%i@:*", colorArr[0], colorArr[1], colorArr[2], x0, y0);
        sendCommand(buffer);
    };

    void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "3:%i#%i#%i#:%i@%i@:%i@%i@:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, x1, y1
            );
            sendCommand(buffer);
    };

    void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "4:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, h, w
            );
            sendCommand(buffer);
    };

    void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "5:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, h, w
            );
            sendCommand(buffer);
    };

    void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "6:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, r_x, r_y
            );
            sendCommand(buffer);
    };

    void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "7:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, r_x, r_y
            );
            sendCommand(buffer);
    };

    void drawCircle(int_least16_t x0, int_least16_t y0, int_least16_t r, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "8:%i#%i#%i#:%i@%i@:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, r
            );
            sendCommand(buffer);
    }

    void fillCircle(int_least16_t x0, int_least16_t y0, int_least16_t r, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "9:%i#%i#%i#:%i@%i@:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, r
            );
            sendCommand(buffer);
    }

    void drawRoudedRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, int_least16_t r, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "10:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, w, h, r
            );
            sendCommand(buffer);
    }

    void fillRoudedRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, int_least16_t r, uint_least16_t color) {
        snprintf(
            buffer, buffer_length, "11:%i#%i#%i#:%i@%i@:%i:%i:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, w, h, r
            );
            sendCommand(buffer);
    }

    void drawText(int_least16_t x0, int_least16_t y0, uint_least16_t font, uint_least16_t color, string text) {
        snprintf(
            buffer, buffer_length, "12:%i#%i#%i#:%i@%i@:%i:%s:*", colorArr[0], colorArr[1], colorArr[2], x0, y0, font, text.c_str()
        );
        sendCommand(buffer);
    }

    int_least16_t get_heigth() {
        return heigth;
    }

    int_least16_t get_width() {
        return width;
    }
private:
    static const unsigned char buffer_length = 50;
    char buffer[buffer_length];
    int width, heigth, port, colorArr[3];
    string widthAndHeigth, servaddr;
    int sendCommand(const char* command) {
        SOCKET my_sock;
        my_sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (my_sock == INVALID_SOCKET)
        {
            printf("socket() error: %d \n", WSAGetLastError());
            WSACleanup();
            return -1;
        }
        HOSTENT* hst;
        sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port);
        if (inet_addr(servaddr.c_str())) {
            dest_addr.sin_addr.s_addr = inet_addr(servaddr.c_str());
        }
        else {
            if (hst = gethostbyname(servaddr.c_str())) {
                dest_addr.sin_addr.s_addr = ((unsigned long**)hst->h_addr_list)[0][0];
            }
            else {
                printf("Unknown host : %d \n", WSAGetLastError());
                closesocket(my_sock);
                WSACleanup();
                return -1;
            }
        }
        sendto(my_sock, command, strlen(command), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
        char buff[1024];
        sockaddr_in server_addr;
        int server_addr_size = sizeof(server_addr);
        int n = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&server_addr, &server_addr_size);
        buff[n] = '\0';
        widthAndHeigth = (const char*)buff;
        if (n == SOCKET_ERROR) {
            printf("recvfrom() error: %d \n", WSAGetLastError());
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }
        parser(widthAndHeigth);
    }
    void parser(string str) {
        string* main_line = new string[50];
        split_string(str, "*", main_line);
        string* sub_line = new string[50];
        split_string(main_line[0], ":", sub_line);
        width = stoi(sub_line[0]);
        heigth = stoi(sub_line[1]);
        delete[] main_line;
        delete[] sub_line;
    }
    void split_string(string str, string delimiter, string* mas) {
        int i = 0, pos = 0;
        while ((pos = str.find(delimiter)) != string::npos) {
            mas[i] = str.substr(0, pos);
            str.erase(0, pos + delimiter.length());
            i++;
        }
    }
};

#endif //Display_h
