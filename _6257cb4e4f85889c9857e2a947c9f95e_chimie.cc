#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Flacon (string n, double v, double a)
	{
		nom = n;
		volume = v;
		pH = a;
	}

	string getNom() const { return nom; }
	
	double getVolume() const { return volume; }
	
	double getPh() const { return pH; }
		
	ostream& etiquette(ostream& sortie) const{
		sortie << getNom() << " : " << getVolume() << " ml, pH " << getPh();
	
		return sortie;	
	}
	
	const Flacon operator+(Flacon flacon) const{
		Flacon nouveauFlacon(getNom() + " + " + flacon.getNom(), 
			getVolume() + flacon.getVolume(), getPh() + flacon.getPh());
		
		return nouveauFlacon;
	}
};
ostream& operator<<(ostream& sortie, Flacon flacon) {	
	return flacon.etiquette(cout);
}

//~ const Flacon operator+(Flacon flacon1, Flacon const& flacon2){
	//~ Flacon nouveauFlacon(flacon1.getNom() + " + " + flacon2.getNom(), 
		//~ flacon1.getVolume() + flacon2.getVolume(), flacon1.getPh() + flacon2.getPh());
	
	//~ return nouveauFlacon;
//~ }

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
