if (D_cd > 0) D_cd --;
if (keyboard_check_pressed(ord('D')) && D_cd == 0 && (T == 0 || act_skill_rh) && y >= room_height-120)
{   
    act_skill_rh = 0;
    zgs_time = 60;
    T = 70;
    D_cd = scr_scd(D_maxcd);
    ds_list_clear(zgsds);
    
}
if (T == 70)
{
    if (zgs_time == 20) act_skill_rh = 1;
    if (zgs_time == 60) image_index = 113;
    if (zgs_time == 55) image_index = 114;
    if (zgs_time == 50) image_index = 115;
    if (zgs_time == 45) image_index = 116;
    if (zgs_time == 40) image_index = 117;
    if (zgs_time == 30) image_index = 118;
    if (zgs_time == 20) image_index = 119;
}
if (T== 70 && zgs_time >= 0)
{
    zgs_time --;
    if (zgs_time  == 35)
    {
        var b = instance_create(x+20*scr_check_face(id),y-55,obj_raceter_hasai);
        if (scr_check_face(id) == -1)
            b.image_xscale = -1;
        b.image_xscale *= 0.7;
        b.image_yscale *= 0.5;
    }
    if (zgs_time  == 59)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+50*scr_check_face(id),y-55,75);
            if(a != noone)
            {
                if(ds_list_find_index(zgsds,a) == -1)
                {   
                    ds_list_add(zgsds,a);
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
            scr_deal_damage_phy(id,a,phy_attack*d_zgs);
        }
    }
    if (zgs_time == 19) {T = 0;}
}
