if (F_cd > 0) {F_cd --;}
if (keyboard_check_pressed(ord('F')) && (T == 0 || act_skill_rh) && F_cd == 0 && y >= room_height-120)//濞翠焦妲?鐠?
{
    ylzz_time = 30
    T = 80;
    F_cd = scr_scd(F_maxcd);
    ds_list_clear(ylzzds);
}
if (T == 80)
{
    if (ylzz_time == 30) image_index = 125;
    if (ylzz_time == 20) image_index = 126;
    if (ylzz_time == 10) image_index = 204;
}
if (ylzz_time > 0 && T == 80)
{
    ylzz_time --;
    x += scr_check_face(id)*1.5;
    y -= 2;
    y -= 1.5;
    if (ylzz_time == 0)
    {
        T = 81; 
        ylzz_time = 48;
    }
}
if (T == 81)
{
    if (ylzz_time == 48) image_index = 206;
    if (ylzz_time == 40) image_index = 207;
    if (ylzz_time == 32) image_index = 208;
    if (ylzz_time == 24) image_index = 209;
    y += 4
    x += scr_check_face(id)*2;
    if (y >= room_height-110)
    {
        var b = instance_create(x,y,obj_raceter_ylzz1);
        b.master = id;
        if (scr_check_face(id) == -1)
            b.image_xscale = -1;
    }
    if (y >= room_height-110)
    {
        var b = instance_create(x,y,obj_raceter_ylzz2);
        if (scr_check_face(id) == -1)
            b.image_xscale = -1;
        b.image_xscale *= 0.7;
        b.image_yscale *= 0.7;
        
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+100*scr_check_face(id),y-55,150);
            if(a != noone)
            {
                if(ds_list_find_index(ylzzds,a) == -1)
                {   
                    ds_list_add(ylzzds,a);
                    ds_list_add(ds,a);
                    instance_deactivate_object(a);
                }   
            }
        }until(a == noone)
        if (ds_list_size(ds) > 0)
        for (var i = 0; i < ds_list_size(ds); i++)
        {
            instance_activate_object(ds[|i]);
            var a = ds[|i];
            scr_deal_damage_phy(id,a,phy_attack * d_ylzz);
        }
        T = 0;
    }
}