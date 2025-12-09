#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"
#include "EE_Tools.h"
#include "Mathmatic_Tools.h"
#include "Unit_transfer.h"

void mainMenu() {
    int choice;
    
    while(1) {
        printf("\n=== MAIN MENU ===\n");
        printf("1. EE Tools\n");
        printf("2. Mathmatic Tools\n");
        printf("3. Unit_transfer\n");
        printf("4. Exit System\n");
        printf("Please select function (1-4): ");
        
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch(choice) {
            case 1:
                electronicEngineeringMenu();
                break;
            case 2:
                engineeringMathMenu();
                break;
            case 3:
                Unit_transfer();
                break;
            case 4:
                printf("Thank you for using! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection, please try again!\n");
        }
    }
}

void electronicEngineeringMenu() {
    int choice;
    
    while(1) {
        printf("\n=== EE Tools ===\n");
        printf("1. Read color-coded Resistor\n");
        printf("2. Read SMD Resistor\n");
        printf("3. Return to Main Menu\n");
        printf("Please select function (1-3): ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                readColorCodedResistor();
                break;
            case 2:
                readSMDResistor();
                break;
            case 3:
                return;
            default:
                printf("Invalid selection, please try again!\n");
        }
    }
}

void engineeringMathMenu() {
    int choice;
    
    while(1) {
        printf("\n=== Mathmatic Tools ===\n");
        printf("1. basicCalculator\n");
        printf("2. numericalrootfinder\n");
        printf("3. Return to Main Menu\n");
        printf("Please select function (1-4): ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                numericalRootFinder();
                break;
            case 3:
                return;
            default:
                printf("Invalid selection, please try again!\n");
        }
    }
}

void Unit_transfer() {
    int choice;
    
    while(1) {
        printf("\n=== Unit_transfer ===\n");
        printf("1. convert_power\n");
        printf("2. convert_frequency\n");
        printf("3. Return to Main Menu\n");
        printf("Please select function (1-3): ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                convert_power();
                break;
            case 2:
                convert_frequency();
                break;
            case 3:
                return;
            default:
                printf("Invalid selection, please try again!\n");
        }
    }
}