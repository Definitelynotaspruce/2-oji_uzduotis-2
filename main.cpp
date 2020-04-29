
#include "headeriai/Studentas.h"
#include "headeriai/funkcijos.h"
#include "headeriai/templatai.h"

int main()
{
    Studentas s1('v', "Jolanta Kosiakaite 1 4 5 2 3 10"), s3;
    Studentas s2 = s1;
    s2.setVardasPavarde("Jolanta Kosiakaite");
    std::cout << (s2 == s1) << std::endl;
    s3 = s1 + s2;
    auto pt = s3.getPazymiai();
    std::cout << s3.getVardas() << " " << pt.size() << std::endl;

    for(auto el : pt)
    {
        std::cout << el << " " ;
    }

    char generavimas; //kintamasis patikrinimui ar vartotojas nori generuoti failus ar ne
    char type; // pasirenkamo konteinerio tipas
    
    std::cout << "Programoje naudoti vektorius, deque ar listus? (veskite 'v', 'd', 'l')";    
    std::cin >> type;   
    c2patikrinimas(type, 'v', 'd', 'l');
     
   if (type == 'v')
   {
   std::vector<Studentas> stud = nuskaitymas<std::vector<Studentas>>(generavimas);
   if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   }  
   else if (type == 'l') 
   { 
   std::list<Studentas> stud = nuskaitymas<std::list<Studentas>>( generavimas ); 
   if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   } 
   else if (type == 'd') 
   {
   std::deque<Studentas> stud = nuskaitymas<std::deque<Studentas>>( generavimas ); 
   if (generavimas == 'n') isvedimas(stud, "rezultatai.txt"); 
   } 

   std::cin.get();
   return 0;
} 