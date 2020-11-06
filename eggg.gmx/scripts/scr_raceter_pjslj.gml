if (G_cd > 0) G_cd --;
if (G_cd == 0 && (T == 0 || act_skill_rh) && keyboard_check_pressed(ord('G'))&& y >= room_height-120)
{
    act_skill_rh = 0
    pjslj_time = 100;
    G_cd = scr_scd(G_maxcd);
    T = 1220;
    ds_list_clear(pjsljds);
}
if (T == 1220)
{
    if (pjslj_time == 100) image_index = 200;
    if (pjslj_time == 94) image_index = 201;
    if (pjslj_time == 88) image_index = 202;
    if (pjslj_time == 82) image_index = 204;
    if (pjslj_time == 76) image_index = 139;
    if (pjslj_time == 70) image_index = 140;
    if (pjslj_time == 64) image_index = 141;
    if (pjslj_time == 58) image_index = 142;
    if (pjslj_time == 52) image_index = 143;
    if (pjslj_time == 46) image_index = 144;
    if (pjslj_time == 40) image_index = 145;
    if (pjslj_time == 35) image_index = 146;
    if (pjslj_time == 30) {image_index = 147;}
    if (pjslj_time == 30) act_skill_rh =1;
}
if (T == 1220 && pjslj_time >= 0)
{
    if (pjslj_time == 20) {T = 0; return 0;}
    if (pjslj_time == 100)
    {
        var a = instance_create(x,y-55,obj_raceter_pjslj);
        if (scr_check_face(id) == -1)
            a.image_xscale = -1
    }
    if (pjslj_time == 100 || pjslj_time == 75 || pjslj_time == 40)
    {
        ds_list_clear(pjsljds);
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x,y-55,200);
            if(a != noone)
            {
                if(ds_list_find_index(pjsljds,a) == -1)
                {   
                    ds_list_add(pjsljds,a);
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
            var l_d = d_jmz;
            scr_deal_true_damage(id,a,phy_attack * d_pjslj);
        }
    }
    pjslj_time --
}
