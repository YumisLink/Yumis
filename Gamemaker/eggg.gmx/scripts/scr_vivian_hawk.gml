if (Q_cd > 0) Q_cd --;
if (keyboard_check_pressed(ord('Q')) && Q_cd == 0 && mp > 12)
{
    mp -= 12;
    Q_cd = scr_scd(Q_maxcd);
    hawk_time = 30;
    T = 20;
    stage = jump_in;
    ds_list_clear(hawkds);
}
if (hawk_time >= 0 && T == 20)
{
    if (y <= room_height-150)
    {
        y -= 2.5;
    }
    if (hawk_time == 30)
    {
        if (y <= room_height-150)
        {
            var bb = instance_create(x,y-55,obj_vivian_hawk);
            if (scr_check_face(id) == -1)
                bb.image_xscale = -1
            bb.image_angle = 330;
            if (scr_check_face(id) == -1)
                bb.image_angle = 30;
            bb.image_xscale *= 1.5;
            bb.image_yscale = 1.5;
            for (var i = 1; i <= 300; i ++)
            {
                var a = scr_xuan_guai(x-20*scr_check_face(id)+i*1.73*scr_check_face(id),y-55 + 0.5*i,1);
                if(a != noone)
                {
                    if(ds_list_find_index(hawkds,a) == -1)
                    {
                        ds_list_add(hawkds,a);
                        scr_deal_damage_phy(id,a,mag_attack * d_hawk * sky_damage);
                    }   
                }
            }
        }
        else 
        {
            var bb = instance_create(x,y-55,obj_vivian_hawk);
            if (scr_check_face(id) == -1)
                bb.image_xscale = -1
            bb.image_xscale *= 1.5;
            for (var i = 1; i <= 300; i ++)
            {
                var a = scr_xuan_guai(x-20*scr_check_face(id)+i*2*scr_check_face(id),y-55,1);
                if(a != noone)
                {
                    if(ds_list_find_index(hawkds,a) == -1)
                    {
                        ds_list_add(hawkds,a);
                        scr_deal_damage_phy(id,a,mag_attack * d_hawk);
                    }   
                }
            }
        }
    }
    hawk_time --;
    if (hawk_time == 0) {jump_in = stage;jump = 3.5;T = 0;}
}