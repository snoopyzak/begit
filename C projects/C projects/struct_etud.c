#include <stdio.h>

struct Etudiant
{
    char Nom[100];
    char Prenom[100];
    int Age;
    char Ville[100];
    char Formation[100];
};

void inputEtudiant(struct Etudiant etudiant)
{
    printf("Enter the name: ");
    scanf("%s", etudiant.Nom);
    
    printf("Enter the first name: ");
    scanf("%s", etudiant.Prenom);
    
    printf("Enter the age: ");
    scanf("%d", &etudiant.Age);
    
    printf("Enter the city: ");
    scanf("%s", etudiant.Ville);
    
    printf("Enter the field of study: ");
    scanf("%s", etudiant.Formation);
}

void displayEtudiant(const struct Etudiant etudiant)
{
    printf("\nStudent Information:\n");
    printf("Name: %s %s\n", etudiant.Prenom, etudiant.Nom);
    printf("Age: %d\n", etudiant.Age);
    printf("City: %s\n", etudiant.Ville);
    printf("Field of Study: %s\n", etudiant.Formation);
}

int main()
{
    struct Etudiant etudiant;
    
    inputEtudiant(etudiant);
    
    displayEtudiant(etudiant);
    
    return 0;
}
