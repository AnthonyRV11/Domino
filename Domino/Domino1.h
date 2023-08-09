#pragma once
#include "EstructuraDomino.h"
#include <time.h>

//funcion que tiene las instrucciones
void instrucciones() {
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "\tBienvenido al domino!!!" << endl;
	cout << "\tEste juego esta creado para que participen 4 personas" << endl;
	cout << "\tSe le asiganaran 5 fichas a cada jugador para iniciar el juego" << endl;
	cout << "\tRecuerde que no puede tener mas de 7 fichas al momento" << endl;
	cout << "\tEl primero que se quede sin fichas sera el ganador" << endl;
	cout << "\tSuerte a todos y que lo disfruten!!!" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
}

//*********************************************************************************************
//Funcion que llena por medio de ciclos el vector con todas las fichas para el juego
void rellenandoCompleto(vector<fichas>& fichasCompletas) {
	int contador1 = 0, contador2 = contador1;

	for (int i = 0; i < 27; i++) {

		fichasCompletas[i].numero1 = contador1;
		fichasCompletas[i].numero2 = contador2;
		contador2 += 1;
		if (contador2 == 7) {
			contador1 += 1;
			contador2 = contador1;
		}


	}
	cout << "-------------------------------------------" << endl;
	cout << "\tTodas las fichas del domino:" << endl;
	cout << "-------------------------------------------" << endl;
	contador1 = 0;
	for (int i = 0; i < 27; i++) {
		cout << " [" << fichasCompletas[i].numero1 << "|" << fichasCompletas[i].numero2 << "] ";
		contador1 += 1;
		if (contador1 == 4) {
			cout << " [" << fichasCompletas[i].numero1 << "|" << fichasCompletas[i].numero2 << "] " << endl;
			contador1 = 0;
		}
	}
	cout << endl;
	system("pause");
	system("cls");

}

//*********************************************************************************************

//Funcion que asigna de forma aleatoria fichas a las barajas de los jugadores
void asignandoFichasIniciales(vector<fichas>& fichasCompletas, vector<fichas>& jugador1, vector<fichas>& jugador2, vector<fichas>& jugador3, vector<fichas>& jugador4, int& total) {
	srand(time(NULL));
	int num = 0;
	fichas lleno;

	for (int i = 0; i < 5; i++) {
		num = rand() % total;
		lleno = fichasCompletas[num];
		fichasCompletas.erase(fichasCompletas.begin() + num);
		jugador1.insert(jugador1.begin(), lleno);
		total -= 1;
	}

	for (int i = 0; i < 5; i++) {
		num = rand() % total;
		lleno = fichasCompletas[num];
		fichasCompletas.erase(fichasCompletas.begin() + num);
		jugador2.insert(jugador2.begin(), lleno);
		total -= 1;
	}

	for (int i = 0; i < 5; i++) {
		num = rand() % total;
		lleno = fichasCompletas[num];
		fichasCompletas.erase(fichasCompletas.begin() + num);
		jugador3.insert(jugador3.begin(), lleno);
		total -= 1;
	}
	for (int i = 0; i < 5; i++) {
		num = rand() % total;
		lleno = fichasCompletas[num];
		fichasCompletas.erase(fichasCompletas.begin() + num);
		jugador4.insert(jugador4.begin(), lleno);
		total -= 1;
	}

}

//*********************************************************************************************

void menuINgame() { //Menu dentro del juego para que el usuario pueda pasar o tomar otra carta
	cout << "1.Para sacar otra ficha." << endl;
	cout << "2.Para colocar una ficha." << endl;
	cout << "3.Para pasar de turno." << endl;
}

//Funcion con un ciclo que recorre la mesa y la muestra
void mostrarMesa(vector<fichas>mesa, int tamanioMesa) {

	int contador = 0;
	cout << "-----------------------------------" << endl;
	cout << "\tMESA" << endl;
	for (int i = 0; i < tamanioMesa; i++) {
		if (contador <= 8) {
			cout << "[" << mesa[i].numero1 << " | " << mesa[i].numero2 << "]" << "   ";
			contador += 1;
		}
		else {
			cout << "[" << mesa[i].numero1 << " | " << mesa[i].numero2 << "]" << "   " << endl;
			contador = 0;
		}
	}
	cout << "\n-----------------------------------" << endl;
}

