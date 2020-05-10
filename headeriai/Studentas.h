#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "zmogus.h"

class Studentas : public Zmogus
{
private:
    std::vector<int> pazymiai = {};
    int egzaminas = 0;
    double vidurkis = 0, mediana = 0;
    double galutinis = 0;    

public:

    Studentas() : egzaminas(0) {  }  
    Studentas( const std::string &ei );
    Studentas(const std::string &vardas, const std::string &pavarde) : Zmogus(vardas, pavarde) { }

    Studentas(const std::string &vardas, const std::string &pavarde, const std::vector<int> &nd, const int &egzas) : 
    Zmogus(vardas, pavarde), pazymiai(nd), egzaminas(egzas) { setVidurkis(); setMediana(); galutinisBalas();  }
    
    Studentas(const std::string &vardas, const std::string &pavarde, const double &galutinis ) : 
    Zmogus(vardas, pavarde), galutinis(galutinis) { }
    
    ~Studentas() = default;

    Studentas(const Studentas &);

    Studentas& operator=(const Studentas&);
    Studentas operator+(const Studentas&) const;
    Studentas operator-(const Studentas&) const; 
    
    bool operator==(const Studentas& studentas) const;
    inline bool operator>(const Studentas& studentas) const {return galutinis > studentas.galutinis; }
    inline bool operator<(const Studentas& studentas) const {return galutinis < studentas.galutinis; }
    inline bool operator>=(const Studentas& studentas) const {return galutinis >= studentas.galutinis; }
    inline bool operator<=(const Studentas& studentas) const {return galutinis <= studentas.galutinis; }
    
    void setVardasPavarde(const std::string &vardas, const std::string &pavarde);
    void setVardasPavarde(const std::string &a );    
    void setPazymiai(std::vector<int> &, int &);  
    void setPazymiai(std::vector<int> &);
   
    double galutinisBalas();

    inline double getVidurkis() const { return vidurkis; };
    inline double getMediana() const {return mediana; };
    inline int getEgzaminas() const {return egzaminas;};
    inline double getGalutinis() const {return galutinis;};
    inline const std::vector<int>& getPazymiai() const {return pazymiai;};

    void setMediana();
    void setVidurkis();
};