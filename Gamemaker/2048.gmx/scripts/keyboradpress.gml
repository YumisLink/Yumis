var i = argument0, j = argument1;
var orz = argument2,lo,flag = 0;
if (orz == "Up")
    while(true)
    {   
        if (j-1 < 0) break;//如果出界则退出
        if (in_place[i,j-1] == spr_null)//如果有空位则上移
        {
            flag = 1;
            in_place[i,j-1] = in_place[i,j];
            in_place[i,j] = spr_null;
        }
        else
            if (in_place[i,j-1] == in_place[i,j])//上下两个是否是相同的图片
            {
                for(lo = 0; lo < 16; lo ++)//判断是i,j对应哪个图片
                    if (in_place[i,j] == obj[lo])
                    {
                        flag = 1;
                        in_place[i,j] = spr_null;
                        in_place[i,j-1] = obj[lo+1];
                        scor += sco[lo+1];
                        break;
                    }
                break;
            }
    j--;
    }
if (orz == "Down")
    while(true)
    {   
        if (j+1 > 4) break;//如果出界则退出
        if (in_place[i,j+1] == spr_null)//如果有空位则下移
        {
            in_place[i,j+1] = in_place[i,j];
            in_place[i,j] = spr_null;
            flag = 1;
        }
        else
            if (in_place[i,j+1] == in_place[i,j])//上下两个是否是相同的图片
            {
                for(lo = 0; lo < 16; lo ++)//判断是i,j对应哪个图片
                    if (in_place[i,j] == obj[lo])
                    {
                        in_place[i,j] = spr_null;
                        in_place[i,j+1] = obj[lo+1];
                        flag = 1;
                        scor += sco[lo+1];
                        break;
                    }
                break;
            }
    j++;
    }
if (orz == "Left")
    while(true)
    {   
        if (i-1 < 0) break;//如果出界则退出
        if (in_place[i-1,j] == spr_null)//如果有空位则左移
        {
            in_place[i-1,j] = in_place[i,j];
            in_place[i,j] = spr_null;
            flag = 1;   
        }
        else
            if (in_place[i-1,j] == in_place[i,j])//上下两个是否是相同的图片
            {
                for(lo = 0; lo < 16; lo ++)//判断是i,j对应哪个图片
                    if (in_place[i,j] == obj[lo])
                    {
                        in_place[i,j] = spr_null;
                        in_place[i-1,j] = obj[lo+1];
                        flag = 1;
                        scor += sco[lo+1];
                        break;
                    }
            }
    i--;
    }
if (orz == "Right")
    while(true)
    {   
        if (i+1 > 4) break;//如果出界则退出
        if (in_place[i+1,j] == spr_null)//如果有空位则上移
        {
            in_place[i+1,j] = in_place[i,j];
            in_place[i,j] = spr_null;
            flag = 1;   
        }
        else
            if (in_place[i+1,j] == in_place[i,j])//上下两个是否是相同的图片
            {
                for(lo = 0; lo < 16; lo ++)//判断是i,j对应哪个图片
                    if (in_place[i,j] == obj[lo])
                    {
                        in_place[i,j] = spr_null;
                        in_place[i+1,j] = obj[lo+1];
                        flag = 1;
                        scor += sco[lo+1];
                        break;
                    }
                break
            }
    i++;
    }
return flag;
