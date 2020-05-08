function [ydot] = velocity_model(t, x)

c = 1;
m = 10;
gamma = 0.01;

v = x(1);
u = x(2);

ydot = zeros(2,1);
ydot(1) = (c/m)*u - gamma*v;
ydot(2) = 0;

end