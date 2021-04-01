var a = argument0;
var b = argument1;
var dam = argument2;
b.hp -= dam;
if (main.name == "zyy")
{
    if (main.qtime > 0)
        scr_recover_hp(dam/20);
}