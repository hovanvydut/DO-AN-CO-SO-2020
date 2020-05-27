#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include "calculate-utility.h"
#include "myConstant.h"
#include <string.h>
#include "myViewFunc.h"
#include <malloc.h>

int main() {
    int i;
    char keyPress;
    int choice;
    int heightBox = 40, widthBox = 200, marginBox = 25;

    // initial config
    initwindow(windowWidth, windowHeight);
    int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;

MENU_FIRST:
    showFirstMenu(maxx, hmaxx, maxy, hmaxy);
    do {
        keyPress = getch();
        if (keyPress != 0) printf("\a");
    } while (keyPress != ENTER && keyPress != ESC);
    if (keyPress == ESC) exit(0);

MENU_SECOND:
    // Menu 2
    char *mainMenuList[] = {"Nhap du lieu tu file", "Nhap du lieu tu ban phim"};
    int lengthMainMenuList = 2;
    char guide1[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
    showMenu2(maxx, hmaxx, maxy, hmaxy, 0, mainMenuList, lengthMainMenuList, guide1);

    choice = 0;
    do {
        keyPress = getch();
        if (keyPress != 0) printf("\a");

        if (keyPress == UP_ARROW)
            choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
        else if (keyPress == DOWN_ARROW)
            choice = (choice + 1) % lengthMainMenuList;
        else if (keyPress == ESC) {
            goto MENU_FIRST;
        }
        showMenu2(maxx, hmaxx, maxy, hmaxy, choice, mainMenuList, lengthMainMenuList, guide1);
    } while (keyPress != ENTER);

    // Nhap du lieu tu file
    if (choice + 1 == 1) {
        // ve khung bao quanh
        cleardevice();
        setcolor(3);
        rectangle(10, 10, maxx - 10, maxy - 10);

        char fileInputName[100];
        int it = 0, keyPressLocal;
        showBox(maxx, hmaxx, maxy, hmaxy, 0, heightBox, widthBox, marginBox);
        do {
            char tmp = getch();
            if (tmp != 0)  printf("\a");

            if (tmp == BACKSPACE) {
                it = it < 0 ? 0 : it - 1;
                fileInputName[it] = '\0';
            } else if (tmp == ESC) {
                goto MENU_SECOND;
            } else {
                fileInputName[it] = tmp;
                fileInputName[it + 1] = '\0';
                it++;
            }
            keyPressLocal = tmp;
            cleardevice();
            showBox(maxx, hmaxx, maxy, hmaxy, 0, heightBox, widthBox, marginBox);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(fileInputName) / 2, fileInputName);
        } while (keyPressLocal != ENTER);

        int *n = 0;
        int *h = 0;
        printf("%s\n", fileInputName);
        int errorFile = readDataFromFile(fileInputName, n, h);
        printf("%d %d", *n, *h);

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
            if (tmp != 0)  printf("\a");
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
            } else if (tmp == ESC) {
                goto MENU_SECOND;
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
            if (tmp != 0)  printf("\a");
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
            } else if (tmp == ESC) {
                goto MENU_SECOND;
            }
            keyPressLocal = tmp;
            cleardevice();
            showBox(maxx, hmaxx, maxy, hmaxy, 2, heightBox, widthBox, marginBox);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ch) / 2, ch);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(ch2) / 2, ch2);
        } while (keyPressLocal != ENTER);

        // Dieu kien bai toan
        if (n < 10 || n > 1e6 || h < 1 || h > 54) {
            char text[] = "Vui long nhap 10 <= N <= 10^6, 1 <= H <= 54";
            outtextxy(hmaxx - textwidth(text) / 2, hmaxy - marginBox - heightBox - textheight(text) - 20, text);
            getch();
            goto BOX1;
        }

        // MENU
        cleardevice();
        char *menuTmp[] = {"Xuat file", "Xuat man hinh"};
        int lengthMenuTmp = 2;
        char guide3[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
        showMenu2(maxx, hmaxx, maxy, hmaxy, 0, menuTmp, lengthMenuTmp, guide3);
        choice = 0;
        do {
            keyPress = getch();
            if (keyPress != 0) printf("\a");
            if (keyPress == UP_ARROW)
                choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
            else if (keyPress == DOWN_ARROW)
                choice = (choice + 1) % lengthMainMenuList;
            else if (keyPress == ESC) {
                goto BOX1;
            }
            char guide4[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
            showMenu2(maxx, hmaxx, maxy, hmaxy, choice, menuTmp, lengthMenuTmp, guide4);
        } while (keyPress != ENTER);

        // Thuc hien tinh toan, san nguyen to
        int *arr = (int*)malloc(sizeof(int) * (n + 1));
        Eratosthenes(arr, n);

        if (choice == 0) {
            writeDataToFile(outputFilePath, arr, n, h);
            cleardevice();
            char text[] = "Vui long xem ket qua o file ./output.txt";
            outtextxy(hmaxx - textwidth(text) / 2, hmaxy - textheight(text) / 2, text);
            getch();
            goto BOX1;
        }

        // Xuat ket qua ra man hinh
        if (choice == 1) {
            int currentPage = 1;
            int numOfCol = floor((windowWidth - 20) / 100.0);
            const int MAX_NUMBER_EACH_PAGE = 168; // 21 * 8

        PAGINATION:
            // ve khung bao quanh
            cleardevice();
            setcolor(3);
            rectangle(10, 10, maxx - 10, maxy - 10);

            i = 0;
            int quantity = 0;
            int col = -1, row = 20;

            for (i = 0; i <= n; i++) {
                if (arr[i] == 0 && heightNumber(i) == h) {
                    quantity++;
                    if (quantity > (currentPage - 1) * MAX_NUMBER_EACH_PAGE
                        && quantity <= currentPage * MAX_NUMBER_EACH_PAGE) {
                        col++;
                    char chTmp[100];
                    number2Char(i, chTmp);
                    outtextxy(col * 100 + 20, row, chTmp);
                    }
                }
                if (col == numOfCol) {
                    col = -1;
                    row += 20;
                }
            }

            const int pages = ceil(quantity/ (float)MAX_NUMBER_EACH_PAGE);
            char infoText[] = "Co tat ca ";
            char tmpChar[100];
            number2Char(quantity, tmpChar);
            strcat(infoText, tmpChar);
            strcat(infoText, " so. Trang ");
            number2Char(currentPage, tmpChar);
            strcat(infoText, tmpChar);
            strcat(infoText, " / ");
            number2Char(pages, tmpChar);
            strcat(infoText, tmpChar);
            setcolor(4);
            outtextxy(hmaxx - textwidth(infoText) / 2, maxy - textheight(infoText), infoText);

        PAGINATION2:
            keyPress = getch();
            if (keyPress == ESC || keyPress == ENTER) {
                goto BOX1;
            } else if (keyPress == DOWN_ARROW) {
                currentPage = currentPage >= pages ? 1 : currentPage + 1;
                goto PAGINATION;
            } else if (keyPress == UP_ARROW) {
                currentPage = currentPage <= 1 ? pages : currentPage - 1;
                goto PAGINATION;
            } else {
                goto PAGINATION2;
            }
        }
    }

    // clear
    getch();
    closegraph();
    return 0;
}
