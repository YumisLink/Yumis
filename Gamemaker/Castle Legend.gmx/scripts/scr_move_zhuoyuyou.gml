if (keyboard_check(16)){
    room_speed = 50;
}
else room_speed = 100;
//低速模式

if (y <= 20) y = 20;
if (y >= 748) y = 748;
if (x <= 20) x = 20;
if (x >= 980) x = 980;
//这个是判断是否出界然后拉回来。

if (pe + 1 > 1000){
    pe = 1000;
} else{
    pe++; 
}
//恢复体力

uncd --;
if (cd > 0) cd --;else cd = 0;

if (uncd <= 0){
    if (allhealth + 10 > 1200){
        allhealth = 1200;
    } else{
        allhealth += mana; 
    }
    uncd = 0;
}
//回蓝的机制

if (cd >= 0 && knock == 1){
    spex -= despex;
    if (x+spex <= 980 && x+spex >= 20) x += spex;
    spey -= despey;
    if (y+spey <= 748 && y+ spey >= 20) y += spey;
    if (cd <= 1) {knock = 0; cd = 0;image_index = 0;}
    return 0;
} 
//翻滚机制

if (cd >= 0 && knock == 2){
    a = collision_circle(x,y,50,obj_guai,1,1);
    if (a != noone) if (em != a.em) a.allhealth -= 300;
    a = collision_circle(x,y,50,obj_shoot,1,1);
    if (a != noone) if (em != a.em) a.allhealth = 0;
    uncd = 200;
    if (cd == 0){
        knock = 0;
        cd = 0;
        speed = 0;
        image_index = 0;
        return 0;
    }
}
//这个是SEI！

if (cd >= 0 && knock = 3){
    var p = instance_create(x,y,obj_shoot);
    randomize();
    p.direction = random_range(0,360);
    p.em = false;
    p.speed = 10;
    p.attack = 55;
    uncd = 100;
    allhealth += 1;
    if (cd == 0){
    knock = 0;
    }
}
//diediedie

if (keyboard_check(ord("W"))&& (knock == 0 || knock = 3)){
    if (y-2.5 >= 20) y -= 2.5; 
}
if (keyboard_check(ord("S"))&& (knock == 0 || knock = 3)){
    if (y+2.5 <= 748)y += 2.5; 
}
if (keyboard_check(ord("A"))&& (knock == 0 || knock = 3)){
    if (x-2.5 >= 20)  x -= 2.5; 
}
if (keyboard_check(ord("D"))&& (knock == 0 || knock = 3)){
    if (x+2.5 <= 980) x += 2.5; 
}
//WASD移动

if (keyboard_check(ord(" ")) && cd == 0 && fgcd <= 0 && knock == 0 && pe > 300){
    cd = 60;
    spey = 0;
    despey = 0;
    spex = 0;
    despex = 0;
    if (keyboard_check(ord("W"))){
        spey = -7.5; 
        despey = spey / 60;
    }
    if (keyboard_check(ord("S"))){
        spey = 7.5; 
        despey = spey / 60;
    }
    if (keyboard_check(ord("A"))){
        spex = -7.5; 
        despex = spex / 60;
        
    }
    if (keyboard_check(ord("D"))){
        spex = 7.5; 
        despex = spex / 60;
    }
    knock = 1;
    image_index = 1;
    pe -= 300;
}
//空格翻滚

if (keyboard_check(ord("E")) && cd == 0 && allhealth > 200 && knock == 0){
    cd = 20;
    speed = 25;
    direction = point_direction(inst_FE09C49D.x,inst_FE09C49D.y,mouse_x,mouse_y);
    knock = 2;
    image_index = 1;
    allhealth -= 200;
}
//SEI!
if (keyboard_check(ord("R")) && weapen != 60){
   weapen = 0;
}
if (keyboard_check(ord("Q")) && cd == 0 && knock == 0 && especial == 30000){
   weapen = 60;
   cd = 500;
   knock = 3;
}//进入diedieide模式