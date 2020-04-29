#pragma once

#include <string>
#include <vector>
#include <algorithm>

class Studentas
{
private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    double galutinis;

public:

    Studentas() : egzaminas(0) { }  
    Studentas(const char &mediana, const std::string &ei );
    Studentas(const std::string vardas, const std::string pavarde) : vardas(vardas), pavarde(pavarde) { }
    Studentas(const std::string vardas, const std::string pavarde, const double galutinis ) : vardas(vardas), pavarde(pavarde), galutinis(galutinis) { }
    Studentas(const std::string vardasPavarde) { setVardasPavarde(vardasPavarde); }

    ~Studentas() = default;

    Studentas(const Studentas &);

    Studentas& operator=(const Studentas&);
    Studentas operator+(const Studentas&) const;

    bool operator==(const Studentas& studentas) const;

    void setVardasPavarde(const std::string &vardas, const std::string &pavarde);
    void setVardasPavarde(const std::string &a );

    void setPazymiai(std::vector<int> &pazymiai, int &egzaminas);

    double galutinisBalas(const char &a);

    inline std::string getVardas() const { return vardas; };
    inline std::string getPavarde() const { return pavarde; };

    inline int getEgzaminas() const {return egzaminas;};

    inline double getGalutinis() const {return galutinis;};

    inline std::vector<int>& getPazymiai() {return pazymiai;};

    double mediana(std::vector<int> &pazymiai);
    double vidurkis(std::vector<int> &pazymiai);
};