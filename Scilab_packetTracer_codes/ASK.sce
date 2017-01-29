x=[1,0,0,0,1,0,1]
l=length(x);
a=gca();
a.data_bounds=[0,-10;10,+10];
for i=1:l
   if(x(i)==1)
       n=i:0.001:i+1
      y=3*sin(2*%pi*n/.05)
      plot(y)
      
     else
         plot(i:i+1,0) 
      end
  end
  xgrid(5)
         