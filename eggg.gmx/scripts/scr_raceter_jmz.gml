if (UPSPACE_cd > 0) UPSPACE_cd --;
if (keyboard_check_pressed(ord('H')) && UPSPACE_cd == 0 && (T == 0 || act_skill_rh) && y >= room_height-120)
{
    act_skill_rh = 0;
    jmz_ready = 0;
    wudi = 1;
    T = 110;
    UPSPACE_cd = scr_scd(UPSPACE_maxcd);
    var b = instance_create(x,y-88,obj_raceter_xuli2);
    b.al = 8;
    image_index = 10;
    ds_list_clear(jmzds);
}
if (T == 110)
    jmz_ready ++;
if ((jmz_ready >= 500 || (!keyboard_check(ord('H'))) && jmz_ready >= 112) && T == 110)
{
    jmz_time = 150;
    T = 111;
}
if (T == 111 && jmz_time > 0)
{
    if (equip_rwldyy_have) jmz_ready += 100;
    if (jmz_time == 120)
    {
        var b = instance_create(x,y-55,obj_raceter_jmz);
        if (scr_check_face(id) == -1)
            b.image_xscale = -1
        /*
        if (ty_ylj)
        {
            var b = instance_create(x,y-55,obj_raceter_jmz2);
            if (scr_check_face(id) == -1)
                b.image_xscale = -1
        }
        instance_create(x,y-55,obj_raceter_jmzsand);
        */
    }
    if (jmz_time == 120)// && jmz_time % 20 == 0)
    {
        ds_list_clear(jmzds);
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x,y-55,600);
            if(a != noone)
            {
                if(ds_list_find_index(jmzds,a) == -1)
                {   
                    ds_list_add(jmzds,a);
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
            if (jmz_ready >= 100)
                scr_deal_damage_phy(id,a,phy_attack* l_d);
            else 
                scr_deal_damage_phy(id,a,phy_attack * l_d/2 * (1 + jmz_ready / 100));
        }
    }
    /*
    if (jmz_time == 30)
    {
        var b = instance_create(x,y,obj_raceter_jmzw);
        b.master = id
    }
    */
}

if (T == 111)
{
    if (jmz_time == 0) {T = 0 ;wudi = 0}
    if (jmz_time == 140) image_index = 12;
    if (jmz_time == 130) image_index = 13
    if (jmz_time == 150) image_index = 11;;
    if (jmz_time == 120) image_index = 14;
    if (jmz_time == 110) image_index = 15;
    if (jmz_time == 100) image_index = 16;
    if (jmz_time == 90) image_index = 17;
    if (jmz_time == 80) image_index = 18;
    if (jmz_time == 70) image_index = 19;
    if (jmz_time == 60) {image_index = 20;act_skill_rh = 1;}
    
    jmz_time --;
}






