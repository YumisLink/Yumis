/*
if (Z_cd > 0) Z_cd --;
if (keyboard_check_pressed(ord('Z')) && Z_cd <= 0 && (T == 0 || act_skill_rh) && y >= room_height-120)
{
    act_skill_rh = 0
    jyz_time = 80;
    T = 60;
    Z_cd = scr_scd(Z_maxcd);
    ds_list_clear(jyzds);
    
}
if (T == 60)
{
    if (jyz_time == 80) image_index = 42;
    if (jyz_time == 76) image_index = 43;
    if (jyz_time == 72) image_index = 44;
    if (jyz_time == 68) image_index = 45;
    if (jyz_time == 64) image_index = 46;
    if (jyz_time == 60) image_index = 47;
    if (jyz_time == 55) image_index = 48;
    if (jyz_time == 50) image_index = 49;
    if (jyz_time == 45) {image_index = 50;act_skill_rh = 1;}
    if (jyz_time == 38) {T = 0;}
    jyz_time --;
}
if ( T== 60 && jyz_time >= 40)
{   
    if (jyz_time == 79)
    {
        var b = instance_create(x+5,y+10,obj_raceter_jyz);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
        b.image_xscale *= 1.1;
        b.image_yscale *= 1.1;
    }
    
    x += 1 * scr_check_face(id);
}
if (T == 60 && jyz_time >= 40)
{
    if (jyz_time == 39)
    {
    var ds = ds_list_create();
    do{
        var a = scr_xuan_guai(x,y,100);
        if(a != noone)
        {
            if(ds_list_find_index(jyzds,a) == -1)
            {   
                ds_list_add(jyzds,a);
                ds_list_add(ds,a);
                instance_deactivate_object(a);
            }   
        }
    }until(a == noone)
    if (ds_list_size(ds) > 0)
    for (var i = 0; i < ds_list_size(ds); i++)
    {
        instance_activate_object(ds[|i]);
        var l_d = d_jmz;
            var a = ds[|i];
        scr_deal_damage_phy(id,a,phy_attack* d_jyz);
    }
    }
}
