if (R_cd > 0) R_cd --;
if (keyboard_check_pressed(ord('R')) && (T == 0 || act_skill_rh) && R_cd == 0 && y >= room_height-120)
{
    act_skill_rh = 0;
    hyjw_time = 300;
    T = 100;   
    load_R_cd = R_maxcd;
    if (equip_rcgdhx_have) load_R_cd *= 0.7;
    R_cd = scr_scd(load_R_cd);
    if (equip_rcgdhx_have) wudi = 1;
    image_index = 2;
}
if (T == 100 && hyjw_time > 0)
{
    if (hyjw_time == 300)
    {
        var b = instance_create(x,y-55,obj_raceter_hyjw);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
    }
    if (hyjw_time == 290 && equip_rcgdhx_have)
    {
        var b = instance_create(x,y-55,obj_raceter_hyjw);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
    }
    var zjcs = 10;
    if (equip_rcgdhx_have) zjcs = 10;
    if (hyjw_time % zjcs == 0 && hyjw_time >= 90)
    {
        var ds = ds_list_create();
        ds_list_clear(hyjwds)
        do{
            var a = scr_xuan_guai(x+20*scr_check_face(id),y-55,30);
            if(a != noone)
            {
                if(ds_list_find_index(hyjwds,a) == -1)
                {   
                    ds_list_add(hyjwds,a);
                    ds_list_add(ds,a);
                    instance_deactivate_object(a);
                }   
            }
        }until(a == noone)
        if (ds_list_size(ds) > 0)
        for (var i = 0; i < ds_list_size(ds); i++)
        {
            instance_activate_object(ds[|i]);
            var l_d = d_hyjw1;
            if (equip_rcgdhx_have) l_d *= 1.5;
            scr_deal_damage_phy(id,ds[|i],phy_attack * l_d);
        }
    }
    hyjw_time --;
    if (hyjw_time == 75)
    {
        var a = instance_create(x,y,obj_raceter_hyjw2);
        if (scr_check_face(id)== -1) a.image_xscale = -1;
        a.master = id;
        a._x = scr_check_face(id);
        act_skill_rh = 1;
    }
    if (hyjw_time <= 40){T = 0;wudi = 0;}
}

if (T == 100 && hyjw_time > 110)
{
    randomize();
    if (hyjw_time % zjcs == 0)
    {
        var i = irandom_range(1,4);
        if(i == 1) image_index = 2;
        if (i == 2) image_index = 10;
        if (i == 3) image_index = 187;
        if (i == 4) image_index = 193;
    }
    if (hyjw_time % zjcs%5 == 0) image_index ++;
}
if (T == 100)
{
    if(hyjw_time == 110) image_index = 199;
    if(hyjw_time == 105) image_index = 200;
    if(hyjw_time == 100) image_index = 201;
    if(hyjw_time == 95) image_index = 202;
    if(hyjw_time == 90) image_index = 203;
    if(hyjw_time == 85) image_index = 204;
    if(hyjw_time == 80) image_index = 205;
    if(hyjw_time == 75) image_index = 206;
    if(hyjw_time == 70) image_index = 207;
    if(hyjw_time == 65) image_index = 208;
    if(hyjw_time == 60) image_index = 209;
}





