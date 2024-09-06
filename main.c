#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating contact type structure/variables.
typedef struct
{
    char nom[20];
    char tele[15];
    char mail[20];
} contact;

//Declaring functions(definition bellow main).
contact ajouter();
contact modifier(contact c[], int n);
void supprimer(contact c[], int n);
int rechercher(contact c[],int n);
void afficher(contact[], int n);

//Main function.
int main()
{
    //Declaring variables
    int choice,nc=0;
    contact c[20];

    //Entring the system
    do
    {
        //Menu
        printf("\n------------- MENU -------------\n");
        printf("-Pour ajouter un contact ............ tapez 1.\n");
        printf("-Pour modifier un contact ........... tapez 2.\n");
        printf("-Pour supprimer un contact ......... .tapez 3.\n");
        printf("-Pour afficher tous les contacts .... tapez 4.\n");
        printf("-Pour rechercher un contact ......... tapez 5.\n");
        printf("-Pour terminer le programme ......... tapez 0.\n");

        //Choice making
        printf("-Donnez votre choix : ");
        scanf("%d",&choice);

        //Choice executing
        switch(choice)
        {
        //Add
        case 1:
            c[nc]=ajouter();
            nc++;
            break;

        //Edit
        case 2:
            modifier(c,nc);
            break;

        //Delete
        case 3:
            supprimer(c,nc);
            break;

        //Display
            case 4:
            afficher(c,nc);
            break;

        //Search
        case 5:
            rechercher(c,nc);
            break;
        }

    }while(choice!=0);

    return 0;
}

//Defining functions:
//1.add new contacts.
contact ajouter()
{
    contact c;
    printf("\n-Entrer le nom de contact :");
    scanf("%s",c.nom);
    printf("-Entrer le numero de contact :");
    scanf("%s",c.tele);
    printf("-Entrer l'email de contact :");
    scanf("%s",c.mail);

    return c;
}

//2.edit already existing contacts.
contact modifier(contact c[], int n){

    int i;
    i=rechercher(c,n);
    printf("\n-Donnez le nouveau num de tele : ");
    scanf("%s",c[i].tele);
    printf("-Donnez le nouveau email : ");
    scanf("%s",c[i].mail);
    printf("\tMis a jours avec succes.");

return c[i];
}

//3.delete a contact from the list.
void supprimer(contact c[], int n){
    int i;
    i=rechercher(c,n);
    if(i==0)
        return;
    for(int j=i; j<n; j++){
        c[i]=c[i+1];
    }
    printf("\n\tLe contact est supprimer avec succes.");
}

//4.search for specific contact (using name).
int rechercher (contact c[], int n)
{
    char name[20];
    printf("\n-Entrer le nom du contact :");
    scanf("%s", name);

    for(int i=0; i<n; i++)
    {
        if(strcmp(c[i].nom,name)==0)
        {
            printf("-Contact est trouvez : \n");
            printf("Nom : %s | Numero : %s | l'Email : %s \n",c[i].nom, c[i].tele, c[i].mail);
            return i;
        }
    }
    printf("\n-Contact n'existe pas.");
    return 0;
}


//5.show all contacts list.
void afficher(contact c[],int n)
{
    printf("\tLA LISTE DES CONTACTS");
    for(int i=0; i<n; i++)
    {
        printf("----CONTACT N'%d-----\n",i+1);
        printf("-Nom : %s\n",c[i].nom);
        printf("-tele : %s\n",c[i].tele);
        printf("-mail : %s\n",c[i].mail);
    }
}
//End :D <3
