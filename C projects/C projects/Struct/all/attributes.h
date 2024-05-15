#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

struct Etudiant
{
    char Nom[100];
    char Prenom[100];
    int Age;
    char Ville[100];
    char Formation[100];
};

struct Departement
{
    char name[99];
};

struct Formator
{
    char first_name[99];
    char last_name[99];
    char speciality[99];
    char departement[99];
};

struct Modules
{
    char name[99];
    int time;
    char teacher[99];
};

struct Formation
{
    char name[25];
    struct Modules modules[6];
    struct Etudiant etud;
    struct Departement dep;
    struct Formator teacher;
};

#endif
