#include <iostream>
#include <string>

// Definice šablony funkce
template <typename T>
T getMax(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Definice šablony třídy
template <typename T>
class Box {
private:
    T item; // Atribut 'item' má generický typ T

public:
    // Konstruktor
    Box(T newItem) {
        this->item = newItem;
    }

    // Metoda pro získání hodnoty
    T getItem() {
        return this->item;
    }
};

int main() {
    // Kompilátor sám pozná (podle typů argumentů), že má vytvořit:
    
    // 1. Verzi pro int: getMax(int a, int b)
    std::cout << "Vetsi z 5 a 10 je: " << getMax(5, 10) << std::endl;

    // 2. Verzi pro double: getMax(double a, double b)
    std::cout << "Vetsi z 3.14 a 2.71 je: " << getMax(3.14, 2.71) << std::endl;

    // 3. Verzi pro std::string: getMax(std::string a, std::string b)
    // (Funguje, protože operátor '>' je pro string definován)
    std::cout << "Vetsi z 'auto' a 'zebra' je: " << getMax(std::string("auto"), std::string("zebra")) << std::endl;

    // Můžeme typ specifikovat i explicitně:
    std::cout << "Vetsi z 5 a 10.5 je: " << getMax<double>(5, 10.5) << std::endl;

    std::cout<<"-----------------------------"<<std::endl; 
    // Vytvoříme instanci Box, která bude uchovávat int
    // Kompilátor vytvoří třídu Box<int>
    Box<int> intBox(123);
    std::cout << "V krabici na cisla je: " << intBox.getItem() << std::endl;

    // Vytvoříme instanci Box, která bude uchovávat std::string
    // Kompilátor vytvoří třídu Box<std::string>
    Box<std::string> stringBox("Ahoj svete");
    std::cout << "V krabici na text je: " << stringBox.getItem() << std::endl;

    return 0;
}