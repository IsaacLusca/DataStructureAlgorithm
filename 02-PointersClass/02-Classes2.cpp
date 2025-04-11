#include <bits/stdc++.h>

using namespace std;

class Cookie {
    // atributos
    private:
        string color;

    // constructor
    public:
        // Cria a instancia cookie com: Cookie* cookie1 = new Cookie("cor")
        Cookie (string color) {
            this->color = color;
        }
        // permite pegar a cor do cookie: cookie1->getColor()
        string getColor () {
            return color;
        }
        // permite definir uma nova cor cookie1->setColor("cor")
        void setColor (string color) {
            this->color = color;
        }

        // remover cor
        void removeColor() {
            this->color = "";
        }
};

int main() {
    // criando um cookieOne com a cor verde
    Cookie* cookieOne = new Cookie("green");
    // Criando o cookieTwo com a cor azul
    Cookie* cookieTwo = new Cookie("blue");

    // Set/definindo uma nova cor para o cookieOne
    cookieOne->setColor("Yellow");
    
    // cookieTwo->removeColor();

    cout << "C1: " << cookieOne->getColor() << endl;
    cout << "C1: " << cookieTwo->getColor() << endl;

    delete cookieTwo;
    return 0;
}