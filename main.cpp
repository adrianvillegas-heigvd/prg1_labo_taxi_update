//---------------------------------------------------------
// Demo           : labo_03_xxx
// Fichier        : labo_03_taxi_update.cpp
// Auteur(s)      : (Hasan Ilingi & Alex Franchi) Pollien Lionel, Villegas Castrillon Adrian
// Date           : 11.10.2022
// But            : Un programme qui calcule le prix d’une course de taxi en €
// Modifications  :
// Remarque(s)    : Modifications des constantes pour les tarifs ... TODO
//---------------------------------------------------------

#include <cstdlib>   // -
#include <iostream>  // -
#include <iomanip>   // -
#include <limits>    // -

using namespace std;

int main() {
   const int    LARGEUR_LIGNE           =   25,
                PRECISION_AFFICHAGE     =    2; // new

   const double TAXE_DE_BASE            = 5.00,
                SURTAXE_PAR_BAGAGE      = 2.50,
                TARIF_PAR_MINUTE_JOUR   = 1.20, // modif
                TARIF_PAR_MINUTE_NUIT   = 1.60;

   const int    DEBUT_TARIF_JOUR        =    8, // new
                FIN_TARIF_JOUR          =   20,
                LIMITE_INF_BAGAGES      =    0,
                LIMITE_SUP_BAGAGES      =    4,
                LIMITE_INF_DISTANCE     =    0,
                LIMITE_SUP_DISTANCE     =  500,
                LIMITE_INF_VITESSE      =   30,
                LIMITE_SUP_VITESSE      =  120;

   int          nombreBagage; // delete start to 0
   double       distanceParcourue,
                vitesseMoyanne;

   double       prixBagage,
                dureeCourse,
                prixCourseJour,
                prixCourseNuit,
                prixTotal;

   // Start program ....TODO
   cout << "Bonjour, ce programe calcule le prix d’une course en € en taxi." << endl
        << "Voici les conditions" << endl
        << "====================" << endl
        << left << setw(LARGEUR_LIGNE) << " - prise en charge" << " : " << TAXE_DE_BASE         << endl
        << left << setw(LARGEUR_LIGNE) << " - supp par bagage" << " : " << SURTAXE_PAR_BAGAGE   << endl
        << left << setw(LARGEUR_LIGNE) << " - tarif/min (jour)" << " : " << TARIF_PAR_MINUTE_JOUR     << endl;

   cout           << "Saisir le nombre de bagage(s):";
   cin            >> nombreDeBagage;
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer

   cout           << "Saisir la distance a parcourir [km]:";
   cin            >> distanceParcourue;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   cout           << "Saisir la vitesse moyenne du parcours [km/h]:";
   cin            >> vitesseMoyanne;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   prixDeBagage   = (double) nombreDeBagage * SURTAXE_PAR_BAGAGE;
   dureeDeCourse  = (double) distanceParcourue / (double) vitesseMoyanne;
   prixDeLaCourse = dureeDeCourse * (double) HEURE_EN_MINUTES * TARIF_PAR_MINUTE;
   prixTotal      = prixDeBagage + TAXE_DE_BASE + prixDeLaCourse;

   cout           << fixed << setprecision(2) << endl  // On fixe 2 chiffres significatifs après la virgule
                  << "votre commande" << endl
                  << "==============" << endl
                  << left << setw(LARGEUR_LIGNE) << " - nbrede bagage"        << " : " << nombreDeBagage    << endl
                  << left << setw(LARGEUR_LIGNE) << " - distance [km]"        << " : " << distanceParcourue << endl
                  << left << setw(LARGEUR_LIGNE) << " - vitesse [km/h]"       << " : " << vitesseMoyanne    << endl
                  << endl
                  << "votre ticket" << endl
                  << "============" << endl
                  << left << setw(LARGEUR_LIGNE) << " - prise en charge"      << " : " << TAXE_DE_BASE      << endl
                  << left << setw(LARGEUR_LIGNE) << " - supp bagages"         << " : " << prixDeBagage      << endl
                  << left << setw(LARGEUR_LIGNE) << " - prix de la course"    << " : " << prixDeLaCourse    << endl
                  << left << setw(LARGEUR_LIGNE) << " TOTAL"                  << " : " << prixTotal         << endl;

   cout << "Presser ENTREE pour quitter" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
