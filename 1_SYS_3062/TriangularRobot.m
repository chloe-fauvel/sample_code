% Triangular robot function

function [robot] = TriangularRobot(x,y,theta)

center = [x y];

% Robot Triangle Shape

a = [0 -3];
b = [12 0];
c = [0 3];

% Rotation Matrix
 rot_matrix = [cos(theta) -sin(theta); sin(theta) cos(theta)];
 
 rota = rot_matrix * a';
 rotb = rot_matrix * b';
 rotc = rot_matrix * c';
 
 % translation
 robot1 = [rota(1) + center(1), rota(2) + center(2)];
 robot2 = [rotb(1) + center(1), rotb(2) + center(2)];
 robot3 = [rotc(1) + center(1), rotc(2) + center(2)];

robot = [robot1; robot2; robot3; robot1];

% plot(robot(:,1),robot(:,2),'r');
% xlim([0 200]);
% ylim([0 200]);

end
 
 
 
 
 
 