t=(0:0.001:9*%pi);
plot2d1(t,1.5*squarewave(t))
y=fft(t)
figure
plot(y)
 
