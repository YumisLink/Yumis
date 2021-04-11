if (!argument5){
    pos = -((argument3 / 100) * sprite_get_height(argument4)) + sprite_get_height(argument4);
}
else {
pos = -((argument3 / 100 ) * sprite_get_width(argument4)) + sprite_get_width(argument4);
}
if (!argument5){
    draw_sprite_part_ext(argument4,0,0,pos,sprite_get_width(argument4),sprite_get_height(argument4) - pos,argument0,argument1 + pos,1,1,c_white,draw_get_alpha());
}
else{
draw_sprite_part_ext(argument4,0,0,0,sprite_get_width(argument4) - pos,sprite_get_height(argument4),argument0,argument1,1,1,c_white,draw_get_alpha());
}