run('head.m')
x_init=[20,10,0]; %车辆初始位置
v_init=[20,10,0];%车辆初始速度
v_suggest=[20,10,30]; %车辆初始建议速度
global CAR ; 
for i=1:N
    
CAR(i).x=x_init(i);
CAR(i).v=v_init(i);  %记录实时速度
CAR(i).a=0;
CAR(i).v_suggest=v_suggest(i);   %车辆建议速度

end