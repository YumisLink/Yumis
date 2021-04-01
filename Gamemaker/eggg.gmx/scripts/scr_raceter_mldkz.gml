if (V_cd > 0) V_cd --;//闁瑰灈鍋撻柤宕囩d
if (mldkz_wait > 0) mldkz_wait --;//闁绘碍鐩欢鎶藉棘椤撶姭鏁勯柡鍌楁櫃缁狅綁姊荤€靛憡鐣辩紒娑橆槸缁剁喖寮崼鏇燂紵
if (mldkz_extra_time > 0) mldkz_extra_time --;
if (using_mldkz) 
{
    xx_time = 0;
    taimafanle = 1;
    using_mldkz = false;
    T = 30;
    mldkz_wait = 30;
    mldkz_extra_time = 300;
    mldkz_time = 40;
    var cd = V_maxcd;
    if (equip_ralsdgj_have) cd *= 0.7;
    V_cd = scr_scd(cd);
    ds_list_clear(mldkzds)
    var k = instance_create(x,y,obj_raceter_sei);
    if (scr_check_face(id)== -1) k.image_xscale = -1;
    k.master = id
}
/*
if(using_mldkz_extra)
{
    using_mldkz_extra = false;
    T = 30;
    taimafanle ++
    mldkz_time = 30;
    mldkz_wait = 30;
    mldkz_extra_time = 300;
    ds_list_clear(mldkzds)
    var k = instance_create(x,y,obj_raceter_sei);
    if (scr_check_face(id)== -1) k.image_xscale = -1;
    k.master = id
}
*/
if(T == 30 && mldkz_time >= 10)
{
    if (mldkz_time == 40)
        instance_create(0,y-55,obj_raceter_dasei1);
    if (mldkz_time == 10)
    {
        var k = instance_create(x,y,obj_raceter_dasei2);
        if (scr_check_face(id)== -1) k.image_xscale = -1;
    }
    var l_list = ds_list_create();
    if(face == 0)
        x -= 25;
    else
        x += 25;
if (mldkz_time == 40)  
{      
    var ds = ds_list_create();
    do{
        var a = scr_xuan_guai(x+35,y-55,80);
        if(a != noone)
        {
            if(ds_list_find_index(mldkzds,a) == -1)
            {   
                ds_list_add(mldkzds,a);
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
        var damage = phy_attack * d_mldkz;
        if (equip_ralsdgj_have) damage *= 2;
        scr_deal_damage_phy(id,a,damage);
    }
}
}
if(T == 30)
{
    mldkz_time --;
    if (mldkz_time <= 0){T = 0;}
    if (mldkz_time == 40) image_index = 194;
    if (mldkz_time == 38) image_index = 195;
    if (mldkz_time == 34) image_index = 196;
    if (mldkz_time == 24) image_index = 197;
    if (mldkz_time == 14) {image_index = 198;act_skill_rh = 1}
}