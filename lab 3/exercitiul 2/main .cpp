#include "Canvas.h"

int main() {
    Canvas canvas(20, 10);

   
    canvas.DrawLine(1,1,7, 5, '*');
    canvas.DrawCircle(3, 4, 2, '*');
    canvas.FillCircle(3, 4, 2, '*');
    canvas.DrawRect(1, 1, 7, 5, '*');
    canvas.FillRect(1, 1, 7, 5, '*');
    canvas.SetPoint(7,5, '*');
    canvas.Print();
    canvas.Clear();

    return 0;
}