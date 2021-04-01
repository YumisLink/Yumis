scr_caozuo_xiaoguo_cd();//闁告柣鍔嬬紞鏃堝椽鐎涘│
if (keyboard_check(vk_left) && T == 0)//鐎归潻濡囦簺 
    {x -= 3.5;}
if (keyboard_check(vk_left) && T == 0 && (name == "vivian" && y >= room_height-120 || name != "vivian") )
    {face = 0;}
if (keyboard_check(vk_right) && T == 0)//闁告瑥纾簺
    {x += 3.5;}
if (keyboard_check(vk_right) && T == 0 && (name == "vivian" && y >= room_height-120 || name != "vivian"))
    {face = 1;}
if (keyboard_check(vk_down))
    {enter_down = 1;}
else 
    {enter_down = 0;}

if (name == "vivian")
{
    if (vs_time > 100)
        x += vs;
}
if ((jump_in == 1 || (name == "vivian" && jump_in <= 7)) && keyboard_check_pressed(ord('C')) && T == 0)//濞存粌鏈宀€鎹勭€圭姷鍎查悹?
{
    if (name == "vivian")
    {
        jump_in ++;
        jump = 6;
        if (keyboard_check(vk_left))
        {
            vs = -3;
            vstime = 100;
        }
        if (keyboard_check(vk_right))
        {
            vs = 3;
            vstime = 100;
        }    
    }
    else 
    {
        jump_in = 2;
        jump = 6
    }
}

if (jump_in == 0 && keyboard_check_pressed(ord('C')))//缂佹鍏涚粩鏉戔枔娴ｅ啰鍎查悹?
{
    if (enter_down == 1 && (T == 0 || act_skill_rh) )
    {
        jump_in = 3;
        jump = 4;
        back_jump = 1;
        xx_time = 0;
    }
    if (enter_down == 0 && T == 0)
    {
        jump_in = 1;
        jump = 6;
    }
}
