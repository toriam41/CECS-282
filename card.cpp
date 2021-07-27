//  card.cpp
//  CECS282
//
//  Created by Tori McDonald on 1/30/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include "card.hpp"

using namespace std;

Card::Card() {
    rank = 'A';
    suit = 'S';
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
    
}

void Card::display() {
    if (rank == 'T') {
        cout<<"10"<<suit<<" ";
    }
    else{
        cout<<rank<<suit<<" ";
    }
    
}

int Card::getValue() {
    int value;
    
    switch (rank) {
        case 'A':
            value = 1;
            break;
            
        case '2':
            value = 2;
            break;
            
        case '3':
            value = 3;
            break;
            
        case '4':
            value = 4;
            break;
            
        case '5':
            value = 5;
            break;
            
        case '6':
            value = 6;
            break;
            
        case '7':
            value = 7;
            break;
            
        case '8':
            value = 8;
            break;
            
        case '9':
            value = 9;
            break;
            
        default:
            value = 10;
            break;
    }
    
    return value;
}





