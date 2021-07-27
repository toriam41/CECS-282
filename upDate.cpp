//
//  upDate.cpp
//  CECS282
//
//  Created by Tori McDonald on 4/19/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include "upDate.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

int upDate::counter = 0;

int upDate::G2J(int month, int day, int year) {
    int i = year;
    int j = month;
    int k = day;
    int JD = k - 32075 + 1461 * (i + 4800 + (j - 14)/12 ) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
    
    return JD;
}

void upDate::J2G(int JD, int &month, int &day, int &year) {
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

upDate::upDate() { // default constructor
    counter++;
    
    dptr = new int[3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
}

upDate::upDate(int m, int d, int y) { // specific date constructor
    counter++;
    
    dptr = new int[3];
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
}

upDate::upDate(int jul) { // Julian date constructor
    counter++;
    int i, j, k;
    
    dptr = new int[3];
    
    int l = jul + 68569;
    int n = 4 * l/ 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    dptr[2] = i;
    dptr[0] = j;
    dptr[1] = k;
}

upDate::upDate(upDate const &d) { // copy constructor
    counter++;
    
    dptr = new int[3];
    dptr[0] = d.dptr[0];
    dptr[1] = d.dptr[1];
    dptr[2] = d.dptr[2];
}

upDate::~upDate() { // deconstructor
    delete [] dptr;
    counter--;
}

void upDate::setDate(int m, int d, int y) {
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
}

int upDate::getMonth() {
    return dptr[0];
}

int upDate::getDay() {
    return dptr[1];
}

int upDate::getYear() {
    return dptr[2];
}

string upDate::getMonthName() {
    return months[dptr[0] - 1];
}

upDate upDate::operator+(int i) {
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j += i;
    
    J2G(j, m1, d1, y1);
    upDate temp(m1, d1, y1);
    
    return temp;
}

upDate upDate::operator-(int i) {
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j -= i;
    
    J2G(j, m1, d1, y1);
    upDate temp(m1, d1, y1);
    
    return temp;
}

void upDate::operator+=(int i) {
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j += i;
    
    J2G(j, dptr[0], dptr[1], dptr[2]);
}

void upDate::operator-=(int i) {
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j -= i;
    
    J2G(j, dptr[0], dptr[1], dptr[2]);
}

upDate upDate::operator++() { // PRE-increment
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j++;
    
    J2G(j, m1, d1, y1);
    dptr[0] = m1;
    dptr[1]= d1;
    dptr[2] = y1;
    
    upDate temp(m1, d1, y1);
    return temp;
}

upDate upDate::operator++(int dummy) { // POST-increment
    upDate temp(*this);
    
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j++;
    
    J2G(j, m1, d1, y1);
    dptr[0] = m1;
    dptr[1]= d1;
    dptr[2] = y1;
    
    return temp;
}

upDate upDate::operator--() { // PRE-increment
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j--;
    
    J2G(j, m1, d1, y1);
    dptr[0] = m1;
    dptr[1]= d1;
    dptr[2] = y1;
    
    upDate temp(m1, d1, y1);
    return temp;
}

upDate upDate::operator--(int dummy) { // POST-increment
    upDate temp(*this);
    
    int m1, d1, y1;
    int j = G2J(dptr[0], dptr[1], dptr[2]);
    j --;
    
    J2G(j, m1, d1, y1);
    dptr[0] = m1;
    dptr[1]= d1;
    dptr[2] = y1;
    
    return temp;
}

upDate upDate::operator=(upDate u) {
    
    
    dptr[0] = u.dptr[0];
    dptr[1] = u.dptr[1];
    dptr[2] = u.dptr[2];
    
    return *this;
}

upDate operator+(int i, upDate u) {
    int m1, d1, y1;
    int j = upDate::G2J(u.dptr[0], u.dptr[1], u.dptr[2]);
    j += i;
    
    upDate::J2G(j, m1, d1, y1);
    upDate temp(m1, d1, y1);
    
    return temp;    
}

ostream& operator<<(ostream &out, const upDate  &u) {
    out << u.dptr[0] << "/" << u.dptr[1] << "/" << u.dptr[2];
    return out;
}

int upDate::operator-(upDate u) {
    int jul1 = G2J(dptr[0], dptr[1], dptr[2]);
    int jul2 = G2J(u.dptr[0], u.dptr[1], u.dptr[2]);
    int difference = jul1 - jul2;
    
    return difference;
}

int upDate::julian() {
    return G2J(dptr[0], dptr[1], dptr[2]);
}

bool upDate::operator<(upDate u) {
    int jul1 = G2J(dptr[0], dptr[1], dptr[2]);
    int jul2 = G2J(u.dptr[0], u.dptr[1], u.dptr[2]);
    
    if (jul1 < jul2) {
        return true;
    }
    else {
        return false;
    }
}

bool upDate::operator>(upDate u) {
    int jul1 = G2J(dptr[0], dptr[1], dptr[2]);
    int jul2 = G2J(u.dptr[0], u.dptr[1], u.dptr[2]);
    
    if (jul1 > jul2) {
        return true;
    }
    else {
        return false;
    }
}

bool upDate::operator==(upDate u) {
    int m = u.getMonth();
    int d = u.getDay();
    int y = u.getYear();
    
    if ((dptr[0] == m) && (dptr[1] == d) && (dptr[2] == y)) {
        return true;
    }
    else {
        return false;
    }
}

int upDate::GetDateCount() {
    return counter;
}
