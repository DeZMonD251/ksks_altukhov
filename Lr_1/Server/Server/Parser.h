#pragma once
#include <stdio.h>
#include <string.h>
#include <sstream>
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
    string* main_line = new string[50];/*2:12#12#12#:50@48@:*ÌÌÌÌÌ => 2:12#12#12:50@48@: and ÌÌÌÌÌ*/
    highlightingTheMainLine(str, "*", main_line);
    string* sub_line = new string[50];/*2:12#12#12:50@48@: => 2 and 12#12#12 and 50@48@*/
    highlightingTheMainLine(main_line[0], ":", sub_line);
    data->number_command = stoi(sub_line[0]);
    if (data->number_command == 1) {
        /*clear display*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
    }
    else if (data->number_command == 2) {
        /*draw pixel*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
    }
    else if (data->number_command == 3) {
        /*draw line*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[3], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYlast[i] = stoi(temp[i]);
        }
    }
    else if (data->number_command == 4) {
        /*draw rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
    }
    else if (data->number_command == 5) {
        /*fill rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
    }
    else if (data->number_command == 6) {
        /*draw ellipse*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
    }
    else if (data->number_command == 7) {
        /*fill ellipse*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
    }
    else if (data->number_command == 8) {
        /*draw circle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->radius = stoi(sub_line[3]);
    }
    else if (data->number_command == 9) {
        /*fill circle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->radius = stoi(sub_line[3]);
    }
    else if (data->number_command == 10) {
        /*draw rounded rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
        data->radius = stoi(sub_line[5]);
    }
    else if (data->number_command == 11) {
        /*fill rounded rectangle*/
        highlightingTheMainLine(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            data->color[i] = stoi(temp[i]);
        }
        highlightingTheMainLine(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->wigth = stoi(sub_line[3]);
        data->heidth = stoi(sub_line[4]);
        data->radius = stoi(sub_line[5]);
    }
    else if (data->number_command == 12) {
        /*draw text*/
        highlightingTheMainLine(sub_line[1], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            data->pointsXYfirst[i] = stoi(temp[i]);
        }
        data->text = sub_line[2];
        data->font = stoi(sub_line[3]);
    }
    else if (data->number_command == 13) {
        /*draw image*/
    }
    else if (data->number_command == 14) {
        /*set orientation*/
        data->angle = stoi(sub_line[1]);
    }
    else if (data->number_command == 15) {
        /*get width*/

    }
    else if (data->number_command == 16) {
        /*get height*/
    }
    else {
        //cout << "Îøèáêà. Êîìàíäà íå íàéäåíà." << endl;
    }
    delete[] main_line;
    delete[] sub_line;
    delete[] temp;
    return data->color[0];
}