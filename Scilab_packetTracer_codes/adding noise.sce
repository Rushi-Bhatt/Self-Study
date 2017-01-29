figure
t=0:50
y=4*sin(2*%pi*t/10)
subplot(311)
title("Original Signal")
plot(t,y)
x=10*rand(t)
z=y+x
subplot(312)
title("Signal after adding noise")
plot(t,z)
subplot(322)
r=z-x
title("Signal after removing noise")
plot(t,r)
