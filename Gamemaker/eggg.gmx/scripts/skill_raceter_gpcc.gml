if (S_cd > 0) S_cd --; //闁告劖鐓￠弨鐩婦
if (keyboard_check(ord('S')) && S_cd <= 0 && (T == 0 || act_skill_rh) )//闁告劖褰冮崺?
{
    act_skill_rh = 0;
    xx_time = 0;
    T = 1;
    if (face == 0) 
        movex = -30;
    if (face == 1) 
        movex = 30;
    var cd = S_maxcd;
    if (equip_ralsdgj_have) cd = 5;
    S_cd = scr_scd(cd);
    gpcc_time = 40;
}
if (T == 1 && gpcc_time <= 40 && gpcc_time >= 20)
{
    x += movex;
    if (movex > 0) movex -=1.5;
    else movex += 1.5
    if (gpcc_time == 40)
    {
        var k = instance_create(x+70*scr_check_face(id),y+10,obj_raceter_sei);
        if (scr_check_face(id)== -1) k.image_xscale = -1;
        k.master = id
    }
    if (gpcc_time  == 40)
    {
        var ds = ds_list_create();
        do{
            var a = scr_xuan_guai(x,y-55,300);
            if(a != noone)
            {
                if(ds_list_find_index(gpcc,a) == -1)
                {   
                    ds_list_add(gpcc,a);
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
            var damage = phy_attack * d_yz;
            //if (equip_ralsdgj_have) damage *= 5;
            scr_deal_damage_phy(id,a,damage);
        }
    }
}
if (T == 1)
{
   if (gpcc_time == 40) image_index = 194;
   if (gpcc_time == 38) image_index = 195;
   if (gpcc_time == 34) image_index = 196;
   if (gpcc_time == 24) image_index = 197;
   if (gpcc_time == 14) {image_index = 198;act_skill_rh = 1}
   gpcc_time --;
   if (gpcc_time <= 8)
        {T = 0;ds_list_clear(gpcc);}
}
