// Domino.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Anthony Rodriguez Valverde
//Inicio: 29/11/2022
//Finalizado: 6/12/2022 
//Proyecto domino, acontinuacion nos encontraremos con la creacion de un domino completo 

#include <iostream>
#include <vector>
using namespace std;
#include "Domino1.h"
#include <Windows.h>
#include <string>
#define color SetConsoleTextAttribute

int main()
{
    instrucciones(); //Mostramos las instrucciones del juego
    system("pause");
    system("cls");

    bool comprobando = true;
    fichas inicio;
    int total = 26, opcion1 = 0, opcion2 = 0, opcion3 = 0, opcion4 = 0;
    int tamanioJugador1 = 0, tamanioJugador2 = 0, tamanioJugador3 = 0, tamanioJugador4 = 0, tamanioMesa = 0;
    string jugador1Nombre, jugador2Nombre, jugador3Nombre, jugador4Nombre;
    vector<fichas>fichasCompletas(27);
    vector<fichas>mesa;
    vector<fichas>jugador1;
    vector<fichas>jugador2;
    vector<fichas>jugador3;
    vector<fichas>jugador4;
    vector<fichas>mesaJuego; //Creamos todas las barajas de los juegadores, la completa para jugar y la mesa
    rellenandoCompleto(fichasCompletas); //Llamamos a la funcion que rellena la baraja completa

    total = fichasCompletas.size();
    asignandoFichasIniciales(fichasCompletas, jugador1, jugador2, jugador3, jugador4, total); //Asignamos de forma aleatoria las fichas a cada baraja de los jugadores

    tamanioJugador1 = jugador1.size(); 
    tamanioJugador2 = jugador2.size();
    tamanioJugador3 = jugador3.size();
    tamanioJugador4 = jugador4.size();

    HANDLE colort = GetStdHandle(STD_OUTPUT_HANDLE);
    color(colort, 7);

    

    cout << "\tIngrese el nombre del primer jugador (Puedo agregarlo completo si desea): " << endl;
    getline(cin, jugador1Nombre);
    system("pause");
    system("cls");
    cout << "\tIngrese el nombre del segundo jugador (Puedo agregarlo completo si desea): " << endl;
    getline(cin, jugador2Nombre);
    system("pause");
    system("cls");
    cout << "\tIngrese el nombre del tercer jugador (Puedo agregarlo completo si desea): " << endl;
    getline(cin, jugador3Nombre);
    system("pause");
    system("cls");
    cout << "\tIngrese el nombre del cuarto jugador (Puedo agregarlo completo si desea): " << endl;
    getline(cin, jugador4Nombre);
    system("pause");
    system("cls"); //Solicitamos los nombres de los jugadores

    inicio.numero1 = 6;
    inicio.numero2 = 6;
    mesaJuego.insert(mesaJuego.begin(), inicio);
    tamanioMesa = mesaJuego.size();

    do { //QUE COMIENZE EL JUEGO!!!
        mostrarMesa(mesaJuego, tamanioMesa);
        cout << endl;
        cout << endl;
        cout << "Turno del jugador: " << jugador1Nombre << endl;
        mostrarFichas(jugador1, tamanioJugador1);
        cout << endl;
        menuINgame();
        cin >> opcion1;
        switch (opcion1)
        {
        case 1:
            sacarFicha(jugador1, fichasCompletas, tamanioJugador1, total);
            break;
        case 2:
            colocaFicha(mesaJuego, tamanioMesa, jugador1, tamanioJugador1);
            if (tamanioJugador1 == 0) {
                cout << "Felicidades jugador " << jugador1Nombre << " eres el ganador!!!" << endl;
                comprobando = false;
            }
            break;
        default:
            cout << "\tPASA DE TURNO!" << endl;
            break;
        }
        system("pause");
        system("cls");


        mostrarMesa(mesaJuego, tamanioMesa);
        cout << endl;
        cout << endl;
        cout << "Turno del jugador: " << jugador2Nombre << endl;
        mostrarFichas(jugador2, tamanioJugador2);
        cout << endl;
        menuINgame();
        cin >> opcion2;
        switch (opcion2)
        {
        case 1:
            sacarFicha(jugador2, fichasCompletas, tamanioJugador2, total);
            break;
        case 2:
            colocaFicha(mesaJuego, tamanioMesa, jugador2, tamanioJugador2);
            if (tamanioJugador2 == 0) {
                cout << "Felicidades jugador " << jugador2Nombre << " eres el ganador!!!" << endl;
                comprobando = false;
            }
            break;
            break;
        default:
            cout << "\tPASA DE TURNO!" << endl;
            break;
        }
        system("pause");
        system("cls");

        mostrarMesa(mesaJuego, tamanioMesa);
        cout << endl;
        cout << endl;
        cout << "Turno del jugador: " << jugador3Nombre << endl;
        mostrarFichas(jugador3, tamanioJugador3);
        cout << endl;
        menuINgame();
        cin >> opcion3;
        switch (opcion3)
        {
        case 1:
            sacarFicha(jugador3, fichasCompletas, tamanioJugador3, total);
            break;
        case 2:
            colocaFicha(mesaJuego, tamanioMesa, jugador3, tamanioJugador3);
            if (tamanioJugador3 == 0) {
                cout << "Felicidades jugador " << jugador3Nombre << " eres el ganador!!!" << endl;
                comprobando = false;
            }
            break;
            break;
        default:
            cout << "\tPASA DE TURNO!" << endl;
            break;
        }
        system("pause");
        system("cls");


        mostrarMesa(mesaJuego, tamanioMesa);
        cout << endl;
        cout << endl;
        cout << "Turno del jugador: " << jugador4Nombre << endl;
        mostrarFichas(jugador4, tamanioJugador4);
        cout << endl;
        menuINgame();
        cin >> opcion4;
        switch (opcion4)
        {
        case 1:
            sacarFicha(jugador4, fichasCompletas, tamanioJugador4, total);
            break;
        case 2:
            colocaFicha(mesaJuego, tamanioMesa, jugador4, tamanioJugador4);
            if (tamanioJugador4 == 0) {
                cout << "Felicidades jugador " << jugador4Nombre << " eres el ganador!!!" << endl;
                comprobando = false;
            }
            break;
            break;
        default:
            cout << "\tPASA DE TURNO!" << endl;
            break;
        }

        system("pause");
        system("cls");

    } while (comprobando == true);


}