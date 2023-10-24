%% Move Robot with PID

clear
close all
clc

%% Parameters

% Workspace
xlim([0 200]);
ylim([0 200]);

% Robot Info

steering = pi/12; %15 degrees
L = 10; % wheel base

% Robot Initial Position
x = 100;
y = 100;

% Orientation
theta(1) = pi/4;

% Build robot model
robot = TriangularRobot(x,y,theta(1));

plot(robot(:,1),robot(:,2),'r');
xlim([0 200]);
ylim([0 200]);

%Initial Move robot parameters
nstep = 200; % number of steps
dt = 0.1; % timestep

%PID Parameters
% tracking a desire velocity
set_vel = 8;

previous_error = 0;
integral = 0;

% New parameters for the velocity model
c = 1; % electromechanic coefficient
m = 1; % mass
gamma = 0.01; % drag coeffient

% PID parameters
kp = 0.2;
ki = 0.03;
kd = 0.01;

%Initialize motion
x(1) = x;
y(1) = y;
vel(1) = 0;

% Main loop

for i = 1:nstep
    
    % Equation of motion of the robot - slide 12 of lecture 15
    x(i+1) = x(i) + vel(i)*cos(theta(i))*dt;
    y(i+1) = y(i) + vel(i)*sin(theta(i))*dt;
    theta(i+1) = theta(i)+vel(i)/L*tan(steering)*dt;
    
    % PID Controller to regulate velocity
    error = set_vel - vel(i);
    integral = integral + error*dt;
    derivative = (error-previous_error)/dt;
    out = kp*error + ki*integral + kd*derivative;
    previous_error = error;
    
    % Velocity model - slide 28 of lecture 14
    vel(i+1) = vel(i) + c/m*out - gamma*vel(i);
    
    % Plot robot
    robot = TriangularRobot(x(i),y(i),theta(i));
    
    robot_plot = plot(robot(:,1),robot(:,2),'b',x,y,'r');
    xlim([0 200]);
    ylim([0 200]);
    drawnow
    
end


figure
hold on
plot(1:nstep+1,vel(1,:),'b')
plot([0 nstep],[set_vel set_vel], 'g')
xlabel('Iteration')
ylabel('Velocity')
title('Velocity Comparison')






