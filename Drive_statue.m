function  Drive_statue()
run('head.m')
global CAR; 
for i=1:N-1
    if CAR(i).v<=CAR(i+1).v_suggest
        distance=(CAR(i).x-CAR(i+1).x);
        if distance>50
            if  CAR(i+1).v<CAR(i+1).v_suggest
             CAR(i+1).a=acc;
             elseif CAR(i+1).v==CAR(i+1).v_suggest
            CAR(i+1).a=0;
            else
            CAR(i+1).a=-acc;
            end
        else
       CAR(i+1).a=0;
       safty_distance=((CAR(i+1).v)^2-(CAR(i).v)^2)/(2*acc)+3;  %��ȫ����
       if safty_distance>(CAR(i).x-CAR(i+1).x)  %���泵����ײ�������ԣ���ֱ��С�ڰ�ȫ�����ɲ��
            CAR(i+1).a=-acc;
            if CAR(i).v>=CAR(i+1).v
                 CAR(i+1).a=0;
            end
       end
       end
    else
        if  CAR(i+1).v<CAR(i+1).v_suggest
             CAR(i+1).a=acc;
        elseif CAR(i+1).v==CAR(i+1).v_suggest
            CAR(i+1).a=0;
        else
            CAR(i+1).a=-acc;
        end
    end
end

end


