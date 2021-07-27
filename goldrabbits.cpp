//
//  goldrabbits.cpp
//  CECS282
//
//  Created by Tori McDonald on 5/5/20.
//  Copyright © 2020 Tori McDonald. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

class BigInt {
private:
    vector<char> number;
    
public:
    BigInt(string num); // DONE
    BigInt(int num); // DONE
    BigInt operator+(BigInt b); // DONE
    BigInt operator-(BigInt b); // DONE
    BigInt operator++(int dummy);
    friend bool operator<(BigInt b, int comp);
    vector<char> getNumberVector(); // DONE
    friend ostream& operator<<(ostream &out, const BigInt &b); //DONE
    void print(); // DONE
    
};

BigInt goldRabbits(BigInt b);

int main() {
    
    //int months = 3000;
    
    BigInt x = 10;
    BigInt y = 1;
    BigInt z = x - y;
    
    cout<< x << " "<< y << " "<< z <<endl;
  
    for (BigInt i = 0; i < 3000; i++) {
            cout << "month " << i << ": " << goldRabbits(i) << endl;
    }

}



BigInt::BigInt(string num) {
    for (char digit : num){
        number.push_back(digit);
    }
}

BigInt::BigInt(int num) {
    int digit;
    string n = "";
    
    if (num == 0) {
        n += (char) num + 48;
    }
    else {
        while (num > 0) {
            digit = num % 10;
            n += (char) (digit + 48);
            num /= 10;
        }
    }
    
    string::reverse_iterator rit = n.rbegin();
    
    while (rit != n.rend()) {
        number.push_back(*rit++);
    }
    
}

vector<char> BigInt::getNumberVector() {
    return number;
}

