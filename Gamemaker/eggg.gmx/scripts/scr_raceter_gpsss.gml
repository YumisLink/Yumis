/*
if (gpsss_cd > 0) gpsss_cd --;//CD
if (gpsss_extra > 0) gpsss_extra --;//
if (gpsss_extra_wait > 0) gpsss_extra_wait --;//闁瑰灈鍋撻柤鍏呯矙濡潡姊鹃弮鍌滄惣鐎垫澘鎳庤ぐ鏌ュ籍閸洘锛?
if (using_gpsss)
{
    gpsss_cd = gpsss_max_cd;
    using_gpsss = false;
    T = 10;
    gpsss_time = 20;
    gpsss_extra = 300;
    gpsss_extra_wait = 100;
}


if (using_gpsss_extra)
{
    using_gpsss_extra = false;
    gpsss_extra = false;
    T = 11;
    gpsss_extra_time = 20;
}


if (T == 10 && gpsss_time > 0)
{
    if (face == 0)
        x -= 10;
    else 
        x += 10;
    if (face == 1)
    {
        var a = scr_xuan_guai(x-35,y-55,1);
        if (a != noone)
        {
            gpsss_time = 0;
            scr_deal_damage_phy(id,a,55+0.3*agile);
        }
    }
    if (face == 0) 
    {
        var a = scr_xuan_guai(x-35,y-55,1);
        if (a != noone)
        {
            gpsss_time = 0;
            scr_deal_damage_phy(id,a,55+35*gpsss_lv+0.3*agile);
        }
    }
    gpsss_time --;
    if (gpsss_time <= 0)
        {scr_skill_end();}
}


if (T == 11 && gpsss_extra_time > 0)
{
    if (gpsss_extra_time % 4 == 0)
    {
        var i;
        var l_list = ds_list_create();
        for (i = 1; i <= 139; i ++)
        {
            var a = scr_xuan_guai(x-100+i,y-55,30);
            if (a != noone)
                if(ds_list_find_index(l_list,a) == -1)
                {
                    ds_list_add(l_list,a)
                    scr_deal_damage_phy(id,a,agile*0.02);
                }
        }
    }
    gpsss_extra_time --;//濡増绻傞ˇ濠氬箮閳ь剟鎳楁禒瀣珵闁衡偓閻愵剚顦ч梻?
    
    if (gpsss_extra_time <= 0)
        {scr_skill_end();}
}