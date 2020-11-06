/*
if (A_cd > 0) A_cd --;
if (keyboard_check_pressed(ord('A')) && A_cd == 0 && (T == 0 || act_skill_rh) && y >= room_height-120)
{
    slz_time = 45;
    T = 40;
    A_cd = scr_scd(A_maxcd);
}
if (T == 40)
{
    slz_time --;
    if (slz_time == 0)
        T = 0;
    if (slz_time == 44)
    {
        ds_list_clear(slzds);
        var a = instance_create(x,y-55,obj_raceter_slz);
        if (scr_check_face(id) == -1)
            a.image_xscale = -1;
        for (var i = 1; i <= 180; i ++)
        {
            var a = scr_xuan_guai(x+i*scr_check_face(id),y-55,1);
            if(a != noone)
            {
                if(ds_list_find_index(slzds,a) == -1)
                {
                    ds_list_add(slzds,a);
                    scr_deal_damage_phy(id,a,phy_attack* d_slz);
                }   
            }
        }
    }
    if (slz_time == 22)
    {
        ds_list_clear(slzds);
        for (var i = 1; i <= 180; i ++)
        {
            var a = scr_xuan_guai(x+i*scr_check_face(id),y-55,1);
            if(a != noone)
            {
                if(ds_list_find_index(slzds,a) == -1)
                {
                    ds_list_add(slzds,a);
                    scr_deal_damage_phy(id,a,phy_attack* d_slz);
                }   
            }
        }
    }
}
