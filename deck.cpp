//
//  deck.cpp
//  CECS282
//
//  Created by Tori McDonald on 2/11/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "deck.hpp"

using namespace std;

Deck::Deck() {
    string ranks = "A23456789TJQK";
    string suits = "SHDC";
    top = 0;
    length = 52;
    int count = 0;
    
    for (int i = 0; i < suits.length(); i++) {
        for (int j = 0; j < ranks.length(); j++) {
            storage[count++] = Card(ranks[j], suits[i]);
        }
    }
}

Card Deck::deal() {
    Card temp = storage[top++];
    length--;
    
    return temp;
}

void Deck::refreshDeck() {
    string ranks = "A23456789TJQK";
    string suits = "SHDC";
    top = 0;
    length = 52;
    int count = 0;
    
    for (int i = 0; i < suits.length(); i++) {
        for (int j = 0; j < ranks.length(); j++) {
            storage[count++] = Card(ranks[j], suits[i]);
        }
    }
}

void Deck::showDeck() {
    int count = 0;
    
    for (int i = top; i < length + top; i++) {
        if (count % 13 == 0) {
            cout<<endl;
        }
        
        storage[i].display();
        count++;
    }
    cout<<endl;
}

int Deck::cardsLeft() {
    return length;
}

void Deck::shuffle() {
    for (int i = 0; i < 1000; i++) {
        int num1 = rand() % 52;
        int num2 = rand() % 52;
        Card temp = storage[num1];
        storage[num1] = storage[num2];
        storage[num2] = temp;
    }
}


