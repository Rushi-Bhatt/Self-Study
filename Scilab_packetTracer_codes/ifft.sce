t=0:100;
x=1*sin(2*%pi*t/100);
y=1/2*sin(2*%pi*t/100);
z=x+y;
figure;
plot(z);
p=fft(z);
figure;
plot(p);
q=ifft(p);
figure;
plot(q);
