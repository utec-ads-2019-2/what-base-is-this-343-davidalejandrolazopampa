//
// Created by David Lazo on 28/10/2019.
//
#include <iostream>
#include <string.h>
char primero[50], segundo[50];
long long david(char array[], long long base, int longitud) {
    long long num = 0, punto = 1;
    for(int i = longitud-1; i >= 0; i--) {
        if(array[i] >= '0' && array[i] <= '9'){num = num + (array[i]-'0') * punto;}
        else{num = num + (array[i]-'A'+10) * punto;}
        punto = punto * base;
    }
    return num;
}
int main() {
    //cout<<"David";
    while(scanf("%s %s", primero, segundo) == 2) {
        int pr = strlen(primero), sd = strlen(segundo),b1 = 1, b2 = 1, i;
        for(i = 0; i < pr; i++) {
            if(primero[i] >= '0' && primero[i] <= '9'){b1 = b1 > primero[i]-'0' ? b1 : primero[i]-'0';}
            else{b1 = b1 > primero[i]-'A'+10 ? b1 : primero[i]-'A'+10;}
        }
        for(i = 0; i < sd; i++) {
            if(segundo[i] >= '0' && segundo[i] <='9'){b2 = b2 > segundo[i]-'0' ? b2 : segundo[i]-'0';}
            else{b2 = b2 > segundo[i]-'A'+10 ? b2 : segundo[i]-'A'+10;}
        }b1++,b2++;
        for(b1; b1 <= 36; b1++) {
            for(i = b2; i <= 36; i++){
                if(david(primero, b1, pr) == david(segundo, i, sd)){
                    printf("%s (base %d) = %s (base %d)\n", primero, b1, segundo, i);goto Break;
        }}}printf("%s is not equal to %s in any base 2..36\n", primero, segundo);
        Break:i == 0;
    }
    return 0;
}