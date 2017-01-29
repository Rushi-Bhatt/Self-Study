clear all
//play with different values of fo
fo = 4;
N = 100; 
T = 2*%pi;
t = linspace(0,T,N);

//the function and its fft (shifted so zero frequency occurs in the middle)
f = sin(2*%pi*fo*t);
figure()
plot(fft(f))
ft = fftshift(fft(f));

// frequency goes in steps 1/T
s = (-N/2+1:N/2) * 1/T;
figure(2),plot(s,abs(ft)),title('fourier')