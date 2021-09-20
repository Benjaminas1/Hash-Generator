#include <iostream>
#include<string>

using namespace std;

void initialiseHash(char *hashed){
    //Filling every char with 0
    for(int i=0; i < sizeof(hashed); i++){
        hashed[i] = 0;
    }
}

void printHash(char *hashed){
    for(int i=0; i < sizeof(hashed); i++){
        cout << hashed[i];
    }
    cout << endl;
}

int sumIntElements(int number){
    int sum = 0;
    while(true){
        sum += number%10;
        number /= 10;
        if(number<10){
            sum += number%10;
            break;
        }
    }
    return sum;
}

void hashAWord(string &word, char *hashed){
    for(int i=0; i<word.length(); i++){
        //Convert letter to int using ascii
        int number = (int)word[i];
        //Adding all number symbols together
        int sum = sumIntElements(number);
        
    }
}

int main(){

    

}