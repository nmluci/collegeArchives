// Pseudocode of Airport Simulator
// Coded by Cxizaki

#include <stdio.h>
#include <conio.h> // Header for getch()
#include <string.h> 

// Main function
int main() {
    // A Structure Datatype for storing customer's personal information
    struct flightInfo {
        char no[8];             // Flight Number
        char depAirport[200];   // Departure Airport Name 
        char destAirport[200];  // Destination Airport Name
        char dateFlight[12];    // Date of Flight
        char depTime[50];       // Departure Time
        char arrTime[50];       // Arrival Time
    };

    // Declared variable using CustInfo Datatype
    struct flightInfo flight;

    // Example Case of Data
    strcpy(flight.no, "JA177");
    strcpy(flight.depAirport, "Soekarno-Hatta International Airport (CKG)");
    strcpy(flight.destAirport, "Yakutsk Airport (YSK)");
    strcpy(flight.dateFlight, "28/10/2045");
    strcpy(flight.depTime, "08.00 WIB (UTC+7)");
    strcpy(flight.arrTime, "13.49 YAKT (UTC+9)");
    // Showcasing the entered data
    printf("Flight Information ---------------------------------------------\n");
    printf("Flight Number %s\n", flight.no);
    printf("Date: %s\n", flight.dateFlight);
    printf("Departured Airport: %s\n", flight.depAirport);
    printf("Destination Airport: %s\n", flight.destAirport);
    printf("Departure Time: %s\n", flight.depTime);
    printf("Arrival Time: %s\n", flight.arrTime);
    printf("-----------------------------------------------------------------\n");
    getch();
    return 0;

}