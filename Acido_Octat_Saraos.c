#include <stdio.h>

float get_Rate(int currency_Num)
{
    switch (currency_Num)
    {
    case 1:
        return 1.00; // PHP
    case 2:
        return 67.00; // EUR
    case 3:
        return 78.00; // GBP
    case 4:
        return 0.38; // JPY
    case 5:
        return 37.50; // AUD
    case 6:
        return 41.50; // CAD
    case 7:
        return 74.00; // CHF
    case 8:
        return 7.50; // HKD
    case 9:
        return 8.20; // CNY
    case 10:
        return 58.00; // USD
    case 11:
        return 12.00; // MYR
    case 12:
        return 45.00; // SGD
    case 13:
        return 33.00; // NZD
    case 14:
        return 0.66; // INR
    case 15:
        return 17.00; // THB
    default:
        return 0.0;
    }
}

const char *getCurrencyName(int code)
{
    switch (code)
    {
    case 1:
        return "Philippine Peso (PHP)";
    case 2:
        return "Euro (EUR)";
    case 3:
        return "British Pound (GBP)";
    case 4:
        return "Japanese Yen (JPY)";
    case 5:
        return "Australian Dollar (AUD)";
    case 6:
        return "Canadian Dollar (CAD)";
    case 7:
        return "Swiss Franc (CHF)";
    case 8:
        return "Hong Kong Dollar (HKD)";
    case 9:
        return "Chinese Yuan (CNY)";
    case 10:
        return "US Dollar (USD)";
    case 11:
        return "Malaysian Ringgit (MYR)";
    case 12:
        return "Singapore Dollar (SGD)";
    case 13:
        return "New Zealand Dollar (NZD)";
    case 14:
        return "Indian Rupee (INR)";
    case 15:
        return "Thai Baht (THB)";
    default:
        return "Unknown Currency";
    }
}


void displayMenu()
{
    printf("\nList of available currencies:\n");
    printf("[1] PHP - Philippine Peso\n");
    printf("[2] EUR - Euro\n");
    printf("[3] GBP - British Pound\n");
    printf("[4] JPY - Japanese Yen\n");
    printf("[5] AUD - Australian Dollar\n");
    printf("[6] CAD - Canadian Dollar\n");
    printf("[7] CHF - Swiss Franc\n");
    printf("[8] HKD - Hong Kong Dollar\n");
    printf("[9] CNY - Chinese Yuan\n");
    printf("[10] USD - US Dollar\n");
    printf("[11] MYR - Malaysian Ringgit\n");
    printf("[12] SGD - Singapore Dollar\n");
    printf("[13] NZD - New Zealand Dollar\n");
    printf("[14] INR - Indian Rupee\n");
    printf("[15] THB - Thai Baht\n");
}


float convertCurrency(int from, int to, float amount)
{
    float rate_From = get_Rate(from);
    float rate_To = get_Rate(to);
    return (amount * rate_From) / rate_To;
}


int main()
{
    int current_Currency = 0;
    int to_Currency = 0;
    float amount = 0.0;
    float converted_amount = 0.0;
    char choice_YorN;

    printf("=========================================\n");
    printf("----------- CURRENCY CONVERTER ----------\n");
    printf("=========================================\n");
    printf("Note: The currency rates used in this program are\n");
    printf("based on approximate exchange values for October 2025.\n");

    do
    {
        displayMenu(); 

        
        do
        {
            printf("\nChoose your current currency [1-15]: ");
            scanf("%d", &current_Currency);

            if (current_Currency > 15 || current_Currency < 1)
            {
                printf("\n-- Invalid Number Choose Only [1-15] --\n");
            }

        } while (current_Currency > 15 || current_Currency < 1);

        do
        {
            printf("\nEnter the currency you want to convert to [1-15]: ");
            scanf("%d", &to_Currency);

            if (to_Currency > 15 || to_Currency < 1)
            {
                printf("\n-- Invalid Number Choose Only [1-15] --\n");
            }

        } while (to_Currency > 15 || to_Currency < 1);

        if (current_Currency == to_Currency)
        {
            printf("\nNo Conversion Needed - Same Currency Chosen!\n");
            continue;
        }

        do
        {
            printf("\nEnter Amount: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("\n-- Enter only positive number --\n");
            }

        } while (amount <= 0);

        converted_amount = convertCurrency(current_Currency, to_Currency, amount);

        printf("\n----------------------------------------\n");
        printf("            CONVERSION RESULT\n");
        printf("----------------------------------------\n");
        printf("From: %s\n", getCurrencyName(current_Currency));
        printf("To  : %s\n", getCurrencyName(to_Currency));
        printf("-----------------------------------------\n");
        printf("Amount Entered     : %.2f\n", amount);
        printf("Converted Amount   : %.2f\n", converted_amount);
        printf("-----------------------------------------\n");

        
        do
        {
            printf("\nWould you like to convert again? (Y/N): ");
            scanf(" %c", &choice_YorN);

            if (choice_YorN == 'Y' || choice_YorN == 'y')
            {
                break; 
            }
            else if (choice_YorN == 'N' || choice_YorN == 'n')
            {
                printf("\n-- Thank You Come Again! --\n");
                break;
            }
            else
            {
                printf("\nInvalid Input, Please enter only Y or N\n");
            }

        } while (choice_YorN != 'Y' && choice_YorN != 'y' && choice_YorN != 'N' && choice_YorN != 'n');

    } while (choice_YorN == 'Y' || choice_YorN == 'y');


    
    return 0;
}
