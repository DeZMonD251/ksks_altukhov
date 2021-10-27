#pragma once
#include <stdio.h>
#include <string.h>
#include <sstream>
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
const int DRAW_IMGAGE = 13;
const int SET_ORIENTATION = 14;
const int GET_WIDTH = 15;
const int GET_HEIGTH = 16;

using namespace std;

struct DATA {
    int number_command = 0, pointsXYfirst[2] = { 0, 0 }, pointsXYlast[2] = { 0,0 }, wigth = 0, heidth = 0, font = 0, color[3] = { 0, 0, 0 }, radius = 0, angle = 0;
    string text;
};
void highlightingTheMainLine(string str, string delimiter, string* mas) {
    int i = 0, pos = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
        mas[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
}
int parser(string str, DATA* data) {
    string* temp = new string[50];
    string* main_line = new string[50];/*2:12#12#12#:50@48@:*ллллл => 2:12#12#12:50@48@: and ллллл*/
    highlightingTheMainLine(str, "*", main_line);
    string* sub_line = new string[50];/*2:12#12#12:50@48@: => 2 and 12#12#12 and 50@48@*/
    highlightingTheMainLine(main_line[0], ":", sub_line);
    data->number_command = stoi(sub_line[0]);
    if (data->number_command == CLEAR_DISPLAY) {
        /*clear display*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line;delete[] sub_line;delete[] temp;
                return -1;
            }
        }
    }
    else if (data->number_command == DRAW_PIXEL) {
        /*draw pixel*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
    }
    else if (data->number_command == DRAW_LINE) {
        /*draw line*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
        highlightingTheMainLine(sub_line[3], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYlast[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
    }
    else if (data->number_command == DRAW_RECTANGLE) {
        /*draw rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;
                return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        } catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        } catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        
        
    }
    else if (data->number_command == FILL_RECTANGLE) {
        /*fill rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == DRAW_ELLIPSE) {
        /*draw ellipse*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp;return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == FILL_ELLIPSE) {
        /*fill ellipse*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == DRAW_CIRCLE) {
        /*draw circle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->radius = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == FILL_CIRCLE) {
        /*fill circle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->radius = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == DRAW_ROUNDED_RECTANGLE) {
        /*draw rounded rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->radius = stoi(sub_line[5]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == FILL_ROUNDED_RECTANGLE) {
        /*fill rounded rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        try {
            data->wigth = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->heidth = stoi(sub_line[4]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
        try {
            data->radius = stoi(sub_line[5]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == DRAW_TEXT) {
        /*draw text*/
        highlightingTheMainLine(sub_line[1], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                delete[] main_line; delete[] sub_line; delete[] temp; return -1;
            }
        }
        data->text = sub_line[2];
        try {
            data->font = stoi(sub_line[3]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == DRAW_IMGAGE) {
        /*draw image*/
    }
    else if (data->number_command == SET_ORIENTATION) {
        /*set orientation*/
        try {
            data->angle = stoi(sub_line[1]);
        }
        catch (const std::exception&) {
            delete[] main_line; delete[] sub_line; delete[] temp; return -1;
        }
    }
    else if (data->number_command == GET_WIDTH) {
        /*get width*/

    }
    else if (data->number_command == GET_HEIGTH) {
        /*get height*/
    }
    else {
    return -2;
    }
    delete[] main_line;
    delete[] sub_line;
    delete[] temp;
    return 0;}