//Hamming Encoding
//Code Word Length = 7, Message Word length = 4, Parity bits =3
clear();
close;
clc;
//Getting Message Word
m3 = input('Enter the 1 bit(MSb) of message word: ');
m2 = input('Enter the 2 bit of message word: ');
m1 = input('Enter the 3 bit of message word: ');
m0 = input('Enter the 4 bit(LSb) of message word: ');
//Generating Parity bits
  b2 = bitxor(m1,bitxor(m3,m2));
  b1 = bitxor(m0,bitxor(m3,m2));
  b0 = bitxor(m0,bitxor(m1,m3));
  m = [m3 m2 m1 m0];
  b = [b2 b1 b0];
  C = [m3 m2 m1 b2 m0 b1 b0];
disp('DISPLAY SECTION')
  disp(m,'Message Word')
  disp(b,'Parity Bits')
  disp(C,'CodeWord')
  disp("   ");
  disp("   ");
disp('Enter the Recieved code')
for i=7:-1:1
    d(i,:)=input('Enter:');
end    
d0=bitxor(d(5),bitxor(d(7),bitxor(d(3),d(1))))
d1=bitxor(d(7),bitxor(d(6),bitxor(d(3),d(2))))
d2=bitxor(d(7),bitxor(d(6),bitxor(d(5),d(4))))
if(d0==0 & d1==0 & d2==0)
    disp('NO ERROR');
else
    disp('ERROR DETECTED'); 
end       
disp(d0,d1,d2)
