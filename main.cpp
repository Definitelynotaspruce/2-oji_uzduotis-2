
#include "headeriai/Studentas.h"
#include "headeriai/funkcijos.h"
#include "headeriai/templatai.h"
#include "headeriai/vector.h"

int main()
{
    char generavimas; //kintamasis patikrinimui ar vartotojas nori generuoti failus ar ne
    char type; // pasirenkamo konteinerio tipas
    
    std::cout << "Programoje naudoti vektorius, homemade vektorius  ar listus? (veskite 'v', 'd', 'l')";    
    std::cin >> type;   
    c2patikrinimas(type, 'v', 'd', 'l');
     
   if (type == 'v')
   {
   std::vector<Studentas> stud = nuskaitymas<std::vector<Studentas>>(generavimas);
   if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   }  
   else if (type == 'l') 
   { 
   //std::list<Studentas> stud = nuskaitymas<std::list<Studentas>>( generavimas ); 
   //if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   } 
   else if (type == 'd') 
   {
   rice::vector<Studentas> stud = nuskaitymas<rice::vector<Studentas>>( generavimas ); 
   if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   } 

   std::cin.get();
   return 0;
} 