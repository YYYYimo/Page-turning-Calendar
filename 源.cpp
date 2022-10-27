#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int Days(int year, int month);
int iWeek_(int iYear, int iMonth);
void print(int iYear, int iMonth);
int main()
{
    int iYear, iMonth;
    cin >> iYear >> iMonth;
    cout << iYear << "年" << iMonth << "月" << endl;
    print(iYear, iMonth);
    while (1) {
        if (_kbhit()) {
            int ch1, ch2;
            system("cls");
            ch1 = _getche();
            if (ch1 == 72 && iMonth != 1) {
                iMonth--;
                cout << iYear << "年" << iMonth << "月" << endl;
                print(iYear, iMonth);
                ch2 = _getch();
            }
            else if (ch1 == 72 && iMonth == 1) {
                iMonth = 12;
                iYear--;
                cout << iYear << "年" << iMonth << "月" << endl;
                print(iYear, iMonth);
                ch2 = _getch();
            }
            else if (ch1 == 80 && iMonth != 12) {
                iMonth++;
                cout << iYear << "年" << iMonth << "月" << endl;
                print(iYear, iMonth);
                ch2 = _getch();
            }
            else if (ch1 == 80 && iMonth == 12) {
                iMonth = 1;
                iYear++;
                cout << iYear << "年" << iMonth << "月" << endl;
                print(iYear, iMonth);
                ch2 = _getch();
            }else if (ch1 == 27)
                break;
        }
        
    }
    return 0;
}
void print(int iYear, int iMonth)
{
    cout << setiosflags(ios::right) << setw(4)  << "一" << "    " << "二" << "    " << "三" << "    " << "四" << "    " << "五" << "    " << "六" << "    " << "日" << endl;
    int week = 1;
    int day = Days(iYear, iMonth);
    int n = 0, i = 1;
   while(i <= day) {
        while (week == 1) {
            if (iWeek_(iYear, iMonth) != 0) {
                if (n < iWeek_(iYear, iMonth) - 1) {
                    cout << setiosflags(ios::right) << setw(4) << "  " << "  ";
                    n++;
                }
                else {
                    cout << setiosflags(ios::right) << setw(4) << i << "  ";
                    n++;
                    i++;
                }
            }
            else {
                if (n < 7) {
                    cout << setiosflags(ios::right) << setw(4) <<  "  " << "  ";
                    n++;
                }
                else {
                    cout << setiosflags(ios::right) << setw(4) << i << "  ";
                    n++;
                    i++;
                }
            }
            if (n % 7 == 0) {
                cout << endl;
                week++;
                n = 0;
            }
        }
        
        if (week > 1) {
            if (iMonth == 6 && i == 14) {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取输出设备的句柄

                CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
                GetConsoleScreenBufferInfo(handle, &csbiInfo);  //获取窗口缓冲区信息
                WORD wOldColorAttrs = csbiInfo.wAttributes;     //获取初始定义的文本属性，即默认属性
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                cout << setiosflags(ios::right) << setw(4) << i << "  ";
                n++;
                i++;
                SetConsoleTextAttribute(handle, wOldColorAttrs);
            }
            if (iMonth == 12 && i == 8) {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取输出设备的句柄

                CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
                GetConsoleScreenBufferInfo(handle, &csbiInfo);  //获取窗口缓冲区信息
                WORD wOldColorAttrs = csbiInfo.wAttributes;     //获取初始定义的文本属性，即默认属性
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//设置红色和蓝色相加
                cout << setiosflags(ios::right) << setw(4) << i << "  ";
                n++;
                i++;
                SetConsoleTextAttribute(handle, wOldColorAttrs);
            }
            cout << setiosflags(ios::right) << setw(4) << i << "  ";
            n++;
            i++;
            if(n % 7 == 0){
                cout << endl;
                n = 0;
            }
        }    
    }
   cout << endl;
}
int Days(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
    {
        int i, j, k;
        i = year % 4;
        j = year % 100;
        k = year % 400;
        if (i == 0 && j != 0 || k == 0)
            return 29;
        else 
            return 28;
    }
}
int iWeek_(int iYear, int iMonth)
{
    int iDay = 1, iWeek, c, y;
    if (iMonth == 1) {
        iYear -= 1;
        iMonth = 13;
    }
    else if (iMonth == 2) {
        iYear -= 1;
        iMonth = 14;
    }
    c = iYear / 100;
    y = iYear % 100;
    iWeek = ((c / 4) - 2 * c + y + (y / 4) + (26 * (iMonth + 1) / 10) + iDay - 1) % 7;
    while (iWeek < 0) iWeek += 7;
    return iWeek;
}
