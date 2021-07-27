//
//  deck.hpp
//  CECS282
//
//  Created by Tori McDonald on 2/11/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include "card.hpp"

class Deck {

private:
    Card storage[52];
    int top;
    int length;

public:
    Deck();
    Card deal();
    void shuffle();
    void showDeck();
    void refreshDeck();
    int cardsLeft();
};
#endif /* deck_hpp */
