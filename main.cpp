#include "iostream"


//functions prototypes
void Main_Menu(char);

void Enemy_AI(int);

void START(void);

void QUIT(void);

void Test(void);

// Global Variables
int My_point = 0;
int Enemy_point = 0;



// main code
int main (void){
    
    char user_choice;

    std::cout << "Welcome to my Rock Paper Scissor game! \n";
    std::cout << "'s/S' : To Start the game \n'q/Q' : To Quit the game \n Enter your choice: ";
    
  
    std::cin >> user_choice;

    Main_Menu(user_choice);

    return 0;

}


// functions defintions
void Main_Menu(char user_choice){

    if (user_choice == 's' || user_choice == 'S'){
        std::cout << "START GAME \n";



    }
    else if (user_choice == 'q' || user_choice == 'Q'){
        std::cout << "QUIT GAME\n";

    }
    else{
        std::cout << "Invalid Input!, game will now quit \n";
        std::cout << "QUIT GAME\n";

    }
}



void Enemy_AI(int){

std::cout << "ENEMY testing \n";

}


void START(void){

std::cout << "Start  \n";

}

void QUIT(void){
std::cout << "Quit \n";

}