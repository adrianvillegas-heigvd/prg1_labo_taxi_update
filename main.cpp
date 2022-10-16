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

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {
   const int    LARGEUR_LIGNE           =   25,
      PRECISION_AFFICHAGE     =    2; // new

   const double TAXE_DE_BASE            = 5.00,
      SURTAXE_PAR_BAGAGE      = 2.60,
      TARIF_PAR_MINUTE_JOUR   = 1.00, // modif
   TARIF_PAR_MINUTE_NUIT   = 1.60;

   const int DEBUT_TARIF_JOUR        =    8, // new
             FIN_TARIF_JOUR          =   20,
      LIMITE_INF_BAGAGES      =    0,
      LIMITE_SUP_BAGAGES      =    4,
      LIMITE_INF_DISTANCE     =    0,
      LIMITE_SUP_DISTANCE     =  500,
      LIMITE_INF_VITESSE      =   30,
      LIMITE_SUP_VITESSE      =  120,
      LIMITE_INF_HH           =   30,
      LIMITE_SUP_HH           =  120,
      LIMITE_INF_MM           =   30,
      LIMITE_SUP_MM           =  120;

   int          nombreBagage, // delete start to 0
   hhDepart,
      mmDepart,
      mmCourseJour = 0,
      mmCourseNuit = 0;
   char         symbolDepart;
   double       distanceParcourue,
      vitesseMoyanne;

   double       prixBagage,
      dureeCourse,
      prixCourseJour,
      prixCourseNuit,
      prixTotal;

   // On fixe 2 chiffres significatifs après la virgule
   cout << fixed << setprecision(PRECISION_AFFICHAGE) << endl;

   // Start program ....TODO
   cout << "Bonjour, ce programe calcule le prix d’une course en € en taxi." << endl
        << "Voici les conditions" << endl
        << "====================" << endl
        << left << setw(LARGEUR_LIGNE) << " - prise en charge" << " : " << TAXE_DE_BASE << endl
        << left << setw(LARGEUR_LIGNE) << " - supp par bagage" << " : " << SURTAXE_PAR_BAGAGE << endl
        << left << setw(LARGEUR_LIGNE) << " - tarif/min (jour)" << " : " << TARIF_PAR_MINUTE_JOUR << endl
        << left << setw(LARGEUR_LIGNE) << " - tarif/min (nuit)" << " : " << TARIF_PAR_MINUTE_NUIT << endl
        << left << setw(LARGEUR_LIGNE) << " - tarif jour" << " : " << DEBUT_TARIF_JOUR << "h00-" << FIN_TARIF_JOUR << "h00" << endl
        << endl;


   // Modif ordre saisie et afifchage
   cout << "Votre commande" << endl
        << "==============" << endl;

   cout << left << setw(LARGEUR_LIGNE) << " - nbre de babage " << "[" << LIMITE_INF_BAGAGES << " - " << LIMITE_SUP_BAGAGES << "] : ";
   cin >> nombreBagage;
   VIDER_BUFFER;
   if (nombreBagage < LIMITE_INF_BAGAGES || nombreBagage > LIMITE_SUP_BAGAGES) {
      cout << "Nombre de bagages incorrecte" << endl; // TODO rappel de limites
      return EXIT_FAILURE;
   }

   cout << left << setw(LARGEUR_LIGNE) << " - distance [km] " << "[" << LIMITE_INF_DISTANCE << " - " << LIMITE_SUP_DISTANCE << "] : ";
   cin >> distanceParcourue;
   VIDER_BUFFER;
   if (distanceParcourue < LIMITE_INF_DISTANCE || distanceParcourue > LIMITE_SUP_DISTANCE) {
      cout << "Distance incorrecte" << endl; // TODO rappel de limites
      return EXIT_FAILURE;
   }

   cout << left << setw(LARGEUR_LIGNE) << " - vitesse [km/h] " << "[" << LIMITE_INF_VITESSE << " - " << LIMITE_SUP_VITESSE << "] : ";
   cin >> vitesseMoyanne;
   VIDER_BUFFER;
   if (vitesseMoyanne < LIMITE_INF_VITESSE || vitesseMoyanne > LIMITE_SUP_VITESSE) {
      cout << "Vitesse incorrecte" << endl; // TODO rappel de limites
      return EXIT_FAILURE;
   }

   // TODO change to time interval and add ifs
   cout << left << setw(LARGEUR_LIGNE) << " - depart " << "[hh:mm] : ";
   cin >> hhDepart;
   cin >> symbolDepart;
   cin >> mmDepart;
   VIDER_BUFFER;
   if (hhDepart < LIMITE_INF_HH && hhDepart > LIMITE_SUP_HH && symbolDepart == ':' && mmDepart < LIMITE_INF_MM && mmDepart > LIMITE_SUP_MM) { //
      cout << "Temp de depart incorrecte" << endl; // TODO rappel de limites
      return EXIT_FAILURE;
   }


   // Calcul du ticket
   prixBagage = SURTAXE_PAR_BAGAGE * nombreBagage;
   dureeCourse = distanceParcourue / vitesseMoyanne  * 60 + mmDepart; // TODO: MATH.CEIL - ARRONDIR NOMBRE DE MINUTES
   cout << dureeCourse << endl;

   bool tarifJour = hhDepart >= DEBUT_TARIF_JOUR && hhDepart < FIN_TARIF_JOUR;
   int heureTarif = hhDepart;

   for (int i=mmDepart; i < dureeCourse; ++i) {
      if (!(i%60)) {
         ++heureTarif;
         tarifJour = heureTarif >= DEBUT_TARIF_JOUR && heureTarif < FIN_TARIF_JOUR ? true : false;
      }

      if (tarifJour)
         ++mmCourseJour;
      else
         ++mmCourseNuit;
   }
   prixCourseJour = TARIF_PAR_MINUTE_JOUR * mmCourseJour;
   prixCourseNuit = TARIF_PAR_MINUTE_NUIT * mmCourseNuit;
   prixTotal = TAXE_DE_BASE + prixBagage + prixCourseJour + prixCourseNuit;


   // Affichage du ticket
   cout << "votre ticket" << endl
        << "============" << endl
        << left << setw(LARGEUR_LIGNE) << " - prise en charge"      << " : " << TAXE_DE_BASE      << endl
        << left << setw(LARGEUR_LIGNE) << " - supp bagages"         << " : " << prixBagage      << endl
        << left << setw(LARGEUR_LIGNE) << " - temps de course"                                    << endl
        << left << setw(LARGEUR_LIGNE) << mmCourseJour << " @ " << TARIF_PAR_MINUTE_JOUR << " : " << prixCourseJour << endl
        << left << setw(LARGEUR_LIGNE) << mmCourseNuit << " @ " << TARIF_PAR_MINUTE_NUIT << " : " << prixCourseNuit << endl
        << "------------------- ----------" << endl
        << left << setw(LARGEUR_LIGNE) << " TOTAL"                  << " : " << prixTotal         << endl;


   cout << "Presser ENTREE pour quitter" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
