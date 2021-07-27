//
//  upDate.hpp
//  CECS282
//
//  Created by Tori McDonald on 4/19/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class upDate {
private:
    static int counter;
    int *dptr;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December"};
    
public:
    upDate(); // DONE
    upDate(int m, int d, int y); // DONE
    upDate(int j); // DONE
    upDate(upDate const &d); // DONE
    ~upDate(); // DONE
    int getMonth(); // DONE
    int getDay(); // DONE
    int getYear(); // DONE
    string getMonthName(); // DONE
    static int G2J(int m, int d, int y); // DONE
    void setDate(int m, int d, int y); // DONE
    static void J2G(int JD, int &month, int &day, int &year); // DONE
    void operator+=(int i); // DONE
    void operator-=(int i); // DONE
    upDate operator+(int i); // DONE
    upDate operator-(int i); // DONE
    upDate operator=(upDate u); // DONE
    upDate operator++(); // DONE
    upDate operator++(int i); // DONE
    upDate operator--(); // DONE
    upDate operator--(int i); // DONE
    int operator-(upDate u); // DONE
    int julian(); // DONE
    bool operator==(upDate u); // DONE
    bool operator>(upDate u); // DONE
    bool operator<(upDate u); // DONE
    friend upDate operator+(int i, upDate u);
    friend ostream& operator<<(ostream &out, const upDate &u); // DONE
    static int GetDateCount(); // DONE
    
};
#endif /* upDate_hpp */
