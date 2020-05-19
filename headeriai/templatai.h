#include <string>
#include <exception>

template <typename Container>
//! Duomenų įvesties nuskaitymo funkcija
Container nuskaitymas (char &failai)
{    
    char ivedimas, mediana;
    std::cout << "Ar norite genruoti 5 studentu failus ? ('t' - taip; 'n' - ne )";
    std::cin >> failai;
    cpatikrinimas(failai, 't','n'); 
    if (failai == 'n') 
    {
    std::cout << "Ar vesite studentus ranka ar skaitysite viska is failo? ('i' - irasymas; 'f' - failas )";
    std::cin >> ivedimas;
    cpatikrinimas(ivedimas, 'i','f'); 
    }
    std::cout << "Skaiciuoti namu darbu pazymiu vidurki ar mediana?  ('m' - mediana; 'v' - vidurki) ";
    std::cin >> mediana; 
    cpatikrinimas(mediana, 'm','v');  
    
    Container a;
   // a.reserve(2000);
    if (failai == 't') tekstogeneravimas (a);
    else if (ivedimas == 'f') skaitymasfailo(a, "Studentai.txt");
    else ivedinejimas(a);
         
    return a;  
}

template <typename Container>
//! Duomenų išvedimo funkcija
void isvedimas(Container &a, std::string failoVardas)
{
    std::ofstream fr ("Rez"  + failoVardas);   
    std::string br (70, '-');
    fr << std::left << std::setw(10) << "Vardas" << std::left << std::setw(10) << "Pavarde" << std::right << std::setw(10) << "Metinis" << std::endl;        
    fr << br << std::endl; 
    std::cout << "SAIZIKAS " << a.size() << std::endl;
    std::cout << "CAPACIKAS " << a.capacity() << std::endl;   
    //auto it = a.begin();
    //std::cout << it->getVardas() << " GRAZUS NE" << std::endl;
    for(auto it : a)
    {
        fr << std::left << std::setw(15) << it.getVardas() << std::left << std::setw(15); 
        fr << it.getPavarde() << std::right << std::setw(4);
        fr << std::fixed << std::setprecision(2) << it.getGalutinis() << std::endl;
    }
/*     while (it != a.end())
    {
        fr << std::left << std::setw(15) << it->getVardas() << std::left << std::setw(15); 
        fr << it->getPavarde() << std::right << std::setw(4);
        fr << std::fixed << std::setprecision(2) << it->getGalutinis() << std::endl;             
        it++;
    }      */
    fr.close();
}

template <typename Container>
//! Duomenų nuskaitymo iš failo funkcija
void skaitymasfailo( Container &a, std::string failopavadinimas )
{   
    std::string vardas, pavarde, eilute, kiek; 
    std::ifstream fd;
    int realokacija = 0;
    try
    {
        fd.open (failopavadinimas);
        if( !fd.is_open() )
        {
            throw std::ios_base::failure("KLAIDA:: NERA TOKIO FAILO, todel viska veskite ranka :) ");
        }
        std::istringstream na(eilute);
        size_t cnt = 0;
        while ( getline (fd, eilute) )
        {
            Studentas stud(eilute);
            a.push_back(stud); 
            if(cnt == 384)
                std::cout << "URA " << stud.getVardas() << std::endl;
            ++cnt;
            //if( a.capacity() == a.size() ) realokacija++;              
        }
        std::cout << "REALOKACIJA IVYKO " << cnt << std::endl;
        fd.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        ivedinejimas(a);
        return; 
    }
}

template <typename Container>
//! Duomenų įvedinėjimo ranka funkcija (vedamas studento vardas, pavardė, pažymiai bei egzaminas)
void ivedinejimas(Container &a)
{
    char ranka;
    int n;
    std::cout << "Kiek studentu vesite? ";
    std::cin >> n;
    skpatikrinimas(n);
    std::cout << "Ar pazymius vesite ranka ar generuoti atsitiktinai? ('r' - ranka; 'g' - generuoti) ";
    std::cin >> ranka;
    cpatikrinimas(ranka, 'r','g');   
    for (int i = 0; i < n; i++)
    a.push_back(vardu_ivedimas(i, ranka));
}

