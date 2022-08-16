#define _WIN32_WINNT 0x0501
#include <iostream>
#include <cstdlib>
#include <string>
#include <mingw.thread.h>
#include <chrono>
using namespace std;
string wifiName, command;
int language, theme;
int main()
{
    system("title Wifi Password Extractor - Created by Nguyen Lan Dung");
    cout << "Type 1 to use English interface" << endl
         << "Nhap 2 de su dung giao dien Tieng Viet" << endl;
    cin >> language;
    while (language != 1 && language != 2)
    {
        cout << "You need to type 1 or 2. Please try again" << endl
             << "Ban can nhap 1 hoac 2. Hay nhap lai" << endl;
        cin >> language;
    }
    if (language == 1)
    {
        cout << "Type 1 for light theme or 2 for dark theme" << endl;
        cin >> theme;
        while (theme != 1 && theme != 2)
        {
            cout << "You need to type 1 or 2. Please try again" << endl;
            cin >> theme;
        }
        if (theme == 1)
        {
            system("color 70");
        }
        if (theme == 2)
        {
            system("color 07");
        }
        cout << "Caution! This program can only be used to see passwords of Wifis that you've connected to at least once" << endl
             << "Your wifi password cannot have any spaces in, otherwise the program will not work correctly" << endl
             << "Read the instructions first, and then the program will continue :)" << endl;
        for (int i = 10; i >= 0; i--)
        {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Timer: " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        system("netsh wlan show profile");
        cout << "Get password of Wifi: ";
        cin >> wifiName;
        command = "netsh wlan show profile name=" + wifiName + " key=clear";
        system(command.c_str());
        cout << "Your password is shown after the 'Key Content' box ";
    }
    if (language == 2)
    {
        cout << "Nhap 1 de su dung light theme hoac 2 de su dung dark theme" << endl;
        cin >> theme;
        while (theme != 1 && theme != 2)
        {
            cout << "Ban can nhap 1 hoac 2. Hay nhap lai" << endl;
            cin >> theme;
        }
        if (theme == 1)
        {
            system("color 70");
        }
        if (theme == 2)
        {
            system("color 07");
        }
        cout << "Chu y! Chuong trinh nay chi co the giup ban xem mat khau cua cac Wifi ma ban da tung ket noi" << endl
             << "Ten Wifi khong duoc co dau va ten Wifi khong duoc co dau cach" << endl
             << "Doc huong dan di da, 10s sau t moi cho qua :)" << endl;
        for (int i = 10; i >= 0; i--)
        {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Timer: " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        system("netsh wlan show profile");
        cout << "Xem mat khau cua wifi: ";
        cin >> wifiName;
        command = "netsh wlan show profile name=" + wifiName + " key=clear";
        system(command.c_str());
        cout << "Mat khau cua ban duoc hien thi sau muc 'Key Content' " << endl;
    }
    system("pause");
}