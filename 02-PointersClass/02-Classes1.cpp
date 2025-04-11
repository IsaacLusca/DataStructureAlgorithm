#include <bits/stdc++.h>

using namespace std;

class Cookie
{
    // Atributos da classe:
    private:
        string color;

    // Construtor possui o mesmo nome da classe e normalmente é definida como public
    public:
        Cookie(string color){
            // o this->color altera a cor do private: string color, e no = color é sobre a string passada como argumento de cookie
            this->color = color;
        }
};

// Criando um cookie:
// Ponteiro para Cookie, toda classe que criar, definir qualquer variavel como igual ao objeto
// sera um ponteiro para esse objeto, no caso o objeto e o """Cookie""".
// o ""new""" faz com que seja executado o constructor, passando para o construtor a cor "green", e com isso se cria o cookie verde"!
Cookie* cookieOne = new Cookie("green");
// Ou seja, pode-se dizer que esse (this) cookie tem a cor (Cookie("green"))

// Criando outro cookie, a instancia, essa(this) 
// especifica do segundo cookie será blue;
Cookie* cookieTwo = new Cookie("blue");

int main() {

    return 0;
}