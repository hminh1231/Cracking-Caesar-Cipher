#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void decryptCipher(string cipherText, int key, ofstream& outputFile) {
    char letter;
    string plainText = " ";
    for (int i = 0; i < cipherText.length(); i++) {
        letter = cipherText[i];
        if (letter >= 'a' && letter <= 'z') {
            letter = letter - key;
            if (letter < 'a') {
                letter = letter + 'z' - 'a' + 1;
            }
            plainText += letter;
        }
        else if (letter >= 'A' && letter <= 'Z') {
            letter = letter - key;
            if (letter < 'A') {
                letter = letter + 'Z' - 'A' + 1;
            }
            plainText += letter;
        }
        else {
            plainText += letter;
        }
    }
    outputFile << "For key: " << key;
    outputFile << " The plain text is: \n" << plainText << "\n\n";
}

int main(int argc, char const* argv[]) {
    string fileName = "cipher.txt";
    ifstream inputFile(fileName.c_str());
    ofstream outputFile("plain.txt");
    if (!inputFile.is_open()) {
        cout << " Could not open file: " << fileName;
        exit(1);
    }
    string cipherText;
    getline(inputFile, cipherText);
    cout << "Please wait. ";
    for (int key = 1; key <= 26; key++) {
        decryptCipher(cipherText, key, outputFile);
        cout << ".";
    }
    cout << "Finished. Please see the plain.txt for output" << endl;
    return 0;
}


