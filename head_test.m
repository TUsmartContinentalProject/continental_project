
N=3; %车辆数目
acc=2; %加速度 1m/s2
v_max=40;  % 道路最高速度 单位m/s
X=zeros(1,N)';%全局变量，各车的位置
Y=zeros(1,N)';


%y=[]
x_init=[100,50,0]; %车辆初始位置
v_init=[6,5,8];%车辆初始速度
v_suggest=[9,10,15]; %车辆初始建议速度
y_init=[2,2,2];

%产生编号
car(:,7)=randperm(N);
car(:,7)=sort(car(:,7));

car(:,8)=[1,1,0];%重排标志位 客车=1，主车为0，其他-1

for i=1:N
    
car(i,1)=x_init(i);
car(i,2)=v_init(i);  %记录实时速度
car(i,3)=0;  %加速度
car(i,4)=v_suggest(i);   %车辆建议速度
car(i,5)=0;%红灯标志 
car(i,6)=y_init(i);% y
end





