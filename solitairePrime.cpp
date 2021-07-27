//  Tori McDonald
//  Program 1 - Solitaire Prime
//  CECS282
//  2/11/2020
//  Created by Tori McDonald on 2/10/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

/**#include "solitairePrime.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

static bool isPrime(int n){
    int num = n;
    int s = sqrt(num);
    
    if (n == 1){
        return false;
    }
    else if (s == 1){
        return true;
    }
    else {
        for (int i = 2; i <= s; i++){
            if (n % i == 0){
                return false;
            }
        }
        
        return true;
    }
}



static void play(Deck gameDeck) {
    Deck d = gameDeck;
    Card c;
    int sum;
    int piles = 1;
    bool prime;
    
    c = d.deal();
    c.display();
    
    sum = c.getValue();
    prime = isPrime(sum);
    
    while (d.cardsLeft() > 0) {
        if (prime == false) {
            c = d.deal();
            c.display();
          
            
            sum += c.getValue();
            prime = isPrime(sum);
        }
        else {
            cout<<"Prime: "<<sum<<endl;
        
            sum = 0;
            piles++;
            
            c = d.deal();
            c.display();
            
            sum = c.getValue();
            prime = isPrime(sum);
            }
    }
    
    if (isPrime(sum)) {
        cout<<"Prime: "<<sum<<"  Winner!"<<endl;
        cout<<"You won in "<<piles<<" piles!\n"<<endl;
    }
    else {
        cout<<"Loser!\n"<<endl;
    }
}


int main() {
    bool run = true;
    int choice;
    Deck myDeck = Deck();
    
    do {
        cout<<"Welcome to Solitaire Prime!"<<endl;
        cout<<"1) New Deck"<<endl<<"2) Display Deck"<<endl<<"3) Shuffle Deck"<<endl<<"4) Play Solitaire Prime"<<endl<<"5) Exit\n";
        
        cin>>choice;
        
        switch (choice) {
            case 1:
                myDeck.refreshDeck();
                break;
            case 2:
                myDeck.showDeck();
                break;
            case 3:
                myDeck.shuffle();
                break;
            case 4:
                play(myDeck);
                break;
            case 5:
                run = false;
                
        }
    } while (run);
    return 0;
}**/

