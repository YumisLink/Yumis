for (var j = 1; j <= 4;j ++)
{
    for (var i = 0; i <= 9; i ++)
    {
        var a = instance_create(x,y,obj_enemy_bullet);
        a.speed = argument0 - (-1+i) * argument0 / 16;
        a.damage = 200;
        a.direction = 90 * j + i * 5;
    }
    for (var i = 0; i <= 9; i++)
    {
        var a = instance_create(x,y,obj_enemy_bullet);
        a.speed = argument0 - (-1+i) * argument0 / 16;
        a.damage = 200;
        a.direction = 90 * j - i * 5;
    }
}
