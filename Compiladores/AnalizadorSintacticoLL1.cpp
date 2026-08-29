#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    int fila = 0;
    int columna = 0;

    //Se llena la tabla con las diferentes transiciones que hay entre los símbolos terminales y no terminales
    vector<vector<string>> tablaLL = {
        {"","I","#","+","-","*","/","(",")","$"},
        {"E","Te","Te","","","","","Te","",""},
        {"e","","","+Te","-Te","","","","0","0"},
        {"T","Ft","Ft","","","","","Ft","",""},
        {"t","","","0","0","*Ft","/Ft","","0","0"},
        {"F","I","#","","","","","(E)","",""}
    };

    //Se imprime en pantalla la tabla LL
    for (int i = 0; i < tablaLL.size(); ++i) {
        for (int j = 0; j < tablaLL[i].size(); ++j) {
            cout << tablaLL[i][j] << "\t";
        }
        cout << endl;
    }

    //Se declaran las pilas, una para guardar las cadenas y otra para los símbolos no terminales
    stack<char> Pila;
    stack<char> Entrada;
    //Se declara el símbolo inicial de la gramática
    char Inicial = 'E';
    //Se declara una variable de tipo booleana para validar si la cadena es aceptada o no
    bool valida = false;

    //Se ingresa la cadena
    string Expresion;
    cout << "Ingresa la cadena: ";
    cin >> Expresion;

    // Condición para verificar si la cadena comienza con un número seguido de una letra
    for (int i = 0; i < Expresion.length() - 1; i++) {
        if (isdigit(Expresion[i]) && isalpha(Expresion[i + 1])) {
            cout << "\n\n\tError: La expresion no puede comenzar con un numero seguido de un caracter.";
            return 1;
        }
    }

    //Se invierte la cadena para que el primer elemento se encuentre en la parte superior de la pila
    reverse(Expresion.begin(), Expresion.end());
    Entrada.push('$');
    //Se crea una variable de tipo bool para saber si un símbolo pertenece a la gramática
    bool validacion = true;
    //Se cambian las variables por la letra I para tokenizar los ID
    for(int i = 0; i < Expresion.length(); i++){
        //Si se leen letras o números, se tomarán como ID y se ingresará una I en la pila Entrada para identificarlo como un ID
        if((isalpha(Expresion[i])) || (isdigit(Expresion[i]))){
            while(isalpha(Expresion[i]) || (isdigit(Expresion[i]))){
                i++;
            }
            Entrada.push('I');
            i--;
        }
        //Si se lee un símbolo terminal se agrega en la pila Entrada
        else if((Expresion[i]) == '+' || (Expresion[i]) == '*' || (Expresion[i]) == '(' || (Expresion[i]) == ')' || (Expresion[i]) == '-' || (Expresion[i]) == '/' || (Expresion[i]) == '#'){
            if(Expresion[i] == '+'){
                Entrada.push('+');
            }else if(Expresion[i] == '*'){
                Entrada.push('*');
            }else if(Expresion[i] == '('){
                Entrada.push('(');
            }else if(Expresion[i] == ')'){
                Entrada.push(')');
            }else if(Expresion[i] == '-'){
                Entrada.push('-');
            }else if(Expresion[i] == '/'){
                Entrada.push('/');
            }else if(Expresion[i] == '#'){
                Entrada.push('#');
            }
        }
        //Si se lee otro símbolo, validacion se cambia a false y se produce un mensaje de error
        else{
            cout << "\n\n\tSe produjo un error en " << Expresion[i] << " ya que no pertenece a la gramatica";
            validacion = false;
        }
    }
    //Si el símbolo no pertenece a la gramática, el programa termina
    if(validacion == false){
        return 1;
    }

    //Se coloca el símbolo '$' en las pilas para poder iniciar el análisis
    Pila.push('$');
    Pila.push(Inicial);

    //Mientras las pilas no sean iguales a '$' significa que aun hay elementos en alguna de las dos pilas
    //que deben eliminarse, ya sea en la de la cadena o en la de los símbolos no terminales
    while(Entrada.top() != '$' || (Pila.top()) != '$'){
        string Produccion;
        char entrada_actual = Entrada.top();
        char pila_actual = Pila.top();
        //Si los valores en el tope de las pilas son diferentes, se accederá a la tablaLL, dependiendo de la combinación de símbolos
        if(entrada_actual != pila_actual){
        //Se define el valor de la fila de acuerdo al símbolo no terminal
        while (fila == 0) {
            if (pila_actual == 'E') {
                fila = 1;
            }else if (pila_actual == 'e') {
                fila = 2;
            }else if (pila_actual == 'T') {
                fila = 3;
            }else if (pila_actual == 't') {
                fila = 4;
            }else if (pila_actual == 'F') {
                fila = 5;
            }
            //Si se lee un símbolo diferente a los no terminales se imprime un mensaje de error y termina el programa
            else{
                cout << "\n\tError, no hay transicion para un elemento de la cadena \n";
                return 1;
              }

            }
        //Se define el valor de la columna de acuerdo al símbolo terminal
        while (columna == 0) {
            if (entrada_actual == 'I') {
                columna = 1;
            } else if (entrada_actual == '#') {
                columna = 2;
            } else if (entrada_actual == '+') {
                columna = 3;
            } else if (entrada_actual == '-') {
                columna = 4;
            } else if (entrada_actual == '*') {
                columna = 5;
            } else if (entrada_actual == '/') {
                columna = 6;
            } else if (entrada_actual == '(') {
                columna = 7;
            } else if (entrada_actual == ')') {
                columna = 8;
            } else if (entrada_actual == '$') {
                columna = 9;
            }

            //Si se lee un símbolo diferente a los terminales se imprime un mensaje de error y termina el programa
            else{
                cout << "\n\tError, no hay transicion para " << Entrada.top();
                return 1;
              }

            }

        //Se guarda en la variable produccion los simbolos terminales o no terminales a los que se dirige el símbolo que se encuentra
        //en el tope de Pila
        Produccion = tablaLL[fila][columna];
        cout << Produccion << endl; // Agregar salto de línea después de cada producción
        //Se extrae el elemento del tope de Pila y se ingresan los que se guardaron en producción invirtiendo su orden
        Pila.pop();
        reverse(Produccion.begin(), Produccion.end());
         for (char c : Produccion){
            Pila.push(c);
        }

        entrada_actual = Entrada.top();
        pila_actual = Pila.top();
        }

        cout << Pila.top();
        //Si los elementos en el tope de las pilas son iguales, se extraen los dos, ya que se trata de símbolos terminales
        if(entrada_actual == pila_actual){
            Pila.pop();
            Entrada.pop();
        }
        //Si en el tope de Pila se encuentra la cadena vacía, se extrae sólo un elemento de Pila
        else if (Pila.top() == '0') {
            Pila.pop();
        }
        //Si producción no tiene una línea de producción, se imprime un mensaje de error y el programa termina
        else if(Produccion == ""){
            cout << "\nLa cadena no es valida, la cadena esta en un caso en donde no hay transicion";
            return 1;
        }
        cout << Pila.top();
        //Se inicializan las variables fila y columna para que no exista conflicto al repetir el bucle
        fila = 0;
        columna = 0;

    }
    //Si las dos pilas tienen en su tope a '$' significa que la cadena es valida
    if((Pila.top() == '$') && (Entrada.top() == '$')){
    valida = true;
    }
    valida ? cout << "\nLa cadena es valida" : cout << "\nLa cadena no es valida";

    return 0;
}

