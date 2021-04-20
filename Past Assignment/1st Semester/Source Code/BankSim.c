// Pseudocode of Bank Simulator
// Coded by Cxizaki

#include <stdio.h>
#include <conio.h> // Header for getch()
#include <string.h> 

// Main function
int main() {
    // A Structure Datatype for storing customer's personal information
    struct CustInfo
    {
        int accountNo;      // Bank Account Number
        char name[120];     // Account Holder's Name
        char address[200];  // Account Holder's Address
        char city[50];      // Account Holder's lived City
        long long phone;    // Account Holder's phone number
    };
    
    // Declared variable using CustInfo Datatype
    struct CustInfo newUser;

    // Example Case of Data
    newUser.accountNo = 100551892;
    strcpy(newUser.name, "Cxizaki");
    strcpy(newUser.address ,"0xF4AC, Russiantown");
    strcpy(newUser.city, "Earthtown Prefecture, Nein Sub-Land, Planet Neptune");
    newUser.phone = 111111111117111;

    // Showcasing the entered data
    printf("Bank Account Information ---------------------------------------\n");
    printf("Account ID. %d\n", newUser.accountNo);
    printf("Name: %s\n", newUser.name);
    printf("Address: %s\n", newUser.address);
    printf("City: %s\n", newUser.city);
    printf("Phone: %lld\n", newUser.phone);
    printf("-----------------------------------------------------------------\n");
    getch();
    return 0;

}