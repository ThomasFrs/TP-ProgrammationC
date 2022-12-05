#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LGMAXNOM 30
#define LGMAXPRENOM 20
#define LGMAXMAIL 254
#define LGMAXREP 64

// Type structuré pour stocker une date de naissance
struct sDate
{
  unsigned char Jour;
  unsigned char Mois;
  unsigned short int Annee;
};

// Type structuré pour stocker un contact
struct sContact
{
  char Nom[LGMAXNOM+1];
  char Prenom[LGMAXPRENOM+1];
  char Mail[LGMAXMAIL+1];
  struct sDate Naissance;
};


/* Affichage des informations d'un contact (version 1)
 * Entrée : 
 *    - Contact : le contact
 */
void AfficherContact1(struct sContact Contact)  
{
  printf("%s\n%s\n%s\n%02d/%02d/%d\n",
         Contact.Nom,
         Contact.Prenom,
         Contact.Mail,
         Contact.Naissance.Jour,
         Contact.Naissance.Mois,
         Contact.Naissance.Annee);
  // Remarque : %02d signifie entier sur 2 caractères avec ajout éventuel d'un 0 à gauche
}  
 
/* Affichage des informations d'un contact (version 2)
 * Entrée : 
 *     - pContact : adresse du contact
 */  
void AfficherContact2(const struct sContact *pContact)  
{
  printf("%s\n%s\n%s\n%02d/%02d/%d\n",
         pContact->Nom, // on utilise un pointeur vers une structure, donc une `->` et non un `.`
         pContact->Prenom,
         pContact->Mail,
         pContact->Naissance.Jour,
         pContact->Naissance.Mois,
         pContact->Naissance.Annee);
}  

/* Affichage de tous les contacts d'un répertoire
 * Entrées :
 *   - Repertoire : tableau de contacts
 *   - NbContacts : nombre de contacts
 */
void AfficherRepertoire(struct sContact Repertoire[], int NbContacts)
{
    for( int i=0; i<NbContacts; i++ )
    {
        const struct sContact *temp = &Repertoire[i]; // AfficherContact2 a besoin d'un const
        AfficherContact2(temp); // on ne peut pas directement transformer Repertoire[i] en un const
    }
}

/* Ajout d'un contact à la fin d'un répertoire
 * Entrée : 
 *    - pNouveau : adresse du contact à ajouter
 * Mises à jour (entrées et sorties):
 *    - Repertoire : tableau de contacts 
 *    - pNbContact : adresse du nombre de contacts
 */
void AjouterContact(struct sContact *pNouveau, 
                    struct sContact Repertoire[], int *pNbContacts)
{
    Repertoire[*pNbContacts] = *pNouveau;
    (*pNbContacts)++;
}

/* Recherche d'un contact par son nom
 * Entrées :
 *    - NomRecherche : nom recherché (chaîne de caractères)
 *    - Repertoire : tableau de contacts 
 *    - NbContacts : nombre de contacts
 * Valeur retournée : indice du contact dans le tableau ou -1 si le contact est
 * absent
 */
int Rechercher(char NomRecherche[], struct sContact Repertoire[], 
               int NbContacts)
{
    for( int i=0; i<NbContacts; i++ )
        if( strcmp(Repertoire[i].Nom, NomRecherche) == 0 ) return i;
    return -1;
}

/* Écriture de tous les contacts d'un répertoire dans un fichier au format binaire
 * Entrées :
 *    - Repertoire : tableau de contacts 
 *    - NbContacts : nombre de contacts
 *    - NomFichier : nom du fichier (chaîne de caractères)
 */
void EcrireFichier(struct sContact Repertoire[], int NbContacts, 
                   char NomFichier[])
{
    FILE *file = fopen(NomFichier, "wb");
    fwrite(Repertoire, sizeof(struct sContact), NbContacts, file);
    fclose(file);
}

/* Lecture d'un répertoire dans un fichier au format binaire
 * Version 1 : lecture contact par contact
 * Entrée :
 *    - NomFichier : nom du fichier (chaîne de caractères)
 * Sortie :
 *    - Repertoire : tableau de contacts 
 * Valeur de retour : nombre de contacts lus
 */
int LireFichier1(struct sContact Repertoire[], char NomFichier[])
{
  // À FAIRE
    FILE *file = fopen(NomFichier, "rb");
    
    int NbContacts = 0;
    struct sContact contact; 
    while( fread(&contact, sizeof(struct sContact), 1, file) != 0 )
    {
        AjouterContact(&contact, Repertoire, &NbContacts);
    }
    fclose(file);
    return NbContacts;
}

