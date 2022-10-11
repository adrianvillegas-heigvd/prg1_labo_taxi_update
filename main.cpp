//---------------------------------------------------------
// Demo           : course_en_taxi
// Fichier        : course_en_taxi.cpp
// Auteur(s)      : Hasan Ilingi & Alex Franchi
// Date           : 03.10.2022
// But            : Un programme qui calcule le prix d’une course de taxi en €
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

//Hello
int main() {
   const int      HEURE_EN_MINUTES     = 60,
      LARGEUR_LIGNE        = 25;

   const double   TAXE_DE_BASE         = 5.00,
      SURTAXE_PAR_BAGAGE   = 2.50,
      TARIF_PAR_MINUTE     = 1.20;

   int            nombreDeBagage       = 0,
      distanceParcourue    = 0,
      vitesseMoyanne       = 0;


   double         dureeDeCourse,
      prixDeBagage,
      prixDeLaCourse,
      prixTotal;

   cout           << "Bonjour, ce programe calcule le prix d’une course en € en taxi." << endl
                  << endl
                  << "Voici les conditions" << endl
                  << "====================" << endl
                  << left << setw(LARGEUR_LIGNE) << " - prise en charge"      << " : " << TAXE_DE_BASE         << endl
                  << left << setw(LARGEUR_LIGNE) << " - supp par bagag"       << " : " << SURTAXE_PAR_BAGAGE   << endl
                  << left << setw(LARGEUR_LIGNE) << " - tarif/Minute"         << " : " << TARIF_PAR_MINUTE     << endl;

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