template <typename Container>
//! Tekstinio failo generavimo funkcija, kuri kuria penkis .txt tipo failus (100,1000,10000,1000000,10000000 studentų)
void tekstogeneravimas (Container &a)
{ 
    srand (time(NULL));    
    int pazymiusk = 10 ;
    int failusk;
    Container protingas;
    Container vargsas;
    protingas.reserve(2000);
    vargsas.reserve(2000);

    std::cout << "----------------------------------------------" << std::endl << std::endl;
    
    for (int z = 0; z < FAILU_SK; z++ )
    {   
        failusk = 1000*pow(10,z);
        
        auto start = std::chrono::system_clock::now();

        std::ofstream dr ("students" + std::to_string(failusk) + ".txt");
        std::cout << "Failas " << "students" + std::to_string(failusk) + ".txt" << " atidarytas " << std::endl;

        for (int i = 0; i < failusk ; i++ )
        {
            dr << std::left << "Studentas" << std::setw(10) << rand()%100 << std::left << "Pavarde" <<  rand()%100 << std::right << std::setw(10);
    
            for (int j = 0; j < pazymiusk; j++ )
            dr <<  rand()%10 +1  << "\t" ;
        
            dr << std::endl;
        }
        dr.close();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << std::endl << "Failo generavimas uztruko " << elapsed_seconds.count() << std::endl;   
        
        start = std::chrono::system_clock::now();        
        skaitymasfailo(a, "students" + std::to_string(failusk) + ".txt");
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Skaitymas is failo uztruko " << elapsed_seconds.count() << std::endl;

        start = std::chrono::system_clock::now(); 
        //conteineriu split funkcijos
        //split_1  (a, protingas, vargsas);
        //split_2 (a, vargsas);  
        //split_3 (a, vargsas);
        split_4 (a, protingas, vargsas);
        end = std::chrono::system_clock::now();        
        elapsed_seconds = end - start;
        std::cout << "Vektoriu perrasymas uztruko " << elapsed_seconds.count() << std::endl;           
        
        start = std::chrono::system_clock::now();        
       //int protinguSk = a.size();
        isvedimas(vargsas, std::to_string(failusk) + "vargsai.txt");
        //isvedimas(protingas, std::to_string(failusk) + "protingi.txt"); 
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Isvedimas uztruko " << elapsed_seconds.count() << std::endl;
        std::cout << "----------------------------------------------" << std::endl << std::endl; 
    }  
}

/* template <typename Container>
//! Konteinerių splitinimo metodas su remove_copy_if bei copy_if (naudojami trys konteineriai)
void split_1(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    std::copy_if ( studentai.begin(), studentai.end(), std::back_inserter(protingi), daugiau_uz_5 );   
    studentai.erase (studentai.begin(), studentai.end());
}

template <typename Container>
//! Konteinerių splitinimo metodas su remove_copy_if (naudojami du konteineriai)
void split_2(Container &studentai, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    studentai.erase ( remove_if ( studentai.begin(), studentai.end(), maziau_uz_5), studentai.end() );    
}

template <typename Container>
//! Konteinerių splitinimo metodas su stable_partition (naudojami du konteineriai)
void split_3(Container &studentai, Container &vargsai)
{
    auto it = stable_partition (studentai.begin(), studentai.end(), daugiau_uz_5);
    copy ( it , studentai.end(), std::back_inserter(vargsai));
    studentai.erase(it, studentai.end());
} */

template <typename Container>
//! Konteinerių splitinimo metodas su remove_copy_if bei copy_if (naudojami trys konteineriai), taciau neistrinamas pradinis konteineris
void split_4(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    std::copy_if ( studentai.begin(), studentai.end(), std::back_inserter(protingi), daugiau_uz_5 );   
}

/* template <typename Container>
void split_5(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    std::copy_if ( studentai.begin(), studentai.end(), std::back_inserter(protingi), daugiau_uz_5 );   
} */
