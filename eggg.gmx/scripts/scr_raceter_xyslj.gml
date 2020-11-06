if (DOWNSPACE_cd > 0) DOWNSPACE_cd --;
if (keyboard_check_pressed(ord('Y')) && DOWNSPACE_cd == 0 && (T == 0 || act_skill_rh) && y >= room_height-120)
{   
    act_skill_rh = 1;
    xyslj_time = 330;
    wudi = 1;
    T = 120;
    var cd = DOWNSPACE_maxcd;
    if (equip_ryhzx_have) cd *= 0.7;
    if (equip_rsljyz_have) cd *= 0.7;
    DOWNSPACE_cd = scr_scd(cd);
    skill_pressed = 0;
}
if (T == 120)
{
    if (xyslj_time == 320 || xyslj_time == 264 || xyslj_time == 210)
    {ds_list_clear(xysljds);}
    if (xyslj_time == 320 /*|| xyslj_time == 310 || xyslj_time == 300 */|| xyslj_time == 264 /*|| xyslj_time == 254 || xyslj_time == 244 */|| xyslj_time == 200/*|| xyslj_time == 200|| xyslj_time == 190*/)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+225*scr_check_face(id),y-55,200);
            if(a != noone)
            {
                if(ds_list_find_index(xysljds,a) == -1)
                {   
                    ds_list_add(xysljds,a);
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
            var d = phy_attack * d_xyslj1;
            if (equip_ryhzx_have) d *= 1.5;
            scr_deal_damage_phy(id,a,d);
        }
    }
if  (xyslj_time == 78)
    ds_list_clear(xysljds);
    if  (xyslj_time == 78/* || xyslj_time == 72 || xyslj_time == 66 || xyslj_time == 60 || xyslj_time == 52 || xyslj_time == 48*/)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+225*scr_check_face(id),y-55,200);
            if(a != noone)
            {
                if(ds_list_find_index(xysljds,a) == -1)
                {   
                    ds_list_add(xysljds,a);
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
            var d = phy_attack * d_xyslj2;
            if (equip_ryhzx_have) d *= 1.5;
            scr_deal_damage_phy(id,a,d);
        }
    }
    if (xyslj_time == 0)    {T = 0;wudi = 0}
    if (xyslj_time == 330)
    {
        var a = instance_create(x,y-55,obj_raceter_xyslj);
        if (equip_rsljyz_have) a.spd = 1;
        else a.spd = 0;
        if (scr_check_face(id) == -1)
            a.image_xscale = -1.5
        else 
            a.image_xscale = 1.5;
        a.image_yscale *= 1.5;
        a = instance_create(x,y-55,obi_raceter_xysjl2);
        if (scr_check_face(id) == -1)
            a.image_xscale = -1;
        a.image_yscale *= 1.5;
        a.image_xscale *= 1.5;
    }
    xyslj_time --;
    if (equip_rsljyz_have) xyslj_time --;
    
}