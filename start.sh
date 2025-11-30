#!/bin/bash

session="glider"

tmux new-session -d -s $session

tmux rename-window -t 0 'Main'
tmux send-keys -t 'Main' 'cd glider_ws' C-m '. install/local_setup.bash' C-m

tmux split-window -h -t $session:0.0 -n 'Servo overview'
tmux send-keys -t 'Servo overview' 'cd glider_ws' C-m '. install/local_setup.bash' C-m 'ros2 topic echo /servo_publisher' C-m

tmux split-window -v -t $session:0.1 -n 'Servo control topic'
tmux send-keys -t 'Servo control topic' 'sudo pigpiod' C-m 'cd glider_ws' C-m '. install/local_setup.bash' C-m 'ros2 run servo_controller servo_control_node' C-m

tmux resize-pane -t $session:0.1 -x 30%
tmux resize-pane -t $session:0.2 -x 30%

tmux select-layout -t $session:0 tiled
