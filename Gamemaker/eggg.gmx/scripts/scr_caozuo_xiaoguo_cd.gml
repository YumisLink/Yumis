if (jump_in) // 閻犲搫鐤囩粚顒佺▔鐎ｎ喗顎?
{
    y -= jump;
    jump -= 0.06;
    if (back_jump == 1)
        x += scr_check_face(id)*-1.5;
}

if (y >= room_height-100) {jump_in = 0; y = room_height-100; back_jump = 0}//閻犲搫鐤囩粚顒傜磼閹惧瓨灏?