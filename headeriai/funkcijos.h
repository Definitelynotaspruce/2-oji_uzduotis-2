#pragma once

#include "Studentas.h"
#include <list>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <iomanip>
#include <random>
#include <cmath>
#include <chrono>

//! Definina generuojamų .txt tipo failų vienetų skaičių
#define FAILU_SK 5 

//! Int skaičiaus patikrinimas (tikrinama, ar paduotas skaičius tinkamas, teigiamas)
void skpatikrinimas(int &n);

//! Char simbolio patikrinimas (tikrinama, ar įrašytas simbolis sutampa su dviem galimais)
void cpatikrinimas(char &a, char b, char c);
//! Char simbolio patikrinimas (tikrinama, ar įrašytas simbolis sutampa su trim galimais)
void c2patikrinimas(char &a, char b, char c, char d);

//! Int skaičiaus patikrinimas (ar atitinka rėžius nuo 1 iki 10)
void patikrint(int &sk);

//! Studentų pažymių įvedimo funkcija
std::vector<int> skaiciu_ivedimas(int &n);

//! Random skaičių generavimo funkcija
std::vector<int> skaiciu_generavimas(int &n, char &a);

//! Studento vardo bei pavardės įvedimo funkcija
Studentas vardu_ivedimas(int &n, char &ranka);

//! Bool tipo funkcija, tikrinanti ar vieno studento vardas "didesnis" už kito
bool alfa(Studentas &a, Studentas &b);
//! Bool tipo funkcija, tikrinanti ar vieno studento galutinis balas didesnis už kito
bool beta(Studentas &a, Studentas &b);
//! Bool tipo funkcija, tikrinanti ar studento galutinis balas mazesnis už 5
bool maziau_uz_5 ( Studentas &s);
//! Bool tipo funkcija, tikrinanti ar studento galutinis balas didesnis už 5
bool daugiau_uz_5 ( Studentas &s);