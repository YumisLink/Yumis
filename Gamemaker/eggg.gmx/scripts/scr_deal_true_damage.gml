randomize();
if (argument1.wudi == 1)return 0;
var damage = argument2;
damage *= argument0.skillpower;
argument1.hp -= damage;
if (damage > 9999999)
{
    instance_create(argument1.x,argument1.y-100,obj_8ge9);
}
else
{
    var k = instance_create(argument1.x,argument1.y-100,obj_draw_damage1);
    k.damage = damage;
    k.gulu = 0;
}
//k = instance_create(argument0.x,argument0.y-100,obj_draw_damage2);
//k.damage = damage;