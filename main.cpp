#include <stdio.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"

void showFirstMenu() {

}
int main() {
    int i;
    char keyPress;
    initwindow(windowWidth, windowHeight);
    int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;

MENU_FIRST:
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
    settextstyle(3, 0, 4);
    char *txt1[] = {"DO AN CO SO", "Ma de tai: 802 - GVHD: Nguyen Van Nguyen", "SV: Ho Van Vy | MSV: 102190200 | 19TCLC_DT4", "MENU", "Nhan Enter de mo menu, Esc de thoat chuong trinh"};
    outtextxy(hmaxx - textwidth(txt1[0]) / 2, 20, txt1[0]);
    setcolor(2);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[1]) / 2, 90, txt1[1]);
    outtextxy(hmaxx - textwidth(txt1[2]) / 2, 120, txt1[2]);
    setcolor(4);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[3]) / 2, hmaxy - textheight(txt1[3]) / 2, txt1[3]);
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[4]) / 2, maxy - 20, txt1[4]);

    do {
        keyPress = getch();
        printf("\a");
    } while (keyPress != ENTER && keyPress != ESC);
    if (keyPress == ESC) exit(0);

    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
    char *mainMenuList[] = {"Nhap du lieu tu file", "Nhap du lieu tu ban phim", "Thoat"};
    int lengthMainMenuList = 3;
    int tmp = maxy / 3;
    settextstyle(3, 0, 2);
    for (i = 0; i < lengthMainMenuList; i++) {
        if (i == 0)
            setcolor(4);
        else
            setcolor(2);
        tmp += textheight(mainMenuList[i]) + 10;
        outtextxy(hmaxx - textwidth(mainMenuList[i]) / 2, tmp, mainMenuList[i]);
    }

    int choice = 0;
    do {
        keyPress = getch();
        printf("\a");
        if (keyPress == UP_ARROW) choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
        else if (keyPress == DOWN_ARROW) choice = (choice + 1) % lengthMainMenuList;

        cleardevice();
        setcolor(3);
        rectangle(10, 10, maxx - 10, maxy - 10);
        settextstyle(3, 0, 2);
        tmp = maxy / 3;
        for (i = 0; i < lengthMainMenuList; i++) {
            if (i == choice)
                setcolor(4);
            else
                setcolor(2);
            tmp += textheight(mainMenuList[i]) + 10;
            outtextxy(hmaxx - textwidth(mainMenuList[i]) / 2, tmp, mainMenuList[i]);
        }
    } while (keyPress != ENTER);
    if (choice == lengthMainMenuList - 1) goto MENU_FIRST;

    // clear
    getch();
    closegraph();
    return 0;
}
