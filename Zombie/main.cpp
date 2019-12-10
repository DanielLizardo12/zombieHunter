//
//  main.cpp
//  Proyecto FInal (Juego Zombies)
//
//  Created by Marco Antonio Lizardo Del Riego on 08/12/19.
//  Copyright © 2019 Marco Antonio Lizardo Del Riego. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

//include this for unix
//#include <unistd.h>
//using namespace std;

//include this for windows
#include <string>
using std::string;


//función creación de zombie
int CreaZombie () {
    if (rand() % 67 < 10)
        return 11;
    else
        return rand() % 10 + 1;
}

//method that lowers player hp
 double LowerHealth(double hp, bool bigZombie){
    double hit;
    if(bigZombie){
        hit =  (rand() % 40) + 30; // if the zombie is big it will cause 30 to 40 of damage
    }else{
        hit = (rand() % 30) + 20; // if the zombie is not big it will cause 20 to 30 of damage
    }
    hp -= hit;

    std::cout << std::endl << "AHH su puta madre te bajó " << hit << " de sangre :V como dicen en los KOF" << std::endl;
    std::cout << std::endl << "Tu salud ha sido reducida a  " << hp  << std::endl;
    std::cout << std::endl;

    return hp;
};

//al poner como semilla el time(NUll) garantizamos que el número generado por srand esté en función del tiempo de la computadora y por lo tanto SIEMPRE sea aleatorio.
int main() {
    srand(time(NULL));
    char enter;

    //EstadísticasDelJuego
    bool jugadorVivo = true; //de modo que cuando sea falso el jugador esté muerto.
    int habilidadDelJugador = 9; //nos ayudará a hacer que el zombie pueda matar el jugador o que el jugador pueda matar al zombie; aleatoriamente.
    int puntuacionDelJugador = 1;
    string nombreDelJugador = "";
    int numeroDeZombies = 0;
    int zombiesMuertos = 0;
    double hp = 100;
    bool bigZombie;

    //Juego

    std::cout << "Bienvenido al apocalípsis Zombie" << std::endl << "Presiona [ENTER] para empezar";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cin.get(); // mantiene la ventana de diálogo abierta

    //Nombre del jugador
    std::cout << "como te llamas we?: ";
    std::cin >> nombreDelJugador;

    //Con cuántos zombies quiere el jugador combatir
    std::cout << "Con cuántos zombies quieres pelear?: ";
    std::cin >> numeroDeZombies;
    std::cout << std::endl;

    std::cout << "Prepárate para pelear por tu miserable vida, " << nombreDelJugador << "!" << std::endl;

    //Iteración principal del juego
    while (jugadorVivo && zombiesMuertos < numeroDeZombies) {
        //crea un zombie aleatorio con la función anterior en función de la habilidad de cada zombie; a cada habilidad (representada por un int) le corresponde un zombie.
        int HabilidadZombie = CreaZombie();

        //secuencia de los chingadazos
        if (HabilidadZombie > 5) {
            std::cout << std::endl << "Aquí viene un Zombie grande!" << std::endl;
            std::cout << std::endl;
            bigZombie = true;
        } else {
            std::cout << std::endl << "Aquí viene un zombie" << zombiesMuertos + 1 << std::endl;
            std::cout << std::endl;
            bigZombie = false;
        }

        std::cout << "Peleando..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(3));

        //Aquí el programa va a alternar aleatoriamente las interjecciones de la pelea
        string golpe [5] = {"¡Pum!", "¡Zaz, culebra!", "¡Wham!", "¡NoScope!", "En la cabeza alv!"};
        srand(time(NULL));

        std::cout << golpe[rand() % (golpe->length() - 1)];
        std::cout << std::endl;

        std::this_thread::sleep_for (std::chrono::seconds(1));

        //Si el Zombie se echa al jugador
        if(habilidadDelJugador < HabilidadZombie) {
            //jugadorVivo = false;
            //std::cout << "Chupaste faros" << std::endl;
        }

            //Si el jugador se echa al zombie
        else  {
            if (habilidadDelJugador - HabilidadZombie > 7) {
                std::cout << "Te echaste al Zombie" << std::endl;
                puntuacionDelJugador = puntuacionDelJugador*2;
            }
            else if (habilidadDelJugador - HabilidadZombie > 5) {
                std::cout << "Decapitaste al zombie alv!" << std::endl;
                puntuacionDelJugador = puntuacionDelJugador*2;
            }

            else if (habilidadDelJugador - HabilidadZombie > 0) {
                std::cout << "Mataste al zombie!" << std::endl;
                puntuacionDelJugador = puntuacionDelJugador*2;
            }

            else {
                std::cout << "Mataste al zombie pero te metieron un chingazo" << std::endl;
                hp = LowerHealth(hp, bigZombie);

                if(hp <= 0){
                    std::cout << std::endl << "En pocas palabras shupaste faros" << std::endl;
                    std::cout << std::endl;
                    jugadorVivo = false;
                }
            }

            zombiesMuertos++;
        }
        std::cout << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }

    //Fin del Juego
    if (zombiesMuertos == numeroDeZombies) {
        //victoria
        std::cout << "Has sobrevivido al apocalipsis we!" << std::endl;
        std::cout << std::endl;
    }

    else {
        //derrota
        std::cout << "No sobreviviste al apocalipsis we, que mal pedo" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Zombies muertos: " << zombiesMuertos << std::endl;
    std::cout << "Puntaje último: " << puntuacionDelJugador << std::endl;
    std::cout << std::endl;
    std::cout << "creditos:" << std::endl;
    std::cout << "Marco Antonio Lizardo Del Riego" << std::endl;
    std::cout << "Rodolfo Manuel Castañeda Castro a.k.a El Flipy" << std::endl;
    std::cout << "Alejando Sandoval Alaniz" << std::endl;
    std::cout << "Juan Raúl Ramos Juárez" << std::endl;
    std::cout << "Wesley Daniel Lizardo González a.k.a Commit" << std::endl;
    std::cout << "caca1" << std::endl;
    std::cout << std::endl;

    return 0;
}
