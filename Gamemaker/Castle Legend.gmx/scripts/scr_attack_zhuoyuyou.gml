leftcd --;
rightcd --;
if (weapen <= 0){
    weapen_huifu++;
    if (weapen_huifu == 100) {weapen = 60; weapen_huifu = 0;}
    return 0;
}
if (mouse_button = mb_left && cd == 0 && allhealth > 0 && leftcd <= 0 && weapen > 0){
    randomize();
    var a = instance_create(x,y,obj_shoot);
    a.direction = random_range(0,20)+point_direction(x,y,mouse_x,mouse_y)-10;
    a.em = false;
    a.speed = 10;
    a.attack = 45;
    uncd = 100
    allhealth -= 1;
    leftcd = 3;
    weapen -= 1;
    return 0;
}
if (mouse_button = mb_right && cd == 0 && allhealth > 14 && rightcd <= 0 && weapen > 1){
    randomize();
    var i = 0,a;
    udirection = point_direction(x,y,mouse_x,mouse_y) - 10;
    for (i = 1; i <= 3;i ++;){
        a = instance_create(x,y,obj_shoot_zhuoyuyou_right);
        a.direction = udirection + i * 10;
        a.em = false;
        a.speed = 10;
        a.attack = 150;
        uncd = 100
        allhealth -= 15;
        cd = 50;
    }if (weapen-15 <= 0)
        weapen = 0;
    else
        weapen -= 15;
    rightcd = 100;
}