p = polyfit([0,15,25,40,50],[100,90,20,3,0],3);
x=0:0.1:50;
y = polyval(p,x);
plot(x,y)