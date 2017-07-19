

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
#include <limits>
using namespace std;

class Grid{

	public:
	Grid (int n){
		size = n;
		board = new char[n*n];
		for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        board[(i*n)+j] = '0';
      }
    }
  }

	Grid(Grid& temp){
		size = temp.size;
		board = new char[size*size];
    for(int i = 0 ; i < size ; i++){
      for(int j = 0 ; j < size ; j++){
        board[(i*size)+j] = temp.board[(i*size)+j];
      }
    }
  }

    char isWin(){
        // returns t for a tie
        // returns x or o for a certian win
        // returns m if the game is not done
        // I switched this up so i return a char not an int. It makes more sense in my head.
        // Check for row wins
        char x;
        for(int i = 0 ; i < size ; i++){
            x = board[i*size];
            if(x == '0'){
                break;
            }
            for(int j = 1 ; j < size ; j++){
                if( board[(i*size)+ j] != x){
                    break;
                } else if( j == size-1){
                    return x;
                }
            }
        }

        // Check for column wins
        for(int i = 0 ; i < size ; i++){
            x = board[i];
            if(x == '0'){
                break;
            }
            for(int j = 1 ; j < size ; j++){
                if( board[(j*size)+ i] != x){
                    break;
                } else if( j == size-1){
                    return x;
                }
            }
        }

        // Check diagonals
        x = board[0];
        if(x != '0'){
            for(int j = 1 ; j < size ; j++){
                if( board[(j*size)+ j] != x){
                    break;
                } else if( j == size-1){
                    return x;
                }
            }
        }

        x = board[size-1];
        if(x != '0'){
            for(int j = 1 ; j < size ; j--){
                if( board[(j*size)+((size-1)-j)] != x){
                    break;
                } else if( j == size-1){
                    return x;
                }
            }
        }

        // Checks if the board is completed
        for(int i = 0 ; i < size ; i++){
            for(int j = 1 ; j < size ; j++){
                if(board[(i*size)+j] == '0'){
                    return 'n';
                }
            }
        }
        return 't';
    }




	void printBoard(){
		for(int i = 0 ; i < size ; i++){
			if(size == 3){
				cout << "   |   |   " << endl;
				cout <<" "<<board[i*size]<<" | "<<""<<board[(i*size)+1]<<" | "<<""<<board[(i*size)+2]<<"\n";
				if(i == size-1){
					cout << "   |   |   " << endl;
					break;
				} else {
					cout <<"___|___|___"<<"\n";
				}
			} else {
				cout << "   |   |   |   " << endl;
        cout <<" "<<board[i*size]<<" | "<<""<<board[(i*size)+1]<<" | "<<""<<board[(i*size)+2]<<" | "<<""<<board[(i*size)+3] << endl;;
        if(i == size-1){
          cout << "   |   |   |   " << endl;
          break;
        } else {
          cout <<"___|___|___|___"<<"\n";
        }
			}
		}
  }

  char getNumber(int row , int col){
		return board[(row*size)+col];
  }

  void setPos(int row , int col , char c){
    board[(row*size)+col] = c;
  }

  bool isFixed(int row , int col){
		if(board[(row*size)+col] == '0'){
			return false;
    } else {
			return true;
    }
  }

  void clearGrid(){
		for(int i = 0 ; i < size ; i++){
      for(int j = 0 ; j < size ; j++){
				board[(i*size)+j] = '0';
      }
    }
  }

	~Grid(){
		delete board;
	}

  protected:
		char *board;
		int size;
};

class GridGame{

	public:
		Grid grid;

		GridGame(int n) : grid (n) {}

		virtual char getStatus() = 0;

		virtual bool placeMark(int row , int col , char c) = 0;

		virtual void placeMark(char player) = 0;

		void drawGrid() const;

		void restart();	

};

class TicTacToe: public GridGame {

	public:

		TicTacToe() : GridGame(3){}
		
		char getStatus(){
            return grid.isWin();
		/*// returns t for a tie
		// returns x or o for a certian win
		// returns m if the game is not done
		// I switched this up so i return a char not an int. It makes more sense in my head.
		// Check for row wins
			char x;
			for(int i = 0 ; i < 3 ; i++){
				x = grid.getNumber(i , 0);
				if(x == '0'){
					break;
				}
				for(int j = 1 ; j < 3 ; j++){
					if( grid.getNumber(i , j) != x){
						break;
					} else if( j == 2){
						return x;
					}
				}
			}		

			// Check for column wins
			for(int i = 0 ; i < 3 ; i++){
        x = grid.getNumber(0 , i);
				if(x == '0'){
          break;
        }
        for(int j = 1 ; j < 3 ; j++){
          if( grid.getNumber(j , i) != x){
            break;
          } else if( j == 2){
            return x;
          }
        }
      }

			// Check diagonals
			x = grid.getNumber(0 , 0);
			if(x != '0'){
      	for(int j = 1 ; j < 3 ; j++){
       	  if( grid.getNumber(j , j) != x){
          	break;
        	} else if( j == 2){
          	return x;
        	}
      	}
			}

			x = grid.getNumber(0 , 2);
			if(x != '0'){        
 				for(int j = 1 ; j < 3 ; j--){
        	if( grid.getNumber(j , 2-j) != x){
         	  break;
        	} else if( j == 2){
          	return x;
        	}
      	}
			}

			// Checks if the board is completed
			for(int i = 0 ; i < 3 ; i++){
				for(int j = 1 ; j < 3 ; j++){
        	if(grid.getNumber(i , j) == '0'){
						return 'n';
					}
	      }
			}
			return 't';*/
		}

		bool placeMark(int row , int col , char c){
			if(!grid.isFixed(row , col)){
				grid.setPos(row , col , c);
				return true;
			}
			return false;
		}

