a=[1 0 1 1 0 0 0 1]
title('Plotting Graph According To Input')
y=-3:3;
plot(10,y)
figure;
n=length(a)

for k=1:n
    if(a(k)==0) then
        plot((k*10):(k*10)+10,1,"X")
    else
        plot((k*10):(k*10)+10,2,"X")
        end
end
set(gca(),"grid",[1 1])