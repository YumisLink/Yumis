if (E_cd > 0) E_cd --;
if (E_cd == 0 &&keyboard_check_pressed(ord('E')) && (T == 0 || act_skill_rh) && y > room_height-130)
{
    act_skill_rh = 0;
    zs_time = 100;
    T = 90;
    E_cd = scr_scd(E_maxcd);
    ds_list_clear(zsds);
}
if (T == 90)
{
    if (zs_time == 40) act_skill_rh = 1;
    if (zs_time == 100) image_index = 139;
    if (zs_time == 70) image_index = 140;
    if (zs_time == 65) image_index = 141;
    if (zs_time == 60) image_index = 142;
    if (zs_time == 55) image_index = 143;
    if (zs_time == 50) image_index = 144;
    if (zs_time == 45) image_index = 145;
    if (zs_time == 40) image_index = 146;
    if (zs_time == 35) image_index = 147;
    if (zs_time == 30) image_index = 148;
    if (zs_time == 25) image_index = 149;
    if (zs_time == 20) image_index = 150;
    if (zs_time == 15) image_index = 151;
    if (zs_time == 10) image_index = 152;
    if (zs_time == 5)  {image_index = 153;T = 0;}
}
if (T == 90 && zs_time > 0)
{
    zs_time --;
    if (zs_time == 60)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+50*scr_check_face(id),y-55,75);
            if(a != noone)
            {
                if(ds_list_find_index(zsds,a) == -1)
                {   
                    ds_list_add(zsds,a);
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
            var damage;
            if (equip_rhmzy_have) damage = max(phy_attack * d_zs,mag_attack * d_zs);
            else damage = max(phy_attack * d_zs * ((a.max_hp - a.hp) / a.max_hp +0.01),mag_attack * d_zs * ((a.max_hp - a.hp) / a.max_hp +0.01))
            scr_deal_damage_phy(id,a,damage);
        }
        
        var b = instance_create(x,y-55,obj_raceter_zs);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
    }
}
