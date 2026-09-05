#include "iostream"


//functions prototypes
int Main_Menu(char);

void Enemy_AI(int);

void START(void);


void QUIT(void);


// Global Variables
int My_point = 0;
int Enemy_point = 0;



// main code
int main (void){
    
    char user_choice;

    std::cout << "Welcome to my Rock Paper Scissor game! \n";
    std::cout << "'s/S' : To Start the game \n'q/Q' : To Quit the game \n Enter your choice: ";
    
  
    while(1){
    std::cin >> user_choice;

    int choice_result = Main_Menu(user_choice);

    if (choice_result == 1){
        void START(void);
        break;

    
    }
    else if (choice_result == 2){
        void QUIT(void);
        
        break;


    }
    else if (choice_result == 3){
        
        void QUIT(void);
        break;
    }
    else{

        break;
    }

    }
    


    return 0;

}


// functions defintions
int Main_Menu(char user_choice){

    if (user_choice == 's' || user_choice == 'S'){
        std::cout << "START GAME \n";

        return 1;


    }
    else if (user_choice == 'q' || user_choice == 'Q'){
        std::cout << "QUIT GAME\n";
        return 2;


    }
    else{
        std::cout << "Invalid Input!, game will now quit \n";
        std::cout << "QUIT GAME\n";
        return 3;

    }
    return 0;
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