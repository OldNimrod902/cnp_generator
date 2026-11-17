#include <bits/stdc++.h>

using namespace std;

bool closeProgram = false;
ofstream save("export.txt");

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
    char gender, affirmation, JJName[30];
    bool foundByName=false;
    srand(time(0));
    cout << "+== GENERATE CNP ======================+" << endl;
    
    cout << "Enter the birth year of the person: ";
    cin >> year;
    while(year < 1800 || year > 2099) {
        cout << "Invalid year. Please enter a year between 1800 and 2099: ";
        cin >> year;
    }
    
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

    cout << "Enter the birth month of the person: ";
    cin >> MM;
    while(MM < 1 || MM > 12) {
        cout << "Invalid month. Please enter a month between 1 and 12: ";
        cin >> MM;
    }
    
    cout << "Enter the birth day of the person: ";
    cin >> DD;
    while(!dayChecker(year, MM, DD)) {
        cout << "Invalid day. Please enter a valid day: ";
        cin >> DD;
    }

    cout << "Enter the gender of the person [M/F]: ";
    cin >> gender;
    while(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
        cout << "Invalid gender. Please enter M for male or F for female: ";
        cin >> gender;
    }

    if(gender == 'F' || gender == 'f') century++;

    cout << "Enter the name of the county of the person\nIf you would rather enter the county code, enter \"code\": ";
    cin.ignore();
    cin.getline(JJName, 30);
    if(strcmp(JJName, "code")==0) {
        do {
            cout << "Enter the county code of the person: ";
            cin >> JJ;
            cout << "You entered " << JJ << ", which is the code of " << counties[JJ] << ". Is this correct? [Y/N]: ";
            cin >> affirmation;
        } while(affirmation == 'N' || affirmation == 'n');
    }
    else {
        for (int i = 1; i < 53; i++)
        {
            if(strcmp(JJName, counties[i])==0) {
                JJ=i;
                foundByName=true;
            }
        }
        while(!foundByName) {
            cout << "County not found. Please enter a valid county name: ";
            cin.getline(JJName, 30);
            for (int i = 1; i < 53; i++)
            {
                if(strcmp(JJName, counties[i])==0) {
                    JJ=i;
                    foundByName=true;
                }
            }
        }
        
    }

    do {
        cout << "Enter a serial number for the person (000-999). Enter 0 for random number: ";
        cin >> NNN;
    } while(NNN < 0 || NNN > 999);
    if(NNN == 0) {
        NNN = rand() % 1000;
    }

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
    cout << "+== GENERATE CNP RANDOMLY =============+" << endl;
    srand(time(0));
    char answer;
    bool export_cnp=false;

    cout << "How many CNPs do you want to generate? ";
    int amount;
    cin >> amount;

    cout << "Would you like to export the generated CNPs? [Y/N]" << endl;
    cin >> answer;
    if(answer == 'Y' || answer == 'y') export_cnp=true;
    if(export_cnp) save << "Exported " << amount << " CNPs: " << endl;

    long long cnp;
    
    cout << "Generated CNPs: " << endl;
    for(int i = 0; i < amount; i++) {
        int S = rand() % 6 + 1;
        int YY;
        int DD;
        if(S==5 || S==6) YY = rand() % 26;
        else YY = rand() % 100;
        int MM = rand() % 12 + 1;
        if(MM==1 || MM==3 || MM==5 || MM==7 || MM==8 || MM==10 || MM==12) DD = rand() % 30 + 1;
        else if(MM==2) DD = rand() % 29 + 1;
        else if (YY%4 != 0) DD = rand() % 27 + 1;
        else DD = rand() % 18 + 1;
        int JJ = rand() % 46 + 1;
        int NNN = rand() % 1000;
        cnp = S;
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
        cout << cnp << endl;
        if(export_cnp) save << cnp << endl;
    }

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
    cout << "+== ABOUT CNP =========================+" << endl << endl;
    cout << "A CNP is a 13 digit number that every Romanian citizen has." << endl;
    cout << "It is generated based on the persons birth date, birth place, and gender." << endl;
    cout << "It is made up based on the following formula:" << endl;
    cout << "SYYMMDDJJNNNC, where; " << endl;
    cout << "S - contains the person's gender and century of birth (e.g. 5 means a man born in 2000-2100)" << endl;
    cout << "YY - contains the last 2 digits of the birth year" << endl;
    cout << "MM - contains the birth month" << endl;
    cout << "DD - contains the birth day" << endl;
    cout << "JJ - contains the birth county (\"Judet\") of the person" << endl;
    cout << "NNN - differentiates those born on the same date, place and gender" << endl;
    cout << "C - check digit, that makes it easy to check if the CNP is correct based on an algorithm" << endl;
    cout << "So every person has a unique one, used in daily life for administrative things." << endl;
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
    cout << "[6] County codes list" << endl;
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

            cout << "Do you want to get details from this CNP? [Y/N]: ";
            char choice;
            cin >> choice;
            if(choice == 'y' || choice == 'Y') {
                getCNPDetails(cnp);
            }
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
    else if (option == 6) {
        cout << "+== COUNTY CODES ======================+" << endl;
        for(int i = 1; i <= 46; i++) {
            cout << "[";
            if (i < 10) cout << "0";
            cout << i << "] " << counties[i] << endl;
        }
        cout << "[51] Calarasi" << endl;
        cout << "[52] Giurgiu" << endl;
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
    cout << "Press enter to return to the main menu" << endl;
    cin.ignore();
    cin.get();
}

int main() {
    do {
        mainmenu();
    } while (!closeProgram);
    return 0;
}