		void placeMark(char player){

		}

		void drawGrid(){
			grid.printBoard();
		}	

		void restart(){
			grid.clearGrid();
		}

		

};

class NewGame: public GridGame {

	public:

		NewGame() : GridGame(4){}
		
		char getStatus(){
		// returns t for a tie
		// returns x or o for a certian win
		// returns m if the game is not done
		// I switched this up so i return a char not an int. It makes more sense in my head.
		// Check for row wins
			char x;
			for(int i = 0 ; i < 4 ; i++){
				x = grid.getNumber(i , 0);
				if(x == '0'){
					break;
				}
				for(int j = 1 ; j < 4 ; j++){
					if( grid.getNumber(i , j) != x){
						break;
					} else if( j == 3){
						return x;
					}
				}
			}		

			// Check for column wins
			for(int i = 0 ; i < 4 ; i++){
        x = grid.getNumber(0 , i);
				if(x == '0'){
          break;
        }
        for(int j = 1 ; j < 4 ; j++){
          if( grid.getNumber(j , i) != x){
            break;
          } else if( j == 3){
            return x;
          }
        }
      }

			// Check diagonals
			x = grid.getNumber(0 , 0);
			if(x != '0'){
      	for(int j = 1 ; j < 4 ; j++){
       	  if( grid.getNumber(j , j) != x){
          	break;
        	} else if( j == 3){
          	return x;
        	}
      	}
			}

			x = grid.getNumber(0 , 3);
			if(x != '0'){        
 				for(int j = 1 ; j < 4 ; j--){
        	if( grid.getNumber(j , 3-j) != x){
         	  break;
        	} else if( j == 3){
          	return x;
        	}
      	}
			}

			// Checks if the board is completed
			for(int i = 0 ; i < 4 ; i++){
				for(int j = 1 ; j < 4 ; j++){
        	if(grid.getNumber(i , j) == '0'){
						return 'n';
					}
	      }
			}
			return 't';
		}

		bool placeMark(int row , int col , char c){
			if(!grid.isFixed(row , col)){
				grid.setPos(row , col , c);
				return true;
			}
			return false;
		}

		void placeMark(char player){

		}

		void drawGrid(){
			grid.printBoard();
		}	

		void restart(){
			grid.clearGrid();
		}
};

class moves{

};



main(){

	int i;//holds the grid number
	int flag=0;
	while(flag==0){
		cout << "Welcome to Tic-Tac-Toe" << "\n";
		cout << "Please enter a 3 or a 4 for the number of columns:";
		cin >>i;
		if(i==3|i==4){
			flag=1;
		}
		else{
			cout << "\n" << "Please enter 3 or 4" << endl;
		}
	}
	
	//TODO ifstatement
	TicTacToe t1;
	NewGame n1; 
	if(i==3){
		cout << "\n" << "The 3x3 playing board will now be created" << "\n" << "\n";		
		t1.drawGrid();
		

		int playerrow;
		int playercol;
		char input[20];
		while(t1.getStatus()=='n'){
		cout << "Enter the row and column seperated by spaces to move:";
		//cin >> playerrow >> playercol;
		while(!(cin>>playerrow>>playercol)){
			cout << "Please enter integers 0-3 for row and column" << endl;
			cout << "Enter the row and column seperated by spaces to move:";
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			//cin >> playerrow >> playercol;

		}
		
	
		cout <<"\n";
		if((playerrow>2|playercol>2)|(playerrow<=2&playercol>2)|(playerrow>2&playercol<=2)){
			cout << "INVALID ROW AND COLUMN" << endl;
			continue;
		}
		
		if(t1.placeMark(playerrow,playercol,'x')!=true){
			cout << "Spot is taken" << "\n";
			continue;
		}
		
		//TODO pc move
		t1.drawGrid();
		if(t1.getStatus()!='n'){
			if(t1.getStatus()=='t'){
				cout << "TIE GAME" << "\n";
				return(0);
			}
			else if(t1.getStatus()=='x'){
				cout << "HUMAN WINS" << "\n";
				return(0);
			}
			else if(t1.getStatus()=='o'){
				cout << "CPU WINS" << "\n";
				return(0);
			}
		}
		
	}


  return 0;
	}
	else if(i==4){
		cout << "\n" << "The 4x4 playing board will now be created" << "\n" << "\n";
		n1.drawGrid();
		
		
		int playerrow;
	int playercol;
	while(n1.getStatus()=='n'){
		cout << "Enter the row and column seperated by spaces to move:";
		//cin >> playerrow >> playercol;
		while(!(cin>>playerrow>>playercol)){
			cout << "Please enter integers 0-4 for row and column" << endl;
			cout << "Enter the row and column seperated by spaces to move:";
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			//cin >> playerrow >> playercol;

		}


		cout <<"\n";
		if((playerrow>3|playercol>3)|(playerrow<=3&playercol>3)|(playerrow>3&playercol<=3)){
			cout << "INVALID ROW AND COLUMN" << endl;
			continue;
		}
		
		if(n1.placeMark(playerrow,playercol,'x')!=true){
			cout << "Spot is taken" << "\n";
			continue;
		}
		
		//TODO pc move
		n1.drawGrid();
		if(n1.getStatus()!='n'){
			if(n1.getStatus()=='t'){
				cout << "TIE GAME" << "\n";
				return(0);
			}
			else if(n1.getStatus()=='x'){
				cout << "HUMAN WINS" << "\n";
				return(0);
			}
			else if(n1.getStatus()=='o'){
				cout << "CPU WINS" << "\n";
				return(0);
			}
		}
		
	}


  return 0;
	}

	return 0;
}





