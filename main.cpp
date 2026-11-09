#include <bits/stdc++.h>

using namespace std;

void mainmenu() {
    int option;
    cout << "+== CNP GENERATOR =====================+" << endl;
    cout << "Choose an option:" << endl;
    cout << "[1] Generate CNP based on input data" << endl;
    cout << "[2] Generate CNP randomly" << endl;
    cout << "[3] Check CNP details" << endl;
    cout << "[4] About CNP" << endl;
    cout << "+======================================+" << endl;
    cout << "[0] Exit" << endl;
    cout << "+======================================+" << endl;
    cout << "Enter your choice: ";
    cin >> option;
}

void generateCNP() {

}

void generateRandomCNP() {

}
void checkCNPDetails() {
    cout << "Enter CNP to check: ";
    int constants[12] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int cnp, checkDigit, calculatedCheckDigit = 0;
    cin >> cnp;
    checkDigit = cnp % 10;
    for (int i = 11; i >= 0 ; i--) {
        calculatedCheckDigit += cnp/10*constants[i];
        cnp/=10;
    }
    calculatedCheckDigit %= 11;
    if (calculatedCheckDigit == 10) calculatedCheckDigit = 1;
    if (calculatedCheckDigit == checkDigit) {
        cout << "The entered CNP is valid." << endl;
    } else {
        cout << "The entered CNP is invalid." << endl;
    }
}

void aboutCNP() {

}

int main() {
    mainmenu();
    return 0;
}