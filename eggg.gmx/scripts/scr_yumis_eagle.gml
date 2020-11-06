if (D_cd > 0) D_cd --;
if (keyboard_check_pressed(ord('D')) && D_cd == 0 && T == 0 && y >= room_height-120)
{
    eagle_time = 1
    D_cd = scr_scd(D_maxcd);    
}
if (eagle_time == 1)
{
    eagle_time = 0;
    var a = instance_create(x,y,obj_yumis_eagle);
    a.master = id;
    a.face = scr_check_face(id);
}