/* Lecture d'un répertoire dans un fichier au format binaire
 * Version 2 : une seule lecture de tous les contacts après calcul du nombre de 
 * contacts
 * Entrée :
 *    - NomFichier : nom du fichier (chaîne de caractères)
 * Sortie :
 *    - Repertoire : tableau de contacts 
 * Valeur de retour : nombre de contacts lus
 */
int LireFichier2(struct sContact Repertoire[], char NomFichier[])
{
    FILE *file = fopen(NomFichier, "rb");
    int NbContacts = 0, position;
    char ch;

    fseek(file, 0, 2); // on va à la fin du fichier
    position = ftell(file); // on demande la position (à la fin du fichier)
    NbContacts = position/sizeof(struct sContact); // on obtient le nombre de lignes 
    fseek(file, 0, 0); // on retourne au début du fichier

    struct sContact contacts[NbContacts]; // liste qui contient des structures de contacts
    fread(contacts, sizeof(struct sContact), NbContacts, file); // on stocke tout le fichier dans contacts
    for( int i=0; i<NbContacts; )
    {
        AjouterContact(&contacts[i], Repertoire, &i); // on ajoute chaque element de la liste
    }

    fclose(file);
    return NbContacts;
}

/* Fonction de comparaison de deux contacts pour le tri d'un tableau de contact 
 * par ordre lexicographique, croissant des noms
 * Entrées : 
 *    - pc1 : adresse du premier contact
 *    - pc2 : adresse du second contact
 * Valeur de retour : entier supérieur, égal ou inférieur à 0, selon que le nom
 * du premier contact est supérieur, égal ou inférieur au nom du second contact
 */
int CompareContacts(const void *pc1, const void *pc2)
{
    // on fait un transtypage des deux const car on peut pas dereferencer des const (ex: pc1->Nom)
    struct sContact *p1 = ((struct sContact*)pc1), *p2 = ((struct sContact*)pc2); 
    return strcmp(p1->Nom, p2->Nom); // strcmp s'occupe de faire les comparaisons
}


int main(void)
{
  // Répertoire initialisé avec trois contacts 
  struct sContact Rep[LGMAXREP]=
    {{"KARENA","Emma","emma.karena@legria.es",{1,5,2001}},
     {"DEUF","John","john.deuf@mayonnaise.fr",{12,1,1999}},
     {"MANVUSSA","Gerard","gerard.manvussa@etonnant.com",{24,11,2000}}
    };
  int NbContacts=3;
  
  printf("***** Répertoire initial :\n");
  AfficherRepertoire(Rep,NbContacts);
  
  // Contact supplémentaire
  struct sContact Nouv={"AMBOLAGE",
                        "Oscar",
                        "oscar.ambolage@latele.com",
                        {9,6,2002}};
  printf("***** Ajout d'un contact.\n");
  AjouterContact(&Nouv,Rep,&NbContacts);
  printf("***** Répertoire après ajout :\n");
  AfficherRepertoire(Rep,NbContacts);

  char Nom[]="DEUF"; // Nom qui va être recherché
  printf("\n***** Recherche de %s :\n",Nom);
  int Ind=Rechercher(Nom,Rep,NbContacts);
  if (Ind==-1)
    printf("%s n'est pas dans le repertoire.\n",Nom);
  else
    AfficherContact2(&(Rep[Ind]));
    
  char Fichier[]="repertoire.dat"; // Nom du fichier binaire
  printf("\n***** Écriture du répertoire dans le fichier %s.\n",Fichier);
  EcrireFichier(Rep,NbContacts,Fichier);
  
  struct sContact RepLu[LGMAXREP]; // Nouveau répertoire
  int NbContactsLus;
  
  printf("\n***** Lecture du répertoire depuis le fichier %s (v1).\n",Fichier);
  NbContactsLus=LireFichier1(RepLu,"repertoire.dat");
  printf("***** Répertoire lu :\n");
  AfficherRepertoire(RepLu,NbContactsLus);
  
  printf("\n***** Lecture du répertoire depuis le fichier %s (v2).\n",Fichier);
  NbContactsLus=LireFichier2(RepLu,"repertoire.dat");
  printf("***** Répertoire lu :\n");
  AfficherRepertoire(RepLu,NbContactsLus);

  printf("\n***** Tri du répertoire lu.\n");
  printf("***** Répertoire trié :\n");
  qsort(RepLu, NbContactsLus, sizeof(struct sContact), CompareContacts);
  printf("---> Appel à qsort à écrire.\n"); // LIGNE À SUPPRIMER
  AfficherRepertoire(RepLu,NbContactsLus);

  return 0;
}
