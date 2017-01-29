t=0:200

x=3*square(2*%pi*t/100);
y=2*square(2*%pi*t/100);

z=x+y;

figure;
plot(t,x);
plot(t,y);
plot(t,z);

p=dft(x,-1);

figure;
plot(p);

