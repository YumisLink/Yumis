if (argument0 == 1){
    a = instance_create(x,y,obj_shoot);
    a.em = true;
    a.attack = 300;
    a.direction = point_direction(x,y,inst_FE09C49D.x,inst_FE09C49D.y);
    a.speed = 5;
    a.image_index = 1;
    attack_time = 0;
}
if (argument0 == 2){
    var i = 0;
    udirection = point_direction(x,y,inst_FE09C49D.x,inst_FE09C49D.y) - 60;
    for (i = 0; i <= 5; i ++){
        a = instance_create(x,y,obj_shoot);
        a.em = true;
        a.attack = 50;
        a.direction = udirection + i * 30
        a.speed = 2.5;
        a.image_index = 1;
    }
    attack_time = 0;
}
if (argument0 == 3){
    a = instance_create(x,y,obj_shoot);
    a.em = true;
    a.attack = 20;
    a.direction = point_direction(x,y,inst_FE09C49D.x,inst_FE09C49D.y);
    a.speed = 1.5;
    a.image_index = 1;
    attack_time = 0;
}