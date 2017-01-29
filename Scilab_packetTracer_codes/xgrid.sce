x=[0,1,0,1,1,1];
l=length(x);
a=gca();
a.data_bounds=[0,-2;10,+2];

for i=1:l
    if(x(i)==0)
        plot(i-1:i,-1);
     else
         plot(i-1:i,1);
     end;
end     
xgrid(4)
            