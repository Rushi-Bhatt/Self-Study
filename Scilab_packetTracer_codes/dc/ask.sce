x=[1 0 1 1 0];
l=length(x);
z=-3:3;
plot(l,z);
plot(0:3*l,0,"-")
for i=0:l-1
    ts=[i*3:0.001:(i*3)+3]
    
    if(x(i+1)==1) then
        plot(ts,(sin(2*%pi*ts)));
    else
        plot(ts,(sin(2*%pi*ts+%pi)));
    end
end
