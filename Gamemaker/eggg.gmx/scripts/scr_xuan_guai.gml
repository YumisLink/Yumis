var a;
var z = argument0;
var zz = argument1;
var zzz = argument2;
a = collision_circle(z,zz,zzz,obj_lajiguai,1,1);
if (a != noone)
    return a;
glo_score = 1;
a = collision_circle(z,zz,zzz,obj_red_sy_boos,1,1);
if (a != noone)
    return a; 
glo_score = 2;
a = collision_circle(z,zz,zzz,obj_red_sy_boos_zhaozi,1,1);
if (a != noone)
    return a; 
glo_score = 3;
a = collision_circle(z,zz,zzz,obj_yueguang,1,1);
if (a != noone)
    return a; 
glo_score = 4;
a = collision_circle(z,zz,zzz,obj_matejia,1,1);
if (a != noone)
    return a; 
glo_score = 5;
a = collision_circle(z,zz,zzz,obj_matejia_dun,1,1);
if (a != noone)
    return a; 
glo_score = 6;
   
return noone;
//    ar0 = x    ar1 = y   ar2 = 閸楀﹤绶?