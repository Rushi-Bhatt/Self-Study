n=1:100
x=5*sin(2*%pi*n/10)
figure
plot(x)
a=fft(x)
figure
plot(a)
