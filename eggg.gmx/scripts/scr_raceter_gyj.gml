if (W_cd > 0) W_cd --;
if (keyboard_check_pressed(ord('W')) && W_cd == 0 && (T == 0 || act_skill_rh)&& y >= room_height-120)
{
    act_skill_rh = 0;
    gyj_ready = 0;
    T = 130;
    W_cd = scr_scd(W_maxcd);
    var b = instance_create(x,y-88,obj_raceter_xuli);
    b.al = 5;
}

if (T == 130)
    gyj_ready ++;

if ((gyj_ready >= 300 || keyboard_check_released(ord('W'))) && T == 130)
{
    gyj_time = 90;
    T = 131;
}
if (T == 131)
{
    if (gyj_time == 90) image_index = 188;
    if (gyj_time == 85) image_index = 189;
    if (gyj_time == 80) image_index = 190;
    if (gyj_time == 75) image_index = 191;
    if (gyj_time == 70) image_index = 192;
    if (gyj_time == 65) image_index = 193;
    if (gyj_time == 60) image_index = 194;
    if (gyj_time == 55) image_index = 195;
    if (gyj_time == 50) image_index = 196;
    if (gyj_time == 45) image_index = 197;
    if (gyj_time == 40) image_index = 198;
    if (gyj_time == 35) image_index = 199;
    if (gyj_time == 30) image_index = 200;
    if (gyj_time == 25) image_index = 201;
    if (gyj_time == 20) image_index = 202;
    if (gyj_time == 15) {image_index = 203;act_skill_rh = 1;}
}
if (T == 131 && gyj_time > 0)
{
    if (equip_rwldyy_have) gyj_ready += 100;
    if (gyj_time == 90 || gyj_time == 60 || gyj_time == 30)
    {
        if (gyj_time == 90)var a = instance_create(x,y,obj_raceter_gyz1);
        if (gyj_time == 60)var a = instance_create(x,y,obj_raceter_gyz2);
        if (gyj_time == 30)var a = instance_create(x,y,obj_raceter_gyz3);
        if (scr_check_face(id)== -1) a.image_xscale = -1;
        a.master = id;
        if (gyj_ready > 65)
        {
            a.damage = phy_attack * (d_gyj1 + d_gyj2); 
        }
        else 
        {
            a.damage = phy_attack * (d_gyj1 + d_gyj2 * gyj_ready/65);
        }
        a._x = scr_check_face(id);
    }
    gyj_time --;
    if (gyj_time == 0)  T = 0; 
}
