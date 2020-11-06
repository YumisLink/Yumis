var l = string_length(argument1);
var name = " ";
var tag = 'f';
var d_y = 0;
x -= 200;
aha = 1;
for (var i = 0; i <= l; i ++)
{
    if (string_char_at(argument1,i) == '/')
    {
        if (string_char_at(argument1,i+1) == '1') tag = '1';
        if (string_char_at(argument1,i+1) == '2') tag = '2';
        if (string_char_at(argument1,i+1) == '3') tag = '3';
        if (string_char_at(argument1,i+1) == '4') tag = '4';
        if (string_char_at(argument1,i+1) == '5') tag = '5';
        if (string_char_at(argument1,i+1) == '6') tag = '6';
        if (string_char_at(argument1,i+1) == '7') tag = '7';
        if (string_char_at(argument1,i+1) == '8') tag = '8';
        if (string_char_at(argument1,i+1) == '9') tag = '9';
        if (string_char_at(argument1,i+1) == 'a') tag = 'a';
        if (string_char_at(argument1,i+1) == 'b') tag = 'b';
        if (string_char_at(argument1,i+1) == 'c') tag = 'c';
        if (string_char_at(argument1,i+1) == 'd') tag = 'd';
        if (string_char_at(argument1,i+1) == 'e') tag = 'e';
        if (string_char_at(argument1,i+1) == 'f') tag = 'f';
        i ++;
       
    }
    else 
    {
        if (string_char_at(argument1,i) == '\' && string_char_at(argument1,i+1) == 'n')
        {
            i ++;
            var bb = instance_create(x,d_y,obj_draw_text);
            bb.tag = tag;
            bb.name = name;
            name = " ";
            bb.font = argument0;
            bb.master = master.id;
            d_y += 10 + font_get_size(argument0);
        }
        else name += string_char_at(argument1,i);
    }
}
bb = instance_create(x+20,y,obj_draw_text_back);
bb.dy = argument2;  bb.dx = x + 15 * (font_get_size(argument0)+10);
bb.master = master.id;
bb = instance_create(x+20,y,obj_draw_text_bk);
bb.dy = argument2;  bb.dx = x + 15 * (font_get_size(argument0)+10);
bb.master = master.id;
bb.tag = '0';