randomize();
if (argument1.wudi == 1)return 0;
var i = random(100);
if (i <= argument0.hit_rate - argument1.evade + 100)
{
    var gulu = 0;
    damage = argument2;
    if (random(100) <= argument0.criti) {damage *= 1+argument0.critical/100;gulu ++;}
    damage *= argument0.skillpower;
    damage *= 1 - argument1.defense;
    damage *= 1 + argument0.element/222 * 10
    damage *= 1 + argument0.yellow/100;
    if (argument0.name == "raceter" && argument0.equip_rbjrzn_have)
    {
        damage *= 1 + (argument0.maxhp - argument0.hp)/argument0.maxhp / 2
    }
    if (argument1.phy_defense > 0) damage *= 1-(argument1.phy_defense*0.006/(argument1.phy_defense*0.006+1))
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
        k.gulu = gulu;
    }
    //k = instance_create(argument0.x,argument0.y-100,obj_draw_damage2);
    //k.damage = damage;
    scr_equip_attack(argument1,argument0,scr_check_face(argument0.id));
    if (argument1.sprite_index == spr_xueluke)
    {
        randomize();
        if (irandom_range(1,5) = 1)
        {
            var a = instance_create(argument1.x,argument1.y-300,obj_luke_powerball);
            randomize();
            a.move_x = random_range(-2,2);
            a.move_y = 1;
            a.master = argument1;
        }
    }
}
else
{
    instance_create(argument1.x,argument1.y-100,obj_draw_miss);
    if (argument0.name == "raceter")
    {
        if (argument0.now_buff == 1)
        {
        var a = instance_create(argument1.x,argument1.y,obj_raceter_skill_ice2);
        a.master = argument0.id;
        }
    }    
}

/*
ar0 = 闁衡偓鐠囨彃姣婇柡?   ar1 闂傚啯褰冮悾褔寮?  ar2 = 濞寸鍊曢?

randomize();
if (argument1.wudi == 1)return 0;
var i = random(100);
if (i <= argument0.hit_rate - argument1.evade + 100)
{
    var gulu = 0;
    var damage = argument2 * (1-(0.006*argument1.phy_defense/(1+argument1.phy_defense*0.006)));
    if (random(100) <= argument0.criti) {damage *= 1+argument0.critical;gulu ++;}
    damage *= 1 + argument0.element / 222;
    damage *= 1 + argument0.white;
    damage *= 1 + argument0.yellow;
    damage *= argument0.skillpower;
    damage *= 1 - argument1.defense;
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
        k.gulu = gulu;
    }
    //k = instance_create(argument0.x,argument0.y-100,obj_draw_damage2);
    //k.damage = damage;
    scr_equip_attack(argument1,argument0,scr_check_face(argument0.id));
}
else
{
    instance_create(argument1.x,argument1.y-100,obj_draw_miss);
    if (argument0.name == "raceter")
    {
        if (argument0.now_buff == 1)
        {
            var a = instance_create(argument1.x,argument1.y,obj_raceter_skill_ice2);
            a.master = argument0.id;
        }
    }    
}
/*
ar0 = 闁衡偓鐠囨彃姣婇柡?   ar1 闂傚啯褰冮悾褔寮?  ar2 = 濞寸鍊曢?