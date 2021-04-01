/*



if (mghk_wait > 0) mghk_wait --;
if (using_mghk)
{
    using_mghk = false;
    mghk_time = 40;
    T = 20;
    mghk_wait = 60;
    mghk_extra_used = 1;
}// 妤犵偟鐓?1婵?
if (using_mghk_2)
{
    using_mghk_2 = false;
    mghk_time_2 = 40;
    T = 21;
    mghk_wait = 60;
    mghk_extra_used = 2;
}// 妤犵偟鐓?2婵?
if(using_mghk_3)
{
    using_mghk_3 = false;
    mghk_time_3 = 60;
    T = 22;
    mghk_extra_used = 0;
}// 妤犵偟鐓?3婵?


if(mghk_wait <= 0)
    {mghk_extra_used = 0;}
    
// 妤犵偟鐓?1婵?
if (T == 20 && mghk_time > 0)
{
    if (mghk_time % 40 == 0)
    {
        var i,j;
        var l_list = ds_list_create();
        var p_;
        if(face == 0) p_ = -5;
        else p_ = 5
        for (i = 1; i <= 20 ; i ++)
            for (j = 1; j <= 6; j ++)
            {
                var a = scr_xuan_guai(x+p_*i,y-70+j*5,25);
                if (a != noone)
                    if(ds_list_find_index(l_list,a) == -1)
                        for(var k = 1; k <= 2 k ++)
                        {
                            scr_deal_damage_phy(id,a,attack*0.25);
                            ds_list_add(l_list,a);
                        }
            }
    }
    mghk_time --;
    if(mghk_time <= 0){T = 0;}
}


// 妤犵偟鐓?2婵?
if (T == 21 && mghk_time_2 > 0)
{
    if (mghk_time_2 % 40 == 0)
    {
        var p_;
        if(face == 0) p_ = -5;
        else p_ = 5
        var i,j;
        var l_list = ds_list_create();
        for (i = 1; i <= 20 ; i ++)
            for (j = 1; j <= 6; j ++)
            {
                var a = scr_xuan_guai(x+p_*i,y-70+j*5,25);
                if (a != noone)
                    if(ds_list_find_index(l_list,a) == -1)
                        for(var k = 1; k <= 2 k ++)
                        {
                            instance_create(x+5*i,y-70,obj_raceter_gpcc_1);
                            scr_deal_damage_phy(a,attack*0.35);
                            ds_list_add(l_list,a);
                        }
            }
    }
    mghk_time_2 --;
    if(mghk_time_2 <= 0){T = 0;}
}


// 妤犵偟鐓?3婵?
if (T == 22 && mghk_time_3 > 0)
{
    if (mghk_time_3 % 60 == 0)
    {
        var p_;
        if(face == 0) p_ = -5;
        else p_ = 5
        var i,j;
        var l_list = ds_list_create();
        for (i = 1; i <= 20 ; i ++)
            for (j = 1; j <= 6; j ++)
            {
                var a = scr_xuan_guai(x+p_*i,y-70+j*5,25);
                if (a != noone)
                    if(ds_list_find_index(l_list,a) == -1)
                        for(var k = 1; k <= 2 k ++)
                        {
                            instance_create(x+5*i,y-70,obj_raceter_gpcc_2);
                            scr_deal_damage(a,attack*0.5);
                            ds_list_add(l_list,a);
                        }
            }
    }
    mghk_time_3 --;
    if(mghk_time_3 <= 0){T = 0;}//閺夆晜绋戦崣鍡楊嚗閸涱喗绨氭俊顖椻偓宕囩
}