BigInt BigInt::operator+(BigInt b) {
    vector<char> num = b.getNumberVector(); // access number inside b
    vector<char>::reverse_iterator it1, it2;
    string newNum = ""; // holds the sum of both big ints in REVERSE order
    string finalNum = ""; // holds the sum of both big ints in correct order
    string::reverse_iterator str;
    int leftover = 0;
    int digit1, digit2, finaldigit, sum;

    it1 = number.rbegin();
    it2 = num.rbegin();
    
    if (number.size() > num.size()){ // it2 has less digits
        while (it2 != num.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            sum = digit1 + digit2 + leftover; // add both digits and leftovers
            //cout<<"sum: "<<sum<<endl;
            
            if (sum >= 10) { // check for carry over
                finaldigit = sum % 10;
                leftover = sum / 10;
            }
            else {
                finaldigit = sum;
                leftover = 0; // set leftover to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            //cout<<newNum<<endl;
            
            it1++; // move pointers
            it2++;
        }
        
        while (it1 != number.rend()) { // add the rest of the big int and possible carry over until no more digits
            sum = (int) *it1 - 48 + leftover;
            //cout<<"sum: "<<sum<<endl;
            
            if (sum >= 10) {
                finaldigit = sum % 10;
                leftover = sum / 10;
            }
            else {
                finaldigit = sum;
                leftover = 0;
            }
            
            newNum += (char) (finaldigit + 48);
            it1++;
        }
        
        if (it1 == number.rend() && leftover > 0) { // add remaining overflow if no more digits
            newNum += (char) (leftover + 48);
            //cout<<newNum<<endl;
        }
    }
    else if (num.size() > number.size()) { // it1 has less digits
        while (it1 != number.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            sum = digit1 + digit2 + leftover; // add both digits and leftovers
            
            if (sum >= 10) { // check for carry over
                finaldigit = sum % 10;
                leftover = sum / 10;
            }
            else {
                finaldigit = sum;
                leftover = 0; // set leftover to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            
            it1++; // move pointers
            it2++;
        }
        
        while (it2 != num.rend()) { // add the rest of the big int and possible carry over until no more digits
            sum = (int) *it2 - 48 + leftover;
            
            if (sum >= 10) {
                finaldigit = sum % 10;
                leftover = sum / 10;
            }
            else {
                finaldigit = sum;
                leftover = 0;
            }
            
            newNum += (char) (finaldigit + 48);
            it2++;
        }
        
        if (it2 == num.rend() && leftover > 0) { // add remaining overflow if no more digits
            newNum += (char) (leftover + 48);
        }
        
    }
    else {
        while (it2 != num.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            sum = digit1 + digit2 + leftover; // add both digits and leftovers
            
            if (sum >= 10) { // check for carry over
                finaldigit = sum % 10;
                leftover = sum / 10;
            }
            else {
                finaldigit = sum;
                leftover = 0; // set leftover to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            
            it1++; // move pointers
            it2++;
        }
        
        if (leftover > 0) { // add remaining overflow if no more digits
            newNum += (char) (leftover + 48);
        }
    }
    
    for (str = newNum.rbegin(); str != newNum.rend(); str++) { // reverse order of digits
        finalNum += *str;
    }
    
    BigInt total(finalNum); // construct new big int with the sum;
    
    return total;
}

BigInt BigInt::operator-(BigInt b) {
    vector<char> num = b.getNumberVector(); // access number inside b
    vector<char>::reverse_iterator it1, it2;
    string newNum = ""; // holds the difference of both big ints in REVERSE order
    string finalNum = ""; // holds the difference of both big ints in correct order
    string::reverse_iterator str;
    int deficit = 0;
    int digit1, digit2, finaldigit, difference;

    it1 = number.rbegin();
    it2 = num.rbegin();
    
    if (number.size() > num.size()){ // it2 has less digits
        while (it2 != num.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            difference = digit1 - digit2 - deficit; // subtract both digits and deficit
            
            if (difference < 0) { // check for carry over
                finaldigit = difference + 10;
                deficit = 1;
            }
            else {
                finaldigit = difference;
                deficit = 0; // set deficit to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            
            it1++; // move pointers
            it2++;
        }
        
        while (it1 != number.rend()) { // subtract the rest of the big int
            difference = (int) *it1 - 48 - deficit;
            
            if (difference < 0) {
                finaldigit = difference + 10;
                deficit = 1;
            }
            else {
                finaldigit = difference;
                deficit = 0;
            }
            
            newNum += (char) (finaldigit + 48);
            it1++;
        }
    }
    else if (num.size() > number.size()) { // it1 has less digits
        while (it1 != number.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            difference = digit1 - digit2 - deficit; // subtract both digits and deficit
            
            if (difference < 0) { // check for carry over
                finaldigit = difference + 10;
                deficit = 1;
            }
            else {
                finaldigit = difference;
                deficit = 0; // set deficit to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            
            it1++; // move pointers
            it2++;
        }
        
        while (it2 != num.rend()) { // add the rest of the big int and possible carry over until no more digits
            difference = (int) *it2 - 48 - deficit;
            
            if (difference < 0) {
                finaldigit = difference + 10;
                deficit = 1;
            }
            else {
                finaldigit = difference;
                deficit = 0;
            }
            
            newNum += (char) (finaldigit + 48);
            it2++;
        }
       
    }
    else {
        while (it2 != num.rend()) {
            digit1 = (int) *it1 - 48;
            digit2 = (int) *it2 - 48;
            difference = digit1 - digit2 - deficit; // subtract both digits and deficit
            
            if (difference < 0) { // check for carry over
                finaldigit = difference + 10;
                deficit = 1;
            }
            else {
                finaldigit = difference;
                deficit = 0; // set deficit to 0 if there's no carry over
            }
            
            newNum += (char) (finaldigit + 48); // add final digit to string
            
            it1++; // move pointers
            it2++;
        }
        
        
        
    }
    
    if (newNum.size() > 1 && newNum[newNum.size() - 1] == '0') {
        newNum.pop_back();
    }
    
    for (str = newNum.rbegin(); str != newNum.rend(); str++) { // reverse order of digits
        finalNum += *str;
    }
    
    
    BigInt total(finalNum); // construct new big int with the sum;
    
    return total;
    
}

BigInt BigInt::operator++(int dummy) {
    BigInt temp(*this);
    BigInt f = temp + BigInt(1);
    number = f.getNumberVector();
    
    return temp;
}

bool operator< (BigInt b, int comp) {
    string num1;
    for (char c : b.getNumberVector()) {
        num1.push_back(c);
    }
    
    
    
    int n = stoi(num1);
    
    if (n < comp) {
        return true;
    }
    
    return false;
}

BigInt goldRabbits(BigInt months) {
    static map<string, string> storage;
    map<string, string>::iterator it;
    string num = "";
    string calculation;
    
    for (char d : months.getNumberVector()) {
        num += d;
    }
    
    it = storage.find(num);
    
    if (it != storage.end()) {
        calculation = storage[num];
    }
    else {
        if (num == "0" || num == "1") {
            calculation = "1";
            storage[num] = calculation;
        }
        else {
            BigInt t1 = months - BigInt(1);
            BigInt t2 = months - BigInt(2);
            BigInt t3 = goldRabbits(t1) + goldRabbits(t2);
            
            for (char d : t3.getNumberVector()) {
                calculation += d;
            }
            
            storage[num] = calculation;
        }
    }
    
    return BigInt(calculation);

}

ostream& operator<<(ostream &out, const BigInt &b) {
    int count = 0;
    string num = "";
    
    for (char c : b.number) {
        num += c;
        count++;
    }
    
    out << num;
    
    return out;
}

void BigInt::print() {
    for (char digit : number) {
        cout << digit;
    }
}




