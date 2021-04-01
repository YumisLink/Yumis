randomize();
if (T_cd > 0) T_cd --;
if (keyboard_check_pressed(ord('T')) && (T == 0 || act_skill_rh) && T_cd == 0 && y >= room_height-120)
{
    act_skill_rh = 0;
    swzr_time = 100;
    T = 140;   
    var cd = T_maxcd;
    if (equip_rwstl_have) cd *= 0.7;
    T_cd = scr_scd(cd);
}
if (T == 140)
{
    if (swzr_time == 100) image_index = 160
    if (swzr_time == 95) image_index = 161
    if (swzr_time == 90) image_index = 162
    if (swzr_time == 85) image_index = 163
    if (swzr_time == 80) image_index = 164
    if (swzr_time == 75) image_index = 165
    if (swzr_time == 70) image_index = 166
    if (swzr_time == 65) image_index = 167
    if (swzr_time == 60) image_index = 168
    if (swzr_time == 55) image_index = 169
    if (swzr_time == 50) image_index = 194
    if (swzr_time == 45) image_index = 195
    if (swzr_time == 40) image_index = 196
    if (swzr_time == 35) image_index = 197
    if (swzr_time == 30) image_index = 198
    
}
if (T == 140 && swzr_time > 0)
{
    if (swzr_time == 64)
    {
        instance_create(x,y,obj_raceter_swzr);
    }
    if (swzr_time == 30)
    {   
        //if (equip_rbjrdbp_have) scr_time_buff(l_time,0,0,0,0,0,0,0,20);
        act_skill_rh = 1;
        
        ds_list_clear(swzrds)
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x,y-55,200);
            if(a != noone)
            {
                if(ds_list_find_index(swzrds,a) == -1)
                {   
                    ds_list_add(swzrds,a);
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
            var kk = irandom_range(0,1);
            if (kk == 1)  var w = instance_create(a.x,a.y-55,obj_raceter_swzr1);
            if (kk == 0)  var w = instance_create(a.x,a.y-55,obj_raceter_swzr2);
            kk = irandom_range(0,1);
            if (kk) w.image_xscale = -1;
            ds_list_add(swzrds,a);
            var damage;
            if (equip_rwstl_have)damage = max(phy_attack * d_swzr*1.5,mag_attack * d_swzr*1.5)
            else  damage = max(phy_attack * d_swzr * ((a.max_hp - a.hp) / a.max_hp +0.02),mag_attack * d_swzr * ((a.max_hp - a.hp) / a.max_hp +0.02))
            scr_deal_damage_phy(id,a,damage);
        }
    }
    swzr_time --;
    if (swzr_time == 0) T = 0;
}
