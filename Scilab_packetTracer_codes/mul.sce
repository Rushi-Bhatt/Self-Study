figure
t=0:100
y=1*sin(2*%pi*t/10)
subplot(411)
title('First Analog Signal');
plot(t,y)
subplot(412)
title('Second Analog Signal');
x=1*sin(2*%pi*t/20)
plot(t,x)
subplot(413)
title('Multiplication of both Signals');
//disp (x)
//disp (y)
l=length(x)
//disp (l)
for i=1:l
    z(i)=y(i)*x(i);
end
plot(t,z)
subplot(414)
title('Dividing multipied signal by second signal');
for i=1:l
    if (x(i)~=0) then
        q(i)=z(i)/x(i);
    end
end
plot(t,q)