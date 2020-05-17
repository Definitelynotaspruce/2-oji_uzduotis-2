#include <string>


class Zmogus 
{
    protected:

     //! Konstruktorius nustatantis varda ir pavardę
    Zmogus(std::string var = " ", std::string pav = " ") : vardas(var), pavarde(pav) { }; 
    std::string vardas, pavarde;

    public:   

    //! Virtualus vardo bei pvardės seteris, kuris padaro klasę abstrakčią
    virtual void setVardasPavarde(const std::string &vardas, const std::string &pavarde) = 0;
    //! Virtualus vardo bei pvardės seteris, kuris padaro klasę abstrakčią
    virtual void setVardasPavarde(const std::string &vardasPavarde ) = 0;

    //! Virtualus vardo getteris
    inline virtual std::string getVardas() const { return vardas; };
    //! Virtualus pavardės getteris
    inline virtual std::string getPavarde() const { return pavarde; };
    //! Virtualus vardo bei pavardės geteris
    inline virtual std::string getVardasPavarde() const { return vardas + " " + pavarde; };

};