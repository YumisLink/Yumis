var show = argument3;
var queue_x = ds_queue_create();
var queue_y = ds_queue_create();
var queue_range = ds_queue_create();
ds_queue_enqueue(queue_range,argument2);
ds_queue_enqueue(queue_x,argument0);
ds_queue_enqueue(queue_y,argument1);//引入四个变量    第一个是x坐标轴   第二个是y坐标轴   第三个是bfs的距离    第四个是显示的精灵
var xn,yn,range;
var i,j;
var use_x,use_y,use_range;
while(!ds_queue_empty(queue_x)){
    range = ds_queue_dequeue(queue_range);
    xn = ds_queue_dequeue(queue_x);
    yn = ds_queue_dequeue(queue_y);//从队列中提取  x  y  range
    if (xn % 2 == 1)// 如果在单数排
        for (i = 1; i <= 6; i++){
            use_x = xn + move_use_x_first[i];
            use_y = yn + move_use_y_first[i];
            use_range = range - 1;
            if (use_x > 0 && use_x <= 13 && use_y > 0 && use_y <= 9 && map_visited[use_x,use_y] == false){//判断是否越界      并且是否被访问过
                map_show = show;
                if (use_range >= 1){//如果距离够就继续给队列加入
                ds_queue_enqueue(queue_y,use_y);
                ds_queue_enqueue(queue_x,use_x);
                ds_queue_enqueue(queue_range,use_range);
                }
            }
        }
    else// 否则则判断复数排
        for (i = 1; i <= 6; i++){
            use_x = xn + move_use_x_second[i];
            use_y = yn + move_use_y_second[i];
            use_range = range - 1;
            if (use_x > 0 && use_x <= 13 && use_y > 0 && use_y <= 9 && map_visited[use_x,use_y] == false){//判断是否越界      并且是否被访问过
                map_show = show;
                if (use_range >= 1){//如果距离够就继续给队列加入
                ds_queue_enqueue(queue_y,use_y);
                ds_queue_enqueue(queue_x,use_x);
                ds_queue_enqueue(queue_range,use_range);
                }
            }
        }
}