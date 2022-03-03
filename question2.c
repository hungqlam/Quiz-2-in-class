#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 100
int randomNumber(int max);

struct gameHistory
{
    int game_count ; 
    int game_win ; 
    int game_lose ;
    int totalGuess ;

};

int main() {
  
  int choice; 
   //Initial The game
        int a = 0; 
        int max ;
        char quit;
        int result=1;
        int checker = 0;
        struct gameHistory arr_game[Max];
        int step = 0;
        int win = 0;
        int lose =0;
        //persist data STEP 
        FILE *fptr;
        fptr = fopen("C:/Users/notic/git/restaurantBill/restaurantBill.c/save_user_max_number.txt","r");
        fscanf(fptr,"%d", &max);
        fclose(fptr);
        int count=0;
        arr_game[count].game_count = 0;
        arr_game[count].game_win = 0;
        arr_game[count].game_lose = 0;
        arr_game[count].totalGuess = 0;
  do
  {
      /* code */
      printf("Press 1 to play a game.\nPress 2 to change the max number.\nPress 3 to quit.\n");
      scanf("%d",&choice);
    if(choice == 1)
    {
       

        
        do
        {
            result = randomNumber(max);
            while (quit!='q')
            {
                
                printf("Enter your number: ");
                scanf("%d",&a);
                arr_game[count].game_count=count+1;

                if(a>result)
                {
                    printf("Your value is higher than  value of the result\n");
                    step = step+1;
                    arr_game[count].totalGuess=step;
                }

                if(a<result)
                {
                     printf("Your value is smaller than  value of the result\n");
                     step = step +1;
                     arr_game[count].totalGuess=step;
                }
               
                if(a == result)
                {
                    printf("Your answer is correct!\n");
                    step = step+1;
                    arr_game[count].totalGuess=step;
                    win = win+1;
                    arr_game[count].game_win=win;
                    quit ='q'; // set for quit game after guess correct
                    checker = 1;
                    count=count+1;
                }
                else {
                    printf("Do you want to quit the game ? type q\n");
                    scanf("%c",&quit);
                    if(quit=='q')
                    {
                        checker = 1;
                        lose = lose +1;
                        arr_game[count].game_lose=lose;
                        count=count + 1;
                    }
                }

                
            }
            
            


            
        } while (!checker);

       
        
        //Code for save result of the game
    };

     if(checker ==1) // reinistial the game so if the player want to replay again after quit game
        {
                 a = 0; 
                 max = 10;
                quit='0';
                result=1;
                checker = 0;
                lose = 0 ;
                win = 0;
                step = 0;
        }


        if(choice == 2)
        {
            int flag = 0;
            fptr = fopen("C:/Users/notic/git/restaurantBill/restaurantBill.c/save_user_max_number.txt","r");
            fscanf(fptr,"%d", &max);
            fclose(fptr);
            printf("Current max value is: %d" , max);

            do
            {
                printf("\nEnter your max value you want to set for the game: ");
                scanf("%d",&max);
                if(max<0)
                {
                    printf("You entered the negative number!!\n");
                }
                if(max>10)
                {
                    printf("You entered the number greater than 10!!\n");
                }

                if(max>0 && max <=10)
                {
                    fptr = fopen("C:/Users/notic/git/restaurantBill/restaurantBill.c/save_user_max_number.txt","w");
                    fprintf(fptr,"%d",max);
                    fclose(fptr);

                    flag = 1; 
                }

                
            } while (!flag);
            
        }
    
    
    




  } while (choice != 3);
  

        if(choice == 3)
        {
            printf("Thank for playing this game!!");
            printf("History of all game:\n");
            for( int i = 0; i<=count ; i++)
            {
                printf("Game No %d : ",i+1);
                printf("\n Win: %d", arr_game[i].game_win);
                printf("\n Lose: %d", arr_game[i].game_lose);
                printf("\n Step to end game: %d\n", arr_game[i].totalGuess);
            }
        }


  

  
  
  
  
  
  
    
  return 0;

}

 int randomNumber(int max)
 {
     int lower = 1, upper = max;
     srand(time(0));
     int num = (rand() % (upper - lower + 1)) + lower;
     return num;

 }