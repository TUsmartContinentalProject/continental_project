clear,clc;
run('global_data.m');
run('head.m');
real_time=0;
while real_time<end_time       %��ѭ��
    Drive_statue();  %�жϸ������ٶ�
    Driving();
    real_time=real_time+delta_time;
end

%������ 21:32