#include <stdio.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"

// configure
int windowWidth = 1200;
int windowHeight = 700;

int main() {
    initwindow(windowWidth, windowHeight);

    // Body
    int mlBody = 10, mtBody = 10, mrBody = 10, mbBody = 10;
    int lBody = mlBody;
    int tBody = mtBody;
    int rBody = getmaxx() - mrBody;
    int bBody = getmaxy() - mbBody;
    setcolor(3);
    rectangle(lBody, tBody, rBody, bBody);

    // Header
    int heightHeader = 100, pdHeader = 10;
    int mlHeader = 10, mtHeader = 10, mrHeader = 10, mbHeader = 10;
    int lHeader = lBody + mlHeader;
    int tHeader = tBody + tHeader + mtHeader;
    int rHeader = getmaxx() - mrBody - mrHeader;
    int bHeader = tBody + tHeader + heightHeader;
    setcolor(3);
    rectangle(lHeader, tHeader, rHeader, bHeader);
    settextstyle(1, 0, 1);
    setcolor(4);
    outtextxy(lHeader + pdHeader, tHeader + pdHeader, "Danang University of Science and Technology");

    // Menu
    int mlMenu = 10, mtMenu = 10, mrMenu = 10, mbMenu = 10, pdMenu = 5;
    int lMenu = lBody + mlMenu;
    int tMenu = tBody + tHeader + heightHeader + mtMenu;
    int rMenu = (getmaxx() - mlBody - mrBody) / 3 - (mlMenu + mrMenu) + lMenu;
    int bMenu = getmaxy() - mbBody - mbMenu;
    setcolor(3);
    rectangle(lMenu, tMenu, rMenu , bMenu);

    char *textMenu[] = {"1. Thong tin do an", "2. Nhap du lieu tu file", "3. Nhap du lieu tu ban phim"};
    int textMenuLength = 3;
    settextstyle(8, 0, 2);
    setcolor(5);
    int tmp = 0;
    for (int i = 0; i < textMenuLength; i++) {
        tmp += textheight(textMenu[i]);
        outtextxy(lMenu + pdMenu, tMenu + pdMenu + tmp, textMenu[i]);
    }

    // clear
    getch();
    closegraph();
    return 0;
}
