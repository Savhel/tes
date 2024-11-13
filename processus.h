//
// // // // //

#ifndef PROCESSUS_H
#define PROCESSUS_H

struct Processus{
    int id;      // Identifiant du processus
    int temps_execution;    // Temps d'exécution
    int temps_attente;      // Temps d'attente
    int temps_fin;          // Temps de fin
    int temps_arriver;    // Temps d'arrivée
    int heures_debut;
    int temps_sejour;
    int temps_restant;
    int priorite;
};


#endif //PROCESSUS_H
