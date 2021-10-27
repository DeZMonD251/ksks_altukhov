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
const int PARSER_OK = 0;
using namespace std;

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
int parser(string str, DATA* data) {
    int result;
    string* temp = new string[50];
    string* main_line = new string[50];/*2:12#12#12#:50@48@:*ллллл => 2:12#12#12:50@48@: and ллллл*/
    split_string(str, "*", main_line);
    string* sub_line = new string[50];/*2:12#12#12:50@48@: => 2 and 12#12#12 and 50@48@*/
    split_string(main_line[0], ":", sub_line);
    data->number_command = stoi(sub_line[0]);
    if (data->number_command == CLEAR_DISPLAY) {
        /*clear display*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
    }
    else if (data->number_command == DRAW_PIXEL) {
        /*draw pixel*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
    }
    else if (data->number_command == DRAW_LINE) {
        /*draw line*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[3], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYlast[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
    }
    else if (data->number_command == DRAW_RECTANGLE) {
        /*draw rectangle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        } catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        } catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == FILL_RECTANGLE) {
        /*fill rectangle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == DRAW_ELLIPSE) {
        /*draw ellipse*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == FILL_ELLIPSE) {
        /*fill ellipse*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == DRAW_CIRCLE) {
        /*draw circle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->radius = stoi(sub_line[3]);
            if (data->radius < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == FILL_CIRCLE) {
        /*fill circle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->radius = stoi(sub_line[3]);
            if (data->radius < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == DRAW_ROUNDED_RECTANGLE) {
        /*draw rounded rectangle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->radius = stoi(sub_line[5]);
            if (data->radius < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == FILL_ROUNDED_RECTANGLE) {
        /*fill rounded rectangle*/
        split_string(sub_line[1], "#", temp);
        for (size_t i = 0; i < 3; i++) {
            try
            {
                data->color[i] = stoi(temp[i]);
                if (data->color[i] < 0 || data->color[i] > 255) {
                    result = INCORRECT_PARAMETERS;
                    goto exit;
                }
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        split_string(sub_line[2], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        try {
            data->width = stoi(sub_line[3]);
            if (data->width < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->height = stoi(sub_line[4]);
            if (data->height < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
        try {
            data->radius = stoi(sub_line[5]);
            if (data->radius < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
        }
    }
    else if (data->number_command == DRAW_TEXT) {
        /*draw text*/
        split_string(sub_line[1], "@", temp);
        for (size_t i = 0; i < 2; i++) {
            try
            {
                data->pointsXYfirst[i] = stoi(temp[i]);
            }
            catch (const std::exception&)
            {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        data->text = sub_line[2];
        try {
            data->font = stoi(sub_line[3]);
            if (data->font < 0) {
                result = INCORRECT_PARAMETERS;
                goto exit;
            }
        }
        catch (const std::exception&) {
            result = INCORRECT_PARAMETERS;
            goto exit;
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
    result = PARSER_OK;
    exit:
    delete[] main_line;
    delete[] sub_line;
    delete[] temp;
    return result;
}