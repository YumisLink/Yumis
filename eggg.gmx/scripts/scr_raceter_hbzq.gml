if (hbzq_cd > 0) hbzq_cd --;
if (hbzq_cd == 0)
{
    hbzq_cd --;
    phy_defence += 3000;
    mag_defence += 3000;
}
if (hbzq_cd <= 8500)
{
    if (hbzq_tag == 1)
    {
        wudi = 0;
        hps -= 100;
        hbzq_tag = 0;
    }
}


if (now_buff == 1)
{
    dark_boom2_cd --;
    if (dark_boom2_cd <= 0)
    {
        dark_boom2_cd = 50;
        var kkds = ds_list_create();
        for (var j = 1; j <= 100; j ++)
        {
            var a = scr_xuan_guai(x-100+j * 2,y-55,2);
            if (a != noone)
            {
                if(ds_list_find_index(kkds,a) == -1)
                {
                    ds_list_add(kkds,a);
                    scr_deal_true_damage(id,a,mag_attack * 0.1);
                }
            }
        }
    }
}