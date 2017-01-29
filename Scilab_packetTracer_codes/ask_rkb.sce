m=[1 0 0 0 1 0 1 1 0]
e=1
ask=[]
n=0:0.001:1
for i=1:length(m)
    if m(i)==0 then
        ask=[ask 0*sin(2*%pi*e*n)]
    else
        ask=[ask 1*sin(2*%pi*e*n)]
    end
end
plot(ask);
xgrid(1)
