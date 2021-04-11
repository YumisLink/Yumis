leftcd --;
if (weapen == 0){
    waepen_huifu++;
    if (weapen_huifu == 100) weapen = 60;
}
if (mouse_button = mb_left && cd == 0 && allhealth > 0 && leftcd == 0 && weapen > 0){
    randomize();
    var a = instance_create(x,y,obj_shoot);
    a.direction = random_range(0,20)+point_direction(x,y,mouse_x,mouse_y)-10;
    a.em = false;
    a.speed = 10;
    a.attack = 75;
    uncd = 100
    allhealth -= 1;
    leftcd = 3;
    return 0;
}
if (mouse_button = mb_right && cd == 0 && allhealth > 0 && rightcd == 0 && weapen > 15){
    randomize();
    var i = 0,a;
    udirection = point_direction(x,y,mouse_x,mouse_y) - 10;
    for (i = 0; i <= 3;i ++;){
        a = instance_create(x,y,obj_shoot_zhuoyuyou_right);
        a.direction = udirection + i * 10;
        a.em = false;
        a.speed = 10;
        a.attack = 250;
        uncd = 100
        allhealth -= 15;
    }
    leftcd = 100;
}
