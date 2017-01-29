a=[0 1 0 0 1 1 1 0]
xtitle('Plotting Graph According To Input')
y=-3:3;
plot(10,y)
//figure;
n=length(a)

for k=1:n
    if(a(k)==0) then
        plot((k*10):(k*10)+10,1,"X")
        if(a(k+1)==1) then
            for j=1:20
                plot((k*10)+10,-1+j/10,"*")
            end
        end
        
          
    else
        plot((k*10):(k*10)+10,-1,"X")
        if(a(k+1)==0) then
            for j=1:20
                plot((k*10)+10,-1+j/10,"*")
            end
        end
    
    end
end
set(gca(),"grid",[1 1])