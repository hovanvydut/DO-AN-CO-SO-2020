#include <stdio.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"
#include <string.h>

void showFirstMenu(int maxx, int hmaxx, int maxy, int hmaxy) {
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
}

void showMenu2(int maxx, int hmaxx, int maxy, int hmaxy, int choice, char *menuList[], int lenMenu) {
    int i;
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);

    int tmp = maxy / 3;
    settextstyle(3, 0, 3);
    for (i = 0; i < lenMenu; i++) {
        if (i == choice)
            setcolor(4);
        else
            setcolor(2);
        tmp += textheight(menuList[i]) + 10;
        outtextxy(hmaxx - textwidth(menuList[i]) / 2, tmp, menuList[i]);
    }
    char guide[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon";
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}

void showBox(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox) {
        int heightBox = 40, widthBox = 200, marginBox = 25;
        char txt1[] = "Nhap n: ", txt2[] = "Nhap h: ";
        cleardevice();
        // Box n
        chooseBox == 1 ? setcolor(4) : setcolor(3);
        rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
        // Box h
        chooseBox == 2 ? setcolor(4) : setcolor(3);
        rectangle(hmaxx - widthBox / 2, hmaxy + marginBox, hmaxx + widthBox, hmaxy + (heightBox + marginBox));

        outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt1) / 2, txt1);
        outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(txt1) / 2, txt2);

    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
        char guide[] = "Dung phim tab de di chuyen giua cac box, enter de xac nhan";
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}

int char2Number(char ch[], int len) {
    int sum = 0, pow = 1, i = 0;
    for (i = len - 1; i > 0; i--) {
        sum += ch[i] * pow;
        pow *= 10;
    }
    return sum;
}

int main() {
    int i;
    char keyPress;
    int choice;

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

        showBox(maxx, hmaxx, maxy, hmaxy, 1);

        int it = 0;
        do {
            char tmp = getch();
            printf("\a");
            if (tmp >= 48 && tmp <= 57) {
                ch[it] = tmp;
                ch[it + 1] = '\0';
                it++;
            }
            char ch2[100];
            strcpy(ch2, ch);
            outtextxy(100, 100, ch2);
        } while (keyPressLocal != ENTER);
        //showMenu2(maxx, hmaxx, maxy, hmaxy, 0, outputScreenMenu, lengthOutputScreenMenu);
    }

    // clear
    getch();
    closegraph();
    return 0;
}
