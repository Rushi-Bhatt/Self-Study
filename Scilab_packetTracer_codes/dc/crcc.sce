clc
msg=input('Input whole message inside []: ');
gen=input('Input whole generator inside []: ');
g=length(gen);
n=length(msg);
disp(msg);
disp(gen);
mseg=[msg zeros(1,g-1)];
disp(mseg);
mseg2=mseg;
for i=1:n
    if mseg(i)==1 then
        for j=1:g
            mseg(i+j-1)=bitxor(mseg(i+j-1),gen(j));
        end
    end
end
net=bitor(mseg2,mseg);
disp(mseg,'mseg')
disp(net,'code');
disp(net(n+1:n+g-1),'crc');
