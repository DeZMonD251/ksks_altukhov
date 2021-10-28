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
const int COMMAND_NOT_FOUND = -2;
const int INCORRECT_PARAMETERS = -1;
const int OK = 0;

using namespace std;

string uncorrect_simv = "abcdefghijklmnopqrstuvwxyz";
struct DATA {
    int number_command = 0, pointsXYfirst[2] = { 0, 0 }, pointsXYlast[2] = { 0,0 }, width = 0, height = 0, font = 0, color[3] = { 0, 0, 0 }, radius = 0, angle = 0;
    string text;
};

void split_string(string str, string delimiter, string* mas) {
    int i = 0, pos = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
        mas[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
}
bool presence_of_letters(string str) {
    /*true - если есть буква*/
    bool answer = false;
    for (size_t i = 0; i < size(uncorrect_simv); i++) {
        if (str.find(uncorrect_simv[i]) != string::npos) {
            answer = true;
            break;
        }
    }
    return answer;
}
int fill_struct_arr(DATA  *data, string sub_line, string command, string *temp) {
    if (command  == "pointsXYfirst") {
        split_string(sub_line, "@", temp);
        for (size_t i = 0; i < 2; i++) {
            if (!presence_of_letters(temp[i])) {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
    }
    else if (command == "pointsXYlast") {
        split_string(sub_line, "@", temp);
        for (size_t i = 0; i < 2; i++) {
            if (!presence_of_letters(temp[i])) {
                data->pointsXYlast[i] = stoi(temp[i]);
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
    }
    else if (command == "color") {
        split_string(sub_line, "#", temp);
        for (size_t i = 0; i < 3; i++) {
            if (!presence_of_letters(temp[i])) {
                if (stoi(temp[i]) >= 0 && stoi(temp[i]) <= 255) {
                    data->color[i] = stoi(temp[i]);
                }
                else {
                    return INCORRECT_PARAMETERS;
                }
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
    }
    else
    {
        return COMMAND_NOT_FOUND;
    }
    return OK;
}
int fill_struct(DATA* data, string sub_line, string command) {
    if (command == "width") {
        if (!presence_of_letters(sub_line)) {
            if (stoi(sub_line) >= 0) {
                data->width = stoi(sub_line);
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
        else {
            return INCORRECT_PARAMETERS;
        }
    }
    else if (command == "height") {
        if (!presence_of_letters(sub_line)) {
            if (stoi(sub_line) >= 0) {
                data->height = stoi(sub_line);
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
        else {
            return INCORRECT_PARAMETERS;
        }
    }
    else if (command == "angle") {
        if (!presence_of_letters(sub_line)) {
            data->angle = stoi(sub_line);
        }
        else {
            return INCORRECT_PARAMETERS;
        }
    }
    else if (command == "radius") {
        if (!presence_of_letters(sub_line)) {
            data->radius = stoi(sub_line);
        }
        else {
            return INCORRECT_PARAMETERS;
        }
    }
    else if (command == "font") {
        if (!presence_of_letters(sub_line)) {
            if (stoi(sub_line) >= 0) {
                data->font = stoi(sub_line);
            }
            else {
                return INCORRECT_PARAMETERS;
            }
        }
        else {
            return INCORRECT_PARAMETERS;
        }
    }
    else
    {
        return COMMAND_NOT_FOUND;
    }
    return OK;
}

int parser(string str, DATA* data) {
    int result, ans;
    string* temp = new string[50];
    string* main_line = new string[50];
    split_string(str, "*", main_line);
    string* sub_line = new string[50];
    split_string(main_line[0], ":", sub_line);
    data->number_command = stoi(sub_line[0]);
    if (data->number_command == CLEAR_DISPLAY) {
        /*clear display*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_PIXEL) {
        /*draw pixel*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 || fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 || fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_LINE) {
        /*draw line*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 || fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 || fill_struct_arr(data, sub_line[2], "pointsXYlast", temp) == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 || fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 || fill_struct_arr(data, sub_line[2], "pointsXYlast", temp) == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_RECTANGLE) {
        /*draw rectangle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 || 
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == FILL_RECTANGLE) {
        /*fill rectangle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_ELLIPSE) {
        /*draw ellipse*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == FILL_ELLIPSE) {
        /*fill ellipse*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_CIRCLE) {
        /*draw circle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "radius") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "radius") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == FILL_CIRCLE) {
        /*fill circle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "radius") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "radius") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_ROUNDED_RECTANGLE) {
        /*draw rounded rectangle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1 ||
            fill_struct(data, sub_line[5], "radius") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2 ||
            fill_struct(data, sub_line[5], "radius") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == FILL_ROUNDED_RECTANGLE) {
        /*fill rounded rectangle*/
        if (fill_struct_arr(data, sub_line[1], "color", temp) == -1 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "width") == -1 ||
            fill_struct(data, sub_line[4], "height") == -1 ||
            fill_struct(data, sub_line[5], "radius") == -1) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "color", temp) == -2 ||
            fill_struct_arr(data, sub_line[2], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "width") == -2 ||
            fill_struct(data, sub_line[4], "height") == -2 ||
            fill_struct(data, sub_line[5], "radius") == -2) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
    }
    else if (data->number_command == DRAW_TEXT) {
        /*draw text*/
        data->text = sub_line[2];
        if (fill_struct_arr(data, sub_line[1], "pointsXYfirst", temp) == -1 ||
            fill_struct(data, sub_line[3], "font") == -1 ) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        else if (fill_struct_arr(data, sub_line[1], "pointsXYfirst", temp) == -2 ||
            fill_struct(data, sub_line[3], "font") == -2 ) {
            result = COMMAND_NOT_FOUND;
            goto exit;
        }
        else {}
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
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == GET_WIDTH) {
        /*get width*/

    }
    else if (data->number_command == GET_HEIGTH) {
        /*get height*/
    }
    else {
        result = COMMAND_NOT_FOUND;
        return result;
    }
    result = OK;
    exit:
    delete[] main_line;
    delete[] sub_line;
    delete[] temp;
    return result;
}