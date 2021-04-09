#!/bin/bash
loc=`find -name file.start | cut -d/ -f1-4 `
file=`find -name file.start -print`
nom=`cat $file | head -n1`
nbligne=`cat $file | wc -l`
nbligne=`expr $nbligne - 1`
cd $loc; gcc $nom.c ;mv a.out $nom.prog; ./$nom.prog