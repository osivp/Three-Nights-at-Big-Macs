#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "char_update.c"

//Prints Stats
void print_stats(int *power)
{
    printf("\nPower:%d\n", *power);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//In Cams Code
void cams_state(int *power, time_t *stime, time_t *ctime, int *timer_max, int rooms[17][6], int *cam_num, int *enter, int *edter, int *vent, int *kid_hit, int *generator, int *tank_tick)
{
    char input = '_';

    //Timer
    while (1)
    {
        do
        {
            printf("                                        ._____________.      \n"
                   "                                        |             |      \n"
                   "     MAP LAYOUT                         |             |      \n"
                   "                             ___________|      1      |      \n"
                   "                             |     0    |             |      \n"
                   ".____________________________|___x______|_____x_______|_____.\n"
                   "|     6    |            5           |      2      |         |\n"
                   "|          x                        x             x         |\n"
                   "|__________|________________________|             |    3    |\n"
                   "           |            4           x             |         |\n"
                   ".__________|________________________|             |         |\n"
                   "|     9    x            8           x             |_________|\n"                      
                   "|          |___x____________________|________x____|___.      \n"
                   "|          x   8   |                       |          |      \n"  
                   "|__________|       |                       |     7    |      \n"
                   "           |       |_______________________|          |      \n"
                   "           |       |      14   x    q      x__x_______|      \n"
                   "           |       |           |___________|     |           \n"
                   "           |       x           |___________|     |           \n"
                   "           |       |           x       w         |           \n"
                   "           |_______|___________|_________________|           \n");

                print_stats(power);
               //What cam in

            switch(*cam_num)
            {
                //Reception
                case 1:
                    printf("You are viewing the Reception, Cam 1\n");
                    break;
                //Dinning Area
                case 2:
                    printf("You are viewing the Dinning Area, Cam 2\n");
                    break;
                //Main Stage
                case 3:
                    printf("You are viewing the Main Stage, Cam 3\n");
                    break;
                //Arcade
                case 4:
                    printf("You are viewing the Arcade, Cam 4\n");
                    break;
                //Kitchen
                case 5:
                    printf("You are viewing the Kitchen, Cam 5\n");
                    break;
                //Freezer
                case 6:
                    printf("You are viewing the Freezer, Cam 6\n");
                    break;
                //Play Pen
                case 7:
                    printf("You are viewing the Play Pen, Cam 7\n");
                    break;
                //Hall
                case 8:
                    printf("You are viewing the Hall, Cam 8\n");
                    break;
                //Bathroom
                case 9:
                    printf("You are viewing the Bathroom, Cam 9\n");
                    break;
                //Dumpster
                case 0:
                    printf("You are viewing the Dumpster, Cam 0\n");
                    break;
                //Left Vent
                case 10:
                    printf("You are viewing the Left Vent, Cam q\n");
                    break;
                //Right Vent
                case 11:
                    printf("You are viewing the Right Vent, Cam w\n");
                    break;
            }

            //Print who in room
            for(int i = 0; i < 6; i++)
            {
                switch(i)
                {
                    //Big Mac
                    case 0:
                    if (*cam_num == 8)
                    {
                        if (rooms[8][i])
                            printf("Mr.Big Mac is seen near the bathroom.\n");
                        if (rooms[12][i])
                            printf("Mr.Big Mac is seen near the office door.\n");
                    }
                    else if (rooms[*cam_num][i])
                        printf("Mr.Big Mac is seen in cam.\n");
                    break;
                    //41 Happy
                    case 1:
                    if (*cam_num == 8)
                    {
                        if (rooms[8][i])
                            printf("41 Happy is seen near the bathroom.\n");
                        if (rooms[12][i])
                            printf("41 Happy is seen near the office door.\n");
                    }
                    else if (rooms[*cam_num][i])
                        printf("41 Happy is seen in cam.\n");
                    break;
                    //Weegie
                    case 2:
                    if (*cam_num == 8)
                    {
                        if (rooms[8][i])
                            printf("Weegie is seen near the bathroom.\n");
                        if (rooms[12][i])
                            printf("Weegie is seen near the office door.\n");
                    }
                    else if (rooms[*cam_num][i])
                        printf("Weegie is seen in cam.\n");
                    break;
                    //67 Kid
                    case 3:
                    if (*cam_num == 8)
                    {
                        if (rooms[8][i])
                            printf("67 Kid is seen near the bathroom.\n");
                        if (rooms[12][i])
                            printf("67 Kid is seen near the office door.\n");
                    }
                    else if (rooms[*cam_num][i])
                        printf("67 Kid is seen in cam.\n");
                    break;
                    //Ed
                    case 4:
                    if (rooms[*cam_num][i])
                    {
                        printf("Ed Sheeran is seen in cam.\n");
                    }
                    break;
                    //Tank
                    case 5:
                    if (rooms[*cam_num][i])
                        printf("A Tank is seen in cam.\n");
                    break;
                }
            }

            printf("\n");

            //Choices
            printf("1. View Reception\n");
            printf("2. View Dinning Area\n");
            printf("3. View Main Stage\n");
            printf("4. View Arcade\n");
            printf("5. View Kitchen\n");
            printf("6. View Freezer\n");
            printf("7. View Play Pen\n");
            printf("8. View Hall\n");
            printf("9. View Bathroom\n");
            printf("0. View Dumpster\n");
            printf("q. view Left Vent\n");
            printf("w. View Right Vent\n");
            printf("a. Controlled Shock\n");
            printf("s. Close Cams\n\n");
            
            //Input
            printf(">> ");
            scanf(" %c", &input);

            //cls
            system("cls");

            //Check Input
            switch(input)
            {
                //Cam View
                //Reception
                case '1':
                    *cam_num = 1;
                    break;
                //Dinning Area
                case '2':
                    *cam_num = 2;
                    break;
                //Main Stage
                case '3':
                    *cam_num = 3;
                    break;
                //Arcade
                case '4':
                    *cam_num = 4;
                    break;
                //Kitchen
                case '5':
                    *cam_num = 5;
                    break;
                //Freezer
                case '6':
                    *cam_num = 6;
                    break;
                //Play Pen
                case '7':
                    *cam_num = 7;
                    break;
                //Hall
                case '8':
                    *cam_num = 8;
                    break;
                //Bathroom
                case '9':
                    *cam_num = 9;
                    break;
                //Dumpster
                case '0':
                    *cam_num = 0;
                    break;
                //Left Vent
                case 'q':
                    *cam_num = 10;
                    break;
                //Right Vent
                case 'w':
                    *cam_num = 11;
                    break;
                
                //Shock
                case 'a':
                    if (*power >= 3)
                        {
                            *power -= 3;
                            printf("SHOCK\n");

                            //67 Kid
                            if (rooms[*cam_num][3])
                            {
                                rooms[*cam_num][3] = 0;
                                rooms[0][3] = 1;
                            }
                        }
                        else
                            printf("You don't have enough power\n");
                    break;
                
                //Close Cams
                case 's':
                    return;
                    break;
                case 'm':
                    printf(
                        "                                        ._____________."
                        "                                        |             |"
                        "                                        |             |"
                        "                             ___________|      1      |"
                        "                             |     0    |             |"
                        ".____________________________|___x______|_____x_______|______."
                        "|     6    |            5           |      2      |    3     |"
                        "|         x|                       x|             |          |"
                        "|__________|________________________|             |          |"
                        "           |            4          x|            x|          |"
                        ".__________|________________________|             |          |"
                        "|     9   x|            8          x|             |          |"                      
                        "|          |___x____________________|_____________|__________|"
                        "|          |x  8   |                       | x          x    |"  
                        "|__________|       |                       |        7        |"
                        "           |       |_______________________|                 |"
                        "           |       |      14   |x   10    x|_________________|"
                        "           |       |           |___________|  x  |            "
                        "           |      x|           |___________|     |            "
                        "           |       |           |x      18        |            "
                        "           |___x___|___________|_________________|            "
                        "           |            |                                     "
                        "           |     13     |                                     "
                        "           |            |                                     "
                        "           |____________|                                     "


                    );
                    return;
                    break;
            }

            time(ctime);   // stores current time in currentTime
        }while (*ctime - *stime < *timer_max);

        time(stime);     // stores current time in startTime
        //printf("TIME!\n");
        char_update(1, rooms, enter, edter, vent, kid_hit, generator, tank_tick);

        if (*cam_num == 'q' && rooms[10][4] && *edter > 3)
            *edter = 3;
        else if (*cam_num == 'w' && rooms[11][4] && *edter > 3)
            *edter = 3;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Turned Around Code
void turn_state(int *power, time_t *stime, time_t *ctime, int *timer_max, int *vent, int rooms[17][6], int *enter, int *edter, int *kid_hit, int *generator, int *tank_tick)
{
    char input = '_';

    while (input != 2)
    {
        do
        {
            do
            {
                print_stats(power);
                if (*vent)
                    printf("Right Vent is Closed.\n");
                else
                    printf("Left Vent is Closed\n");
                
                //Choices
                printf("1. Switch Closed Vent\n");
                printf("s. Turn Back Around\n");

                //Input
                printf(">> ");
                scanf("%c", &input);

                //cls
                system("cls");
                    
                //Check Input
                switch(input)
                {
                    case '1':
                        if (*vent == 1)
                            *vent = 0;
                        else
                            *vent = 1;
                        break;
                    case 's':
                        return;
                        break;
                }
            }while (input < 1 || input > 2);

            time(ctime);   // stores current time in currentTime
        }while (*ctime - *stime < *timer_max && input != 2);

        time(stime);     // stores current time in startTime
        printf("TIME!\n");
        char_update(1, rooms, enter, edter, vent, kid_hit, generator, tank_tick);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Gaemplay
int main_gameplay()
{
    //Vars
    int input = 0;          //Input
    int power_max = 10;     //Max Power
    int power = 5;          //Power
    int generator = 1;      //Generator State
    int vent = 0;           //Which vent is shut, 0 Left, 1 Right
    int cam_num = 3;        //What cam on
    int enter = 2;          //How much longer till Big Mac enter the office
    int edter = 7;          //How much longer till Ed enter the office
    int kid_hit = 12;       //How long till 67 Kid strikes
    int tank_tick = 5;      //How long between tank attacks

    //Room Array
    int rooms[17][6] = {0};

    //Character Setting
    rooms[3][0] = 1;   //Main Stage | 0 Big Mac
    rooms[4][1] = 1;   //Arcade     | 1 41 Happy
    rooms[16][2] = 1;  //Outside    | 2 Weegie
    rooms[0][3] = 1;   //Dumpster   | 67 kid
    rooms[7][4] = 1;   //Play Pen   | 4 Ed
    rooms[6][5] = 1;   //Freezer    | 5 Ice Cream Truck (TANK)


    //Player Vars
    int pState = 0;     //Player State
    /*
    0 = Facing Door
    1 = Facing Vents
    2 = In Cams
    */
    int alive = 1;      //Player Alive

    //Timer
    int timer_max = 2;      //Timer Reset Time
    time_t stime, ctime;    //Start Time | Current Time
    
    time(&stime);     // stores current time in startTime

    //Gameplay
    while(alive)
    {
        //Timer
        do
        {
            //Check if Alive
            for(int i = 0; i < 5; i++)
            {
                switch(i)
                {
                    //Big Mac
                    case 0:
                        if (rooms[14][0])
                        {
                            alive = 0;
                            printf("Big Mac Got You!\n");
                        }
                    break;

                    //41 Happy
                    case 1:
                        if (rooms[14][1])
                        {
                            alive = 0;
                            printf("41 Happy Got You!\n");
                        }
                    break;

                    //67 Kid
                    case 3:
                        if (rooms[14][3])
                        {
                            alive = 0;
                            printf("67 Kid Got You!\n");
                        }
                    break;

                    //Ed Sheeran
                    case 4:
                        if (rooms[14][4])
                        {
                            alive = 0;
                            printf("Ed Sheeran Got You!\n");
                        }
                    break;
                }
            }

            if (rooms[15][0] == 0)
                enter = 2;

            if (alive == 0)
                return 0;

            //Input
            do
            {
                print_stats(&power);
                //Choices
                printf("1. Charge Battery\n");
                printf("2. Active Lasers\n");
                printf("3. Cams\n");
                printf("4. Turn Around\n");
                printf("5. Repair Generator\n");

                //Input
                printf(">> ");
                scanf("%d", &input);

                //cls
                system("cls");

                //Check Input
                switch(input)
                {
                    //Charge Power
                    case 1:
                        if (generator)
                        {
                            if (power < power_max)
                            {
                                power += 1;
                                stime -= 1;         //Causes power to take 1 second
                            }
                            else
                                printf("Power is full\n");
                        }
                        else
                            printf("The generator is broken\n");
                        break;
                    
                    //Activate Lasers
                    case 2:
                        if (power >= 2)
                        {
                            power -= 2;

                            //Weegie
                            if (rooms[15][2])
                            {
                                printf("Weegie Got U\n");
                                alive = 0;
                            }
                            //Big Mac
                            else if (rooms[15][0])
                            {
                                rooms[15][0] = 0;
                                rooms[2][0] = 1;
                                printf("SOUNDS\n");
                            }
                        }
                        else
                            printf("You don't have enough power\n");
                        break;
                    
                    //Cams
                    case 3:
                        cams_state(&power, &stime, &ctime, &timer_max, rooms, &cam_num, &enter, &edter, &vent, &kid_hit, &generator, &tank_tick);
                        break;
                    //Turn Around
                    case 4:
                        turn_state(&power, &stime, &ctime, &timer_max, &vent, rooms, &enter, &edter, &kid_hit, &generator, &tank_tick);
                        break;
                    //Repair Gen
                    case 5:
                        if (generator)
                            printf("Generator already works\n");
                        else
                        {
                            printf("Generator fixed\n");
                            generator = 1;
                            stime -= 2;         //Causes power to take 2 second
                        }
                        break;
                    }
            }while (input < 1 || input > 5);

            time(&ctime);   // stores current time in currentTime
        }while (ctime - stime < timer_max);

        time(&stime);     // stores current time in startTime
        printf("TIME!\n");
        char_update(1, rooms, &enter, &edter, &vent, &kid_hit, &generator, &tank_tick);
    }

    return 0;
}