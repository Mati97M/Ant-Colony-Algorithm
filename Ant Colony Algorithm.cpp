// Ant Colony Algorithm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"Vertex/Vertex.h"
#include "Edge/Edge.h"
#include "Ant/Ant.h"
#include <cstdlib>
#include <ctime>

Vertexes_vector best_solutionV;
Vertexes_vector best_solutionE;
//parameters
int ants_num{ 4 };

double feromone_reductor{ 0.8 };
int iteration_num{ 50 };


int main()
{
    srand(time(NULL));
    //prepearing Vertexes
    auto A = new Vertex("A", 185, 245);
    auto B = new Vertex("B", 35, 235);
    auto C = new Vertex("C", 135, 215);
    auto D = new Vertex("D", 205, 205);
    auto E = new Vertex("E", 45, 195);
    auto F = new Vertex("F", 155, 185);
    auto G = new Vertex("G", 105, 155);
    auto H = new Vertex("H", 185, 155);
    auto I = new Vertex("I", 45, 125);
    auto J = new Vertex("J", 175, 115);
    auto K = new Vertex("K", 95, 105);
    auto L = new Vertex("L", 225, 105);
    auto M = new Vertex("M", 45, 65);
    auto N = new Vertex("N", 125, 65);
    auto O = new Vertex("O", 195, 45);
   /* auto U = new Vertex("U", 80, 61);
    auto P = new Vertex("P", 10, 0);
    auto R = new Vertex("R", 20, 80);*/

    // z B do O
    Ant::target = O;
    //////////////////////////////////////////////Ant colony Algorithm
    while (iteration_num--)
    {
        //creating ants
        std::vector<Ant> ants;
        for (int i = 0; i < ants_num; i++)
        {
            ants.push_back(Ant());
        }
        //putting ants on start - B
        for (auto& ant : ants) { ant.set_current_V(B); }

        while (Ant::target->get_ants_num() != ants_num)
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
    //wydrukuj najlepszy wynik
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
