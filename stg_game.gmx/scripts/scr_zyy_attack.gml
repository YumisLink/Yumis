if (left_cd > 0)left_cd --;
if (right_cd> 0)right_cd --;
if (e_cd > 0)e_cd --;
if (q_cd> 0)q_cd --;
if (qtime > 0) qtime --;
if (mouse_check_button(mb_left) && left_cd <= 0 && T == 0)
{
    randomize();
    var a = instance_create(x,y,obj_zyy_bullet);
    a.direction = point_direction(x,y,mouse_x,mouse_y) + random_range(-5,5);
    a.alltime = 500
    a.damage = damage;
    left_cd = left_maxcd;
}
if (mouse_check_button_pressed(mb_right) && right_cd <= 0 && T == 0)
{
    var a = instance_create(x,y,obj_zyy_sword);
    a.image_angle = point_direction(x,y,mouse_x,mouse_y);;
    right_cd = right_maxcd;
    T = 1;
    right_time = 30;
    ds_list_clear(right_ds);
    
}
if (keyboard_check_pressed(ord('E')) && e_cd <= 0 && T == 0)
{
    e_cd = e_maxcd;
    e_time = 30;
    speed = 30;
    wudi = 1;
    direction = point_direction(x,y,mouse_x,mouse_y);
    T = 2;
    ds_list_clear(e_ds);
}
if (keyboard_check_pressed(ord('Q')) && q_cd <= 0 && T == 0)
{
    q_cd = q_maxcd;
        qtime = 300;
    if (pow > 10000)
    {
        qtime  = 900;
        pow = 0;
    }
}


if (T == 1 && right_time >= 0)
{
    right_time --;
    if (right_time == 0) T = 0;
    var rdir = point_direction(x,y,mouse_x,mouse_y)-60;
    for (var i = 1; i <= 30; i++)
        for (var j = 1; j <= 10; j++)
        {
            var a = scr_check_enemy2(x + j*10*dcos(rdir+5*i),y-j*10*dsin(rdir+5*i),2);
            if (a != noone && ds_list_find_index(right_ds,a) == -1)
            {
                deal_damage(main,a,damage * 17.50);
                ds_list_add(right_ds,a);
                
            }
        }
}
if (T == 2 && e_time >= 0)
{
    e_time --;
    speed --;
    for (var i = 1; i <= 36; i++)
        {
            var a = scr_check_enemy2(x + 10*cos(10*i),y + 10*sin(10*i),10);
            if (a != noone && ds_list_find_index(e_ds,a) == -1)
            {
                deal_damage(main,a,damage * 30.00);
                ds_list_add(e_ds,a);
            }
        }
    if (e_time == 0 || speed == 0) {T = 0;wudi = 0}
}









