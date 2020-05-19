#include "../headeriai/Studentas.h"
#include <sstream>

Studentas::Studentas(const std::string &eilute)
{
    std::string naujas;
    std::istringstream e(eilute);
    e >> vardas >> pavarde;

    while (e >> naujas)
    {
        pazymiai.push_back(stoi(naujas));
    }
    egzaminas = *(pazymiai.end() - 1);
    pazymiai.erase(pazymiai.end() - 1);
    galutinis = galutinisBalas();
}

Studentas::Studentas(const Studentas &studentas)
{
    vardas = studentas.vardas;
    pavarde = studentas.pavarde;
    pazymiai = studentas.pazymiai;
    egzaminas = studentas.egzaminas;
    galutinis = studentas.galutinis;
}

Studentas &Studentas::operator=(const Studentas &studentas)
{
    if (this != &studentas)
    {
        vardas = studentas.vardas;
        pavarde = studentas.pavarde;
        pazymiai = studentas.pazymiai;
        egzaminas = studentas.egzaminas;;
        galutinis = studentas.galutinis;
    }

    return *this;
}

bool Studentas::operator==(const Studentas &studentas) const
{
    if (pazymiai.size() == studentas.pazymiai.size())
    {
        auto it2 = studentas.pazymiai.begin();
        for (auto it = pazymiai.begin(); it != pazymiai.end(); ++it, ++it2)
        {
            if (*it != *it2)
                return false;
        }
    }
    else
    {
        return false;
    }

    if (vardas == studentas.vardas && pavarde == studentas.pavarde && egzaminas == studentas.egzaminas && galutinis == studentas.galutinis)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Studentas Studentas::operator+(const Studentas &studentas) const
{
    if (vardas == studentas.vardas && pavarde == studentas.pavarde)
    {
        Studentas s(*this);
        s.pazymiai.insert(s.pazymiai.end(), studentas.pazymiai.begin(), studentas.pazymiai.end());
               
        return s;
    }
    return *this;
}


void Studentas::setVardasPavarde(const std::string &a, const std::string &b)
{
    vardas = a;
    pavarde = b;
}
void Studentas::setVardasPavarde(const std::string &a)
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
void Studentas::setPazymiai(std::vector<int> &a)
{
    pazymiai = a;
}

double Studentas::galutinisBalas()
{
    if (pazymiai.size() == 0)
    {
        galutinis = egzaminas * 0.6;

        return galutinis;
    }
    else
    {   
        
        galutinis = calculateVidurkis() * 0.4 + egzaminas * 0.6;

        return galutinis;
    }
}

// cia medianai apskaiciuoti
double Studentas::calculateMediana()
{
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
        return (double)pazymiai[pazymiai.size() / 2];
    return (double)(pazymiai[(pazymiai.size() - 1) / 2] + pazymiai[pazymiai.size() / 2]) / 2.0;
}

// cia vidurkiui apskaiciuoti
double Studentas::calculateVidurkis()
{
    double suma = 0;
    for (size_t i = 0; i < pazymiai.size(); i++)
        suma += pazymiai[i];

    return (suma / pazymiai.size());
}