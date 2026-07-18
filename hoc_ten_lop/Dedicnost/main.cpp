#include <iostream>

/*1. Zvířata
Vytvořte základní třídu Zivocich s protected atributem jmeno.
Vytvořte konstruktor Zivocich(string j).
Vytvořte odvozenou třídu Pes, která přidá atribut rasa.
Vytvořte konstruktor Pes(string j, string r), který správně zavolá konstruktor předka.
Vytvořte metodu stekej(), která vypíše: "[jmeno] ([rasa]): Haf!".*/

class Zivocich{
    protected:
        std::string jmeno;

    public:
        Zivocich (std::string j){
            this->jmeno =j;
        }
};

class Pes : public Zivocich {
    private: 
        std::string rasa;

    public:
        Pes (std::string j, std::string rasa) : Zivocich (j){
            this->rasa = rasa;
        }
        void Stekej();
        
};

int main(){
    Pes pes1 ("Potato","Pug Dog");
    pes1.Stekej();

    return 0;

}

void Pes:: Stekej(){
    std::cout<<"{"<<jmeno<<"} rasa: ["<<rasa<<"]: Half"<<std::endl;
}