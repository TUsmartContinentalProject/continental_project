clear,clc;
run('global_data.m');
run('head.m');
real_time=0;
while real_time<end_time       %大循环
    Drive_statue();  %判断各车加速度
    Driving();
    real_time=real_time+delta_time;
end

%王新宇 21:32