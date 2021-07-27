//
//  birthday.cpp
//  birthday
//
//  Created by Tori McDonald on 1/23/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string name;
    int age;
    int birthYear;
    char thisYear;
    
    cout<<"What is your name?: ";
    cin>>name;
    cout<<"How old are you, "<<name<<"?: ";
    cin>>age;
    cout<<name<<", have you had your birthday yet this year? (y/n): ";
    cin>>thisYear;
    
    if (thisYear == 'y' || thisYear == 'Y'){
        birthYear = 2020 - age;
    }
    else{
        birthYear = 2020 - age - 1;
    }
    
    cout<<endl;
    cout<<"Hi "<<name<<", I guess that you were born in "<<birthYear<<"."<<endl;
    cout<<"\n Press enter to continue: ";
    
    getchar();
    getchar();
    
    return 0;
    
}
