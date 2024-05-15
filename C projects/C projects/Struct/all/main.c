#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attributes.h"
#include "printer.h"

#define MAX_FORMATIONS 6

void printFormationToFile(struct Formation *form);
void loadFormations(struct Formation formations[MAX_FORMATIONS]);
void enterFormationData(struct Formation *formation, struct Formation formations[MAX_FORMATIONS]);
void printMenu();
void navigateFormations(struct Formation formations[MAX_FORMATIONS]);

void loadFormations(struct Formation formations[MAX_FORMATIONS])
{
    FILE* file = fopen("formations.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file formations.txt\n");
        exit(1);
    }

    for (int i = 0; i < MAX_FORMATIONS; ++i)
    {
        fscanf(file, "%s", formations[i].name);

        strcpy(formations[i].modules[0].name, "");
        formations[i].modules[0].time = 0;
        strcpy(formations[i].modules[0].teacher, "");
        strcpy(formations[i].etud.Nom, "");
        strcpy(formations[i].etud.Prenom, "");
        formations[i].etud.Age = 0;
        strcpy(formations[i].etud.Ville, "");
        strcpy(formations[i].etud.Formation, "");
        strcpy(formations[i].dep.name, "");
        strcpy(formations[i].teacher.first_name, "");
        strcpy(formations[i].teacher.last_name, "");
        strcpy(formations[i].teacher.speciality, "");
        strcpy(formations[i].teacher.departement, "");
    }

    fclose(file);
}


void enterFormationData(struct Formation *formation, struct Formation formations[MAX_FORMATIONS])
{
    int formationIndex;
    printf("Select a formation:\n");
    for (int i = 0; i < MAX_FORMATIONS; i++) {
        if (strlen(formations[i].name) > 0) {
            printf("%d. %s\n", i + 1, formations[i].name);
        }
    }

    printf("Enter the index of the formation: ");
    scanf("%d", &formationIndex);

    if (formationIndex < 1 || formationIndex > MAX_FORMATIONS || strlen(formations[formationIndex - 1].name) == 0)
    {
        printf("Invalid formation index.\n");
        return;
    }

    printf("Enter module name: ");
    scanf("%s", formation->modules[0].name);
    printf("Enter module time: ");
    scanf("%d", &formation->modules[0].time);
    printf("Enter module teacher: ");
    scanf("%s", formation->modules[0].teacher);

    printf("Enter student last name: ");
    scanf("%s", formation->etud.Nom);
    printf("Enter student first name: ");
    scanf("%s", formation->etud.Prenom);
    printf("Enter student age: ");
    scanf("%d", &formation->etud.Age);
    printf("Enter student city: ");
    scanf("%s", formation->etud.Ville);
    printf("Enter student formation: ");
    scanf("%s", formation->etud.Formation);

    printf("Enter department name: ");
    scanf("%s", formation->dep.name);

    printf("Enter teacher first name: ");
    scanf("%s", formation->teacher.first_name);
    printf("Enter teacher last name: ");
    scanf("%s", formation->teacher.last_name);
    printf("Enter teacher speciality: ");
    scanf("%s", formation->teacher.speciality);
    printf("Enter teacher department: ");
    scanf("%s", formation->teacher.departement);

    printf("Formation data entered successfully.\n");
}

void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Enter formation data\n");
    printf("2. Print formation data to file\n");
    printf("3. Load formations from file\n");
    printf("4. Navigate formations\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void showFormations(struct Formation formations[MAX_FORMATIONS])
{
    printf("Select a formation:\n");
    for (int i = 0; i < MAX_FORMATIONS; i++)
    {
        if (strlen(formations[i].name) > 0)
        {
            printf("%d. %s\n", i + 1, formations[i].name);
        }
    }
}

void navigateFormations(struct Formation formations[MAX_FORMATIONS])
{
    int formationIndex;
    do
    {
        printf("\nEnter formation index (1-%d) or 0 to go back: \n", MAX_FORMATIONS);
        for (int i = 0; i < MAX_FORMATIONS; i++)
            {
                if (strlen(formations[i].name) > 0)
                {
                    printf("%d. %s\n", i + 1, formations[i].name);
                }
            }
        scanf("%d", &formationIndex);
        if (formationIndex >= 1 && formationIndex <= MAX_FORMATIONS)
        {
            printFormationToFile(&formations[formationIndex - 1]);
        }
        else if (formationIndex != 0)
        {
            printf("Invalid index. Please enter a valid index.\n");
        }
    } while (formationIndex != 0);
}

int main()
{
    struct Formation formations[MAX_FORMATIONS];
    int choice;
    int formationsLoaded = 0;

    do
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterFormationData(&formations[0], formations);
                break;
            case 2:
                printf("\nPrinting formation data to file...\n");
                printFormationToFile(&formations[0]);
                break;
            case 3:
                printf("\nLoading formations from file...\n");
                loadFormations(formations);
                formationsLoaded = 1;
                printf("Formations loaded successfully.\n");
                break;
            case 4:
                if (formationsLoaded)
                {
                    navigateFormations(formations);
                }
                else
                {
                    printf("Please load formations first.\n");
                }
                break;
            case 5:
                    printf("\nExiting the program.\n");
                    break;
                default:
                    printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}