run('head.m')
x_init=[20,10,0]; %������ʼλ��
v_init=[20,10,0];%������ʼ�ٶ�
v_suggest=[20,10,30]; %������ʼ�����ٶ�
global CAR ; 
for i=1:N
    
CAR(i).x=x_init(i);
CAR(i).v=v_init(i);  %��¼ʵʱ�ٶ�
CAR(i).a=0;
CAR(i).v_suggest=v_suggest(i);   %���������ٶ�

end