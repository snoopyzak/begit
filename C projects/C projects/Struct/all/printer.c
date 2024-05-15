#include <stdio.h>
#include "attributes.h"

void printFormationToFile(struct Formation *form)
{
    FILE* fptr;
    fptr = fopen("data.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fptr, "+------------------+-------------------+\n");
    fprintf(fptr, "| Formation name   | %18s |\n", form->name);
    fprintf(fptr, "+------------------+-------------------+\n");
    fprintf(fptr, "| Module name      | %18s |\n", form->modules[0].name);
    fprintf(fptr, "| Module time      | %18d |\n", form->modules[0].time);
    fprintf(fptr, "| Module teacher   | %18s |\n", form->modules[0].teacher);
    fprintf(fptr, "+------------------+-------------------+\n");
    fprintf(fptr, "| Student last name| %18s |\n", form->etud.Nom);
    fprintf(fptr, "| Student first name| %17s |\n", form->etud.Prenom);
    fprintf(fptr, "| Student age      | %18d |\n", form->etud.Age);
    fprintf(fptr, "| Student city     | %18s |\n", form->etud.Ville);
    fprintf(fptr, "| Student formation| %18s |\n", form->etud.Formation);
    fprintf(fptr, "+------------------+-------------------+\n");
    fprintf(fptr, "| Department name  | %18s |\n", form->dep.name);
    fprintf(fptr, "+------------------+-------------------+\n");
    fprintf(fptr, "| Teacher first name| %17s |\n", form->teacher.first_name);
    fprintf(fptr, "| Teacher last name| %18s |\n", form->teacher.last_name);
    fprintf(fptr, "| Teacher speciality| %17s |\n", form->teacher.speciality);
    fprintf(fptr, "| Teacher department| %17s |\n", form->teacher.departement);
    fprintf(fptr, "+------------------+-------------------+\n");
    fclose(fptr);
}