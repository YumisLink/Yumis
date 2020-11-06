
if (lxl_cd > 0) lxl_cd --;
if (lxs_cd > 0) lxs_cd --;
if (lxy_cd > 0) lxy_cd --;
if (lxx_cd > 0 ) lxx_cd --;
if (T == 50)
{
    instance_create(x,y,obj_raceter_lx);
}
if (keyboard_check_pressed(ord('Q')) && T == 50)
{
    T = 0;
    return 0;
}
if (keyboard_check_pressed(ord('Q')) && (T == 0 || act_skill_rh) && y >= room_height-120)
{
    T = 50;
    return 0;
}
if (keyboard_check_pressed(ord('C')) && T == 50 && lxy_cd == 0)//濞翠焦妲?鐠?
{
    lxy_time = 70
    T = 51;
    var l_cd = lxy_maxcd;
    if (equip_ryhzs_have) l_cd *= 0.5; 
    lxy_cd = scr_scd(l_cd);
    jump_in = 1;
    jump = 5.0;
    ds_list_clear(lxds);
}
if (lxy_time > 0 && T == 51)
{
    lxy_time --;
    if (lxy_time == 0)  T = 0;
    x += scr_check_face(id)*2.5;
    if (lxy_time == 69)
    {
        var a = instance_create(x,y-5,obj_raceter_lxy);
        if (scr_check_face(id) == -1)
            a.image_xscale = -1
        a.master = id;
    }
    for (var j = 1; j <= 5; j ++)
        for (var i = 1; i <= 50; i ++)
        {
            var a = scr_xuan_guai(x-30*scr_check_face(id)+i*3*scr_check_face(id),y-53+j,1);
            if(a != noone)
            {
                if(ds_list_find_index(lxds,a) == -1)
                {
                    ds_list_add(lxds,a);
                    var d = d_lxy;
                    if (equip_ryhzs_have) d *= 2;
                    scr_deal_damage_phy(id,a,phy_attack* d);
                }   
            }
        }
}



if (keyboard_check_pressed(ord('X')) && y <= room_height-130 && lxl_cd == 0 && T == 0)//濞翠焦妲?閽€?
{
    T = 52;
    var l_cd = lxl_maxcd;
    if (equip_ryhzs_have) l_cd *= 0.5; 
    lxl_cd = scr_scd(l_cd);
    ds_list_clear(lxds);
    lxl_time = 0;
}
if (T == 52)
{
    lxl_time ++;
    y -= 2;
    if (lxl_time % 25 == 0) ds_list_clear(lxds);
    if (lxl_time > 25)
    {
        y += 9;
        x += 2.5*scr_check_face(id);
        var a = scr_xuan_guai(x+20,y,5);
        if(a != noone)
        {
            if(ds_list_find_index(lxds,a) == -1)
            {
                ds_list_add(lxds,a);
                var d = d_lxl1;
                if (equip_ryhzs_have) d *= 2;
                scr_deal_damage_phy(id,a,phy_attack* d);
            }   
        }
    }
    if (y >= room_height-100) 
    {
        ds_list_clear(lxds);
        T = 0;lxx_time =0;
        for (var i = 1; i <= 50; i ++)
        {
            var a = scr_xuan_guai(x-75*scr_check_face(id)+i*3*scr_check_face(id),y,1);
            if(a != noone)
            {
                if(ds_list_find_index(lxds,a) == -1)
                {
                    ds_list_add(lxds,a);
                    var d = d_lxl2;
                    if (equip_ryhzs_have) d *= 2;
                    scr_deal_damage_phy(id,a,phy_attack* d);
                }   
            }
        }
    }
}

if (keyboard_check_pressed(ord('Z')) && T == 50 && lxs_cd == 0)//濞翠礁绺?閸?
{
    T = 53;
    var l_cd = lxs_maxcd;
    if (equip_ryhzs_have) l_cd *= 0.5; 
    lxs_cd = scr_scd(l_cd);
    ds_list_clear(lxds);
    lxs_time = 40;
}
if (T == 53 && lxs_time >= 0)
{
    lxs_time --;
    y -= 8;
    x += 1*scr_check_face(id);
    var a = scr_xuan_guai(x,y+55,8);
    if(a != noone)
    {
        if(ds_list_find_index(lxds,a) == -1)
        {
            ds_list_add(lxds,a);
            var d = d_lxs;
            if (equip_ryhzs_have) d *= 2;
            scr_deal_damage_phy(id,a,phy_attack* d);
        }   
    }
    if (lxs_time == 0) 
    {
        T = 0;
    }
} 
if (keyboard_check_pressed(ord('X')) && T == 50 && lxx_cd == 0)//濞翠焦妲?閸?
{
    T = 54;
    lxx_cd = scr_scd(lxx_maxcd);
    ds_list_clear(lxds);
    lxx_time = 25;
}
if (T == 54 && lxx_time > 0)
{
    lxx_time --;
    var a = scr_xuan_guai(x+80*scr_check_face(id),y-55,40);
    if (a != noone)
    {
        lxx_time = 0;
        lxx_time2 = 40
        ds_list_clear(lxds);
    }
    if (lxx_time == 0)
    {
        lxx_time2 = 40
        ds_list_clear(lxds);
    
    }
    x += 10*scr_check_face(id);
}
if (T == 54 && lxx_time2 >= 0)
{
    lxx_time2 --;;
    if (lxx_time2 % 5 == 0)
    {
        for (var i = 1; i <= 50; i ++)
        {
            var a = scr_xuan_guai(x+i*5*scr_check_face(id),y,1);
            if(a != noone)
            {
                if(ds_list_find_index(lxds,a) == -1)
                {
                    ds_list_add(lxds,a);
                    var d = d_lxx;
                    if (equip_ryhzs_have) d *= 2;
                    scr_deal_damage_phy(id,a,phy_attack* d);
                }   
            }
        }
    }
    if (lxx_time2 == 0){T = 0;}
}













//if (y >= room_height-100)i ++;
