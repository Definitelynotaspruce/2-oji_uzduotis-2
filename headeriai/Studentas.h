#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Zmogus.h"

class Studentas : public Zmogus
{
private:
    std::vector<int> pazymiai = {};
    int egzaminas = 0;
    double galutinis = 0;    

public:

    //! Default konstruktorius, inicializuojantis egzaminą 0
    Studentas() : egzaminas(0) {  }  
    //! Konstruktorius, kuris inicializuoja studentą iš visos nuskaitytos eilutės
    Studentas( const std::string &ei );
    //! Konstruktorius, kuris inicializuoja studento vardą bei pavardę
    Studentas(const std::string &vardas, const std::string &pavarde) : Zmogus(vardas, pavarde) { }

    //! Konstruktorius, kuris inicializuoja studentą su visais paduotais parametrais
    Studentas(const std::string &vardas, const std::string &pavarde, const std::vector<int> &nd, const int &egzas) : 
    Zmogus(vardas, pavarde), pazymiai(nd), egzaminas(egzas) {  galutinis = galutinisBalas();  }
    
    //! Konstruktorius, kuris inicializuoja studento vardą, pavardę ir galutinį balą
    Studentas(const std::string &vardas, const std::string &pavarde, const double &galutinis ) : 
    Zmogus(vardas, pavarde), galutinis(galutinis) { }
    
    //! Destruktorius
    ~Studentas() = default;

    //! Copy konstruktorius
    Studentas(const Studentas &);

    //! Operatorius '=', kuris prilygina vieno studento reiksmse kitam
    Studentas& operator=(const Studentas&);
    //! Operatorius '+', kuris sudeda vienodų studentų pažymius
    Studentas operator+(const Studentas&) const;
    
    //! Operatorius '==', kuris tikrina, ar du studentai yra vienodi (bei ar jų pažymiai vienodi)
    bool operator==(const Studentas& studentas) const;
    //! Operatorius '>', kuris tikrina, ar pirmo studento galutinis balas yra didesnis už antrojo
    inline bool operator>(const Studentas& studentas) const {return galutinis > studentas.galutinis; }
    //! Operatorius '<', kuris tikrina, ar antro studento galutinis balas yra mažesnis už pirmojo
    inline bool operator<(const Studentas& studentas) const {return galutinis < studentas.galutinis; }
    //! Operatorius '>=', kuris tikrina, ar pirmo studento galutinis balas yra didesnis ar lygus antrojo galutiniam
    inline bool operator>=(const Studentas& studentas) const {return galutinis >= studentas.galutinis; }
    //! Operatorius '<=', kuris tikrina, ar antrojo studento galutinis balas yra didesnis ar lygus pirmojo galutiniam
    inline bool operator<=(const Studentas& studentas) const {return galutinis <= studentas.galutinis; }
    
    //! Vardo bei pvardės seteris, imantis du 'string' tipo elementus
    void setVardasPavarde(const std::string &vardas, const std::string &pavarde);
    //! Vardo bei pvardės seteris, imantis viena 'string' tipo elementą
    void setVardasPavarde(const std::string &a );   
    //! Pazymiu seteris, imantis pazymiu vektorių bei galutinį egzamino balą
    void setPazymiai(std::vector<int> &, int &); 
    //! Pazymiu seteris, imantis pazymiu vektorių
    void setPazymiai(std::vector<int> &);
    
   
    //! Double funkcija, apskaiciuojanti galutini studento balą
    double galutinisBalas();

    //! Studento vidurkį grazinanti funkcija
    inline double getVidurkis() { return calculateVidurkis(); };
    //! Studento medianą grazinanti funkcija
    inline double getMediana()  {return calculateMediana(); };
    //! Studento egzamino balą grazinanti funkcija
    inline int getEgzaminas() const {return egzaminas;};
    //! Studento galutinį balą grazinanti funkcija
    inline double getGalutinis() { return galutinisBalas();};
    //! Studento pazymiu vektorių grazinanti funkcija
    inline const std::vector<int>& getPazymiai() const {return pazymiai;};

    //! Studento medianą apskaiciuojanti funkcija
    double calculateMediana();
    //! Studento vidurki apskaiciuojanti funkcija
    double calculateVidurkis();
};