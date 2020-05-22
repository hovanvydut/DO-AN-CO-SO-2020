#include <stdio.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"
#include <string.h>
#include "myViewFunc.h"

int main() {
    int i;
    char keyPress;
    int choice;
    int heightBox = 40, widthBox = 200, marginBox = 25;

    // Menu 2
    char *mainMenuList[] = {"Nhap du lieu tu file", "Nhap du lieu tu ban phim", "Thoat"};
    int lengthMainMenuList = 3;

    //
    char *outputScreenMenu[] = {"Xuat ra man hinh", "Xuat ra file"};
    int lengthOutputScreenMenu = 2;

    initwindow(windowWidth, windowHeight);
    int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;

MENU_FIRST:
    showFirstMenu(maxx, hmaxx, maxy, hmaxy);
    do {
        keyPress = getch();
        printf("\a");
    } while (keyPress != ENTER && keyPress != ESC);
    if (keyPress == ESC) exit(0);


    showMenu2(maxx, hmaxx, maxy, hmaxy, 0, mainMenuList, lengthMainMenuList);

    choice = 0;
    do {
        keyPress = getch();
        printf("\a");

        if (keyPress == UP_ARROW)
            choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
        else if (keyPress == DOWN_ARROW)
            choice = (choice + 1) % lengthMainMenuList;

        showMenu2(maxx, hmaxx, maxy, hmaxy, choice, mainMenuList, lengthMainMenuList);
    } while (keyPress != ENTER);

    // Quay lai main menu
    if (choice == lengthMainMenuList - 1)
        goto MENU_FIRST;

    // Nhap du lieu tu file
    if (choice + 1 == 1) {
        cleardevice();
        outtext("Nhap du lieu tu file");

    // Nhap du lieu tu ban phim
    } else if (choice + 1 == 2) {
        int n, h, keyPressLocal;
        char ch[100] = "";
        int it = 0, it2 = 0;
        char ch2[100] = "";

        BOX1:
        // nhap so n
        showBox(maxx, hmaxx, maxy, hmaxy, 1, heightBox, widthBox, marginBox);
        outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ch) / 2, ch);
        outtextxy(hmaxx - widthBox / 2 + 5, hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(ch2) / 2, ch2);
        do {
            char tmp = getch();
            printf("\a");
            if (tmp >= 48 && tmp <= 57) {
                ch[it] = tmp;
                ch[it + 1] = '\0';
                it++;
            }
            if (tmp == BACKSPACE) {
                it = it < 0 ? 0 : it - 1;
                ch[it] = '\0';
            }

            n = char2Number(ch, it);
            if (tmp == TAB) {
                goto BOX2;
            }
            keyPressLocal = tmp;
            cleardevice();
            showBox(maxx, hmaxx, maxy, hmaxy, 1, heightBox, widthBox, marginBox);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ch) / 2, ch);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(ch2) / 2, ch2);
        } while (keyPressLocal != ENTER);


        BOX2:
        // nhap chieu cao h
        cleardevice();
        showBox(maxx, hmaxx, maxy, hmaxy, 2, heightBox, widthBox, marginBox);
        outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ch) / 2, ch);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(ch2) / 2, ch2);
        do {
            char tmp = getch();
            printf("\a");
            if (tmp >= 48 && tmp <= 57) {
                ch2[it2] = tmp;
                ch2[it2 + 1] = '\0';
                it2++;
            }
            if (tmp == BACKSPACE) {
                it2 = it2 < 0 ? 0 : it2 - 1;
                ch2[it2] = '\0';
            }
            h = char2Number(ch2, it2);
            if (tmp == TAB) {
                goto BOX1;
            }
            keyPressLocal = tmp;
            cleardevice();
            showBox(maxx, hmaxx, maxy, hmaxy, 2, heightBox, widthBox, marginBox);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ch) / 2, ch);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(ch2) / 2, ch2);
        } while (keyPressLocal != ENTER);

        printf("%d %d", n, h);
        //showMenu2(maxx, hmaxx, maxy, hmaxy, 0, outputScreenMenu, lengthOutputScreenMenu);
    }

    // clear
    getch();
    closegraph();
    return 0;
}
