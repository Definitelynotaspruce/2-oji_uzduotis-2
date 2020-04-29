#include "headeriai/Studentas.h"
#include <sstream>

Studentas::Studentas(const char &mediana, const std::string &ei)
{
    std::string naujas;
    std::istringstream e(ei);
    e >> vardas >> pavarde;

    while (e >> naujas)
    {
        pazymiai.push_back(stoi(naujas));
    }
    egzaminas = *(pazymiai.end() - 1);
    pazymiai.erase(pazymiai.end() - 1);
    galutinis = galutinisBalas(mediana);
}

Studentas::Studentas(const Studentas &studentas)
{
    vardas = studentas.vardas;
    pavarde = studentas.pavarde;
    pazymiai = studentas.pazymiai;
    egzaminas = studentas.egzaminas;
    galutinis = studentas.galutinis;
}

Studentas& Studentas::operator=(const Studentas &studentas)
{
    if (this != &studentas)
    {
        vardas = studentas.vardas;
        pavarde = studentas.pavarde;
        pazymiai = studentas.pazymiai;
        egzaminas = studentas.egzaminas;
        galutinis = studentas.galutinis;
    }

    return *this;
}

bool Studentas::operator==(const Studentas &studentas) const
{
    if(pazymiai.size() == studentas.pazymiai.size())
    {
        auto it2 = studentas.pazymiai.begin();
        for(auto it = pazymiai.begin(); it != pazymiai.end(); ++it, ++it2)
        {
            if(*it != *it2)
                return false;
        }
    }
    else
        return false;
    if(vardas == studentas.vardas && pavarde == studentas.pavarde)
        if(egzaminas == studentas.egzaminas && galutinis == studentas.galutinis)
            return true;
    else return false;

    return false; // Jeigu viskas sufailina 
}

Studentas Studentas::operator+(const Studentas &studentas) const
{
    if(*this == studentas)
    {
        Studentas s(*this);
        s.pazymiai.insert(s.pazymiai.end(), studentas.pazymiai.begin(), studentas.pazymiai.end() );

        return s;
    }
}

void Studentas::setVardasPavarde(const std::string &a, const std::string &b)
{
    vardas = a;
    pavarde = b;
}
void Studentas::setVardasPavarde(const std::string &a )
{
    std::string naujas;
    std::istringstream e(a);
    e >> vardas >> pavarde;
}
void Studentas::setPazymiai(std::vector<int> &a, int &b)
{
    pazymiai = a;
    egzaminas = b;
}
double Studentas::galutinisBalas(const char &a)
{
    if (pazymiai.size() == 0)
        return egzaminas * 0.6;
    else if (a == 'm')
        return mediana(pazymiai) * 0.4 + egzaminas * 0.6;
    else
        return vidurkis(pazymiai) * 0.4 + egzaminas * 0.6;
}

// cia medianai apskaiciuoti
double Studentas::mediana(std::vector<int> &sk)
{
    std::sort(sk.begin(), sk.end());
    if (sk.size() % 2 != 0)
        return (double)sk[sk.size() / 2];
    return (double)(sk[(sk.size() - 1) / 2] + sk[sk.size() / 2]) / 2.0;
}

// cia vidurkiui apskaiciuoti
double Studentas::vidurkis(std::vector<int> &sk)
{
    double suma = 0;
    for (size_t i = 0; i < sk.size(); i++)
        suma += sk[i];

    return suma / sk.size();
}