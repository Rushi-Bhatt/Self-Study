m=[1 0 0 1 0 1 0 1 0]
e=1
psk=[]
n=0:0.001:1
for i=1:length(m)
    if m(i)==0 then
        psk=[psk -1*sin(2*%pi*e*n)]
    else
        psk=[psk 1*sin(2*%pi*e*n)]
    end
end
plot(psk);
xgrid(4)