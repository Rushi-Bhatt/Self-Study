clc
clear
Vmax=+20
Vmin=-20
f=250
level=8
//square(-20,Vmin-1,20,Vmax+1)
//square(-20,Vmin-1,20,Vmax+1)
data=linspace(0,2*%pi,f/5)
disp(data);
title("flat top sampling")
plot2d2(data,Vmax*sin(data))
figure
title("point sampling")
plot2d3(data,Vmax*sin(data))
delta=(Vmax-Vmin)/level
quanta=[]
for i=1:f/5
    for j=0:level-1
        if((Vmax*sin(data(i))>Vmin+delta*j)&(Vmax*sin(data(i))<=Vmin+delta*(j+1)))
            quanta(i)=j;
            break
        end
    end
end
for i=1:f/5
    printf("\nData:%+f | Quantized Binary : %d",Vmax*sin(data(i)),quanta(i))
end
enco=[]
for i=1:f/5
    for j=0:level-1
    if quanta(i)==j then
      enco(i)=Vmin+delta*(j+0.5);
      disp(enco(i));
    end
    end
end
figure(3);
title("Encoding")
plot(data,enco)
