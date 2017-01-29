m=[0 1 0 1 0 0 1 0 0]
e1=1
e2=3
fsk=[]
n=0:0.001:1
for i=1:length(m)
    if m(i)==0 then
        fsk=[fsk 1*sin(2*%pi*e1*n)]
    else
        fsk=[fsk 1*sin(2*%pi*e2*n)]
    end
end
plot(fsk);
xgrid(4)