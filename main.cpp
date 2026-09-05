#include "iostream"
#include <cctype>
#include <random>

 // useful link : https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c


using u32 = uint_least32_t;
using engine = std::mt19937;


// Global Variables
int My_point = 0;
int Enemy_point = 0;



//functions prototypes

char Enemy_bot(u32);
char Player_one(void);
void QUIT(void);


// main code
int main (void){
     
    // init 
    std::random_device os_seed;
    const u32 seed = os_seed();

    char user_choice;

    std::cout << "Welcome to my Rock Paper Scissor game! \n";
    
    do{

        std::cout << "'s/S' : To Start the game \n'q/Q' : To Quit the game \n Enter your choice: ";
        std::cin >> user_choice;
        
        if (user_choice == 'S' || user_choice == 's'){

            char player_choice = Player_one();
            char enemy_choice = Enemy_bot(seed);
            //std::cout << " Enmey bot selected vakue: " << value << std::endl;

            if (player_choice ==  enemy_choice ){
                std:: cout << "Draw\n";
            }
            else if (player_choice == 'R' && enemy_choice == 'S'){
                std::cout << "player wins \n";
            }
            else if (player_choice == 'P' && enemy_choice == 'R'){
                std::cout << "player wins \n";
            }
            else if (player_choice == 'S' && enemy_choice == 'P'){
                std::cout << "player wins \n";
            }
            else{
                std::cout << "enemy wins \n";
            }
        }
    
        else if (user_choice == 'Q' || user_choice == 'q'){
            QUIT();
            break;
        }

        else{
            std::cout << "invalid input\n";
            std::cout << "please try again\n";

        }
    }while(user_choice != 'Q' || user_choice != 'q');
    
 return 0;
}




char Enemy_bot(u32 seed){

    int enemy_choice = 0;

    std::cout << "ENEMY testing \n";
    engine generator (seed);
    
    std::uniform_int_distribution<u32> distribute(1,3);    
    
   // for( int repetition = 0; repetition < 5; ++repetition )
    //std::cout << distribute( generator ) << std::endl;

    enemy_choice = distribute( generator );

    if(enemy_choice == 1){
        return 'R';
    }
    else if (enemy_choice == 2){
        return 'P';
    }
    else if (enemy_choice == 3){
        return 'S';
    }
    else{
    return 'R';
    }
}


char Player_one(void){
    int  choice = 0;
    
    while(1){

         std::cout << "Select your move\n Enter: \n 1 for Rock \n 2 for paper \n 3 for Scissors \n:";
         std::cin >> choice;
       
        if(choice == 1){
            return 'R';
            break;
        }
    
        else if(choice ==2){
            return 'P';
            break;
        }
        
        else if(choice == 3){
            return 'S';
            break;
        }

        else{
            std::cout << "invalid input, Please try again \n";
        }
    }
}

void QUIT(void){
std::cout << "Quit \n";

}