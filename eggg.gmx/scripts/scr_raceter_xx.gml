if (xx_time > 0 ){xx_time --;}
if (xx_time <= 0 && (T == 20 || T == 21)) T = 0;
if (keyboard_check(ord('X')) && T == 0 && y >= room_height-120)
{
    act_skill_rh = 0;
    xx_time = 60;
    T = 20;
    ds_list_clear(pingAds);
}// ping A 1
if (T == 20 && xx_time > 36)
{
    if (xx_time == 42)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+55,y-55,55);
            if(a != noone)
            {
                if(ds_list_find_index(pingAds,a) == -1)
                {   
                    ds_list_add(pingAds,a);
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
            scr_deal_damage_phy(id,a,phy_attack*0.75);
        }
        var b = instance_create(x,y-55,obj_raceter_pingA);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
        
    }
}
if (T == 20)
{
    if (xx_time == 60) image_index = 188;
    if (xx_time == 50) image_index = 189;
    if (xx_time == 40) image_index = 190;
    if (xx_time == 30) image_index = 191;
    if (xx_time == 20) {image_index = 192;act_skill_rh = 1;}
    if (xx_time == 30) image_index = 193;
}
if (keyboard_check(ord('X')) && T == 20 && xx_time > 0 && xx_time <= 20)
{
    act_skill_rh = 0;
    xx_time = 40;
    T = 21;
    ds_list_clear(pingAds);
    
}
if (T == 21)
{
    if (xx_time == 10)
    {
        var b = instance_create(x,y-55,obj_raceter_pingA2);
        if (scr_check_face(id)== -1) b.image_xscale = -1;
    }
    if (xx_time == 10 || xx_time == 35)
    {
        ds_list_clear(pingAds);
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x+55,y-55,55);
            if(a != noone)
            {
                if(ds_list_find_index(pingAds,a) == -1)
                {   
                    ds_list_add(pingAds,a);
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
                    scr_deal_damage_phy(id,a,phy_attack*0.85);
        }
    }
}
if (T == 21)
{
    if (xx_time == 40) image_index = 194;
    if (xx_time == 33) image_index = 195;
    if (xx_time == 22) image_index = 196;
    if (xx_time == 11) image_index = 197;
    if (xx_time == 6) image_index = 198;
}
