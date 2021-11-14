// Ant Colony Algorithm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"Vertex/Vertex.h"
#include "Edge/Edge.h"
#include "Ant/Ant.h"
#include <cstdlib>
#include <ctime>

//parameters
constexpr int ants_num =  4 ;
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

    std::string best_solutionV;
    double global_shortest_path{};
    bool first_iteration{ true };

    //preaparing Edges 
    Edge::create_Edge(B, E);
    Edge::create_Edge(B, C);
    Edge::create_Edge(B, A);

    Edge::create_Edge(E, C);
    Edge::create_Edge(E, G);
    Edge::create_Edge(E, I);

    Edge::create_Edge(I, G);
    Edge::create_Edge(I, M);

    Edge::create_Edge(M, K);

    Edge::create_Edge(K, J);
    Edge::create_Edge(K, N);

    Edge::create_Edge(N, O);

    Edge::create_Edge(O, L);

    Edge::create_Edge(L, J);

    Edge::create_Edge(J, H);

    Edge::create_Edge(H, G);
    Edge::create_Edge(H, D);

    Edge::create_Edge(D, A);
    Edge::create_Edge(D, C);

    Edge::create_Edge(A, C);

    Edge::create_Edge(C, F);

    Edge::create_Edge(F, G);




    // z B do O
    Ant::start = B;
    Ant::target = O;
    //////////////////////////////////////////////Ant colony Algorithm
    while (iteration_num--)
    {
        //creating ants
        std::vector<Ant*> ants;
        for (int i = 0; i < ants_num; i++)
        {
            ants.push_back(new Ant());
        }
        //putting ants on start - B
        for (auto& ant : ants) { ant->set_current_V(Ant::start); }

        while (Ant::target->get_ants_num() != ants_num)
        {
            //each ant search finish & memorise, which nodes where visited
            for (auto& ant : ants)
            {
                ant->move_to_next_V();
            }
        }
        Ant::reset_target();
        //find local minimum
        double local_shortest_path{ (*ants.begin())->get_path_length()};
        Ant* bestAnt = *ants.begin();
        for (auto& ant : ants)
        { 
            if (ant->get_path_length() < local_shortest_path) 
            {
                local_shortest_path = ant->get_path_length();
                bestAnt = ant;

            }
        }
        //compare results &  set best solution, if was founded.
        if (first_iteration)
        {
            global_shortest_path = local_shortest_path;
            first_iteration = !first_iteration;
            best_solutionV = bestAnt->get_path_name();
        }
        if (local_shortest_path < global_shortest_path)
        {
            global_shortest_path = local_shortest_path;
            best_solutionV = bestAnt->get_path_name();
        }

    //reduce feromones globally
        Edge::reduce_feromoneG(feromone_reductor);
        //increase feromones on visited paths
        for (auto& ant : ants) { ant->put_feromone(); }
        std::cout << "Iteration: completed" << std::endl;
        for (const auto& ant : ants) delete ant;
    }
    //wydrukuj najlepszy wynik
    std::cout << "Shortest found Path =  "<< best_solutionV <<" lentgth= "<< global_shortest_path<<std::endl;
    //realising memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;
    delete H;
    delete I;
    delete J;
    delete K;
    delete L;
    delete M;
    delete N;
    delete O;
 

    return 0;

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
