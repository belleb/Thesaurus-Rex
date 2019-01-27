#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

// frequencies of letters
char frequencies[153] = {'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e',
't','t','t','t','t','t','t','t','t','t','t','t','t','a','a','a','a','a','a','a','a','a','a','a','a',
'r','r','r','r','r','r','r','r','r','r','r','r','i','i','i','i','i','i','i','i','i','i','i','n','n','n',
'n','n','n','n','n','n','n','n','o','o','o','o','o','o','o','o','o','o','o','s','s','s','s','s','s',
's','s','s','s','s','s','d','d','d','d','d','d','c','c','c','c','c','h','h','h','h','h','l','l','l','l','l',
'f','f','f','f','m','m','m','m','p','p','p','p','u','u','u','u','g','g','g','y','y','y','w','w',
'b','j','k','q','v','x','z'};

// gets a random letter (probability weighted by the structure of the English language) 
char getLetter(){
    
    int letter_index = rand() % 153; //get index
    
    return frequencies[letter_index];
}

// produces random board
string getBoard(){

    static string b;
    
    int i, j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            b += getLetter();
        }
    }    
    return b;
}


int main (){

    srand (time(NULL)); // initializes random seed
    string p;
    p = getBoard();

    // prints board
    //cout << p; 
    return 0;
}