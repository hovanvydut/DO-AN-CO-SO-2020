#include <stdio.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"


int main() {
    initwindow(windowWidth, windowHeight);

    // Body
    const int mlBody = 10, mtBody = 10, mrBody = 10, mbBody = 10;
    const int lBody = mlBody;
    const int tBody = mtBody;
    const int rBody = getmaxx() - mrBody;
    const int bBody = getmaxy() - mbBody;
    setcolor(3);
    rectangle(lBody, tBody, rBody, bBody);

    // Header
    const int heightHeader = 100, pdHeader = 10;
    const int mlHeader = 10, mtHeader = 10, mrHeader = 10, mbHeader = 10;
    const int lHeader = lBody + mlHeader;
    const int tHeader = tBody + tHeader + mtHeader;
    const int rHeader = getmaxx() - mrBody - mrHeader;
    const int bHeader = tBody + tHeader + heightHeader;
    setcolor(3);
    rectangle(lHeader, tHeader, rHeader, bHeader);
    settextstyle(9, 0, 1);
    setcolor(4);
    outtextxy(lHeader + pdHeader, tHeader + pdHeader, "Danang University of Science and Technology");

    // Menu
    const int mlMenu = 10, mtMenu = 10, mrMenu = 10, mbMenu = 10, pdMenu = 5;
    const int lMenu = lBody + mlMenu;
    const int tMenu = tBody + tHeader + heightHeader + mtMenu;
    const int rMenu = (getmaxx() - mlBody - mrBody) / 3 - (mlMenu + mrMenu) + lMenu;
    const int bMenu = getmaxy() - mbBody - mbMenu;
    setcolor(3);
    rectangle(lMenu, tMenu, rMenu , bMenu);

    char *textMenu[] = {"1. Thong tin do an", "2. Nhap du lieu tu file",
                        "3. Nhap du lieu tu ban phim", "4. Thoat"};
    const int textMenuLength = 4;
    settextstyle(8, 0, 2);
    setcolor(5);
    int tmp = 0;
    for (int i = 0; i < textMenuLength; i++) {
        tmp += textheight(textMenu[i]);
        outtextxy(lMenu + pdMenu, tMenu + pdMenu + tmp, textMenu[i]);
    }

    int choiceMenu = 1;
    char c;
    do {
        c = getch();
        switch(c) {
            case DOWN_ARROW: {
                choiceMenu++;
                if (choiceMenu > textMenuLength)
                    choiceMenu = 1;
                if (choiceMenu < 1)
                    choiceMenu = 1;
                break;
            }
            case UP_ARROW: {
                choiceMenu--;
                if (choiceMenu > textMenuLength)
                    choiceMenu = 1;
                if (choiceMenu < 1)
                    choiceMenu = textMenuLength;
                break;
            }
        }

        cleardevice();
        setcolor(3);
        rectangle(lBody, tBody, rBody, bBody);
        setcolor(3);
        rectangle(lHeader, tHeader, rHeader, bHeader);
        settextstyle(9, 0, 1);
        setcolor(4);
        outtextxy(lHeader + pdHeader, tHeader + pdHeader, "Danang University of Science and Technology");
        setcolor(3);
        rectangle(lMenu, tMenu, rMenu , bMenu);

        tmp = 0;
        settextstyle(8, 0, 2);
        for (int i = 0; i < -1; i++);
    } while (c != ENTER);

    // clear
    getch();
    closegraph();
    return 0;
}
