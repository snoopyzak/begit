#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char nom[70];
    char country[70];
    char division[70];
} equipe;

typedef struct {
    int num;
    int age;
    char nom[70];
    char poste[70];
    equipe eq;
} joueur;

int recherche_eq(int Numrech) {
    FILE *F1 = fopen("equipe.txt", "r");
    if (F1 == NULL) {
        perror("Erreur lors de l'ouverture du fichier equipe.txt");
        return -1;
    }
    equipe eq;

    // Move file position to the beginning of the file
    fseek(F1, 0, SEEK_SET);

    while (fscanf(F1, "%d %[^\n] %[^\n] %[^\n]", &eq.num, eq.nom, eq.division, eq.country) == 4) {
        if (eq.num == Numrech) {
            fclose(F1);
            return 1;
        }
    }
    fclose(F1);
    return -1;
}

int recherche_j(int Numrech, joueur *j) {
    FILE *F1 = fopen("joueur.txt", "r");
    if (F1 == NULL) {
        perror("Erreur lors de l'ouverture du fichier joueur.txt");
        return -1;
    }

    // Move file position to the beginning of the file
    fseek(F1, 0, SEEK_SET);

    while (fscanf(F1, "%d %s %d %s %[^\n]", &j->num, j->nom, &j->age, j->poste, j->eq.nom) == 5) {
        if (j->num == Numrech) {
            fclose(F1);
            return 1;
        }
    }
    fclose(F1);
    return -1;
}

void ajouter_eq() {
    equipe eq;
    int ID;
    FILE *F1 = fopen("equipe.txt", "a");

    if (F1 == NULL) {
        perror("Erreur lors de l'ouverture du fichier equipe.txt");
        return;
    }

    printf("Veuillez entrer le numero de la nouvelle equipe : ");
    scanf("%d", &ID);

    while (recherche_eq(ID) == 1) {
        printf("Ce numero existe deja.\n");
        printf("Veuillez entrer le numero de la nouvelle equipe : ");
        scanf("%d", &ID);
    }

    eq.num = ID;
    printf("\nVeuillez entrer le nom : ");
    scanf("%s", eq.nom);
    printf("Veuillez entrer le pays : ");
    scanf("%s", eq.country);
    printf("Veuillez entrer la division : ");
    scanf("%s", eq.division);

    fprintf(F1, "%d %s %s %s\n", eq.num, eq.nom, eq.division, eq.country);
    printf("L'ajout est bien fait.\n");

    fclose(F1);
}

void modifier_eq() {
    int ID;
    printf("Veuillez saisir le numero de l'equipe a modifier : ");
    scanf("%d", &ID);

    if (recherche_eq(ID) == 1) {
        FILE *F1 = fopen("equipe.txt", "r");
        FILE *F2 = fopen("rempequipe.txt", "w");

        equipe eq;

        while (fscanf(F1, "%d %s %s %s", &eq.num, eq.nom, eq.division, eq.country) == 4) {
            if (eq.num == ID) {
                printf("Veuillez entrer le nouveau nom : ");
                scanf("%s", eq.nom);
                printf("Veuillez entrer le nouveau pays : ");
                scanf("%s", eq.country);
                printf("Veuillez entrer la nouvelle division : ");
                scanf("%s", eq.division);
            }
            fprintf(F2, "%d %s %s %s\n", eq.num, eq.nom, eq.division, eq.country);
        }
        fclose(F1);
        fclose(F2);

        remove("equipe.txt");
        rename("rempequipe.txt", "equipe.txt");
        printf("La modification est bien faite.\n");

    } else {
        printf("Le numero saisi n'existe pas.\n");
    }
}

void supprimer_eq() {
    int ID;
    char nom[30];

    printf("Veuillez saisir le numero de l'equipe a supprimer : ");
    scanf("%d", &ID);

    if (recherche_eq(ID) == 1) {
        printf("Voulez-vous vraiment supprimer cette equipe ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");

        int x;
        scanf("%d", &x);

        switch (x) {
            case 1: {
                FILE *F1 = fopen("equipe.txt", "r");
                FILE *F2 = fopen("rempequipe.txt", "w");

                equipe eq;

                while (fscanf(F1, "%d %s %s %s", &eq.num, eq.nom, eq.division, eq.country) == 4) {
                    if (ID != eq.num) {
                        fprintf(F2, "%d %s %s %s\n", eq.num, eq.nom, eq.division, eq.country);
                    }
                }
                fclose(F1);
                fclose(F2);

                remove("equipe.txt");
                rename("rempequipe.txt", "equipe.txt");

                printf("Veuillez confirmer le nom de votre equipe pour supprimer tous les joueurs de cette equipe : ");
                scanf("%s", nom);

                FILE *F3 = fopen("joueur.txt", "r");
                FILE *F4 = fopen("rempjoueur.txt", "w");

                joueur j;

                while (fscanf(F3, "%d %s %d %s %s", &j.num, j.nom, &j.age, j.poste, j.eq.nom) == 5) {
                    if (strcmp(j.eq.nom, nom) != 0) {
                        fprintf(F4, "%d %s %d %s %s\n", j.num, j.nom, j.age, j.poste, j.eq.nom);
                    }
                }

                fclose(F3);
                fclose(F4);

                remove("joueur.txt");
                rename("rempjoueur.txt", "joueur.txt");
                printf("La suppression est bien faite.\n");
                break;
            }
            case 2:
                printf("La suppression est annulee.\n");
                break;
            default:
                printf("Erreur.\n");
                break;
        }
    } else {
        printf("Le numero saisi n'existe pas.\n");
    }
}

