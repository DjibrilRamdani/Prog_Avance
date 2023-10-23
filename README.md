# Simulation de Restauration Universitaire

Ce code simule un scénario de restauration dans le restaurant universitaire de l'IUT d'Aix-en-Provence où un cuisinier prépare des repas et des étudiants viennent les consommer durant la pause midi.
## Composants principaux :

    Cuisinier : Il s'occupe de préparer des repas. Lorsque le stock de repas est vide, il le remplit à nouveau.

    Etudiants : Ils viennent manger dans le restaurant. Si le stock est vide, ils attendent que le cuisinier reviennent en ayant préparer de nouveaux repas.

## Détails Techniques :

    - Mutex (mtx) : On l'a utilisé afin d'assurer qu'un seul étudiantpuisse prendre un repas à la fois.

    - Sémaphores (stockRemplie, stockVide) : On l'a utilisé pour signaler au cuisinier lorsqu'il doit cuisiner plus de repas et quand les repas sont prêts à être servis.

## Comment ça fonctionne :

    - Le cuisinier attend que le stock soit vide. Une fois vide, il prépare 10 repas.

    - Les étudiants essaient de prendre un repas. Si le stock est vide, ils le signalent au cuisinier et attendent que les repas soient prêts.

    - Une fois que les repas sont prêts, les étudiants prennent les repas.

## Pour exécuter le code :

    Compilez le code avec un compilateur C++ qui supporte C++11 ou supérieur.
    Exécutez le programme.

Vous verrez alors des logs indiquant le processus de cuisson des repas et leur service aux étudiants.



## Membres

- CANALE Enzo <img align="left" src="https://avatars.githubusercontent.com/u/92590811" alt="profile" width="20" height="20"/>
- KADDOURI Mohammed <img align="left" src="https://avatars.githubusercontent.com/u/98416541" alt="profile" width="20" height="20"/>
- RAMDANI Djibril <img align="left" src="https://avatars.githubusercontent.com/u/92161799" alt="profile" width="20" height="20"/>
