#include <stdio.h>
#include "main_gameplay_win.c"
#include <unistd.h>
void main_menu()
{
    //NESTED FUNCTIONS
    //How to play loading
    void how_play()
    {
        //How to play text  *TEMP*
        printf("Blah\n\n");
        printf("How To Play\n");
        printf("This game is pretty self explanatory, you navigate with number keys and letter keys a,s,w,q. You have to attempt to beat the game by checking cams and using your actions efficently. It is reccomended to charge your battery before you start actually playing. - Danielle Rosanne (brianjgriffin09@yahoo.com for questions!\n\n");
        //Return to Main Menu
        int temp;

        printf("1. Return to Main Menu\n>> ");
        scanf("%d", &temp);
        system("cls");

        main_menu();
    }

    //Save Code Inputing
    void save_code()
    {
        int input = 0;
        do
        {
            //Instructions
            printf("Input a save code that you get at the end of the night (4 Numbers)\n");

            //Input
            printf("Type 1 to Return to Main Menu\n>> ");
            scanf("%d", &input);
            system("cls");

            //Check if code is valid
            switch(input)
            {
                case 6967:
                    printf("HI\n");
                    break;
                case 7274:
                    printf("BT!\n");
                    break;
                default:
                    system("cls");
                    break;
            }
        }while (input != 1);

        main_menu();
    }
    

    //Prints Main Menu title and options
    printf("Three Nights At Big Macs (Placeholder title text)\n\n"); //placeholder as windows is dogshit when it comes to ascii text. :P

    //printf("▄▄▄█████▓ ██░ ██  ██▀███  ▓█████ ▓█████                               \n"
    //       "▓  ██▒ ▓▒▓██░ ██▒▓██ ▒ ██▒▓█   ▀ ▓█   ▀                               \n"
    //       "▒ ▓██░ ▒░▒██▀▀██░▓██ ░▄█ ▒▒███   ▒███                                 \n"
    //       "░ ▓██▓ ░ ░▓█ ░██ ▒██▀▀█▄  ▒▓█  ▄ ▒▓█  ▄                               \n"
    //       "  ▒██▒ ░ ░▓█▒░██▓░██▓ ▒██▒░▒████▒░▒████▒                              \n"
    //       "▒ ░░    ▒ ░░▒░▒░ ▒▓ ░▒▓░░░ ▒░ ░░░ ▒░ ░                              \n"
    //       "    ░     ▒ ░▒░ ░  ░▒ ░ ▒░ ░ ░  ░ ░ ░  ░                              \n"
    //       "░       ░  ░░ ░  ░░   ░    ░      ░                                 \n"
    //       "        ░  ░  ░   ░        ░  ░   ░  ░                              \n"
    //       "                                                                    \n"
    //       " ███▄    █  ██▓  ▄████  ██░ ██ ▄▄▄█████▓  ██████     ▄▄▄     ▄▄▄█████▓\n"
    //       " ██ ▀█   █ ▓██▒ ██▒ ▀█▒▓██░ ██▒▓  ██▒ ▓▒▒██    ▒    ▒████▄   ▓  ██▒ ▓▒\n"
    //       "▓██  ▀█ ██▒▒██▒▒██░▄▄▄░▒██▀▀██░▒ ▓██░ ▒░░ ▓██▄      ▒██  ▀█▄ ▒ ▓██░ ▒░\n"
    //       "▓██▒  ▐▌██▒░██░░▓█  ██▓░▓█ ░██ ░ ▓██▓ ░   ▒   ██▒   ░██▄▄▄▄██░ ▓██▓ ░ \n"
    //       "▒██░   ▓██░░██░░▒▓███▀▒░▓█▒░██▓  ▒██▒ ░ ▒██████▒▒    ▓█   ▓██▒ ▒██▒ ░ \n"
    //       "░ ▒░   ▒ ▒ ░▓   ░▒   ▒  ▒ ░░▒░▒  ▒ ░░   ▒ ▒▓▒ ▒ ░    ▒▒   ▓▒█░ ▒ ░░   \n"
    //       "░ ░░   ░ ▒░ ▒ ░  ░   ░  ▒ ░▒░ ░    ░    ░ ░▒  ░ ░     ▒   ▒▒ ░   ░    \n"
    //       "░   ░ ░  ▒ ░░ ░   ░  ░  ░░ ░  ░      ░  ░  ░       ░   ▒    ░      \n"
    //       "        ░  ░        ░  ░  ░  ░               ░           ░  ░        \n"
    //       "                                                                    \n"
    //       " ▄▄▄▄    ██▓  ▄████     ███▄ ▄███▓ ▄▄▄       ▄████▄    ██████         \n"
    //       "▓█████▄ ▓██▒ ██▒ ▀█▒   ▓██▒▀█▀ ██▒▒████▄    ▒██▀ ▀█  ▒██    ▒         \n"
    //       "▒██▒ ▄██▒██▒▒██░▄▄▄░   ▓██    ▓██░▒██  ▀█▄  ▒▓█    ▄ ░ ▓██▄           \n"
    //       "▒██░█▀  ░██░░▓█  ██▓   ▒██    ▒██ ░██▄▄▄▄██ ▒▓▓▄ ▄██▒  ▒   ██▒        \n"
    //       "░▓█  ▀█▓░██░░▒▓███▀▒   ▒██▒   ░██▒ ▓█   ▓██▒▒ ▓███▀ ░▒██████▒▒        \n"
    //       "░▒▓███▀▒░▓   ░▒   ▒    ░ ▒░   ░  ░ ▒▒   ▓▒█░░ ░▒ ▒  ░▒ ▒▓▒ ▒ ░        \n"
    //       "▒░▒   ░  ▒ ░  ░   ░    ░  ░      ░  ▒   ▒▒ ░  ░  ▒   ░ ░▒  ░ ░        \n"
    //       "░    ░  ▒ ░░ ░   ░    ░      ░     ░   ▒   ░        ░  ░  ░          \n"
    //       "░       ░        ░           ░         ░  ░░ ░            ░          \n"
    //       "    ░                                     ░                         \n\n");
    
    printf("1. New Game\n");
    printf("2. Input Save Code\n");
    printf("3. How To Play\n");
    printf("4. Quit\n");
    printf("5. Credits\n");


    int input;

    //Checks for the input in the main menu
    do
    {
        printf(">> ");
        scanf("%d", &input);
    }while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5); //you have to add a few extra things like a input and a != operator with the number or else it wont work smh- I shouldve thought. Lol.

    //Decrypts menu input
    switch(input)
    {
        case 1:
            system("cls");
            main_gameplay();
            break;
        case 2:
            system("cls");
            save_code();
            break;
        case 3:
            system("cls");
            how_play();
            break;
        case 4:
            system("cls");
            exit(1);
            break;
        case 5:
            system("clear");
            printf("Built by a team of hardworking individuals.\n");
            printf("Locke, Oliver, Nathan, and Danielle.\n");
            sleep(10);
            system("clear");
            main_menu();
            break;
    }
    return;
}