void ajouter_j() {
    joueur j;
    int ID;
    FILE *F1 = fopen("joueur.txt", "a");

    if (F1 == NULL) {
        perror("Erreur lors de l'ouverture du fichier joueur.txt");
        return;
    }

    printf("Veuillez entrer le numero du nouveau joueur : ");
    scanf("%d", &ID);

    while (recherche_j(ID, &j) == 1) {
        printf("Ce numero existe deja.\n");
        printf("Veuillez entrer le numero du nouveau joueur : ");
        scanf("%d", &ID);
    }

    j.num = ID;

    printf("\nVeuillez entrer le nom : ");
    scanf("%s", j.nom);
    printf("Veuillez entrer l'age : ");
    scanf("%d", &j.age);
    printf("Veuillez entrer la poste : ");
    scanf("%s", j.poste);
    printf("Veuillez entrer l'equipe : ");
    scanf("%s", j.eq.nom);

    fprintf(F1, "%d %s %d %s %s\n", j.num, j.nom, j.age, j.poste, j.eq.nom);
    printf("L'ajout a bien ete fait.\n");

    fclose(F1);
}

void modifier_j() {
    int ID;
    printf("Veuillez saisir le numero du joueur a modifier : ");
    scanf("%d", &ID);
    joueur j;
    if (recherche_j(ID, &j) == 1) {
        FILE *F1 = fopen("joueur.txt", "r");
        FILE *F2 = fopen("rempjoueur1.txt", "w");

        joueur j;

        while (fscanf(F1, "%d %s %d %s %s", &j.num, j.nom, &j.age, j.poste, j.eq.nom) == 5) {
            if (j.num == ID) {
                printf("Veuillez entrer le nouveau nom : ");
                scanf("%s", j.nom);
                printf("Veuillez entrer le nouveau age : ");
                scanf("%d", &j.age);
                printf("Veuillez entrer la nouvelle poste : ");
                scanf("%s", j.poste);
                printf("Veuillez entrer la nouvelle equipe : ");
                scanf("%s", j.eq.nom);
            }
            fprintf(F2, "%d %s %d %s %s\n", j.num, j.nom, j.age, j.poste, j.eq.nom);
        }
        fclose(F1);
        fclose(F2);
        remove("joueur.txt");
        rename("rempjoueur1.txt", "joueur.txt");
        printf("La modification est bien faite.\n");
    } else {
        printf("Le numero saisi n'existe pas.\n");
    }
}

void supprimer_j() {
    int a;
    int ID;
    FILE *F1, *F2, *F3;
    printf("Veuillez saisir le numero du joueur a supprimer : ");
    scanf("%d", &ID);
    joueur j;
    if (recherche_j(ID, &j) == 1) {
        printf("\nVoulez vous vraiment supprimer ce joueur ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                F1 = fopen("joueur.txt", "r");
                F2 = fopen("rempla.txt", "w");
                while (fscanf(F1, "%d %s %d %s %s", &j.num, j.nom, &j.age, j.poste, j.eq.nom) == 5) {
                    if (ID != j.num) {
                        fprintf(F2, "%d %s %d %s %s\n", j.num, j.nom, j.age, j.poste, j.eq.nom);
                    }
                }
                fclose(F1);
                fclose(F2);
                remove("joueur.txt");
                rename("rempla.txt", "joueur.txt");
                printf("La suppression a bien ete faite.\n");
                break;
            case 2:
                printf("La suppression est annulee.\n");
                break;
            default:
                printf("Erreur.\n");
                break;
        }
    } else {
        printf("Le numero saisi n'existe pas.\n");
    }
}

int main(int argc, char *argv[]) {
    int x;
    do {
        int n, m;
        printf("Que voulez vous choisir ?\n");
        printf("1. Equipe\n");
        printf("2. Joueur\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Que voulez vous faire ?\n");
                printf("1. Ajouter\n");
                printf("2. Modifier\n");
                printf("3. Supprimer\n");
                scanf("%d", &m);
                switch (m) {
                    case 1:
                        ajouter_eq();
                        break;
                    case 2:
                        modifier_eq();
                        break;
                    case 3:
                        supprimer_eq();
                        break;
                    default:
                        printf("erreur.\n");
                        break;
                }
                break;

            case 2:
                printf("Que voulez vous faire ?\n");
                printf("1. Ajouter\n");
                printf("2. Modifier\n");
                printf("3. Supprimer\n");
                scanf("%d", &m);
                switch (m) {
                    case 1:
                        ajouter_j();
                        break;
                    case 2:
                        modifier_j();
                        break;
                    case 3:
                        supprimer_j();
                        break;
                    default:
                        printf("erreur\n");
                        break;
                }
                break;
        }
        printf("Voulez vous continuer ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        scanf("%d", &x);
    } while (x == 1);

    return 0;
}
