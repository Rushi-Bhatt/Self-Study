x=[1,1,0,0,1,1,1]
l=length(x);
a=gca();
q=1;

a.data_bounds=[0,-2;10,+2];
for i=1:l
    if(x(i)==0)
         q=q;
        
     
     plot2d3(i-1,-1:1)
      plot((i-1:0.00001:i-0.5),q) 
      plot2d3(i-0.5,-1:1)
      plot(i-0.5:0.00001:i,-q)  
       
    end    
    if(x(i)==1)
          q=-q;
           
           
      plot(i-1:0.00001:i-0.5,q) 
      plot2d3(i-0.5,-1:1)
      plot(i-0.5:0.00001:i,-q)  
     
    end
              
end  
       
xgrid(5)
