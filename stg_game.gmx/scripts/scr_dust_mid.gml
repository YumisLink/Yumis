if (T == 1 && hp <= 0){T = 2; hp = 3000;}
if (T == 2 && hp <= 0){T = 3; hp = 1500;}
if (T == 3 && hp <= 0){T = 4; hp = 3000;}
if (T == 4 && hp <= 0){T = 5; hp = 3000;}
if (T == 4 && hp <= 0){T = 6; hp = 3000;}

if (T == 1 && time >= 150)
{
    time = 0;
    for (var i = 1; i <= 36; i ++)
    {
        var a = instance_create(x,y,obj_enemy_bullet);
        a.direction = i * 10;
        a.speed = 2;
        a.damage = 200;
    }
}
if (T == 2 && time >= 350)
{
    time = 0;
    midT2dir = point_direction(x,y,main.x,main.y)-60
    midT2 = 100;
    randomize();
    for (var i = 1; i <= 25; i ++)
    {
        var a = instance_create(x + i*35*dcos(midT2dir),y - i*35*dsin(midT2dir),obj_enemy_bullet);
        a.direction = random_range(0,360);
        a.speed = 0.2;
        a.damage = 200;
    }
}
if (T == 2 && midT2 > 0)
{
    midT2 --;
    if (midT2 <= 50)
    {
        if (midT2 % 5 == 0)
        {
            midT2dir += 12;
            randomize();
            for (var i = 1; i <= 25; i ++)
            {
                var a = instance_create(x + i*35*dcos(midT2dir),y - i*35*dsin(midT2dir),obj_enemy_bullet);
                a.direction = random_range(0,360);
                a.speed = 0.2;
                a.damage = 200;
            }
        }
    }
}

if (T == 3 && time >= 200)
{
    time = 0;
    midT2dir = point_direction(x,y,main.x,main.y);
    midT3dir = point_direction(x,y,main.x,main.y) + 180;
    midT3 = 180;
    
    var a = instance_create(x,y,obj_enemy_bullet);
    a.direction = midT2dir;
    a.speed = 2.5;
    a.damage = 200;
    
    var a = instance_create(x,y,obj_enemy_bullet);
    a.direction = midT3dir;
    a.speed = 2.5;
    a.damage = 200;
}
if (T == 3 && midT3 > 0)
{
    midT3 --;
    midT2dir += 11;
    midT3dir += 11;
    
    var a = instance_create(x,y,obj_enemy_bullet);
    a.direction = midT2dir;
    a.speed = 2.5;
    a.damage = 200;
    
    var a = instance_create(x,y,obj_enemy_bullet);
    a.direction = midT3dir;
    a.speed = 2.5;
    a.damage = 200;
}
if (T == 4 && time >= 200)
{
    time = 0;
    var qq = point_direction(x,y,main.x,main.y);
    for (var i = 1; i <= 1; i ++)
    {
        if (i == 1)
        for (var j = 1; j <= 13; j ++)
        {
            var a = instance_create(x,y,obj_enemy_bullet);
            a.direction = qq -60 + j * 10;
            a.speed = 2;
            a.damage = 200;
            a.boom = 1;
        
        }
    }
}

if (T == 5 && time >= 300)
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




















