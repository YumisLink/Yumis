if (keyboard_check_pressed(ord('I')) && zbl == 0)
{
    zbl = 1;
    instance_create(x,y,obj_zbl);
    zbl_time ++;
}
else 
{
    if (keyboard_check_pressed(ord('I'))) {zbl = 0;}
}