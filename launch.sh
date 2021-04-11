#!/bin/bash
loc=`find -name file.start | cut -d/ -f1-4 ` # Localisation de file.start
file=`find -name file.start -print` # Sauvegarde du chemin complet vers le fichier
nom=`cat $file | head -n1` # Lecture de la 1ère ligne (Nom du programme)
#nbligne=`cat $file | wc -l` # test
#nbligne=`expr $nbligne - 1` # test
cd $loc; gcc $nom.c ;mv a.out $nom.prog; ./$nom.prog # Compilation et exécution du programme
# A ajouter :
#   - arguments pris en compte sur les lignes qui suivent