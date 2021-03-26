#include <stdio.h>
#include <stdlib.h>

#define max max
#define cdemi rationnel deux = {1,2}
#define demi deux

typedef struct rationnel
{
    int num ;
    int den ;
}rationnel;

rationnel simplifier(rationnel r){
    int diviseur = pgcd(r);
    r.num = r.num / diviseur;
    r.den = r.den / diviseur;
    return r;
}

rationnel creer(int num, int den){
    rationnel r;
    r.num = num;
    r.den = den;
    r = simplifier(r);
    return r;
}

rationnel saisir(){
    int num, den;
    rationnel saisie;
    printf("Saisir le rationel (Format : numérateur/dénominateur) : ");
    scanf("%d/%d", &num, &den);
    saisie = creer(num,den);
    return saisie;
}

void afficher(rationnel r){
    printf("J'ai trouvé ce résultat : %d/%d\n", r.num, r.den);
}

int pgcd(rationnel r){
    int a, b, reste;
    a = r.num;
    b = r.den;
    do{
        reste = a % b;
            if(reste == 0)
                break;
        a = b;
        b = reste;
    }while(reste!=0);
    return b;
}



rationnel produit(rationnel r1, rationnel r2){
    r1.num = r1.num * r2.num;
    r1.den = r1.den * r2.den;
    r1 = simplifier(r1);
    return r1;
}

rationnel somme(rationnel r1, rationnel r2){
    r1.num = r1.num * r2.den;
    r2.num = r2.num * r1.den;
    r1.den = r1.den * r2.den;
    r1.num = r1.num + r2.num;
    r1 = simplifier(r1);
    return r1;
}

rationnel difference(rationnel r1, rationnel r2){
    r1.num = r1.num * r2.den;
    r2.num = r2.num * r1.den;
    r1.den = r1.den * r2.den;
    r1.num = r1.num - r2.num;
    r1 = simplifier(r1);
    return r1;
}

rationnel quotient(rationnel r1, rationnel r2){
    int num, den;
    num = r2.den;
    den = r2.num;
    r2.den = den;
    r2.num = num;
    return produit(r1,r2);
}

rationnel moyenne(rationnel t[], int nbRationnels){
    rationnel retour, nb;
    nb.num = nbRationnels;
    nb.den = 1;
    int i;
    for(i = 0; i < nbRationnels; i++){
        retour = somme(retour, t[i]);
    }
    retour = quotient(retour, nb);
    return retour;
}

int comparer(rationnel r1, rationnel r2){
    if((r1.num == r2.num) && (r1.den == r2.den))
        return 0;
    r1.num = r1.num * r2.den;
    r2.num = r2.num * r1.den;
    if(r1.num > r2.num)
        return 1;
    else 
        return -1;
    
}

rationnel max(rationnel t[], int nbRationnels){
    int i;
    rationnel max;
    max = t[0];
    for(i = 1; i < nbRationnels; i++){
        if(comparer(t[i], max) > 0)
            max = t[i];
    }
    return max;
}

rationnel rabs(rationnel r){
    if(r.num < 0)
        r.num *= -1;
    return r;

}

rationnel rsqrt(rationnel x, rationnel precision){
    rationnel u, uk;
    cdemi;
    uk = produit(x, demi); 
    do{
        u = uk;
        uk = produit(demi,(somme(u,(quotient(x,u)))));
    }while( (comparer(difference(rabs(u), rabs(uk)), precision) >= 0 ));
    return uk;
}

rationnel std(rationnel t[], int nbRationnels, rationnel precision){
    rationnel retour = {0,0}, calcul, moy, n = {nbRationnels,1};
    int i;
    moy = moyenne(t, nbRationnels);
    for(i = 0; i < nbRationnels; i++){
        calcul = difference(t[i], moy);
        calcul = produit(retour, retour);
        retour = somme(retour, calcul);
    }
    retour = quotient(retour, n);
    retour = rsqrt(retour, precision);
    return retour;
}

void main(){
    int num1, den1, num2, den2, choix;
    rationnel r1;
    rationnel r2;
    num1 = 16;
    den1 = 28;
    num2 = 25;
    den2 = 68;
   /* r1 = creer(num1, den1);
    r2 = creer(num2, den2);
    afficher(r1);
    afficher(r2);
    r1 = quotient(r1,r2);
   */ //afficher(r1);
    printf("Faites votre choix : \n-1 : Simplier un rationel\n-2 : Additionner deux rationels\n-3 : Soustraire deux rationels\n-4 : Multiplier deux rationels\n-5 : Diviser deux rationels\n-6 : Comparer deux rationels\n-7 : Page suivante\n-0 : Quitter\nChoix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 0 :    printf("Aurevoir !\n");
                exit(0);
                break;
    case 1 :    r1 = saisir();
                afficher(r1);
                break;
    case 2 :    r1 = saisir();
                r2 = saisir();
                r1 = somme(r1, r2);
                afficher(r1);
                break;
    case 3 :    r1 = saisir();
                r2 = saisir();
                r1 = difference(r1, r2);
                afficher(r1);
                break;
    case 4 :    r1 = saisir();
                r2 = saisir();
                r1 = produit(r1, r2);
                afficher(r1);
                break;
    case 5 :    r1 = saisir();
                r2 = saisir();
                r1 = quotient(r1, r2);
                afficher(r1);
                break;
    case 6 :    
                
            

    
    }
    //printf("%d\n", pgcd(r));
}