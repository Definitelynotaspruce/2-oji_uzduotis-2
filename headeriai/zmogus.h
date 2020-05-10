#include <string>


class Zmogus 
{
    protected:
    std::string vardas, pavarde;

    public:

    Zmogus(std::string var = " ", std::string pav = " ") : vardas(var), pavarde(pav) { };  

    inline virtual void setVardasPavarde(const std::string &vardas, const std::string &pavarde) = 0;
    inline virtual void setVardasPavarde(const std::string &vardasPavarde ) = 0;

    inline virtual std::string getVardas() const { return vardas; };
    inline virtual std::string getPavarde() const { return pavarde; };
    inline virtual std::string getVArdasPavarde() const { return vardas + pavarde; };

};