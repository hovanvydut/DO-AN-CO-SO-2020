
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

void showMenu2(int maxx, int hmaxx, int maxy, int hmaxy, int choice, char *menuList[], int lenMenu, char guide[]) {
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

    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}

void showBox(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox, int heightBox, int widthBox, int marginBox) {
        char txt1[] = "Nhap n: ", txt2[] = "Nhap h: ";
        cleardevice();
        // Box n
        chooseBox == 1 ? setcolor(4) : setcolor(3);
        rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
        // Box h
        chooseBox == 2 ? setcolor(4) : setcolor(3);
        rectangle(hmaxx - widthBox / 2, hmaxy + marginBox, hmaxx + widthBox, hmaxy + (heightBox + marginBox));

        setcolor(3);
        outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt1) / 2, txt1);
        outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(txt1) / 2, txt2);

    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
        char guide[] = "Dung phim tab de di chuyen giua cac box, enter de xac nhan, ESC de quay lui";
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}
