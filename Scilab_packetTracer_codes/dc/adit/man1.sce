a=[0 1 0 0 1 1]
xtitle('Plotting Graph According To Input')
xtitle( '0                        1                    0                        0                        1                        1', 'X axis', 'Y axis', 'Z axis' ) ;
y=-3:3;
plot(10,y)
set(gca(),"grid",[1 1])
n=length(a)

for k=1:n
    if(a(k)==1) then
        plot((k*10):(k*10)+5,-1,"*")
        for j=1:20,
            plot((k*10)+5,-1+(j/10),"*")
        end
        plot((k*10)+5:(k*10)+10,1,"*")
        if(a(k+1)==1) then
            for j=1:20
                plot((k*10)+10,-1+(j/10),"*")
            end
        end
                      
    else
        plot((k*10):(k*10)+5,1,"*")
        for j=1:20,
            plot((k*10)+5,-1+(j/10),"*")
        end
        plot((k*10)+5:(k*10)+10,-1,"*")
        if(a(k+1)==0) then
            for j=1:20
                plot((k*10)+10,-1+(j/10),"*")
            end
        end
    end
end
set(gca(),"grid",[1 1])