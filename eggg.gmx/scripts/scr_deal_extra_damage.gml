var damage = argument2 * 1-(0.06*argument1.mag_defense/(1+argument1.mag_defense*0.06));
damage *= 1 - argument1.defense
if (damage <= 1)damage = 1; 
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