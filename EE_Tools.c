#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


void readColorCodedResistor() {
    char* colors[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Gray", "White"};// all band colors
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double multipliers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    
    int bandType, band1, band2, band3, band4, band5;
    
    printf("\n=== Read color-coded resistor ===\n");
    printf("Select resistor type (4-4 bands, 5-5 bands): ");
    scanf("%d", &bandType);

    if(bandType == 4) {
        // 4-band resistor: 2 digits, multiplier, tolerance
        printf("\n--- 4-Band Resistor ---\n");
        printf("Color Codes for Bands 1-3: 0-Black, 1-Brown, 2-Red, 3-Orange, 4-Yellow, 5-Green, 6-Blue, 7-Violet, 8-Gray, 9-White\n");
        printf("Color Codes for Band 4 (Tolerance): 1-Brown(1%%), 2-Red(2%%), 3-Gold(5%%), 4-Silver(10%%)\n\n");

        printf("Enter 1st band (digit 1, 0-9): ");
        scanf("%d", &band1);
        printf("Enter 2nd band (digit 2, 0-9): ");
        scanf("%d", &band2);
        printf("Enter 3rd band (multiplier, 0-9): ");
        scanf("%d", &band3);
        printf("Enter 4th band (tolerance, 1-4): ");
        scanf("%d", &band4);

        if(band1 < 0 || band1 > 9 || band2 < 0 || band2 > 9 || band3 < 0 || band3 > 9) {
            printf("Invalid input!\n");//Input Validation
            return;
        }

        double resistance = (values[band1] * 10 + values[band2]) * multipliers[band3];
        char* tolerance;

        switch(band4) {
            case 1: tolerance = "1%"; break;
            case 2: tolerance = "2%"; break;
            case 3: tolerance = "5%"; break;
            case 4: tolerance = "10%"; break;
            default: tolerance = "Unknown";
        }

        printf("\n4-Band Resistor Value: ");
        if(resistance >= 1000000) {
            printf("%.2f MOhm", resistance/1000000);
        } else if(resistance >= 1000) {
            printf("%.2f KOhm", resistance/1000);
        } else {
            printf("%.0f Ohm", resistance);
        }
        printf(" +/-%s\n", tolerance);


        printf("Color Bands: %s - %s - %s - ", colors[band1], colors[band2], colors[band3]);
        switch(band4) {
            case 1: printf("Brown\n"); break;
            case 2: printf("Red\n"); break;
            case 3: printf("Gold\n"); break;
            case 4: printf("Silver\n"); break;
            default: printf("Unknown\n");
        }

    } else if(bandType == 5) {
        // 5-band resistor: 3 digits, multiplier, tolerance
        printf("\n--- 5-Band Resistor ---\n");
        printf("Color Codes for Bands 1-4: 0-Black, 1-Brown, 2-Red, 3-Orange, 4-Yellow\n");
        printf("                         5-Green, 6-Blue, 7-Violet, 8-Gray, 9-White\n");
        printf("Color Codes for Band 5 (Tolerance):\n");
        printf("  1-Brown(1%%), 2-Red(2%%), 3-Orange(0.05%%), 4-Yellow(0.02%%), 5-Gold(5%%), 6-Silver(10%%), 7-Violet(0.5%%)\n\n");

        printf("Enter 1st band (digit 1, 0-9): ");
        scanf("%d", &band1);
        printf("Enter 2nd band (digit 2, 0-9): ");
        scanf("%d", &band2);
        printf("Enter 3rd band (digit 3, 0-9): ");
        scanf("%d", &band3);
        printf("Enter 4th band (multiplier, 0-9): ");
        scanf("%d", &band4);
        printf("Enter 5th band (tolerance, 1-4): ");
        scanf("%d", &band5);

        if(band1 < 0 || band1 > 9 || band2 < 0 || band2 > 9 || band3 < 0 || band3 > 9 || band4 < 0 || band4 > 9) {
            printf("Invalid color code input!\n");
            return;
        }

        double resistance = (values[band1] * 100 + values[band2] * 10 + values[band3]) * multipliers[band4];
        char* tolerance;

        switch(band5) {
            case 1: tolerance = "1%"; break;
            case 2: tolerance = "2%"; break;
            case 3: tolerance = "0.05%"; break;  // Orange for precision resistors
            case 4: tolerance = "0.02%"; break;  // Yellow for precision resistors
            case 5: tolerance = "5%"; break;
            case 6: tolerance = "10%"; break;
            case 7: tolerance = "0.5%"; break;   // Violet for precision resistors
            default: tolerance = "Unknown";
        }

        printf("\n5-Band Resistor Value: ");
        if(resistance >= 1000000) {
            printf("%.3f MOhm", resistance/1000000);
        } else if(resistance >= 1000) {
            printf("%.3f KOhm", resistance/1000);
        } else {
            printf("%.0f Ohm", resistance);
        }
        printf(" +/-%s\n", tolerance);


        printf("Color Bands: %s - %s - %s - %s - ",
               colors[band1], colors[band2], colors[band3], colors[band4]);
        switch(band5) {
            case 1: printf("Brown\n"); break;
            case 2: printf("Red\n"); break;
            case 3: printf("Orange\n"); break;
            case 4: printf("Yellow\n"); break;
            case 5: printf("Gold\n"); break;
            case 6: printf("Silver\n"); break;
            case 7: printf("Violet\n"); break;
            default: printf("Unknown\n");
        }
        
    } else {
        printf("Invalid resistor type! Please enter 4 or 5.\n");
    }
}


void readSMDResistor() {
    char code[10];
    int type;
    
    printf("\n=== SMD RESISTOR READER ===\n");
    printf("Encoding types:\n");
    printf("1. 3-digit code (e.g., 103, 472)\n");
    printf("2. 4-digit code (e.g., 4700, 1001)\n");
    printf("3. E-96 code (e.g., 01C, 68X)\n");
    printf("4. Letter code (e.g., R10, 4K7)\n");
    printf("Select encoding type (1-4): ");
    scanf("%d", &type);
    getchar();
    
    printf("Enter resistor code: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = 0;
    
    for(int i = 0; code[i]; i++) {
        code[i] = toupper(code[i]);
    }
    
    double resistance = 0;
    double tolerance = 0;
    char* tolerance_str = "Unknown";
    
    switch(type) {
        case 1:
            if(strlen(code) == 3 && isdigit(code[0]) && isdigit(code[1]) && isdigit(code[2])) {
                int digit1 = code[0] - '0';
                int digit2 = code[1] - '0';
                int multiplier = code[2] - '0';
                resistance = (digit1 * 10 + digit2) * pow(10, multiplier);
                tolerance = 5.0;
                tolerance_str = "5%";
            } else {
                printf("Invalid 3-digit code!\n");
                return;
            }
            break;
            
        case 2:
            if(strlen(code) == 4 && isdigit(code[0]) && isdigit(code[1]) && isdigit(code[2]) && isdigit(code[3])) {
                int digit1 = code[0] - '0';
                int digit2 = code[1] - '0';
                int digit3 = code[2] - '0';
                int multiplier = code[3] - '0';
                resistance = (digit1 * 100 + digit2 * 10 + digit3) * pow(10, multiplier);
                tolerance = 1.0;
                tolerance_str = "1%";
            } else {
                printf("Invalid 4-digit code!\n");
                return;
            }
            break;
            
        case 3:
            if(strlen(code) == 3) {
                double e96_values[] = {
                    100, 102, 105, 107, 110, 113, 115, 118, 121, 124, 127, 130,
                    133, 137, 140, 143, 147, 150, 154, 158, 162, 165, 169, 174,
                    178, 182, 187, 191, 196, 200, 205, 210, 215, 221, 226, 232,
                    237, 243, 249, 255, 261, 267, 274, 280, 287, 294, 301, 309,
                    316, 324, 332, 340, 348, 357, 365, 374, 383, 392, 402, 412,
                    422, 432, 442, 453, 464, 475, 487, 499, 511, 523, 536, 549,
                    562, 576, 590, 604, 619, 634, 649, 665, 681, 698, 715, 732,
                    750, 768, 787, 806, 825, 845, 866, 887, 909, 931, 953, 976
                };
                
                char multiplier_codes[] = {'A','B','C','D','E','F','G','H','X','Y','Z'};
                double multiplier_values[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 0.1, 0.01, 0.1, 0.01};
                
                if(isdigit(code[0]) && isdigit(code[1])) {
                    int index = (code[0] - '0') * 10 + (code[1] - '0') - 1;
                    if(index >= 0 && index < 96) {
                        resistance = e96_values[index];
                        
                        for(int i = 0; i < 11; i++) {
                            if(code[2] == multiplier_codes[i]) {
                                resistance *= multiplier_values[i];
                                break;
                            }
                        }
                        tolerance = 1.0;
                        tolerance_str = "1%";
                    } else {
                        printf("Invalid E-96 code index!\n");
                        return;
                    }
                } else {
                    printf("Invalid E-96 code format!\n");
                    return;
                }
            }
            break;
            
        case 4:
            {
                char num_part[10] = {0};
                char unit_part[5] = {0};
                int num_idx = 0, unit_idx = 0;
                int decimal_point = -1;
                
                for(int i = 0; code[i]; i++) {
                    if(isdigit(code[i]) || code[i] == '.') {
                        if(code[i] == '.') decimal_point = i;
                        num_part[num_idx++] = code[i];
                    } else if(isalpha(code[i])) {
                        unit_part[unit_idx++] = code[i];
                    }
                }
                num_part[num_idx] = '\0';
                unit_part[unit_idx] = '\0';
                
                if(strlen(num_part) > 0) {
                    resistance = atof(num_part);
                    
                    if(strcmp(unit_part, "R") == 0) {
                    } else if(strcmp(unit_part, "K") == 0) {
                        resistance *= 1000;
                    } else if(strcmp(unit_part, "M") == 0) {
                        resistance *= 1000000;
                    } else {
                        if(strlen(unit_part) == 2) {
                            char unit_char = unit_part[0];
                            char digit_char = unit_part[1];
                            if(isdigit(digit_char)) {
                                resistance = (resistance * 10 + (digit_char - '0'));
                                if(unit_char == 'K') resistance *= 100;
                                else if(unit_char == 'M') resistance *= 100000;
                            }
                        }
                    }
                    tolerance = 5.0;
                    tolerance_str = "5%";
                } else {
                    printf("Invalid letter code format!\n");
                    return;
                }
            }
            break;
            
        default:
            printf("Invalid encoding type!\n");
            return;
    }
    
    printf("\n=== RESISTOR VALUE ===\n");
    printf("Code: %s\n", code);
    printf("Resistance: ");
    
    if(resistance >= 1000000) {
        printf("%.3f MOhm", resistance / 1000000);
    } else if(resistance >= 1000) {
        printf("%.3f KOhm", resistance / 1000);
    } else if(resistance >= 1) {
        printf("%.3f Ohm", resistance);
    } else {
        printf("%.3f mOhm", resistance * 1000);
    }
    
    printf(" +/-%s\n", tolerance_str);

}