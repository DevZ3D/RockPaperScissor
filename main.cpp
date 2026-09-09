#include "iostream"
#include <cctype>
#include <random>

 // useful link : https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c


using u32 = uint_least32_t;
using engine = std::mt19937;




//functions prototypes

char enemy_bot(u32);
char player_one(void);
char player_two(void);

void QUIT(void);

void game_mode_selection();
char process_player_input(int);
bool game_repeat_process(void);
void game_process(int mode);


// main code
int main (void){
     
    char user_choice;

    std::cout << "Welcome to my Rock Paper Scissor game! \n";
    
    do{

        std::cout << "'s/S' : To Start the game \n'q/Q' : To Quit the game \n Enter your choice: ";
        std::cin >> user_choice;
        
        if (user_choice == 'S' || user_choice == 's'){

            game_mode_selection();
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



void game_mode_selection(){
    
    int user_choice; 
    

    do  {
        
        std::cout <<" select 1 to play agisnt player two or select 2 to playe agisnt bot \n or select 3 to go back to menu!\n";
        std::cin >> user_choice;

        if(user_choice == 1){
             game_process(1);
        }

        else if (user_choice == 2){  
            game_process(2);
        }
           
        else if (user_choice == 3){  
            break;  
        }

        else { 
            std::cout << "invalid input \n";  
            std::cout << "pls try again!";
        }

        } while((user_choice != 1) || (user_choice != 2)|| (user_choice != 3));

}



char process_player_input(int player){

  int  choice = 0;
    
    while(1){

         std::cout << "Select your move player"<< player << "\n Enter: \n 1 for Rock \n 2 for paper \n 3 for Scissors \n:";
         std::cin >> choice;
       
        if(choice == 1){
            return 'R';
            break;
        }
    
        else if(choice == 2){
            return 'P';
            break;
        }
        
        else if(choice == 3){
            return 'S';
            break;
        }

        else{
            std::cout << "invalid input, Please try again" << player << "\n";
        }
    }
    return choice;
}



char player_one(void){
    char player_one_choice = process_player_input(1);
    return player_one_choice;
}


char player_two(void){
    char player_one_choice = process_player_input(2);
    return player_one_choice;
}




char enemy_bot(u32 seed){

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



bool game_repeat_process(void){
    bool choice_repeat;

   do {
        std::cin >> choice_repeat;
        
        if  (choice_repeat == true ){
            break;
        }
        else if( choice_repeat == false ) {
            break;
        }
        else{
            std::cout <<"not valid! pls try agian!\n";
        }

    } while((choice_repeat != true) || (choice_repeat != false));

    return choice_repeat;
}


void game_process(int mode){

    bool game_repeat = true;
      do{
             // init 
        std::random_device os_seed;
        const u32 seed = os_seed();

        char player_one_choice;
        char player_two_choice;
        
        int player_one_points = 0;
        int player_two_points = 0;
        


        do{ 
            if (mode == 1){
                player_one_choice = player_one();
                player_two_choice = player_two();
            }
            else if (mode == 2){
                player_one_choice = player_one();
                player_two_choice = enemy_bot(seed);
                //std::cout << " Enmey bot selected vakue: " << value << std::endl;
                }
            
            if (player_one_choice == player_two_choice){
                std::cout << "Draw\n";
                std::cout << "no point";
            }
            else if (player_one_choice == 'R' && player_two_choice == 'S'){
                std::cout <<"player one wins \n";
                player_one_points++;
            } 
            else if (player_one_choice == 'P' && player_two_choice == 'R'){
                std::cout <<"player one wins \n";
                player_one_points++;
            }
            else if (player_one_choice == 'S' && player_two_choice == 'P'){
                std::cout <<"player one wins \n";
                player_one_points++;
            }
            else{
                std::cout <<"player two wins \n";
                player_two_points++;
            }
            } while((player_one_points <= 3) || (player_two_points <= 3));
 
            if (player_one_points >= 3 ){
                 std::cout << "player One wins! \n";
                 game_repeat = game_repeat_process();

            }
            else{
                 std::cout << "player Two wins! \n";
                 game_repeat = game_repeat_process();
            }

         } while(game_repeat  != false);
}




void QUIT(void){
std::cout << "Quit \n";

}
