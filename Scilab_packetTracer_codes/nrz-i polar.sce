x=[1,0,0,1,1,1]
l=length(x);
a=gca();
q=1;
a.data_bounds=[0,-2;10,+2];
for i=1:l
    if(x(i)==0)
        
        q=q;
        
    else
        
        q=-q;
         
    end
    plot(i-1:i,q)          
end         
xgrid(0)