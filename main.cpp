#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

mutex mtx;


sem_t stockRemplie, stockVide; //signal
unsigned repasDisponnible = 0;

void cuisinier(){
    while (true){
        sem_wait(&stockVide);
        repasDisponnible = 10;
        cout << "Les repas sont dans le stock" << endl;
        sem_post(&stockRemplie);// signal plein

        usleep(1000000);
    }
}

void etudiant(unsigned i){
    while (true){
        mtx.lock();// lock le service
        if (repasDisponnible == 0){
            cout << "Attendre pour le repas " << endl;
            sem_post(&stockVide);//
            sem_wait(&stockRemplie);//
        }
        --repasDisponnible;

        mtx.unlock();

        cout << "Repas servie à l'étudiant " << i << endl;
        usleep(1000000);
    }
}

int main()
{
    unsigned etudiants = 20;
    vector<thread> etudiants_threads;
    thread cuisinierThread(cuisinier);
    for (unsigned i = 0; i < etudiants; ++i) {
        etudiants_threads.push_back(thread(etudiant, i));
    }
    cuisinierThread.join();

    for (thread &thread : etudiants_threads) {
        thread.join();
    }
    return 0;
}
