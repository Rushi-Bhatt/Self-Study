x=[1,1,0,0,1,1,1]
l=length(x);
a=gca();
q=1;


a.data_bounds=[0,-2;10,+2];
for i=1:l
    if(x(i)==0)
             plot(i-1:0.00001:i,0)
    end    
    
    if(x(i)==1)
        q=-q
        if(q=-1)
          plot2d3(i-1,0:-q)
          plot(i-1:0.00001:i,-q)
          plot2d3(i,0:-q)
       else
           plot2d3(i-1,-q:0)
           plot(i-1:0.00001:i,-q)
           plot2d3(i,-q:0)
       end      
 end
end              
  
       
xgrid(5)
