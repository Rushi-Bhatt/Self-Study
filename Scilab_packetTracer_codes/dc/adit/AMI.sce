a=[1 1 0 1 0 1 ]
xtitle('Plotting Graph According To Input')
xtitle( '            1                        1                        0                        1                        0                        1', 'X axis', 'Y axis', 'Z axis' ) ;
y=-5:5;
plot(10,y)
//figure;
n=length(a)
s=1

for k=1:n
    if(a(k)==0) then
        plot((k*10):(k*10)+10,0,".")
        if(a(k+1)==1) then
          if(s==1) then
              for j=1:20
                  plot((k*10)+10,j/20,".")
              end
                  
          else
              for j=1:12
                  plot((k*10)+10,-1+j/12,".")
              end 
           
           end
        end
        
          
    else
        plot((k*10):(k*10)+10,s,".")
        if(s==-1) then
                s=1
            else
                s=-1
            end
    if(a(k+1)==0) then
          if(s==1) then
              for j=1:20
                  plot((k*10)+10,-1+j/20,".")
              end
                  
          else
              for j=1:40
                  plot((k*10)+10,j/40,".")
              end 
           
           end
      end
      
      if(a(k+1)==1) then
          
              for j=1:40
                  plot((k*10)+10,-1+j/20,".")
              end
                  
       end

    
    end
end
set(gca(),"grid",[1 1])