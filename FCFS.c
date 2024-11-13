#include <stdio.h>
#include "processus.h"
#include "FCFS.h"


// Fonction pour calculer les temps moyens de séjour et d'attente
void TempMoyen(struct Processus proc[], int n) {
    int temp_attente[n], temp_sejour[n];
    int completion_time[n];

    /* En déclarant int completion_time[n];, on crée un tableau capable de stocker les temps
       de fin pour n processus. */

    // Calcul des temps de fin pour chaque processus
    completion_time[0] = proc[0].temps_arriver + proc[0].temps_execution; // temps de fin du premier processus

    for (int i = 1; i < n; i++) {//i=0 car on considere que le premier processus est deja traiter

        /*Vérifier si le temps d'arrivée du processus actuel (proc[i].temps_arriver) est supérieur au
   temps de fin du processus précédent (completion_time[i - 1]).Si c'est le cas, cela signifie que le
    processus doit attendre jusqu'à son propre temps d'arrivée.
    On calcule alors son temps de fin comme la somme de son temps d'arrivée et de son temps d'exécution
    et else Si le processus arrive pendant ou après l'exécution du processus précédent,
    on calcule son temps de fin en ajoutant son temps d'exécution au temps de fin du processus précédent..*/


        if (proc[i].temps_arriver > completion_time[i - 1]) {
            completion_time[i] = proc[i].temps_arriver + proc[i].temps_execution;
        } else {
            completion_time[i] = completion_time[i - 1] + proc[i].temps_execution; // Pour le processus suivant
        }
    }

    // Calcul du temps de séjour et du temps d'attente
    for (int i = 0; i < n; i++) {
        temp_sejour[i] = completion_time[i] - proc[i].temps_arriver; // Temps de séjour = Temps de fin - Temps d'arrivée
        temp_attente[i] = temp_sejour[i] - proc[i].temps_execution; // Temps d'attente = Temps de séjour - Temps d'exécution
    }

    // Affichage des détails des processus et de leurs temps
    printf("ID\tTemps_arriver\tTemps_execution\tTemps_attente\tTemps_sejour\tTemps_fin\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",
               proc[i].id,
               proc[i].temps_arriver,
               proc[i].temps_execution,
               temp_attente[i],
               temp_sejour[i],
               completion_time[i]);
    }

    /////////////////////////////////////////////////// Afficher le diagramme de Gantt
    printf("\nDiagramme de Gantt:\n"); // Affiche le titre du diagramme de Gantt
    printf("  "); // Ajoute un espacement pour aligner le diagramme avec les identifiants des processus

    // Boucle pour afficher les identifiants des processus dans le diagramme
    for (int i = 0; i < n; i++) {
        printf("| P%d ", proc[i].id); // Affiche chaque identifiant de processus précédé d'un trait vertical (|)
    }
    printf("|\n"); // Ferme le diagramme avec un dernier trait vertical

    printf("  "); // Ajoute un espacement pour aligner les temps avec le diagramme
    printf("0"); // Affiche le temps 0, qui représente le début de l'exécution

    // Boucle pour afficher les temps de fin de chaque processus dans le diagramme
    for (int i = 0; i < n; i++) {
        printf("\t%d", completion_time[i]); // Affiche le temps de fin de chaque processus, séparé par des tabulations
    }
    printf("\n"); // Ajoute une nouvelle ligne après l'affichage des temps



    ////////////////////////////////////////// // Calcul et affichage des temps moyens d'attente et de séjour
    float temp_attente_moyen = 0, temp_de_sejour_moyen = 0;
    for (int i = 0; i < n; i++) {
        temp_attente_moyen += temp_attente[i]; // Somme des temps d'attente
        temp_de_sejour_moyen += temp_sejour[i]; // Somme des temps de séjour
    }
    printf("\nTemps d'attente moyen: %.2f\n", temp_attente_moyen / n); // Affichage du temps d'attente moyen
    printf("Temps de séjour moyen: %.2f\n", temp_de_sejour_moyen / n); // Affichage du temps de séjour moyen
}







