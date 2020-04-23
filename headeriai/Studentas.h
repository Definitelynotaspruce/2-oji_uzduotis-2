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
    Studentas( char &mediana, std::string &ei );
    
    void setVardasPavarde(std::string &vardas, std::string &pavarde);

    void setPazymiai(std::vector<int> &pazymiai, int &egzaminas);

    double galutinisBalas(char &a);

    inline std::string getVardas() const { return vardas; };
    inline std::string getPavarde() const { return pavarde; };

    double getGalutinis();
    double mediana(std::vector<int> &pazymiai);
    double vidurkis(std::vector<int> &pazymiai);
};