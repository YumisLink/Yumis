if (A_cd > 0) A_cd --;
if (T == 0 && keyboard_check_pressed(ord('X')) && A_cd == 0 && mp > 5)
{
    mp -= 5;
    A_cd = scr_scd(A_maxcd);
    slag_time = 10;
    stage = jump_in;
}
if (slag_time > 0)
{
    slag_time --;
    if (y <= room_height-150)
    {
        jump_in = -1;
        x -= 1 *scr_check_face(id);
        y -= 3.5;
    }
    if (slag_time == 9)
    {
        randomize();
        var b = instance_create(x-30*scr_check_face(id),y-85 + random(20),obj_vivian_slag);
        b.master = id;
        b._x = scr_check_face(id);
        if (y <= room_height-150)
            b.dir = 45;
        else 
            b.dir = 0;
    }
    if (slag_time == 0) {jump_in = stage;jump = 3.5}
}