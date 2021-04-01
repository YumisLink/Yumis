randomize();
if (argument1.wudi == 1)return 0;
var i = random(100);
if (i <= argument0.hit_rate - argument1.evade + 100)
{
    
    damage = argument2
    if (random(100) <= argument0.criti) damage *= 1+argument0.critical;
    if (argument1.defense > 0) damage *= 1-(argument1.defense*0.006/(argument1.defense*0.006+1))
    argument1.hp -= damage;
    /*
    if (argument1.name == "raceter")
    {
        if (damage > argument1.hp && argument1.hbzq_cd = -1)
        {
            argument1.hbzq_cd = 9000;
            argument1.wudi = 1;
            argument1.hps += 100;
            argument1.hbzq_tag = 1;
            return 0;
        }
        if (damage/argument1.max_hp > 0.05 && argument1.now_buff == 1)
        {
            var b = instance_create(argument1.x,argument1.y,obj_raceter_dark_boom8);
            b.master = argument1;
        }
        
    }
    */
    if (damage > 99999999)
    {
        instance_create(argument1.x,argument1.y-100,obj_8ge9);
    }
    else
    {
        var k = instance_create(argument1.x,argument1.y-100,obj_draw_damage1);
        k.damage = damage;
        k.gulu = 0;
    }
}
else
{
    instance_create(argument1.x,argument1.y-100,obj_draw_miss); 
}