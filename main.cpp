#include <iostream>
#include <string>
#include <vector>

using namespace std;

void initialiseHash(int *hashed){

    string hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

    for(int i=0; i<64; i++){
        hashed[i] = 0;
        if(isdigit(hash[i])) hashed[i] = (int)hash[i] - 48;
        else hashed[i] = (int)hash[i] - 87;
        //cout << hashed[i] << " ";
    }
    
}

void printHash(int *hashed){
    string hash = "";

    //Converting numbers into characters and adding to 'hash' string
    for(int i=0; i < 64; i++){
        if(hashed[i] < 10) hash += to_string(hashed[i]);
        else hash += hashed[i] + 87;
    }
    cout << hash << endl;
}

int reverseInt(int number){
    int reversedNumber = 0, remainder;

    while(number != 0) {
        remainder = number%10;
        reversedNumber = reversedNumber*10 + remainder;
        number /= 10;
    }
    return reversedNumber;
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

void hashString(string &inputStr, int *hashed){

    if(inputStr == "") return;

    vector<int> allIntSums;
    int fullSum = 0;

    for(int i=0; i<inputStr.length(); i++){
        //Convert letter to int using ascii
        int number = (int)inputStr[i];
        //Adding all number symbols together
        int sum = sumIntElements(number);

        allIntSums.push_back(sum);
        fullSum += sum;
    }

    if(inputStr.length() < 64){
        for(int i=0; i<64; i++){
            for(int inputStrIndex = 0; inputStrIndex<inputStr.length(); inputStrIndex++){
                if(i + inputStrIndex <= 64){
                    hashed[i] += fullSum + allIntSums[inputStrIndex];
                    hashed[i] = hashed[i]%16;
                    i++;
                }
                else break;
            }
        }
    }
    else{
        int hashedIndex = 0;
        for(int i = 0; i<inputStr.length(); i++){
            if(i == 64) hashedIndex = 0;
            hashed[hashedIndex] += fullSum + allIntSums[i];
            hashed[hashedIndex] = hashed[hashedIndex]%16;
            hashedIndex++;
        }
    }
    
}

int main(){

    string inputStr = "Lietuva!";
    int hashed[64];

    initialiseHash(hashed);

    hashString(inputStr, hashed);

    printHash(hashed);

}