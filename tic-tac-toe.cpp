#include <iostream>
#include<ctime>

void drawBoard(char *spaces);
void playerTurn(char *spaces,char player);
void computerTurn(char *spaces,char computer);
bool checkWinner(char *spaces,char computer ,char player);
int main(){

char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};

char player ='X';
char computer = 'O';
bool running = true;

drawBoard(spaces);

while(running){
    
    playerTurn(spaces,player);
    


    computerTurn(spaces,computer);
    drawBoard(spaces);
    if(checkWinner(spaces,computer,player)){
        std::cout<<"Thanks for playing";
         break;
         running = false;
    }
   
}


  return 0;

}
void drawBoard(char *spaces){
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<"   "<<spaces[0]<<"  |   "<<spaces[1]<<"  |  "<<spaces[2]<<"  \n";
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<" -----|---"<<"---|-----\n";
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<"   "<<spaces[3]<<"  |   "<<spaces[4]<<"  |  "<<spaces[5]<<"  \n";
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<" -----|---"<<"---|-----\n";
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<"   "<<spaces[6]<<"  |   "<<spaces[7]<<"  |  "<<spaces[8]<<"  \n";
    std::cout<<"      |   "<<"   |     \n";
    std::cout<<"\n\n";
    
}
void playerTurn(char *spaces,char player){

   
   int number;

   do{
    std::cout<<"Enter your input from (1-9)\n";
    std::cin>>number;
    number--;
    if(spaces[number]==' '){
        spaces[number]=player;
        break;
        }

   }while(!number >0 || !number <8);

}
void computerTurn(char *spaces,char computer){
   
   
    srand(time(0));
   

      while(true){
        int number = rand() % 9;

        if (spaces[number] == ' '){
          spaces[number] = computer;
          break;
          }
     
   }
   


   
}
bool checkWinner(char *spaces ,char computer ,char player){
      if(spaces[0] != ' ' && spaces[0]==spaces[1] && spaces[1]==spaces[2] ){
           (spaces[0]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[3] != ' ' && spaces[3]==spaces[4] && spaces[4]==spaces[5] ){
           (spaces[3]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[6] != ' ' && spaces[6]==spaces[7] && spaces[7]==spaces[8] ){
           (spaces[6]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[0] != ' ' && spaces[0]==spaces[3] && spaces[3]==spaces[6] ){
           (spaces[0]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[1] != ' ' && spaces[1]==spaces[4] && spaces[4]==spaces[7] ){
           (spaces[1]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[2] != ' ' && spaces[2]==spaces[5] && spaces[5]==spaces[8] ){
           (spaces[2]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[0] != ' ' && spaces[0]==spaces[4] && spaces[4]==spaces[8] ){
           (spaces[0]==player)?std::cout<<"You win!":std::cout<<"You Lost!";
      }
      else if(spaces[2] != ' ' && spaces[2]==spaces[4] && spaces[4]==spaces[6] ){
           (spaces[2]==player)?std::cout<<"You win!":std::cout<<"You Lost!";

      }
      else{
           return false;
      }
return true;

}


