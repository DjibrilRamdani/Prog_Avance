#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

// Mutex pour s'assurer que l'accès à la ressource (repas) est exclusif.
mutex mtx;

// Sémaphores pour gérer l'état du stock de repas.
sem_t stockRemplie, stockVide;

// Variable qui indique combien de repas sont disponibles.
unsigned repasDisponnible = 0; 

void cuisinier(){
    while (true){
        // Attente que le stock soit vide.
        sem_wait(&stockVide);
        
        // Remplissage du stock avec 10 repas.
        repasDisponnible = 10;
        cout << "Les repas sont dans le stock" << endl;
        
        // Signal que le stock est rempli.
        sem_post(&stockRemplie);

        // Délai pour simuler le temps de cuisson.
        usleep(1000000);
    }
}

void etudiant(unsigned i){
    while (true){
        // Verrouillage de la ressource (repas).
        mtx.lock();
        
        // Si le stock est vide.
        if (repasDisponnible == 0){
            cout << "Attendre pour le repas " << endl;
            
            // Signal au cuisinier que le stock est vide.
            sem_post(&stockVide);
            
            // Attendre que le stock soit rempli.
            sem_wait(&stockRemplie);
        }
        
        // Prendre un repas.
        --repasDisponnible;

        // Déverrouillage de la ressource.
        mtx.unlock();

        // Information sur le repas servi à l'étudiant.
        cout << "Repas servie à l'étudiant " << i << endl;
        
        // Délai pour simuler le temps de prise du repas.
        usleep(1000000);
    }
}

int main()
{
    unsigned etudiants = 20;
    vector<thread> etudiants_threads;
    
    // Lancement du thread du cuisinier.
    thread cuisinierThread(cuisinier);
    
    // Lancement des threads des étudiants.
    for (unsigned i = 0; i < etudiants; ++i) {
        etudiants_threads.push_back(thread(etudiant, i));
    }
    
    // Attente de la fin du thread du cuisinier (qui ne se terminera jamais dans ce cas).
    cuisinierThread.join();

    // Attente de la fin des threads des étudiants (qui ne se termineront jamais non plus).
    for (thread &thread : etudiants_threads) {
        thread.join();
    }
    
    return 0;
}
