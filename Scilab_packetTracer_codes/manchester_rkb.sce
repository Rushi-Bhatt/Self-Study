x=[1,0,0,1,1,1]
l=length(x);
a=gca();
q=1;

a.data_bounds=[0,-2;10,+2];
for i=1:l
    if(x(i)==0)
        if(i+1<=l)
         if(x(i+1)==0)
          plot2d3(i,-1:1)
      end  
     end 
      plot((i-1:0.00001:i-0.5),-1) 
      plot2d3(i-0.5,-1:1)
      plot(i-0.5:0.00001:i,1)  
     
        
    else
       if(i+1<=l)
         if(x(i+1)==1)
          plot2d3(i,-1:1) 
      end
      end
      plot(i-1:0.00001:i-0.5,1) 
      plot2d3(i-0.5,-1:1)
      plot(i-0.5:0.00001:i,-1)  
     
    end
              
end  
       
xgrid(5)