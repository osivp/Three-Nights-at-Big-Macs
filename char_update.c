#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen_random()
{
    //Int Rand Seed
    srand(time(0));
    return (rand() % 20) + 1;
}

void change_room(int character, int rooms[17][6], int *enter)
{
    //Check rooms for character
    int c_room = 0;
    for(int i = 0; i < 17; i++)
    {
        if (rooms[i][character] == 1)
        {
            c_room = i;     //Current Room
            break;
        }
    }

    int n_room = gen_random();      //Next Room Random Number (If multiple options)

    //Check and move to different room
    switch(c_room)
    {
        //Reception
        case 1:
            rooms[c_room][character] = 0;

            rooms[2][character] = 1;
            break;
        //Dinning Area
        case 2:
            rooms[c_room][character] = 0;

            if (n_room > 12)
                rooms[4][character] = 1;
            else if (n_room > 8)
                rooms[5][character] = 1;
            else if (n_room > 3)
                rooms[8][character] = 1;
            else
                rooms[3][character] = 1;
            break;
        //Kitchen
        case 5:
            rooms[c_room][character] = 0;

            if (n_room > 14)
                rooms[6][character] = 1;
            else
                rooms[2][character] = 1;
            break;
        //Arcade
        case 4:
            rooms[c_room][character] = 0;

            if (n_room > 14)
                rooms[2][character] = 1;
            else
                rooms[8][character] = 1;
            break;
        //Bathroom Hall
        case 8:
            rooms[c_room][character] = 0;

            if (n_room > 10)
                rooms[12][character] = 1;
            else if (n_room > 8)
                rooms[2][character] = 1;
            else
                rooms[9][character] = 1;
            break;
        //Bathroom
        case 9:
            rooms[c_room][character] = 0;

            rooms[8][character] = 1;
            break;
        //Office Hall
        case 12:
            rooms[c_room][character] = 0;

            if (n_room > 1)
                rooms[15][character] = 1;
            else
                rooms[8][character] = 1;
            break;
        
        //Skip 13 Gen Room
        //Skip 14 Office
        //Skip 7 Play Pen
        //Skip 10 & 11 Vents

        //Main Stage
        case 3:
            rooms[c_room][character] = 0;

            rooms[2][character] = 1;
            break;
        //Freezer
        case 6:
            rooms[c_room][character] = 0;

            rooms[5][character] = 1;
            break;
        
        //Skip 0 Dumpster

        //Office Entrence
        case 15:
            if (*enter <= 0)
            {
                rooms[c_room][character] = 0;
                rooms[14][character] = 1;
            }
            else
                *enter -= 1;
            break;
        
        //Outside
        case 16:
            rooms[c_room][character] = 0;

            rooms[1][character] = 1;
            break;
    }
}

void ed_update(int rooms[17][6], int tick, int *edter, int *vent)
{
    //If activated for move
    if (rooms[7][4] && tick == 0)
    {
        rooms[7][4] = 0;

        if (gen_random() > 10)
            rooms[10][4] = 1;
        else
            rooms[11][4] = 1;

        *edter = 7;
    }
    //If able to enter
    else if (*edter <= 0 && rooms[7][4] == 0)
    {
        if (rooms[10][4] && *vent == 0)
            rooms[7][4] = 1;
        else if (rooms[11][4] && *vent)
            rooms[7][4] = 1;
        else
            rooms[14][4] = 1;

        rooms[10][4] = 0;
        rooms[11][4] = 0;
    }
    //Tick down for entering office
    else if (tick)
        *edter -= 1;
}

void k67_update(int rooms[17][6], int *kid_hit, int tick)
{
    //If activated for move
    if (rooms[0][3] && tick == 0)
    {
        int i = 1;
        int rng;

        while (i)
        {
            rng = gen_random();
            if (rng > 12 || rng == 7 || rng == 10 || rng == 11)
                break;
            else
            {
                rooms[0][3] = 0;
                rooms[rng][3] = 1;
                *kid_hit = 12;
                i = 0;
            }
        }
    }
    //If attack
    else if (*kid_hit <= 0 && rooms[0][3] == 0)
    {
        for(int i = 0; i <= 12; i++)
        {
            rooms[i][3] = 0;
        }
        rooms[14][3] = 1;
    }
    //Tick down for attack
    else if (tick)
        *kid_hit -= 1;
}

void tank_update(int *generator, int *tank_tick, int tick)
{
    //If generator works
    if (*generator)
    {
        //Cooldown tick
        if (tick)
            *tank_tick -= 1;
        //If activated for action
        else if (*tank_tick <= 0 && tick == 0)
        {
            *generator = 0;
            *tank_tick = 5;
            printf("*BOOM*\n");
        }
    }

}

//Update characters with given chance
int update(int rooms[17][6], int *enter, int *edter, int *vent, int *kid_hit, int *generator, int *tank_tick, int bm, int we, int ed, int ki, int ta)
{
    //Big Mac
    if (gen_random() <= bm)
    {
        change_room(0, rooms, enter);
    }

    //Weegie
    if (gen_random() <= we && rooms[14][2] == 0)
    {
        change_room(2, rooms, enter);
    }

    if (rooms[14][2])
    {
        rooms[14][2] = 0;
        rooms[5][2] = 1;
    }

    //Ed
    if (gen_random() <= ed)
    {
        ed_update(rooms, 0, edter, vent);
    }

    ed_update(rooms, 1, edter, vent);

    //67 Kid
    if (gen_random() <= ki)
    {
        k67_update(rooms, kid_hit, 0);
    }

    k67_update(rooms, kid_hit, 1);

    //Tank
    if (gen_random() <= ta)
    {
        tank_update(generator, tank_tick, 0);
    }

    tank_update(generator, tank_tick, 1);
}

void char_update(int night, int rooms[17][6], int *enter, int *edter, int *vent, int *kid_hit, int *generator, int *tank_tick)
{
    /*
    Character Number:
    0 Big Mac | Night 1,2,3
    1 41 Happy | Night 2,3
    2 Weegie | Night 1,2,3
    3 67 Kid | Night 1,2,3
    4 Ed Sheeran | Night 1,2,3
    5 Ice Cream Truck (TANK) | Night 2,3

    update(MISC, BIGMAC, WEEGIE, ED, 67KID, TANK )
    */

    //NIGHT 1
    if (night == 1)
    {
        if (generator)
            update(rooms, enter, edter, vent, kid_hit, generator, tank_tick, 12, 8, 3, 4, 4);
        else
            update(rooms, enter, edter, vent, kid_hit, generator, tank_tick, 15, 10, 4, 5, 4);
    }
    //Night 2
    else if (night == 2)
    {
        printf("temp\n");
    }
}