#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)  
{
    this->height = height;
    this->width = width;
    canvas = new char* [height];
    for (int i = 0; i < height; ++i) {
        canvas[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}


void Canvas::DrawCircle(int x, int y, int ray, char ch)
{

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1)) && ((i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1)))
            {
                canvas[i][j] = ch;
            }
            else
                canvas[i][j] = ' ';
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <=ray*ray)
            {
                canvas[i][j] = ch;
            }
            else
                canvas[i][j] = ' ';
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
        if(i==top ||  i==bottom || j==left || j==right)
           canvas[i][j] = ch;
        }
    }

}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            canvas[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height) {
         canvas[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    int error = 0;
    int deltaError = (deltaY / deltaX);
    int Y = y1;
    for (int X = x1; X <= x2; ++X) {
        canvas[X][Y] = ch;
        error = error + deltaError;
           if (error >= 0.5) {
                 ++Y;
                 error -= 1.0;
               }
        }
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}

