if buff_time > 0  buff_time --;
if (buff_open)
{
    T = 10001;
    buff_time = 10;
    buff_open = 0;
}
if (buff_time <= 0 && T = 10001)
{
    instance_create(x,y-135,obj_buff_show)
    T --;
}
if (buff_time <= 0 && T = 10000)
{
    if (keyboard_check_pressed(vk_right))
    {
        var a = instance_create(x,y-135,obj_buff);
        a.master = id;
        a.use = spr_buff_raceter_ice;
        T = 0;
        buff_flag = 1;
        if (now_buff == 0)
        {
            now_buff = 2;
            potence += r_potence * 0.2;
        }
        if (now_buff == 1)
        {
            now_buff = 2;
            hit_rate += 30;
            potence += r_potence * 0.2;
            brain -= r_brain * 0.35
        }
        var b = instance_create(x,y+88,obj_buff_diang);
        b.master = id;
    }
    if (keyboard_check_pressed(vk_left))
    {
        var a = instance_create(x,y-135,obj_buff);
        a.master = id;
        a.use = spr_buff_raceter_dark;
        T = 0;
        buff_flag = 1;
        if (now_buff == 0)
        {
            now_buff = 1;
            hit_rate -= 30;
            brain += r_brain * 0.35;
        }
        if (now_buff == 2)
        {
            now_buff = 1;
            hit_rate -= 30;
            potence -= r_potence * 0.2;
            brain += r_brain * 0.35;
        }
        var b = instance_create(x,y+88,obj_buff_diang);
        b.master = id;
    }
}