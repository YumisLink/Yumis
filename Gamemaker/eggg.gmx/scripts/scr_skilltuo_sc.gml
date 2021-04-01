if (keyboard_check_pressed(vk_left))
{
    skill_pressed *= 10;
    skill_pressed += 1;
}
if (keyboard_check_pressed(vk_right))
{
    skill_pressed *= 10;
    skill_pressed += 2;
}
if (keyboard_check_pressed(vk_up))
{
    skill_pressed *= 10;
    skill_pressed += 3;
}
if (keyboard_check_pressed(vk_down))
{
    skill_pressed *= 10;
    skill_pressed += 4;
}
if (skill_pressed > 1000)
{
    skill_pressed %= 1000;
}

if (keyboard_check_pressed(ord(' ')) && (T == 0))
{
    buff_open = 1;
    skill_pressed = 0;
}