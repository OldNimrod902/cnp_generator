#include <bits/stdc++.h>

using namespace std;

bool closeProgram = false;

void getCNPDetails(long long cnp) {
    int S, AA, LL, ZZ, JJ, NNN;
    cnp /= 10;
    NNN = cnp % 1000;
    cnp /= 1000;
    JJ = cnp % 100;
    cnp /= 100;
    ZZ = cnp % 100;
    cnp /= 100;
    LL = cnp % 100;
    cnp /= 100;
    AA = cnp % 100;
    cnp /= 100;
    S = cnp % 10;

}


void generateCNP() {

}

void generateRandomCNP() {

}
bool isCNPvalid(long long cnp) {
    int constants[12] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int checkDigit, calculatedCheckDigit = 0;

    if(cnp < 1000000000000 || cnp > 9999999999999) {
        return false;
    }

    checkDigit = cnp % 10;
    cnp /= 10;
    for (int i = 11; i >= 0 ; i--) {
        calculatedCheckDigit += (cnp%10)*constants[i];
        cnp/=10;
    }
    calculatedCheckDigit %= 11;
    if (calculatedCheckDigit == 10) calculatedCheckDigit = 1;
    if (calculatedCheckDigit == checkDigit) {
        return true;
    } else {
        return false;
    }
}

void aboutCNP() {

}

void mainmenu() {
    int option;
    cout << "+== CNP GENERATOR =====================+" << endl;
    cout << "    Select an option:" << endl << endl;
    cout << "[1] Generate CNP based on input data" << endl;
    cout << "[2] Generate CNP randomly" << endl;
    cout << "[3] Verify CNP" << endl;
    cout << "[4] Get data from CNP" << endl;
    cout << "[5] About CNP" << endl;
    cout << "+======================================+" << endl;
    cout << "[0] Close the app" << endl;
    cout << "+======================================+" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    if (option == 1) {
        generateCNP();
    } 
    else if (option == 2) {
        generateRandomCNP();
    } 
    else if (option == 3) {
        long long cnp;
        cout << "Enter CNP to check: ";
        cin >> cnp;
        if (isCNPvalid(cnp)) {
            cout << "The entered CNP is valid." << endl;
        } else {
            cout << "The entered CNP is invalid." << endl;
        }
    }
    else if (option == 4) {
        cout << "soon";
    }
    else if (option == 5) {
        aboutCNP();
    }
    else if (option == 0) {
        cout << "Closing..." << endl;
        closeProgram = true;
        return;
    }
    else {
        cout << "Invalid option. Please try again." << endl;
        mainmenu();
    }
}

int main() {
    do {
        mainmenu();
    } while (!closeProgram);
    return 0;
}