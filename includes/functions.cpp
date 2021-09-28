#include "functions.hpp"

bool allCharactersSame(string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] != s[0])
            return false;
 
    return true;
}

void initialiseHash(int *hashed){

    string hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

    for(int i=0; i<64; i++){
        hashed[i] = 0;
        if(isdigit(hash[i])) hashed[i] = (int)hash[i] - 48;
        else hashed[i] = (int)hash[i] - 87;
        //cout << hashed[i] << " ";
    }
    
}

string hashToString(int hashed[]){
    string hash = "";

    //Converting numbers into characters and adding to 'hash' string
    for(int i=0; i < 64; i++){
        if(hashed[i] < 10) hash += to_string(hashed[i]);
        else hash += hashed[i] + 87;
    }
    return hash;
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

string hashString(string inputStr){

    //To do:
    //Implementuoti reverseInt

    int hashed[64];
    initialiseHash(hashed);

    if(inputStr == "") return hashToString(hashed);

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
        for(int i=0; i<64;){
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
            if(i % 64 == 0 && i != 0) hashedIndex = 0;
            hashed[hashedIndex] += fullSum + allIntSums[i];
            hashed[hashedIndex] = hashed[hashedIndex]%16;
            hashedIndex++;
        }
    }
    
    return hashToString(hashed);
}

string generateRandomSymbols(int length){
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(97,122);

    string output = "";
    for(int i=0; i<length; i++){
        output += char(distribution(generator));
    }

    return output;
}

void hashFromFile(string inputFileName){
    ifstream in("inputFiles/" + inputFileName + ".txt");
    if(!in.is_open()){
        cout << "Failed opening file '" << "inputFiles/" << inputFileName << ".txt" << endl;
        return;
    }

    string line;
    while (getline(in, line))
    {
        cout << hashString(line) << endl;
    }

    in.close();
}

void inputFromCmd(){
    string inputString;
    cout << "Input: ";
    cin >> inputString;

    cout << hashString(inputString) << endl;
}

void inputFromFile(){
    string inputFileName;
    cout << "Input file name (without .txt extention): ";
    cin >> inputFileName;

    hashFromFile(inputFileName);
}

void generate1100SymbolFiles(){
    ofstream out("inputFiles/1100randSymbols.txt");
    out << generateRandomSymbols(1100);
    out.close();

    out.open("inputFiles/1100randSymbols2.txt");
    out << generateRandomSymbols(1100);
    out.close();
}

void basicTests(){
    cout << "Performing basic tests: " << endl;
    cout << "......................................." << endl;
    cout << "Two files with different single symbols" << endl;

    cout << "a.txt - ";
    hashFromFile("a");

    cout << "b.txt - ";
    hashFromFile("b");
    cout << endl;

    cout << "Two files with (>1100) random symbols" << endl;
    generate1100SymbolFiles();
    cout << "1100randSymbols.txt - ";
    hashFromFile("1100randSymbols");

    cout << "1100randSymbols2.txt - ";
    hashFromFile("1100randSymbols2");
    cout << endl;

    cout << "Two files with 1 different symbol" << endl;
    cout << "fileA.txt - ";
    hashFromFile("fileA");

    cout << "fileB.txt - ";
    hashFromFile("fileB");
    cout << endl;

    cout << "Empty file" << endl;
    cout << hashString("") << endl;
}

void effectivenessTest(){
    using namespace std::chrono;

    steady_clock::time_point begin;
    steady_clock::time_point end;
    MD5 md5;
    SHA1 sha1;
    SHA256 sha256;


    ifstream in("inputFiles/konstitucija.txt");
    if(!in.is_open()){
        cout << "Failed opening file 'inputFiles/konstitucija.txt'" << endl;
        return;
    }
    in.close();

    cout << "Performing algorithm affectiveness tests:" << endl;
    cout << "........................................." << endl;

    int lineSum = 0;
    double hashTime = 0;
    double md5Time = 0;
    double sha1Time = 0;
    double sha256Time = 0;
    
    string line;
    for(int i=0; i<1000; i++)
    {
        in.open("inputFiles/konstitucija.txt");

        while (getline(in, line))
        {
            begin = steady_clock::now();
            hashString(line);
            end = steady_clock::now();
            hashTime += duration<double>(end - begin).count();

            begin = steady_clock::now();
            md5(line);
            end = steady_clock::now();
            md5Time += duration<double>(end - begin).count();

            begin = steady_clock::now();
            sha1(line);
            end = steady_clock::now();
            sha1Time += duration<double>(end - begin).count();

            begin = steady_clock::now();
            sha256(line);
            end = steady_clock::now();
            sha256Time += duration<double>(end - begin).count();
            
        }
        in.close();
    }
    
    
    cout << "Custom hash time: " << hashTime << "s" << endl;
    cout << "MB5 hash time: " << md5Time << "s" << endl;
    cout << "SHA1 hash time: " << sha1Time << "s" << endl;
    cout << "SHA256 hash time: " << sha256Time << "s" << endl;
    
    in.close();
}

void collisionTest(){
    int stringQuantity = 25000;
    int symbolSize[4] = {10, 100, 500, 1000}; //Don't change this

    int collisionCount = 0;

    cout << "Performing hashing algorithm collision test" << endl;
    cout << "..........................................." << endl;
    cout << "Collisions: ";
    
    for(int i=0; i<4; i++){
        for(int pairIndex=0; pairIndex<stringQuantity; pairIndex++){
            string first = generateRandomSymbols(symbolSize[i]);
            string second = generateRandomSymbols(symbolSize[i]);
            if(hashString(first) == hashString(second)) collisionCount++;
        }
    }

    cout << collisionCount << " out of " << stringQuantity*4 << endl;
}

void diversityTest(){
    
}