#include "headeriai/Studentas.h"
#include <sstream>

Studentas::Studentas(char &mediana, std::string &ei)
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

void Studentas::setVardasPavarde(std::string &a, std::string &b)
{
    vardas = a;
    pavarde = b;
}
void Studentas::setPazymiai(std::vector<int> &a, int &b)
{
    pazymiai = a;
    egzaminas = b;
}
double Studentas::galutinisBalas(char &a)
{
    if (pazymiai.size() == 0)
        return egzaminas * 0.6;
    else if (a == 'm')
        return mediana(pazymiai) * 0.4 + egzaminas * 0.6;
    else
        return vidurkis(pazymiai) * 0.4 + egzaminas * 0.6;
}

double Studentas::getGalutinis() { return galutinis; }

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