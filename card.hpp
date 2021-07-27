//
//  card.hpp
//  CECS282
//
//  Created by Tori McDonald on 1/30/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

class Card {
private:
    char rank;
    char suit;
    
public:
    Card();
    Card(char r, char s);
    int getValue();
    void display();
};

#endif /* card_hpp */
