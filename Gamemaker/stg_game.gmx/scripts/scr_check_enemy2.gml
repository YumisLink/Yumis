var a;
var z = argument0;
var zz = argument1;
var zzz = argument2;
a = collision_circle(z,zz,zzz,obj_dust_boss,1,1);
if (a != noone)
    return a;
a = collision_circle(z,zz,zzz,obj_enemy_bullet,1,1);
if (a != noone)
    return a;
return noone;
//    ar0 = x    ar1 = y   ar2 = 半径