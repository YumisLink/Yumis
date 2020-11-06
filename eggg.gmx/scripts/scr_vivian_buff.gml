if buff_time > 0  buff_time --;
if (buff_open)
{
    buff_open = 2;
}
if (buff_open == 2)
{
    
    var a = instance_create(x,y-135,obj_buff);
    a.master = id;
    a.use = spr_buff_raceter_dark;
    buff_open = 1;
    buff_flag = 1;
    if (now_buff == 0)
    {
        now_buff = 1;
        brain += V_brain * 0.35;
    }
    if (now_buff == 1)
    {
        now_buff = 1;
    }
    var b = instance_create(x,y+88,obj_buff_diang);
    b.master = id;
}