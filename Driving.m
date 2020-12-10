function  Driving()
 run('head.m');
global CAR; 

for i=1:N
    CAR(i).v=CAR(i).v+CAR(i).a*delta_time;
    CAR(i).x=CAR(i).x+(CAR(i).v*delta_time+0.5*CAR(i).a*delta_time^2);
end

end

