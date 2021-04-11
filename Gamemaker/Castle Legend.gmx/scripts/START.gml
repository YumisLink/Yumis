globalvar map_show,map_health,map_mana,map_attack,map_defense,map_name,hero,hero_mana;
globalvar move_use_x_first,move_use_x_second,move_use_y_first,move_use_y_second;
move_use_x_first[1] = -1; move_use_x_first[2] = -1; move_use_x_first[3] = 0; move_use_x_first[4] = 1; move_use_x_first[5] = 0; move_use_x_first[6] = -1;
move_use_y_first[1] = 0; move_use_y_first[2] = -1; move_use_y_first[3] = -1; move_use_y_first[4] = 0; move_use_y_first[5] = 1; move_use_y_first[6] = 1;
move_use_x_second[1] = -1; move_use_x_second[2] = 0; move_use_x_second[3] = 1; move_use_x_second[4] = 1; move_use_x_second[5] = 1; move_use_x_second[6] = 0;
move_use_y_second[1] = 0; move_use_y_second[2] = -1; move_use_y_second[3] = -1; move_use_y_second[4] = 0; move_use_y_second[5] = 1; move_use_y_second[6] = 1;
hero[1] = "Cyan";
hero_mana[1] = 5;
var i,j;
for (i = 1; i <= 13; i ++)
    for (j = 1; j <= 9; j ++){
        map_show[i,j] = spr_null;
        map_health[i,j] = 0;
        map_mana[i,j] = 0;
        map_attack[i,j] = 0;
        map_defense[i,j] = 0;
        map_visited[i,j] = false;
        map_name[i,j] = "none";
    }
