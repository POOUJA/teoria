/* 
 * File:   main.cpp
 * Author: algarcia
 *
 * Created on 17 de diciembre de 2015, 16:12
 */

#include <cstdlib>
#include <iostream>

#include "TicTacToe.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   TicTacToe *partida = new TicTacToe ();
   TicTacToe *p2 = new TicTacToe(*partida);
   
   return 0;
}

