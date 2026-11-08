#include <iostream>

bool isPalindromeHex(int number){

    int reversed = 0;

    while (number > reversed) {
        reversed = (reversed << 4) | (number & 0xF);
        number >>= 4;
    }

    return (number == reversed) || (number == (reversed >> 4));

}

bool isPalindromeDec(int number){

    int number_ = number;
    int reversed = 0;

    while (number_ > reversed) {
        int digit = number_ % 10;
        reversed = (reversed * 10) + digit;
        number_ /= 10;
    }

    return number_ == reversed;

}

bool isPalindromeBin(int number){   

    int reversed = 0;

    while (number > reversed) {
        reversed = (reversed << 1) | (number & 0x1);
        number >>= 1;
    }

    return (number == reversed) || (number == (reversed >> 1));

}

int main(int startValue, int endValue){
    
    int currentNumber = startValue;

    while(currentNumber <= endValue) {

        if ((currentNumber & 0x1) == 0) {//Fails if end digit in binary is 0
            currentNumber++;
            continue;
        }

        //Check in sequence of least likely palindrome to most
        if(isPalindromeHex(currentNumber)){
            if(isPalindromeDec(currentNumber)){
                if(isPalindromeBin(currentNumber)){
                    return currentNumber;
                }
            }
        }
        currentNumber++;
    }
}
