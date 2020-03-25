/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <iostream>
#include <vector>

/*
* Interface de gestion de tout les jeux
*/
class IGame {

    public:
        virtual ~IGame() = 0;

    /*
    * Récupère la map dans un fichier texte 
    * (ou prend celle par défaut)
    */
        virtual void setMap() = 0;
    /*
    * Récupère la précédente position du joueur
    * (ou prend celle par défaut)
    */
        virtual void setPos() = 0;
    /*
    * Récupère la précédente position des 'gums'
    * (ou prend celle par défaut)
    */
        virtual void setFood() = 0;
    /*
    * Modification des positions
    * Permet de bouger joueurs & enemies
    */
        virtual void move() = 0;
    /*
    * Affichage des éléments des jeux aux positions spécifiées
    */
        virtual void display() = 0;

    protected:
        //
    private:
        /*
        * Position Joueur
        */
        size_t x;
        size_t y;
        //
};

#endif /* !IGAME_HPP_ */