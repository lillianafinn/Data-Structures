//utilizing backtracking to solve Nqueens
#include <iostream>
using namespace std;

class nqueens {
  public:
    nqueens() {verbose = false; findall = false; }

    void set_verbose() {verbose = true; }
    void set_findall() {findall = true; }
    void play_game(int N = 0);

  private:
    bool is_valid(int, int);
    bool place_queen(int);
    void show_solution();

    bool verbose;
    bool findall;
    int N;
    long N_solutions;
    int *board;

};

void nqueens::play_game(int n_N) {
  if(n_N <= 0) return;

  N = n_N, N_solutions = 0;

  board = new int[N];
  for(int i = 0; i < N; i++) {
    board[i] = 0;
  }

  place_queen(0);
  delete [] board;
}

bool nqueens::is_valid(int row, int col) {
  for(int i = 0; i < row; i++) {
    int j = board[i];
    if(j == col || abs(col-j) == (row-i) {
        return false;
    }
    return true;
  }
}

bool nqueens::place_queen(int row) {
    if(is_valid(row, row)) {
      N_solutions++;
      show_solution();
      return findall == false;
    }
    for(int col = 0; col < N; col++) {
      board[row] = col;
      if(is_valid(row, col)) {
        if(verbose) {
          cout << "trying Q " << row << " at column " << col << endl;
        }
        if(place_queen(row+1) == true) return true;
      }
    }

    if(verbose) {
      cout << " exit Q " << row << " -- backtracking" << endl;
    }
    return false;
}

void nqueens::show_solution() {
    cout << "\nSolution:" << N_solutions;
    for(int row = 0; row < N; row++) {
      cout << endl;
      for(int col = 0; col < N; col++) {
        if(col == board[row]) cout << " Q";
        else cout << " .";

      }
    }
    cout << "\n\n";
}

int main(int argc, char *argv[]) {
  nqueens nq;

  nq.set_verbose();
  nq.set_findall();

  nq.play_game(atoi(argv[argc-1]));
}



