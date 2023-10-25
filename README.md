# Simulation de Restauration Universitaire

Ce projet est une simulation d'un scénario de restauration. 
Nous avons prit comme expemple le restaurant universitaire de l'IUT d'Aix-en-Provence où un cuisinier prépare des repas et des étudiants viennent les consommer durant la pause midi comme a notre habitude.
## Acteurs principaux :

    Le cuisinier : Il s'occupe de préparer des repas et lorsque le stock de repas est vide, il le remplit à nouveau.

    Les étudiants (nous) : Ils viennent manger dans le restaurant. Si le stock est vide, ils attendent que le cuisinier reviennent en ayant préparer de nouveaux repas.

## Un peu d'explications de code :

    - Mutex : Il on été utilisé afin d'assurer qu'un seul étudiant puisse prendre un repas à la fois.

    - Sémaphores : On a utilisés stockRemplie et stockVide afin de définir l'état du stock.

## Comment cela fonctionne :

    - Les étudiants prennent un repas. Si aucun repas est disponnible le cuisinier remplie le stock.

    - Le cuisinier attend que le stock soit vide. Une fois vide, il prépare 10 repas.

    - Les étudiants continue de se servir.

  

## Pour exécuter le code :

    Compilez le code avec un compilateur C++ qui supporte C++11 ou supérieur.
    Exécutez le programme.

Vous verrez alors des logs indiquant le processus de cuisson des repas et leur service aux étudiants.



## Membres

- CANALE Enzo <img align="left" src="https://avatars.githubusercontent.com/u/92590811" alt="profile" width="20" height="20"/>
- KADDOURI Mohammed <img align="left" src="https://avatars.githubusercontent.com/u/98416541" alt="profile" width="20" height="20"/>
- RAMDANI Djibril <img align="left" src="https://avatars.githubusercontent.com/u/92161799" alt="profile" width="20" height="20"/>
