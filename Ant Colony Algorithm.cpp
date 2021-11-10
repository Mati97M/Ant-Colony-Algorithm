// Ant Colony Algorithm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"Verticle/Verticle.h"
#include "Edge/Edge.h"
#include "Ant/Ant.h"
#include <cstdlib>
#include <ctime>

Verticles_vector best_solutionV;
Verticles_vector best_solutionE;
//parameters
int ants_num{ 4 };

double feromone_reductor{ 0.8 };
int iteration_num{ 50 };


int main()
{
    srand(time(NULL));
    //prepearing verticles
    auto A = new Verticle("A", 10, 11);
    auto B = new Verticle("B", 20, 22);
    auto C = new Verticle("C", 30, 33);
    auto D = new Verticle("D", 40, 44);
    auto E = new Verticle("E", 50, 55);
    auto F = new Verticle("F", 60, 66);
    auto G = new Verticle("G", 70, 77);
    auto H = new Verticle("H", 80, 88);
    auto I = new Verticle("I", 90, 99);
    auto J = new Verticle("J", 100, 11);
    auto K = new Verticle("K", 15, 51);
    auto L = new Verticle("L", 25, 52);
    auto M = new Verticle("M", 75, 75);
    auto N = new Verticle("N", 18, 81);
    auto O = new Verticle("O", 47, 40);
    auto U = new Verticle("U", 80, 61);
    auto P = new Verticle("P", 10, 0);
    auto R = new Verticle("R", 20, 80);

    // z A do I
    Ant::target =  I;
    //////////////////////////////////////////////Ant colony Algorithm
    while (iteration_num--)
    {
        //creating ants
        std::vector<Ant> ants;
        for (int i = 0; i < ants_num; i++)
        {
            ants.push_back(Ant());
        }
        //putting ants on start - A
        for (auto& ant : ants) { ant.set_current_V(A); }

        while (I->get_ants_num() != ants_num)
        {
            //each ant search finish & memorise, which nodes where visited

        }
        //compare results

        //set best solution, if was founded

        //reduce feromones globally
        Edge::reduce_feromoneG(feromone_reductor);
        //increase feromones on visited paths
        for (auto& ant : ants) { ant.put_feromone(); }
    }

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
