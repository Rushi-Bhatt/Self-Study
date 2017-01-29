a=[0 1 0 0 1 1 1 0]
xtitle('Plotting NRZ-I According To Input','X Axis')
y=-3:3;
plot(10,y)
//figure;
n=length(a)
s=1;

for k=1:n
    if(a(k)==0) then
        plot((k*10):(k*10)+10,s,"X")
    else
        if(s==1) then
            s=-1;
        else
            s=1;
        end
        plot((k*10):(k*10)+10,s,"X")
        for j=1:15
            plot((k*10),-1+(j/7.5),"*")
        end
        end
end
set(gca(),"grid",[1 1])