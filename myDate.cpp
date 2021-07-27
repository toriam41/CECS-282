//
//  myDate.cpp
//  CECS282
//
//  Created by Tori McDonald on 5/7/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include "myDate.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


int G2J(int month, int day, int year) {
    int i = year;
    int j = month;
    int k = day;
    int JD = k - 32075 + 1461 * (i + 4800 + (j - 14)/12 ) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
    
    return JD;
}

void J2G(int JD, int &month, int &day, int &year) {
    int i, j, k;

    int l = JD + 68569;
    int n = 4 * l/ 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    year = i;
    month = j;
    day = k;
}


myDate::myDate() {
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y) {
    if (m > 12 || m < 1 || d > 31 || d < 1){
        month = 5;
        day = 11;
        year = 1959;
    }
    else {
        month = m;
        day = d;
        year = y;
    }
}

void myDate::display() {
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

void myDate::increaseDate(int n) {
    int newDate = G2J(month, day, year) + n;
    J2G(newDate, month, day, year);
}

void myDate::decreaseDate(int n) {
    int newDate = G2J(month, day, year) - n;
    J2G(newDate, month, day, year);
}

int myDate::daysBetween(myDate d) {
    int jul1 = G2J(d.month, d.day, d.year);
    int jul2 = G2J(month, day, year);
    
    return jul1 - jul2;
}

int myDate::getMonth() {
    return month;
}

int myDate::getDay() {
    return day;
}

int myDate::getYear() {
    return year;
}

int myDate::dayOfYear() {
    int days = 0;
    
    if (month == 1) {
        return day;
    }
    else {
         if ((year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
             for (int i = month - 2; i >= 0; i--) {
                 days += leapyear[i];
             }
         }
         else {
             for (int i = month - 2; i >= 0; i--) {
                 days += daysInMonth[i];
             }
         }
    }
    
    return day + days;
}

string myDate::dayName() {
    int jul = G2J(month, day, year);
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    return days[jul % 7];
}
