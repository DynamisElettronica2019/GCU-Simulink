p = polyfit([15,25,40,50],[100,20,3,0],3);
x=15:0.1:50;
y = polyval(p,x);
plot(x,y)