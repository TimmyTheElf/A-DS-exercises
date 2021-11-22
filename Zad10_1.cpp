
#include <iostream>
#include <iomanip>

using namespace std;

// Typ elementów listy dla kolejki

struct slistEl
{
  slistEl * next;
  int data;
};

// Zmienne globalne

int n;                   // Liczba wierzchołków
char ** A;               // Macierz sąsiedztwa
bool * visited;          // Tablica odwiedzin

// Procedura przejścia wszerz
//---------------------------
void BFS ( int v )
{
  cout<< "BFS: ";
  int i;
  slistEl *q, *head, *tail; // Kolejka

  q = new slistEl;        // W kolejce umieszczamy v
  q->next = NULL;
  q->data = v;
  head = tail = q;

  visited [ v ] = true;   // Wierzchołek v oznaczamy jako odwiedzony

  while( head )
  {
    v = head->data;       // Odczytujemy v z kolejki

    q = head;             // Usuwamy z kolejki odczytane v
    head = head->next;
    if( !head ) tail = NULL;
    delete q;

    cout  << v+1<< " ";

    for( i = 0; i < n; i++ )
      if( ( A [ v ][ i ] == 1 ) && !visited [ i ] )
      {
        q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sąsiadów
        q->next = NULL;
        q->data = i;
        if( !tail ) head = q;
        else tail->next = q;
        tail = q;
        visited [ i ] = true; // i oznaczamy ich jako odwiedzonych
      }
  }
  cout<<endl;
}

void DFS ( int v )
{
  int i;

  visited [ v ] = true;  // Zaznaczamy węzeł jako odwiedzony
  cout <<v+1 <<" ";  // Przetwarzamy węzeł ( wypisujemy jego numer )

// Rekurencyjnie odwiedzamy nieodwiedzonych sąsiadów

  for( i = 0; i < n; i++ )
    if( ( A [ v ][ i ] == 1 ) && !visited [ i ] ) DFS ( i );
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main( )
{
  int ilGraf;
  cin>>ilGraf;
  for(int q= 0; q< ilGraf;q++){
  cout<<"Graf nr " <<q+1<<endl;
  int m, v1, v2;

  cin >> n >> m;// Czytamy liczbę wierzchołków i krawędzi

  A = new char * [ n ];       // Tworzymy tablicę wskaźników
  visited = new bool [ n ];   // Tworzymy tablicę odwiedzin

  for(int i = 0; i < n; i++ )
    A [ i ] = new char [ n ]; // Tworzymy wiersze

  // Macierz wypełniamy zerami

  for(int i = 0; i < n; i++ )
  {
    visited [ i ] = false; // Zerujemy tablicę odwiedzin
    for(int j = 0; j < n; j++ ) A [ i ][ j ] = 0;
  }

  // Odczytujemy kolejne definicje krawędzi

  for(int i = 0; i < m; i++ )
  {
    cin >> v1 >> v2;
    v1--;
    v2--;  // Wierzchołek startowy i końcowy krawędzi
    A[v1][v2] = 1;
    A[v2][v1] = 1;// Krawędź v1->v2 obecna
  }


  // Przechodzimy graf wszerz
  cout<< "DFS: ";
  DFS(0);
  cout<<endl;
  for(int i = 0; i < n; i++ )
  {
    visited [ i ] = false; // Zerujemy tablicę odwiedzin
  }
  BFS(0);


  // Usuwamy macierz

  for(int i = 0; i < n; i++ ) delete A [ i ];
  delete [ ] A;
  delete [ ] visited;

  }
  return 0;
}
