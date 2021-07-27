//
//  myDate.hpp
//  CECS282
//
//  Created by Tori McDonald on 5/7/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>
#include <string>

using namespace std;

class myDate {
private:
    int month, day, year;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapyear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string months[12] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    
public:
    myDate();
    myDate(int m, int d, int y);
    void display();
    void increaseDate(int n);
    void decreaseDate(int n);
    int daysBetween(myDate d);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
};






#endif /* myDate_hpp */
