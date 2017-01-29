a=[0 1 0 0 1 1]
xtitle('Plotting Graph According To Input')
xtitle( '            0                        1                        0                        0                        1                        1', 'X axis', 'Y axis', 'Z axis' ) ;
y=-3:3;
plot(10,y)
set(gca(),"grid",[1 1])
n=length(a)
s=1;

for k=1:n
    if(a(k)==1) then
        plot((k*10):(k*10)+5,s,"*")
        for j=1:15,
            plot((k*10)+5,-1+(j/7.5),"*")
        end
        if(s==-1) then
                s=1
            else
                s=-1
            end
        plot((k*10)+5:(k*10)+10,s,"*")
        //if(a(k+1)==1) then
           // if(s==-1) then
             //  s=1
            //else
              //  s=-1
           // end
                           
            
          //  for j=1:20
            //    plot((k*10)+10,-1+(j/10),"*")
           // end
        //end
        if(a(k+1)==0) then
            for j=1:20
                plot((k*10)+10,-1+(j/10),"*")
            end
        end
                      
    else
        if(s==-1) then
                s=1
            else
                s=-1
            end
        plot((k*10):(k*10)+5,s,"*")
        for j=1:15,
            plot((k*10)+5,-1+(j/7.5),"*")
        end
        if(s==-1) then
                s=1
            else
                s=-1
            end
        plot((k*10)+5:(k*10)+10,s,"*")
        if(a(k+1)==0) then
            for j=1:20
                plot((k*10)+10,-1+(j/10),"*")
            end
        end
    end
end
set(gca(),"grid",[1 1])