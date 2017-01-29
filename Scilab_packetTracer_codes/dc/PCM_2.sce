clf();
a=gca();
a.x_location="middle";
p=0
a=1
w=1
t=[0:0.001:2*%pi]';
wave=a*sin((w*t)+p);
subplot(2,1,1);
plot2d1(t,wave);
T=2*%pi/w;

//Sampling

ST=T/10;
q=0:ST:2*%pi;
n=size(q,"*");
//for i=0:ST:n
//    samples(i)=a*sin((w*q[i])+p);
//end
sampled_wave=a*sin((w*q)+p);
subplot(2,1,2);
b=gca();
b.x_location="middle";
plot2d3(q,sampled_wave);

//Quantization

L=8;
bits=ceil(log (8)/log (2));
delta=2*a/L;

for i=1:n
    j=0;
    for k=1:L
        if sampled_wave(i)>=(-a+(j*delta)) & sampled_wave(i)<(-a+((j+1)*delta)) then
            //quant_wave(i)=(-2*a+(2*j+1)*delta)/2;
            dec(i)=j;
            //err(i)=quant_wave(i)-sampled_wave(i);
            decimal=int(dec(i));
            bin(i)=dec2bin(decimal,3);
            disp(bin(i));
        end
        j=j+1;
    end
end
