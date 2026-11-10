#include <bits/stdc++.h>

using namespace std;

bool closeProgram = false;

char counties[53][30] = {
    "0",
    "Alba",
    "Arad",
    "Arges",
    "Bacau",
    "Bihor",
    "Bistrita-Nasaud",
    "Botosani",
    "Brasov",
    "Braila",
    "Buzau",
    "Caras-Severin",
    "Cluj",
    "Constanta",
    "Covasna",
    "Dambovita",
    "Dolj",
    "Galati",
    "Gorj",
    "Harghita",
    "Hunedoara",
    "Ialomita",
    "Iasi",
    "Ilfov",
    "Maramures",
    "Mehedinti",
    "Mures",
    "Neamt",
    "Olt",
    "Prahova",
    "Satu Mare",
    "Salaj",
    "Sibiu",
    "Suceava",
    "Teleorman",
    "Timis",
    "Tulcea",
    "Vaslui",
    "Valcea",
    "Vrancea",
    "Bucuresti",
    "Bucuresti S.1",
    "Bucuresti S.2",
    "Bucuresti S.3",
    "Bucuresti S.4",
    "Bucuresti S.5",
    "Bucuresti S.6",
    "47",
    "48",
    "49",
    "50",
    "Calarasi",
    "Giurgiu"
};


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
    cout << "Gender: " << (S % 2 == 0 ? "Female" : "Male") << endl;
    cout << "Date of Birth: ";
    if (S == 1 || S == 2) cout << "19";
    else if (S == 3 || S == 4) cout << "18";
    else if (S == 5 || S == 6) cout << "20";
    cout << AA << "/" << LL << "/" << ZZ << endl;
    cout << "County: " << counties[JJ] << endl;
    cout << "Serial Number: " << NNN << endl;
}

bool dayChecker(int year, int month, int day) {
    if (day < 1 || day > 31) return false;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30; 
    }
    return true;
}

int returnCheckDigit(long long cnp) {
    int constants[12] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int checkDigit = 0;

    for(int i = 11; i >= 0 ; i--) {
        checkDigit += (cnp%10)*constants[i];
        cnp/=10;
    }
    checkDigit %= 11;
    if(checkDigit == 10) checkDigit = 1;
    return checkDigit;
}

void generateCNP() {
    int year, century, YY, MM, DD, JJ, NNN;
    char gender, affirmation;
    cout << "+== GENERATE CNP ======================+" << endl;
    
    do {
        cout << "Enter the birth year of the person: ";
        cin >> year;
    } while(year < 1800 || year > 2099);
    
    if(year>1999) {
        century = 5;
    }
    else if(year>1899) {
        century = 1;
    }
    else {
        century = 3;
    }

    YY = year % 100;

    do {
        cout << "Enter the birth month of the person: ";
    cin >> MM;
    } while(MM < 1 || MM > 12);
    
    do {
        cout << "Enter the birth day of the person: ";
        cin >> DD;
    } while(!dayChecker(year, MM, DD));

    do {
        cout << "Enter the gender of the person [M/F]: ";
        cin >> gender;
    } while(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f');

    if(gender == 'F' || gender == 'f') century++;
    do {
        cout << "Enter the county code of the person: ";
        cin >> JJ;
        cout << "You entered " << JJ << ", which is the code of " << counties[JJ] << ". Is this correct? [Y/N]: ";
        cin >> affirmation;
    } while(affirmation == 'N' || affirmation == 'n');

    do {
        cout << "Enter the serial number of the person (NNN): ";
        cin >> NNN;
    } while(NNN < 1 || NNN > 999);


    long long cnp;
    cnp = century;
    cnp *= 100;
    cnp += YY;
    cnp *= 100;
    cnp += MM;
    cnp *= 100;
    cnp += DD;
    cnp *= 100;
    cnp += JJ;
    cnp *=1000;
    cnp += NNN;
    cnp = cnp*10 + returnCheckDigit(cnp);
    
    cout << "The generated CNP is " << cnp << endl << endl;
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
        long long cnp;
        cout << "Enter CNP to get details: ";
        cin >> cnp;
        if (isCNPvalid(cnp)) {
            getCNPDetails(cnp);
        } else {
            cout << "The entered CNP is invalid." << endl;
        }
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