if (T == 1 && hp <= 0){T = 2; hp = 3000;}
if (T == 2 && hp <= 0){T = 3; hp = 1500;}
if (T == 3 && hp <= 0){T = 4; hp = 3000;}
if (T == 4 && hp <= 0){T = 5; hp = 3000;}
if (T == 5 && hp <= 0){T = 6; hp = 3000;}
if (T == 6 && hp <= 0){T = 7; hp = 3000;}
if (T == 7 && hp <= 0){T = 8; hp = 3000;}


if (T == 1 && time >= 300)
{
    time = 0;
    var k = instance_create(x,y,obj_enemy_star);
    k.damage = 200;
    k.speed = point_distance(x,y,main.x,main.y)/100;
    k.dspeed = -1 * k.speed / 200;
    k.maxtime = 200;
    k.four_star_boom = true;
    k.direction = point_direction(x,y,main.x,main.y);
    k.starlight = true;
    
    for (var i = 1;i <= 20; i ++)
    {
        var a;
            
        a = instance_create(x + i/10 * 150,y - sqrt(4-(i/10-2) * (i/10-2)) * 150,obj_enemy_bullet);
        a.damage = 200;
        a.x90 = 1;
        a.x180 = 1;
        a.x270 = 1;
        a.master = id;
        a.rool = true
        a.rool_speed = 0.9
            
        a = instance_create(x + i/10 * 150,y + sqrt(4-(i/10-2) * (i/10-2)) * 150,obj_enemy_bullet);
        a.damage = 200;
        a.x90 = 1;
        a.x180 = 1;
        a.x270 = 1;
        a.master = id;
        a.rool = true
        a.rool_speed = 0.9
            
    }    
}