//Funcion con un ciclo que recorre la baraja y la muestra
void mostrarFichas(vector<fichas>jugador, int tamanio) {
	cout << "-----------------------------------" << endl;
	cout << "Sus fichas: " << endl;

	cout << endl;
	for (int i = 0; i < tamanio; i++) {
		cout << "[" << jugador[i].numero1 << " | " << jugador[i].numero2 << "]" << "   ";
	}

}

//Funcion para sacar una ficha
void sacarFicha(vector <fichas>& Jugador, vector <fichas>& fichasCompletas, int& tamanioJugador, int& total) {
	int num = 0;  //Funcion para poder sacar una carta
	fichas ingresando;
	srand(time(NULL));

	num = rand() % total;
	total -= 1;

	ingresando = fichasCompletas[num];
	fichasCompletas.erase(fichasCompletas.begin() + num);
	Jugador.insert(Jugador.begin(), ingresando);
	tamanioJugador = Jugador.size();

	cout << "\tLa carta que te toco es: " << endl;

	cout << "[" << Jugador[0].numero1 << "|" << Jugador[0].numero2 << "]" << endl;
}

//Funcion creada para poder colocar las fichas del domino
void colocaFicha(vector<fichas>& mesaJuego, int& tamanioMesa, vector <fichas>& Jugador, int& tamanioJugador) {

	int opcion = 0, opcionDentro = 0, izquierda = 0, derecha = 0;
	fichas cambio, insertandoCambio;
	cout << "\tDigite el numero de la ficha desea colocar" << endl;
	cout << "\t1.Para la primer ficha" << endl;
	cout << "\t2.Para la segunda ficha" << endl;
	cout << "\t3.Para la tercer ficha" << endl;
	cout << "\t4.Para la cuarta ficha" << endl;
	cout << "\t5.Para la quinta ficha" << endl;
	cout << "\t6.Para la sexta ficha" << endl;
	cout << "\t7.Para la septima ficha" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		cambio = Jugador[0];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin());
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin());
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin());
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin());
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;


	case 2:
		cambio = Jugador[1];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 1);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 1);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 1);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin() + 1, insertandoCambio);
					Jugador.erase(Jugador.begin());
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;


	case 3:
		cambio = Jugador[2];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 2);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 2);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 2);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 2);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;

	case 4:
		cambio = Jugador[3];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 3);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 3);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 3);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 3);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;


	case 5:
		cambio = Jugador[4];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 4);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 4);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 4);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 4);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;


	case 6:
		cambio = Jugador[5];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 5);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 5);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 5);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 5);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;


	default:
		cambio = Jugador[6];
		izquierda = cambio.numero1;
		derecha = cambio.numero2;
		cout << "\tIngrese (1) si desea colocarla de primera, (2) si desea colocarla de ultimo" << endl;
		cin >> opcionDentro;
		switch (opcionDentro)
		{
		case 1:
			if (derecha == mesaJuego[0].numero1) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 6);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[0].numero1) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 6);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}
			break;
		default:
			if (derecha == mesaJuego[tamanioMesa - 1].numero2) {
				insertandoCambio.numero1 = izquierda;
				insertandoCambio.numero2 = derecha;
				mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
				Jugador.erase(Jugador.begin() + 6);
				tamanioMesa = mesaJuego.size();
				tamanioJugador = Jugador.size();
			}
			else {
				if (izquierda == mesaJuego[tamanioMesa - 1].numero2) {
					insertandoCambio.numero1 = derecha;
					insertandoCambio.numero2 = izquierda;
					mesaJuego.insert(mesaJuego.begin(), insertandoCambio);
					Jugador.erase(Jugador.begin() + 6);
					tamanioMesa = mesaJuego.size();
					tamanioJugador = Jugador.size();
				}
				else {
					cout << "\tEsa ficha no es valida!!!" << endl;
				}
			}

			break;
		}
		break;
	}

}


