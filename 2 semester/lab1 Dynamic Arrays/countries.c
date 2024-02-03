#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country {
    char name[50];
    int gold;
    int silver;
    int bronze;
};

void addCountry(struct Country countries[], int *totalCountries) {
    char name[50];
    int gold, silver, bronze;

    printf("Enter country name: ");
    scanf("%s", name);

    printf("Enter number of gold medals: ");
    scanf("%d", &gold);

    printf("Enter number of silver medals: ");
    scanf("%d", &silver);

    printf("Enter number of bronze medals: ");
    scanf("%d", &bronze);

    int countryIndex = -1;
    for (int i = 0; i < *totalCountries; i++) {
        if (strcmp(countries[i].name, name) == 0) {
            countryIndex = i;
            break;
        }
    }

    if (countryIndex != -1) {
        countries[countryIndex].gold += gold;
        countries[countryIndex].silver += silver;
        countries[countryIndex].bronze += bronze;
    } else {
        strcpy(countries[*totalCountries].name, name);
        countries[*totalCountries].gold = gold;
        countries[*totalCountries].silver = silver;
        countries[*totalCountries].bronze = bronze;
        (*totalCountries)++;
    }

    for (int i = 0; i < *totalCountries - 1; i++) {
        for (int j = 0; j < *totalCountries - i - 1; j++) {
            int totalMedals1 = countries[j].gold + countries[j].silver + countries[j].bronze;
            int totalMedals2 = countries[j + 1].gold + countries[j + 1].silver + countries[j + 1].bronze;

            if (totalMedals1 < totalMedals2 ||
                (totalMedals1 == totalMedals2 && strcmp(countries[j].name, countries[j + 1].name) > 0)) {
                struct Country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }

    printf("Data updated successfully.\n");
}

void displayCountryData(struct Country countries[], int totalCountries) {
    char name[50];
    printf("Enter country name: ");
    scanf("%s", name);

    int countryIndex = -1;
    for (int i = 0; i < totalCountries; i++) {
        if (strcmp(countries[i].name, name) == 0) {
            countryIndex = i;
            break;
        }
    }

    if (countryIndex != -1) {
        printf("Country: %s\n", countries[countryIndex].name);
        printf("Gold: %d\n", countries[countryIndex].gold);
        printf("Silver: %d\n", countries[countryIndex].silver);
        printf("Bronze: %d\n", countries[countryIndex].bronze);
        printf("Total Medals: %d\n",
               countries[countryIndex].gold + countries[countryIndex].silver + countries[countryIndex].bronze);
    } else {
        printf("Country not found.\n");
    }
}

void displaySummaryTable(struct Country countries[], int totalCountries) {
    printf("Medal Summary Table:\n");
    printf("Place\tCountry\tGold\tSilver\tBronze\tTotal\n");

    for (int i = 0; i < totalCountries; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", i + 1, countries[i].name, countries[i].gold, countries[i].silver,
               countries[i].bronze,
               countries[i].gold + countries[i].silver + countries[i].bronze);
    }
}

int main() {
    struct Country countries[100];
    int totalCountries = 0;
    int choice;

    do {
        printf("\nMain Menu:\n");
        printf("1. Add/Update Country Data\n");
        printf("2. Display Country Data\n");
        printf("3. Display Summary Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n1. Add/Update Country Data:\n");
                addCountry(countries, &totalCountries);
                break;
            case 2:
                printf("\n2. Display Country Data:\n");
                displayCountryData(countries, totalCountries);
                break;
            case 3:
                printf("\n3. Display Summary Table:\n");
                displaySummaryTable(countries, totalCountries);
                break;
            case 4:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
