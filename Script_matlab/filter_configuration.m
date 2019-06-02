s = tf([1,0],1);
F = 1/(1+s/(2*pi*10));      %filtro a 10Hz
F_z=c2d(F,0.001);